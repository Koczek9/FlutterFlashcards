import 'package:flashcards_flutter/widgets/learning_stateless.dart';
import 'package:flutter/material.dart';
import 'package:flashcards_flutter/models/flashcard.dart';

class Learning extends StatefulWidget {
  Learning({super.key, required this.flashcards});

  final List<Flashcard> flashcards;
  int currentIndex = 0;

  @override
  State<Learning> createState() => _LearningState();

  get flashcard => flashcards[currentIndex];
}

class _LearningState extends State<Learning> {
  void nextFlashcard() {
    setState(() {
      widget.currentIndex =
          (widget.currentIndex + 1) % widget.flashcards.length;
      // Logic to go to the next flashcard
      // For example, you could keep track of the current index and increment it
    });
  }

  @override
  Widget build(BuildContext context) {
    return LearningStateless(
      flashcard: widget.flashcard,
      onNextPressed: nextFlashcard,
    );
  }
}
