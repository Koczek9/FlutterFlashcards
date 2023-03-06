#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <random>
#include <ctime>
#include <algorithm>

#include "flashcard.h"

#define QUIT_CODE -2

void shuffle(std::vector<Flashcard> &cards);
int checkInput(const int maxInput, bool isInputANumber);
void learning(std::vector<Flashcard>& cards);
void matchingGame(std::vector<Flashcard>& cards);
void chooseTranslation(std::vector<Flashcard>& cards);
void chooseGame (std::vector<Flashcard>& cards);