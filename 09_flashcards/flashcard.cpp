#include "flashcard.h"

std::string findXml(std::string sentence, std::string word)
{   
    int position1 = sentence.find("<" + word + ">");
    int position2 = sentence.find("</" + word + ">");

    if (position1 < 0 || position2 < 0)
    {
        return std::string();
    }
    return sentence.substr(position1 + word.length() + 2, position2 - position1 - word.length() - 2);
}

Flashcard::Flashcard(std::string word, std::string usage, std::string translation)
{
    int colon = word.find(':');
    word = word.substr(colon + 1);
    std::transform(word.begin(), word.end(), word.begin(), tolower);
    this->word = word;
    this->usage = usage;
    this->translation = translation;
}

Flashcard::Flashcard(std::string word, std::string usage) : Flashcard(word,usage, std::string())
{

}

Flashcard::Flashcard(std::string serializedItem)
{
    deserialize(serializedItem);
}

std::string Flashcard::serialize()
{
    std::string serialize;
    serialize += "<Flashcard>\n";
    serialize += "    <word>" + word + "</word>\n";
    serialize += "    <usage>" + usage + "</usage>\n";
    serialize += "    <translation>" + translation + "</translation>\n";
    serialize += "    <known>" + known + "</known>\n";
    serialize += "</Flashcard>\n";
    return serialize;
}

void Flashcard::deserialize(std::string serialize)
{
    word = findXml(serialize, "word");
    usage = findXml(serialize, "usage");
    translation = findXml(serialize, "translation");
    known = findXml(serialize, "known");
}

void Flashcard::setKnown(bool isKnown)
{
    if(isKnown)
    {
        known = "true";
    }
    else 
    {
        known = "false";
    }
}

bool Flashcard::getKnown()
{
    bool isKnown = 0;
    if(known == "true")
    {
        isKnown = 1;
    }
    return isKnown;
}
