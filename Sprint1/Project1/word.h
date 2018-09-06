#ifndef WORD_H
#define WORD_H
#include <string>



class Word
{
private:
    std::string word;
    std::string pOS;
public:
    Word();
    Word(std::string w, std::string pos);
};

#endif // WORD_H
