import 'package:flutter/material.dart';
import 'package:flashcards_flutter/widgets/flashcard_scaffold.dart';

class MatchingGame extends StatelessWidget {
  const MatchingGame({super.key});

  @override
  Widget build(BuildContext context) {
    return FlashcardScaffold(
      title: 'Matching Game',
      body: Center(child: Text('This is the Matching Game screen.')),
    );
  }
}
