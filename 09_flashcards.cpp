#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

class Flashcard {
    public:
    std::string word;
    std::string usage;
    std::string translation;

    Flashcard(std::string word, std::string usage, std::string translation)
    {
        int colon = word.find(':');
        word = word.substr(colon + 1);
        std::transform(word.begin(), word.end(), word.begin(), tolower);
        this->word = word;
        this->usage = usage;
        this->translation = translation;
    }

    Flashcard(std::string word, std::string usage) : Flashcard(word,usage, std::string())
    {

    }
};

void learning(std::vector<Flashcard> cards);

int main() 
{
    std::string line;
    std::vector<Flashcard> cards;

    //Read from the text file
    std::ifstream flashcards ("flashcards4.csv");

    while (getline (flashcards, line))
    {
      int position = line.find('\t');
      std::string translation = line.substr(0,position);
      line = line.substr(position + 1);
      position = line.find('\t');
      std::string usage = line.substr(position + 1);
      std::string word = line.substr(0,position);

      cards.emplace_back(Flashcard(word, usage, translation));
    }
    
    //shuffle cards
    auto rd = std::random_device {}; 
    auto rng = std::default_random_engine { rd() };
    std::shuffle(std::begin(cards), std::end(cards), rng);

    //std::cout << "Choose one of the following options: " << std::endl;

    learning(cards);

    return 0;
}

void learning(std::vector<Flashcard> cards)
{   
    std::cout << "********************************* Learning *********************************" << std::endl << std::endl;
    
    for(int i = 0; i < cards.size();)
    {
        std::cout << "                                  " << cards[i].word << std::endl << std::endl;
        std::cout << "1 see translation    2 see usage    3 already known   4 next word     Q quit"<< std::endl;

        char choice;
        std::cin >> choice;

        switch (choice)
        {
        case '1':
            std::cout << cards[i].translation << std::endl;
            break;
        case '2':
            std::cout << cards[i].usage << std::endl << std::endl;
            break;
        case '3':
            i++;
            break;
        case '4':
            i++;
            break;
        case 'q':
        case 'Q':
            i = cards.size();
            break;
        default:
            break;
        }
    }
}