import 'package:flashcards_flutter/models/settings.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';

class SettingsProvider extends StateNotifier<Settings> {
  SettingsProvider() : super(Settings());

  void replaceSettings(Settings newSettings) {
    state = newSettings;
  }

  void setSettings({
    bool? skipKnown,
    int? matchingOptionsCount,
    int? translationOptionsCount,
  }) {
    state = state.copyWith(
      skipKnown: skipKnown ?? state.skipKnown,
      matchingOptionsCount: matchingOptionsCount ?? state.matchingOptionsCount,
      translationOptionsCount:
          translationOptionsCount ?? state.translationOptionsCount,
    );
  }
}

final settingsProvider = StateNotifierProvider<SettingsProvider, Settings>(
  (ref) => SettingsProvider(),
);
