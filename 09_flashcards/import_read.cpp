#include "import_read.h"

std::vector<Flashcard> importFile(std::string fileName)
{
    std::vector<Flashcard> cards;
    std::string line;
    std::ifstream fileToImport(fileName);

    while(getline(fileToImport, line))
    {
        int position = line.find('\t');
        std::string translation = line.substr(0,position);
        line = line.substr(position + 1);
        position = line.find('\t');
        std::string usage = line.substr(position + 1);
        std::string word = line.substr(0,position);

        cards.emplace_back(Flashcard(word, usage, translation));
    } 
    fileToImport.close ();
    return cards;
}

void writeXML(std::string fileName, std::vector<Flashcard> cards)
{
    std::ofstream MyFileWrite (fileName);

    for(auto card : cards)
    {
        MyFileWrite << card.serialize();
    }

    MyFileWrite.close ();
}

std::vector<Flashcard> readFile(std::string fileName)
{
    std::vector<Flashcard> cards;
    std::string fullFile;
    std::string line;
    std::ifstream MyFileRead(fileName);
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
    return cards;
}
    