#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <random>
#include <ctime>
#include <algorithm>

#include "flashcard.h"

void shuffle(std::vector<Flashcard> &cards);
void learning(std::vector<Flashcard> cards);
void matchingGame(std::vector<Flashcard> cards);
void chooseTranslation(std::vector<Flashcard> cards);