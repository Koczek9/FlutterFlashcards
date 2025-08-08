import 'package:flashcards_flutter/screens/matching_game.dart';
import 'package:flashcards_flutter/widgets/flashcard_scaffold.dart';
import 'package:flutter/material.dart';
import 'package:flashcards_flutter/screens/learning.dart';
import 'package:flashcards_flutter/screens/select.dart';
import 'package:flashcards_flutter/screens/translation_game.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:flashcards_flutter/providers/flashcards_provider.dart';

class ScreenSelector extends ConsumerStatefulWidget {
  const ScreenSelector({super.key});

  @override
  ConsumerState<ScreenSelector> createState() => _ScreenSelectorState();
}

class _ScreenSelectorState extends ConsumerState<ScreenSelector> {
  void selectGame(BuildContext context, Games game) {
    Navigator.of(context).push(
      MaterialPageRoute(
        builder: (ctx) {
          if (game == Games.matching) {
            return MatchingGame();
          } else if (game == Games.translation) {
            return TranslationGame();
          } else if (game == Games.learning) {
            ref.read(flashcardsProvider.notifier).resetCurrentRandomCards();
            return Learning();
          }
          return Text("Game not implemented");
        },
      ),
    );
  }

  @override
  void initState() {
    super.initState();
    ref.read(flashcardsProvider.notifier).readFromFile();
  }

  @override
  Widget build(BuildContext context) {
    return FlashcardScaffold(
      title: "Flashcards",
      editVisible: false,
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
