import 'package:flashcards_flutter/widgets/flashcard_scaffold.dart';
import 'package:flutter/material.dart';
import 'package:flashcards_flutter/models/flashcard.dart';
import 'package:flashcards_flutter/widgets/answer_button.dart';
import 'package:flashcards_flutter/providers/settings_provider.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'dart:math';

class TranslationGame extends ConsumerStatefulWidget {
  TranslationGame({super.key, required this.flashcards});
  final List<Flashcard> flashcards;
  final Random random = Random();

  Flashcard get randomCard {
    return flashcards[random.nextInt(flashcards.length)];
  }

  int score = 0;
  int attempts = 0;

  void applyAnswer(bool correct) {
    attempts++;
    if (correct) {
      score++;
    }
    // You can add more logic here, like showing a message or updating the UI
  }

  @override
  ConsumerState<TranslationGame> createState() => _TranslationGameState();
}

class _TranslationGameState extends ConsumerState<TranslationGame> {
  @override
  Widget build(BuildContext context) {
    final currentSettings = ref.watch(settingsProvider);
    final int optionCount = currentSettings.translationOptionsCount;
    if (widget.flashcards.isEmpty || widget.flashcards.length < optionCount) {
      return FlashcardScaffold(
        title: 'Translation Game',
        body: Center(
          child: Text(
            'Flashcards count ${widget.flashcards.length} is too low for this game. Minimum required: ${optionCount + 1}. You can change this in settings.',
            style: TextStyle(fontSize: 24, color: Colors.red),
          ),
        ),
      );
    }
    final Flashcard correctAnswer = widget.randomCard;
    List<Flashcard> possibleAnswers = [correctAnswer];

    while (possibleAnswers.length < optionCount) {
      final Flashcard answer = widget.randomCard;
      if (!possibleAnswers.contains(answer)) {
        possibleAnswers.add(answer);
      }
    }
    possibleAnswers.shuffle();

    return FlashcardScaffold(
      title: 'Translation Game',
      body: SizedBox(
        width: double.infinity,
        child: Container(
          margin: const EdgeInsets.all(30),
          child: Column(
            mainAxisAlignment: MainAxisAlignment.center,
            crossAxisAlignment: CrossAxisAlignment.stretch,
            children: [
              Text(
                correctAnswer.word,
                textAlign: TextAlign.center,
                style: TextStyle(fontSize: 24),
              ),

              ...possibleAnswers.map((flashcard) {
                return AnswerButton(
                  answerText: flashcard.translation,
                  onTap: () {
                    final bool isCorrect = flashcard == correctAnswer;
                    widget.applyAnswer(isCorrect);
                    if (!isCorrect) {
                      ScaffoldMessenger.of(context).showSnackBar(
                        SnackBar(
                          content: Text(
                            'Wrong! ${correctAnswer.word} = ${correctAnswer.translation}',
                          ),
                          duration: const Duration(seconds: 3),
                        ),
                      );
                    }

                    setState(() {
                      // Trigger a rebuild to show the next question
                    });
                  },
                );
              }),
              const SizedBox(height: 20),
              Text("Score: ${widget.score}/${widget.attempts}"),
            ],
          ),
        ),
      ),
    );
  }
}
