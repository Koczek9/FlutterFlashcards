import 'package:flutter/material.dart';
import 'package:flashcards_flutter/screens/settings_screen.dart';

class FlashcardScaffold extends StatelessWidget {
  const FlashcardScaffold({super.key, required this.title, required this.body});

  final String title;
  final Widget body;

  void _openSettings(BuildContext context) {
    Navigator.of(
      context,
    ).push(MaterialPageRoute(builder: (ctx) => SettingsScreen()));
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text(title),
        backgroundColor: Colors.deepPurple.shade200,
        actions: [
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
