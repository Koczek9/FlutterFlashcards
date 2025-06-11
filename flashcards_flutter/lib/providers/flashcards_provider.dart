import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:flashcards_flutter/models/flashcard.dart';
import 'package:xml/xml.dart';
import 'dart:io';
import 'package:flutter/services.dart';
import 'package:path_provider/path_provider.dart';
import 'dart:math';

class FlashcardsProvider extends StateNotifier<List<Flashcard>> {
  FlashcardsProvider() : super([]);

  /*
  void addFlashcard(Flashcard flashcard) {
    state = [...state, flashcard];
  }

  void removeFlashcard(Flashcard flashcard) {
    state = state.where((fc) => fc != flashcard).toList();
  }

  void clearFlashcards() {
    state = [];
  }
  */

  final Random _random = Random();

  Future<String> loadDictionaryXml() async {
    return await rootBundle.loadString('assets/dictionary.xml');
  }

  void importDefaultFlashcards() async {
    var xmlString = await loadDictionaryXml();
    parseFlashcardsXml(xmlString);
    saveToFile();
  }

  void readFromFile() async {
    final file = File(await _flashcardsPath);
    if (!file.existsSync()) {
      print('Flashcards file does not exist at ${file.path}.');
      return;
    }
    var xmlString = await file.readAsString();
    parseFlashcardsXml(xmlString);
  }

  void parseFlashcardsXml(String xmlString) async {
    var document = XmlDocument.parse(xmlString);
    var flashcards = document.findAllElements('flashcard').map((element) {
      return Flashcard(
        translation: element
            .findElements('translation')
            .single
            .firstChild
            .toString(),
        usage: element.findElements('usage').single.firstChild.toString(),
        word: element.findElements('word').single.firstChild.toString(),
        known:
            element.findElements('known').single.firstChild.toString() ==
            'true',
        levelOfKnowledge:
            int.tryParse(
              element
                  .findElements('levelOfKnowledge')
                  .single
                  .firstChild
                  .toString(),
            ) ??
            0,
      );
    }).toList();
    state = flashcards;
    print('Loaded ${flashcards.length} flashcards from XML file.');
  }

  Future<String> get _flashcardsPath async {
    final directory = await getApplicationDocumentsDirectory();
    final flashcardsDirectory = '${directory.path}/flashcards.xml';

    return flashcardsDirectory;
  }

  void saveToFile() async {
    final flashcards = state;
    if (flashcards.isEmpty) {
      print('No flashcards to save.');
      return;
    }
    var builder = XmlBuilder();
    builder.processing('xml', 'version="1.0" encoding="UTF-8"');
    builder.element(
      'flashcards',
      nest: () {
        for (var flashcard in flashcards) {
          builder.element(
            'flashcard',
            nest: () {
              builder.element('word', nest: flashcard.word);
              builder.element('usage', nest: flashcard.usage);
              builder.element('translation', nest: flashcard.translation);
              builder.element('known', nest: flashcard.known.toString());
              builder.element(
                'levelOfKnowledge',
                nest: flashcard.levelOfKnowledge.toString(),
              );
            },
          );
        }
      },
    );
    var xmlString = builder.buildDocument().toXmlString(pretty: true);
    final file = File(await _flashcardsPath);
    await file.writeAsString(xmlString);
    print('Flashcards saved to ${file.path}');
  }

  List<Flashcard> get flashcards => state;

  Flashcard get randomCard {
    return flashcards[_random.nextInt(flashcards.length)];
  }

  List<Flashcard> randomCards(int count) {
    List<Flashcard> selectedCards = [];
    if (count > flashcards.length) {
      return selectedCards;
    }

    while (selectedCards.length < count) {
      Flashcard card = randomCard;
      if (!selectedCards.contains(card)) {
        selectedCards.add(card);
      }
    }
    return selectedCards;
  }
}

final flashcardsProvider =
    StateNotifierProvider<FlashcardsProvider, List<Flashcard>>(
      (ref) => FlashcardsProvider(),
    );
