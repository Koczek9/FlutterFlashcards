#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>

class Flashcard {
    public:
    std::string word;
    std::string usage;

    Flashcard(std::string word, std::string usage){
        int colon = word.find(':');
        word = word.substr(colon + 1);
        std::transform(word.begin(), word.end(), word.begin(), tolower);
        this->word = word;
        this->usage = usage;
    }
};

int main() 
{
    std::string line;
    std::vector<Flashcard> cards;

    //Read from the text file
    std::ifstream flashcards ("flashcards.csv");

    while (getline (flashcards, line))
    {
      int position = line.find('\t');
      std::string usage = line.substr(position + 1);
      std::string word = line.substr(0,position);

      cards.emplace_back(Flashcard(word, usage));
    }
    
    //shuffle cards
    auto rd = std::random_device {}; 
    auto rng = std::default_random_engine { rd() };
    std::shuffle(std::begin(cards), std::end(cards), rng);
 
    for(auto card : cards)
    {
        std::cout << card.word << std::endl;
    }

    /* for(int i = 0; i < cards.size(); i++)
    {
        std::cout << cards[i].usage << std::endl;
    } */

    //std::cout << "Choose one of the following options: " << std::endl;

    return 0;
}

