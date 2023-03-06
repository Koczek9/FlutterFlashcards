#pragma once

#include <iostream>
#include <algorithm>

std::string findXml(const std::string& sentence, const std::string& word);

class Flashcard {
    std::string known = "false";
    public:
    std::string word;
    std::string usage;
    std::string translation;
    int levelOfKnowledge = 0;

    Flashcard(std::string word, const std::string& usage, const std::string& translation);
    Flashcard(std::string word, const std::string& usage);
    Flashcard(const std::string& serializedItem);

    std::string serialize() const;
    void deserialize(const std::string& serialize);
    void setKnown(bool isKnown);
    bool getKnown() const;
};