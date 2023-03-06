#pragma once

#include <iostream>
#include <vector>
#include <fstream>

#include "flashcard.h"

#define DATA_BASE_FILE_NAME "../dictionary.xml"

std::vector<Flashcard> importFile(const std::string& fileName);
void writeXML(const std::string& fileName, const std::vector<Flashcard>& cards);
std::vector<Flashcard> readFile(const std::string& fileName);