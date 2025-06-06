import 'package:flutter/material.dart';
import 'package:flashcards_flutter/providers/settings_provider.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';

class SettingsScreen extends ConsumerWidget {
  const SettingsScreen({super.key});

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    final currentSettings = ref.watch(settingsProvider);
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
              title: const Text('Skip known (not yet implemented)'),
              value: currentSettings.skipKnown,
              onChanged: (bool value) {
                ref
                    .read(settingsProvider.notifier)
                    .setSettings(skipKnown: value);
                // Here you could also apply the theme change globally
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
          ],
        ),
      ),
    );
  }
}
