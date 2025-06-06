import 'package:flashcards_flutter/screens/matching_game.dart';
import 'package:flashcards_flutter/widgets/flashcard_scaffold.dart';
import 'package:flutter/material.dart';
import 'package:flashcards_flutter/screens/learning.dart';
import 'package:flashcards_flutter/screens/select.dart';
import 'package:flashcards_flutter/screens/translation_game.dart';

class ScreenSelector extends StatelessWidget {
  const ScreenSelector({super.key});

  void selectGame(BuildContext context, Games game) {
    Navigator.of(context).push(
      MaterialPageRoute(
        builder: (ctx) {
          if (game == Games.matching) {
            return MatchingGame();
          } else if (game == Games.translation) {
            return TranslationGame();
          } else if (game == Games.learning) {
            return Learning();
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
