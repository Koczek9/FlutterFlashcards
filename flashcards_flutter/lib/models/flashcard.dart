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

  String findXml(String sentence, String word) {
    int position1 = sentence.indexOf("<$word>");
    int position2 = sentence.indexOf("</$word>");

    if (position1 < 0 || position2 < 0) {
      return "";
    }
    return sentence.substring(
      position1 + word.length + 2,
      position2 - position1 - word.length - 2,
    );
  }

  void deserialize(String serialize) {
    word = findXml(serialize, "word");
    usage = findXml(serialize, "usage");
    translation = findXml(serialize, "translation");
    known = findXml(serialize, "known") == "true";
    levelOfKnowledge = int.parse(findXml(serialize, "levelOfKnowledge"));
  }

  String serialize() {
    String serialize = "";
    serialize += "<Flashcard>\n";
    serialize += "    <word>$word</word>\n";
    serialize += "    <usage>$usage</usage>\n";
    serialize += "    <translation>$translation</translation>\n";
    serialize += "    <known>$known</known>\n";
    serialize += "    <levelOfKnowledge>$levelOfKnowledge</levelOfKnowledge>\n";
    serialize += "</Flashcard>\n";
    return serialize;
  }

  Flashcard.fromXml(String xml) {
    deserialize(xml);
  }
}
