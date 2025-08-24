import 'package:flutter/material.dart';
import 'package:flashcards_flutter/models/flashcard.dart';
import 'package:flashcards_flutter/widgets/known_button.dart';

class LearningStateless extends StatelessWidget {
  LearningStateless({
    super.key,
    required this.flashcard,
    required this.onNextPressed,
    required this.onPreviousPressed,
    required this.onSavePressed,
  });

  final Flashcard flashcard;
  final void Function() onNextPressed;
  final void Function() onPreviousPressed;
  final void Function() onSavePressed;
  final bool editingMode = true;

  @override
  Widget build(BuildContext context) {
    final overrideTranslationController = TextEditingController(
      text: flashcard.translation,
    );

    const double boxHeight = 40;
    double height = MediaQuery.sizeOf(context).height;
    height -=
        MediaQuery.paddingOf(context).top +
        MediaQuery.paddingOf(context).bottom;

    return Expanded(
      child: Column(
        mainAxisAlignment: MainAxisAlignment.center,
        children: [
          SizedBox(height: height / 6),
          Container(
            constraints: BoxConstraints(
              minWidth: double.infinity,
              minHeight: boxHeight,
            ),
            alignment: Alignment.center,
            decoration: BoxDecoration(color: Colors.deepPurple.shade300),
            child: Text(
              flashcard.word,
              style: TextStyle(fontSize: 24, fontWeight: FontWeight.bold),
              textAlign: TextAlign.center,
            ),
          ),
          if (!editingMode)
            Container(
              constraints: BoxConstraints(
                minWidth: double.infinity,
                minHeight: boxHeight,
              ),
              alignment: Alignment.center,
              decoration: BoxDecoration(color: Colors.deepPurple.shade200),
              child: Text(
                flashcard.translation,
                style: TextStyle(fontSize: 18),
                textAlign: TextAlign.center,
              ),
            ),
          if (editingMode)
            TextField(
              decoration: InputDecoration(
                labelText: 'Override translation',
                labelStyle: TextStyle(color: Colors.black),
                border: OutlineInputBorder(),
                fillColor: Colors.deepPurple.shade200,
                filled: true,
              ),
              textAlign: TextAlign.center,
              maxLines: 1,
              controller: overrideTranslationController,
            ),

          SizedBox(height: 10),
          Text(flashcard.usage, style: TextStyle(fontSize: 16)),
          Spacer(),
          KnownButton(flashcard: flashcard),
          Row(
            children: [
              ElevatedButton(
                onPressed: () => onPreviousPressed(),
                child: Text("Previous"),
              ),
              ElevatedButton(
                onPressed: () => onNextPressed(),
                child: Text('Next'),
              ),
              Spacer(),
              if (editingMode)
                ElevatedButton(
                  onPressed: () {
                    String overrideTranslationCandidate =
                        overrideTranslationController.text.trim().toLowerCase();
                    if (overrideTranslationCandidate.isEmpty) {
                      ScaffoldMessenger.of(context).showSnackBar(
                        SnackBar(
                          content: Text('Translation cannot be empty!'),
                          duration: const Duration(seconds: 2),
                        ),
                      );
                      return;
                    }
                    flashcard.translation = overrideTranslationCandidate;
                    FocusScope.of(context).unfocus();
                    onSavePressed();
                  },
                  child: Text("Save"),
                ),
            ],
          ),
        ],
      ),
    );
  }
}
