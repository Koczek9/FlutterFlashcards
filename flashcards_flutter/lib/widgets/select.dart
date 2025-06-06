import 'package:flutter/material.dart';

enum Games { learning, matching, translation, select, settings }

class Select extends StatelessWidget {
  const Select({super.key, required this.onGameSelected});

  final void Function(Games) onGameSelected;

  @override
  Widget build(BuildContext context) {
    return Center(
      child: Column(
        mainAxisAlignment: MainAxisAlignment.center,
        children: [
          ElevatedButton(
            onPressed: () => onGameSelected(Games.learning),
            child: const Text('Learning'),
          ),
          ElevatedButton(
            onPressed: () => onGameSelected(Games.matching),
            child: const Text('Matching'),
          ),
          ElevatedButton(
            onPressed: () => onGameSelected(Games.translation),
            child: const Text('Translation'),
          ),
        ],
      ),
    );
  }
}
