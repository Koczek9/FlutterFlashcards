import 'package:flutter/material.dart';
import 'package:flashcards_flutter/models/flashcard.dart';

class LearningStateless extends StatelessWidget {
  const LearningStateless({
    super.key,
    required this.flashcard,
    required this.onNextPressed,
  });

  final Flashcard flashcard;
  final void Function() onNextPressed;

  @override
  Widget build(BuildContext context) {
    const double boxHeight = 40;
    double height = MediaQuery.sizeOf(context).height;
    height -=
        MediaQuery.paddingOf(context).top +
        MediaQuery.paddingOf(context).bottom;

    return Column(
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
        SizedBox(height: 10),
        Text(flashcard.usage, style: TextStyle(fontSize: 16)),
        Spacer(),
        Row(
          children: [
            ElevatedButton(
              onPressed: () {
                flashcard.known = true;
              },
              child: Text("Known"),
            ),
            ElevatedButton(
              onPressed: () => onNextPressed(),
              child: Text('Next'),
            ),
          ],
        ),
        SizedBox(height: height / 15),
      ],
    );
  }
}
