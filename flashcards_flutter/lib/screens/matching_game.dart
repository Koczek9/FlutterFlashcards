import 'package:flutter/material.dart';
import 'package:flashcards_flutter/widgets/flashcard_scaffold.dart';
import 'package:flashcards_flutter/widgets/matching_button.dart';
import 'package:flashcards_flutter/models/matching_element.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:flashcards_flutter/providers/flashcards_provider.dart';
import 'package:flashcards_flutter/providers/settings_provider.dart';
import 'package:flashcards_flutter/models/flashcard.dart';

class MatchingGame extends ConsumerStatefulWidget {
  MatchingGame({super.key, this.words});
  List<MatchingElement>? words;
  List<MatchingElement>? translations;

  @override
  ConsumerState<MatchingGame> createState() => _MatchingGameState();
}

class _MatchingGameState extends ConsumerState<MatchingGame> {
  void onTap(MatchingElement element) {
    setState(() {
      // Select the clicked element and reset others
      setClicked(element);
      setVanished(element);
    });
  }

  void setClicked(MatchingElement element) {
    // Toggle the clicked element (so you can deselect) and reset others
    List<MatchingElement> elements = element.type == MatchingElementType.word
        ? widget.words!
        : widget.translations!;

    for (var e in elements) {
      if (e.name == element.name) {
        e.isClicked = !e.isClicked;
      } else {
        e.isClicked = false;
      }
    }
  }

  void setVanished(MatchingElement element) {
    List<MatchingElement> mirrorElements =
        element.type == MatchingElementType.word
        ? widget.translations!
        : widget.words!;

    var mirrorElement = mirrorElements.firstWhere(
      (e) => e.isClicked,
      orElse: () => MatchingElement(
        flashcard: Flashcard(word: "", usage: "", translation: ""),
        type: element.type,
      ),
    );

    if (mirrorElement.isClicked) {
      if (mirrorElement.flashcard == element.flashcard) {
        // If the clicked element matches the selected one, mark both as vanished
        element.isVanished = true;
        mirrorElement.isVanished = true;
      }
      // Reset clicked state either way
      element.isClicked = false;
      mirrorElement.isClicked = false;
    }
  }

  @override
  Widget build(BuildContext context) {
    final currentSettings = ref.watch(settingsProvider);
    final int optionCount = currentSettings.matchingOptionsCount;

    if (widget.words == null ||
        widget.words!.isEmpty ||
        widget.words!.every((test) => test.isVanished == true) ||
        widget.words!.length != optionCount) {
      // When no words found
      // or all words vanished
      // or someone increased the option count while in game
      List<Flashcard> possibleAnswers = ref
          .read(flashcardsProvider.notifier)
          .randomCards(optionCount);

      widget.words = possibleAnswers
          .map(
            (flashcard) => MatchingElement(
              flashcard: flashcard,
              type: MatchingElementType.word,
            ),
          )
          .toList();
      widget.translations = possibleAnswers
          .map(
            (flashcard) => MatchingElement(
              flashcard: flashcard,
              type: MatchingElementType.translation,
            ),
          )
          .toList();

      // Shuffle one list, items were chosen randomly so shuffling one is enough
      widget.translations!.shuffle();
    }

    if (widget.words == null || widget.words!.length < optionCount) {
      return FlashcardScaffold(
        title: 'Matching Game',
        body: Center(
          child: Text(
            'Flashcards count is too low for this game. Minimum required: $optionCount. You can change this in settings.',
            style: TextStyle(fontSize: 24, color: Colors.red),
          ),
        ),
      );
    }

    return FlashcardScaffold(
      title: 'Matching Game',
      body: Center(
        child: Row(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            Expanded(
              child: Column(
                mainAxisAlignment: MainAxisAlignment.center,
                crossAxisAlignment: CrossAxisAlignment.stretch,
                children: [
                  for (var element in widget.words!)
                    MatchingButton(element: element, onTap: onTap),
                ],
              ),
            ),
            Expanded(
              child: Column(
                mainAxisAlignment: MainAxisAlignment.center,
                crossAxisAlignment: CrossAxisAlignment.stretch,
                children: [
                  for (var element in widget.translations!)
                    MatchingButton(element: element, onTap: onTap),
                ],
              ),
            ),
          ],
        ),
      ),
    );
  }
}
