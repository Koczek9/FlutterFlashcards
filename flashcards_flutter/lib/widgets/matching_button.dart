import 'package:flutter/material.dart';
import 'package:flashcards_flutter/models/matching_element.dart';

class MatchingButton extends StatelessWidget {
  const MatchingButton({super.key, required this.element, required this.onTap});

  final void Function(MatchingElement) onTap;
  final MatchingElement element;

  @override
  Widget build(BuildContext context) {
    if (element.isVanished) {
      return const SizedBox(height: 48);
    }

    return ElevatedButton(
      onPressed: () {
        onTap(element);
      },
      style: ElevatedButton.styleFrom(
        foregroundColor: Colors.white,
        backgroundColor: element.isClicked
            ? Colors.blue.shade300
            : Colors.deepPurple.shade300,
        shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(30)),
        padding: const EdgeInsets.symmetric(horizontal: 24, vertical: 12),
      ),
      child: Text(element.name, textAlign: TextAlign.center),
    );
  }
}
