#pragma once

#include <iostream>
#include <algorithm>

std::string findXml(std::string sentence, std::string word);

class Flashcard {
    std::string known = "false";
    public:
    std::string word;
    std::string usage;
    std::string translation;
    int levelOfKnowledge = 0;

    Flashcard(std::string word, std::string usage, std::string translation);
    Flashcard(std::string word, std::string usage);
    Flashcard(std::string serializedItem);

    std::string serialize();
    void deserialize(std::string serialize);
    void setKnown(bool isKnown);
    bool getKnown();
};