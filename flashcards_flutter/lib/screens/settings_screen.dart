import 'package:flutter/material.dart';
import 'package:flashcards_flutter/providers/settings_provider.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:flashcards_flutter/providers/flashcards_provider.dart';
import 'package:file_picker/file_picker.dart';

class SettingsScreen extends ConsumerWidget {
  const SettingsScreen({super.key});

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    final currentSettings = ref.watch(settingsProvider);

    void _importFlashcardsFromFile() async {
      FilePickerResult? result = await FilePicker.platform.pickFiles(
        type: FileType.custom,
        allowedExtensions: ['xml', 'db'],
      );
      if (result != null) {
        if (result.files.first.extension == "db") {
          // pop up with message
          showDialog(
            context: context,
            builder: (context) {
              return AlertDialog(
                title: const Text('Database File Selected'),
                content: const Text('Please use python importer first'),
                actions: [
                  TextButton(
                    onPressed: () {
                      Navigator.of(context).pop();
                    },
                    child: const Text('OK'),
                  ),
                ],
              );
            },
          );
        } else {
          ref
              .read(flashcardsProvider.notifier)
              .importFlashcardsFromFile(result.files.first.path!);
        }
        // Process the selected file
      }
    }

    return Scaffold(
      appBar: AppBar(
        title: const Text('Settings'),
        backgroundColor: Colors.deepPurple.shade200,
      ),
      body: Center(
        child: Column(
          mainAxisSize: MainAxisSize.min,
          children: [
            SwitchListTile(
              title: const Text('Skip known'),
              value: currentSettings.skipKnown,
              onChanged: (bool value) {
                ref
                    .read(settingsProvider.notifier)
                    .setSettings(skipKnown: value);
              },
            ),
            Text("Translation game options count:"),
            Slider(
              value: currentSettings.translationOptionsCount.toDouble(),
              onChanged: (value) {
                ref
                    .read(settingsProvider.notifier)
                    .setSettings(translationOptionsCount: value.toInt());
              },
              min: 2,
              max: 10,
              divisions: 8,
              label:
                  'Translation Options Count: ${currentSettings.translationOptionsCount}',
            ),
            Text("Matching game options count:"),
            Slider(
              value: currentSettings.matchingOptionsCount.toDouble(),
              onChanged: (value) {
                ref
                    .read(settingsProvider.notifier)
                    .setSettings(matchingOptionsCount: value.toInt());
              },
              min: 2,
              max: 10,
              divisions: 8,
              label:
                  'Learning Options Count: ${currentSettings.matchingOptionsCount}',
            ),
            SizedBox(height: 80),
            ElevatedButton(
              onPressed: () {
                ref.read(flashcardsProvider.notifier).importDefaultFlashcards();
              },
              child: const Text('Import default Flashcards file'),
            ),
            SizedBox(height: 10),
            ElevatedButton(
              onPressed: () => _importFlashcardsFromFile(),
              child: const Text('Import Flashcards from file'),
            ),
          ],
        ),
      ),
    );
  }
}
