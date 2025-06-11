import 'package:flashcards_flutter/models/flashcard.dart';

enum MatchingElementType { word, translation }

class MatchingElement {
  Flashcard flashcard;
  bool isClicked;
  bool isVanished;
  MatchingElementType type;

  MatchingElement({
    required this.flashcard,
    this.isClicked = false,
    this.isVanished = false,
    required this.type,
  });

  String get name {
    return type == MatchingElementType.word
        ? flashcard.word
        : flashcard.translation;
  }
}
