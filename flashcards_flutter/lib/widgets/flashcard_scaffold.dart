import 'package:flashcards_flutter/screens/learning.dart';
import 'package:flutter/material.dart';
import 'package:flashcards_flutter/screens/settings_screen.dart';

class FlashcardScaffold extends StatelessWidget {
  const FlashcardScaffold({
    super.key,
    required this.title,
    required this.body,
    this.editVisible = true,
  });

  final String title;
  final Widget body;
  final bool editVisible;

  void _openSettings(BuildContext context) {
    Navigator.of(
      context,
    ).push(MaterialPageRoute(builder: (ctx) => SettingsScreen()));
  }

  void _openEdit(BuildContext context) {
    Navigator.of(context).push(MaterialPageRoute(builder: (ctx) => Learning()));
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text(title),
        backgroundColor: Colors.deepPurple.shade200,
        actions: [
          if (editVisible)
            IconButton(
              icon: const Icon(Icons.edit),
              onPressed: () {
                _openEdit(context);
              },
            ),
          IconButton(
            icon: const Icon(Icons.settings),
            onPressed: () {
              _openSettings(context);
            },
          ),
        ],
      ),
      body: body,
    );
  }
}
