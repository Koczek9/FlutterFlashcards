#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    /*
    * Create vector of words that can fit 
    * in one line given width of characters in lines.
    *
    * @param[in] words      original vector of words
    * @param[in] maxWidth   desired width of characters in one line
    * @param[in/out] index  index of first word in new line in original vector
    *                       of words. It will be overwritten by the index of 
    *                       first word in the next line
    *
    * @return new vector of words which fit in one line
    */
    vector<string> getWordsInLine(vector<string>& words, int maxWidth, int& index)
    {
        vector<string> wordsInLine;
        int wordsSpaceInLineLength = -1;
        while(wordsSpaceInLineLength + 1 + words[index].size() <= maxWidth)
        {
            wordsInLine.emplace_back(words[index]);
            wordsSpaceInLineLength += 1 + words[index].size();
            index += 1;
            if(index >= words.size())
            {
                break;
            }
        }
        return wordsInLine;
    }

    /*
    * Create fully (left and right) justified line of text
    * with given words. Spaces between words are distributed 
    * as evenly as possible.
    *
    * @param[in] wordsInLine    vector of words in one line
    * @param[in] maxWidth       desired width of characters in one line
    *
    * @return new fully (left and right) justified line of text
    */
    string createLine(vector<string>& wordsInLine, int maxWidth)
    {
        string line = "";
        int wordsInLineLength = 0;

        for(int i = 0; i < wordsInLine.size(); i++)
        {
            wordsInLineLength += wordsInLine[i].size();
        }

        string shorterSpaces = "";
        int spacesToDevide = maxWidth - wordsInLineLength;
        int minLengthOfSpaces = spacesToDevide / (wordsInLine.size() - 1);
        int numberOfLongerSpaces = spacesToDevide % (wordsInLine.size() - 1);

        for(int i = 1; i <= minLengthOfSpaces; i++)
        {
            shorterSpaces += ' ';
        }

        for(int i = 0; i < wordsInLine.size(); i++)
        {
            if(i < numberOfLongerSpaces)
            {
                line += wordsInLine[i] + shorterSpaces + ' ';
            }
            else if (i == wordsInLine.size() - 1)
            {
                line += wordsInLine[i];
            }
            else
            {
                line += wordsInLine[i] + shorterSpaces;
            }
        }

        return line;
    }

    /*
    * Create left justified line of text with given words. 
    * Number of characters equals maxWidth.
    * Extra spaces are appended at the end of line.
    *
    * @param[in] wordsInLine    vector of words in one line
    * @param[in] maxWidth       desired width of characters in one line
    *
    * @return new left justified line of text
    */
    string createLastLine(vector<string>& wordsInLine, int maxWidth)
    {
        string line = "";

        for(int i = 0; i < wordsInLine.size(); i++)
        {
            if(i != wordsInLine.size() - 1)
            {
                line += wordsInLine[i] + ' ';
            }
            else
            {
                line += wordsInLine[i];
            }
        }

        while(line.size() < maxWidth)
        {
            line += ' ';
        }

        return line;

    }
    
    /*
    * Format the text such that each line has exactly maxWidth 
    * characters and is justified.
    *
    * @param[in] words      original vector of words
    * @param[in] maxWidth   desired width of characters in one line
    *
    * @return new justified text
    */
    vector<string> fullJustify(vector<string>& words, int maxWidth) 
    {
        vector<string> result;
        int index = 0;
        
        while(index < words.size())
        {
            vector<string> wordsInLine = getWordsInLine(words, maxWidth, index);
            string line;

            if(index == words.size() ||  wordsInLine.size() == 1)
            {
                line = createLastLine(wordsInLine, maxWidth);
            }
            else
            {
                line = createLine(wordsInLine, maxWidth);
            }

            result.emplace_back(line);
        }

        return result;
    }
};

int main()
{
    //vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    vector<string> words = {"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"};
    //vector<string> words = {"What","must","be","acknowledgment","shall","be"};
    //vector<string> words = {"Listen","to","many,","speak","to","a","few."};
    //vector<string> words = {"a","b","c","d","e","f","g"};
    
    Solution solution;

    vector<string> result = solution.fullJustify(words, 20);
    
    for(auto item : result)
    {
        cout << item<< endl;
    }

    return 0;
}
