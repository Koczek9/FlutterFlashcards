import 'package:flutter/material.dart';
import 'package:flashcards_flutter/models/flashcard.dart';

// I wanted the learning stateless to remain stateless so I moved the only
// logic that needed to be stateful into its own widget.
class KnownButton extends StatefulWidget {
  const KnownButton({super.key, required this.flashcard});

  final Flashcard flashcard;

  @override
  State<KnownButton> createState() => _KnownButtonState();
}

class _KnownButtonState extends State<KnownButton> {
  @override
  Widget build(BuildContext context) {
    return Row(
      mainAxisAlignment: MainAxisAlignment.center,
      children: [
        Text('Known', style: TextStyle(fontSize: 16)),
        Checkbox(
          value: widget.flashcard.known,
          onChanged: (value) {
            setState(() {
              widget.flashcard.known = value!;
            });
          },
        ),
      ],
    );
  }
}
