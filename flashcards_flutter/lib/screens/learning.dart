import 'package:flashcards_flutter/screens/learning_stateless.dart';
import 'package:flutter/material.dart';
import 'package:flashcards_flutter/widgets/flashcard_scaffold.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:flashcards_flutter/providers/flashcards_provider.dart';

class Learning extends ConsumerStatefulWidget {
  Learning({super.key});

  int currentIndex = 0;
  @override
  ConsumerState<Learning> createState() => _LearningState();
}

class _LearningState extends ConsumerState<Learning> {
  @override
  Widget build(BuildContext context) {
    var flashcards = ref.watch(flashcardsProvider.notifier).currentRandomCards;
    final titleString = flashcards.isEmpty ? "Learning" : "Edit Flashcards";

    if (flashcards.isEmpty) {
      flashcards = ref.watch(flashcardsProvider);
    }

    if (flashcards.isEmpty) {
      return FlashcardScaffold(
        title: titleString,
        editVisible: false,
        body: Center(
          child: Text(
            'No flashcards available. Please add some flashcards to start.',
            style: TextStyle(fontSize: 24, color: Colors.red),
          ),
        ),
      );
    }

    return FlashcardScaffold(
      title: titleString,
      editVisible: false,
      body: Column(
        children: [
          LearningStateless(
            flashcard: flashcards[widget.currentIndex],
            onNextPressed: () {
              setState(() {
                widget.currentIndex =
                    (widget.currentIndex + 1) % flashcards.length;
              });
            },
          ),
          SizedBox(height: 20),
          Text('Progress: ${widget.currentIndex + 1} / ${flashcards.length}'),
          Slider(
            value: widget.currentIndex.toDouble(),
            onChanged: (value) {
              setState(() {
                widget.currentIndex = value.toInt();
              });
            },
            min: 0,
            max: flashcards.length - 1,
            //divisions: 8,
          ),
          SizedBox(height: 40),
        ],
      ),
    );
  }
}
