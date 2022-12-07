#pragma once

#include <iostream>
#include <vector>
#include <fstream>

#include "flashcard.h"

std::vector<Flashcard> importFile(std::string fileName);
std::vector<Flashcard> readFile(std::string fileName);