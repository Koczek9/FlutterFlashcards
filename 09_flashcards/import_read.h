#pragma once

#include <iostream>
#include <vector>
#include <fstream>

#include "flashcard.h"

#define DATA_BASE_FILE_NAME "dictionary.xml"

std::vector<Flashcard> importFile(std::string fileName);
void writeXML(std::string fileName, std::vector<Flashcard> cards);
std::vector<Flashcard> readFile(std::string fileName);