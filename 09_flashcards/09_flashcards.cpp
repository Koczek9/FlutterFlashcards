#include "flashcard.h"
#include "games.h"
#include "import_read.h"

int main() 
{   
    std::vector<Flashcard> cards;
    //cards = importFile("flashcards4.csv");
    cards = readFile("../flashcardsXML.xml");
    shuffle(cards);
    //learning(cards);
    matchingGame(cards);

    return 0;
}