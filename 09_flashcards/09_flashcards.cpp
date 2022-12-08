#include "flashcard.h"
#include "games.h"
#include "import_read.h"

int main() 
{   
    std::vector<Flashcard> cards;
    //cards = importFile("dictionary.csv");
    //writeXML(DATA_BASE_FILE_NAME, cards);
    cards = readFile(DATA_BASE_FILE_NAME);
    //shuffle(cards);
    //learning(cards);
    matchingGame(cards);

    return 0;
}