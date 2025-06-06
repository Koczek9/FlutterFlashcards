import 'package:flashcards_flutter/screens/matching_game.dart';
import 'package:flashcards_flutter/widgets/flashcard_scaffold.dart';
import 'package:flutter/material.dart';
import 'package:flashcards_flutter/screens/learning.dart';
import 'package:flashcards_flutter/models/flashcard.dart';
import 'package:flashcards_flutter/screens/select.dart';
import 'package:flashcards_flutter/screens/settings_screen.dart';
import 'package:flashcards_flutter/screens/translation_game.dart';

class ScreenSelector extends StatelessWidget {
  const ScreenSelector({super.key});

  static List<Flashcard> flashcards = [
    Flashcard(
      word: "foes",
      usage: "He ducked inside, checking the corners for foes.",
      translation: "wrogowie",
    ),
    Flashcard(
      word: "tailored",
      usage:
          "His clothing was terribly dusty, but well tailored: a fine suit, a silver cravat at the neck, twinkling cuff links on the sleeves of his fine white shirt.",
      translation: "Dostosowane",
    ),
    Flashcard(
      word: "rattle",
      usage:
          "His sudden Push caused the wall to rattle, the old rusty nails straining in their places.",
      translation: "grzechotka",
    ),
    Flashcard(
      word: "sudden",
      usage: "His sudden Push caused the wall to rattle.",
      translation: "nagły",
    ),
    Flashcard(
      word: "Push",
      usage: "His sudden Push caused the wall to rattle.",
      translation: "Pchnij",
    ),
    Flashcard(
      word: "twinkling",
      usage:
          "His clothing was terribly dusty, but well tailored: a fine suit, a silver cravat at the neck, twinkling cuff links on the sleeves of his fine white shirt.",
      translation: "migoczący",
    ),
  ];

  void selectGame(BuildContext context, Games game) {
    Navigator.of(context).push(
      MaterialPageRoute(
        builder: (ctx) {
          if (game == Games.matching) {
            return MatchingGame();
          } else if (game == Games.translation) {
            return TranslationGame(flashcards: flashcards);
          } else if (game == Games.learning) {
            return Learning(flashcards: flashcards);
          }
          return Text("Game not implemented");
        },
      ),
    );
  }

  @override
  Widget build(BuildContext context) {
    return FlashcardScaffold(
      title: "Flashcards",
      body: Container(
        /*decoration: BoxDecoration(
            gradient: LinearGradient(
              colors: [
                const Color.fromARGB(255, 5, 204, 61),
                const Color.fromARGB(255, 85, 33, 175),
              ],
              begin: Alignment.topLeft,
              end: Alignment.bottomRight,
            ),
          ),
          */
        padding: const EdgeInsets.all(20),
        alignment: Alignment.center,
        child: Select(onGameSelected: selectGame),
      ),
    );
  }
}
