import 'package:flutter/material.dart';

enum Games { learning, matching, translation, select, settings }

class Select extends StatelessWidget {
  const Select({super.key, required this.onGameSelected});

  final void Function(BuildContext, Games) onGameSelected;

  @override
  Widget build(BuildContext context) {
    return Center(
      child: Column(
        mainAxisAlignment: MainAxisAlignment.center,
        children: [
          ElevatedButton(
            onPressed: () => onGameSelected(context, Games.learning),
            child: const Text('Learning'),
          ),
          ElevatedButton(
            onPressed: () => onGameSelected(context, Games.matching),
            child: const Text('Matching'),
          ),
          ElevatedButton(
            onPressed: () => onGameSelected(context, Games.translation),
            child: const Text('Translation'),
          ),
        ],
      ),
    );
  }
}
