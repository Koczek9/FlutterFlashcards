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

    Flashcard(std::string word, std::string usage){
        int colon = word.find(':');
        word = word.substr(colon + 1);
        std::transform(word.begin(), word.end(), word.begin(), tolower);
        this->word = word;
        this->usage = usage;
    }
};

void learning(std::vector<Flashcard> cards);

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
 
    /* for(auto card : cards)
    {
        std::cout << card.word << std::endl;
    } */

    /* for(int i = 0; i < cards.size(); i++)
    {
        std::cout << cards[i].usage << std::endl;
    } */

    //std::cout << "Choose one of the following options: " << std::endl;


    std::cout << "********************************* Learning *********************************" << std::endl << std::endl;

    learning(cards);

    return 0;
}

void learning(std::vector<Flashcard> cards)
{   
    for(int i = 0; i < cards.size();)
    {
        std::cout << "                                  " << cards[i].word << std::endl << std::endl;
        std::cout << "1 see translation    2 see usage    3 already known   4 next word     Q quit"<< std::endl;

        char choice;
        std::cin >> choice;

        switch (choice)
        {
        case '1':
            std::cout << "You see a translation" << std::endl;
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