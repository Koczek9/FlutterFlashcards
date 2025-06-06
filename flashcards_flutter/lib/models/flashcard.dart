String _removeColon(String word) {
  int colon = word.indexOf(':');
  if (colon < 0) {
    return word;
  }
  return word.substring(colon + 1).trim();
}

class Flashcard {
  bool known = false;
  String word = "";
  String usage = "";
  String translation = "";
  int levelOfKnowledge = 0;

  Flashcard({
    required String word,
    required this.usage,
    required String translation,
    this.known = false,
    this.levelOfKnowledge = 0,
  }) : word = _removeColon(word.toLowerCase()),
       translation = translation.toLowerCase();
}
