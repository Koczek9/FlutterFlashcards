class Settings {
  bool skipKnown;
  int matchingOptionsCount;
  int translationOptionsCount;

  Settings({
    this.skipKnown = false,
    this.matchingOptionsCount = 4,
    this.translationOptionsCount = 4,
  });

  copyWith({
    bool? skipKnown,
    int? matchingOptionsCount,
    int? translationOptionsCount,
  }) {
    return Settings(
      skipKnown: skipKnown ?? this.skipKnown,
      matchingOptionsCount: matchingOptionsCount ?? this.matchingOptionsCount,
      translationOptionsCount:
          translationOptionsCount ?? this.translationOptionsCount,
    );
  }
}
