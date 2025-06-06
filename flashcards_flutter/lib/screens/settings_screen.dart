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
        child: SwitchListTile(
          title: const Text('Skip known'),
          value: currentSettings.skipKnown,
          onChanged: (bool value) {
            ref.read(settingsProvider.notifier).setSettings(skipKnown: value);
            // Here you could also apply the theme change globally
          },
        ),
      ),
    );
  }
}
