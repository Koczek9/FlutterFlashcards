#include <random>
#include <ctime>

#include "flashcard.h"
#include "games.h"

int main() 
{
    std::string line;
    std::vector<Flashcard> cards;

    //Read from the imported text file.
    /* std::ifstream flashcards ("flashcards4.csv");

    while (getline (flashcards, line))
    {
      int position = line.find('\t');
      std::string translation = line.substr(0,position);
      line = line.substr(position + 1);
      position = line.find('\t');
      std::string usage = line.substr(position + 1);
      std::string word = line.substr(0,position);

      cards.emplace_back(Flashcard(word, usage, translation));
    } */

    std::string fullFile;
    std::ifstream MyFileRead ("flashcardsXML.xml");
    while (getline (MyFileRead, line))
    {
        fullFile += line;
    }

    MyFileRead.close ();

    bool working = true;
    while(working)
    {
        std::string card = findXml(fullFile, "Flashcard");
        if (card.empty())
        {
            working = false;
            break;
        }
        cards.emplace_back(Flashcard(card));
        int position2 = fullFile.find("</Flashcard>");
        fullFile = fullFile.substr(position2 +1);
    }

    /* auto rd = std::random_device {}; 
    auto rng = std::default_random_engine { rd() };
    std::shuffle(std::begin(cards), std::end(cards), rng); */


    //learning(cards);
    matchingGame(cards);

    return 0;
}