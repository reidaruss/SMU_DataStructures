#include "output.h"
#include <fstream>
#include <iostream>
#include <string.h>
#include <ctype.h>



using namespace std;

Output::Output()
{

}

DSVector<Index> Output::sortWords(DSVector<Index>& v)
{
    string temp;
    for(int i = 1; i < v.getSize(); i ++)
    {
        for(int j = 1; j < v.getSize(); j++)
        {

            if(v[j-1] < v[j])
            {

                temp = v[j-1].getWord();        //if element to the left is smaller, flip them
                v[j-1].setString(v[j].getWord());
                v[j].setString(temp);
            }
        }
    }


    return v;


}

void Output::writeOut(char* argv[], DSVector<Index> v)
{
    ofstream fout(argv[3]); //create output stream object
    if(fout.is_open())
    {
        char cat = '\0'; //category to be written with.

        for(int i = v.getSize()-2; i > 0; i--)
        {
            if(putchar(toupper(v[i].getFE())) != cat)   //check if first letter is equal to the current category
            {
                cat = putchar(toupper(v[i].getFE()));       //if not then make new category
                fout << "[" << cat << "]" << endl;
                fout << v[i].getWord() << ": " << v[i].returnPages() << endl;
            }
            else
            {
                fout << v[i].getWord() << ": " << v[i].returnPages() << endl;   //if category is the same output new word
            }
        }

    }
    else
        cout << "Error in file output" << endl;

}
