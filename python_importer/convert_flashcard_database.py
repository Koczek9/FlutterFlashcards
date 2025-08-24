# This script converts a flashcard database from vocab.db sqlite format to dictionary.xml format

import sqlite3
from googletrans import Translator
import asyncio
import Levenshtein

def read_database(input_db_path):
    with sqlite3.connect(input_db_path) as conn:
        cursor = conn.cursor()

        cursor.execute("SELECT word, id FROM words")
        words = cursor.fetchall()
        flashcards = []
        for word, id in words:
            cursor.execute("SELECT usage FROM LOOKUPS WHERE word_key = ?", [id])
            usages = cursor.fetchall()
            flashcards.append((word, usages[0][0].strip() if usages else ''))

    return flashcards


async def translate_words(flashcards, to_lang="pl", from_lang="en"):
    words = []
    for word in flashcards:
        words.append(word[0])

    async with Translator() as translator:
        translations = await translator.translate(words, src=from_lang, dest=to_lang)
        for i, translation in enumerate(translations):
            flashcards[i] = (flashcards[i][0].lower(), flashcards[i][1], translation.text.lower())

    return flashcards


def save_flashcards_to_xml(flashcards, output_xml_path):
    with open(output_xml_path, 'w') as xml_file:
        xml_file.write("<flashcards>\n")
        for (word, usage, translation) in flashcards:
            xml_file.write(f"  <flashcard>\n")
            xml_file.write(f"    <word>{word}</word>\n")
            xml_file.write(f"    <usage>{usage}</usage>\n")
            xml_file.write(f"    <translation>{translation}</translation>\n")
            xml_file.write(f"    <known>false</known>\n")
            xml_file.write(f"    <levelOfKnowledge>0</levelOfKnowledge>\n")
            xml_file.write(f"  </flashcard>\n")
        xml_file.write("</flashcards>\n")


def verify_translation_worked(flashcards):
    for (word, _, translation) in flashcards:
        if Levenshtein.distance(word, translation) < 2:
            print(f"Translation probably failed for '{word}' as translation is '{translation}'")


async def convert_flashcard_database(input_db_path, output_xml_path):
    flashcards = read_database(input_db_path)
    flashcards = await translate_words(flashcards)
    save_flashcards_to_xml(flashcards, output_xml_path)
    verify_translation_worked(flashcards)

if __name__ == "__main__":
    asyncio.run(convert_flashcard_database('vocab.db', 'dictionary.xml'))
