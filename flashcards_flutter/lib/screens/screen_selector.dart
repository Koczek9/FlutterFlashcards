import 'package:flutter/material.dart';
import 'package:flashcards_flutter/widgets/learning.dart';
import 'package:flashcards_flutter/models/flashcard.dart';
import 'package:flashcards_flutter/screens/select.dart';
import 'package:flashcards_flutter/screens/settings.dart';
import 'package:flashcards_flutter/screens/translation_game.dart';

class ScreenSelector extends StatefulWidget {
  const ScreenSelector({super.key});

  @override
  State<ScreenSelector> createState() => _ScreenSelectorState();
}

class _ScreenSelectorState extends State<ScreenSelector> {
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
  Games currentGame = Games.select;

  void pickGame(Games game) {
    setState(() {
      currentGame = game;
    });
  }

  @override
  Widget build(BuildContext context) {
    Widget screenWidget;
    String title = "";

    if (currentGame == Games.learning) {
      screenWidget = Learning(flashcards: flashcards);
      title = "Learning";
    } else if (currentGame == Games.translation) {
      screenWidget = TranslationGame(flashcards: flashcards);
      title = "Choose translation";
    } else if (currentGame == Games.settings) {
      screenWidget = Settings();
      title = "Settings";
    } else if (currentGame == Games.matching) {
      // Placeholder for matching game
      screenWidget = Center(
        child: Text("Matching game is not implemented yet."),
      );
      title = "Matching game";
    } else {
      screenWidget = Select(onGameSelected: pickGame);
      title = "Flashcards";
    }

    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(
          title: Text(title),
          backgroundColor: Colors.deepPurple.shade200,
          actions: [
            IconButton(
              icon: const Icon(Icons.settings),
              onPressed: () {
                pickGame(Games.settings);
              },
            ),
            IconButton(
              icon: const Icon(Icons.home),
              onPressed: () {
                pickGame(Games.select);
              },
            ),
          ],
        ),
        //backgroundColor: const Color.fromARGB(255, 77, 80, 152),
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
          child: screenWidget,
        ),
      ),
    );
  }
}
