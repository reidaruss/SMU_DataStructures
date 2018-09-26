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

                temp = v[j-1].getWord();
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
            if(putchar(toupper(v[i].getFE())) != cat)
            {
                cat = putchar(toupper(v[i].getFE()));
                fout << "[" << cat << "]" << endl;
                fout << v[i].getWord() << ": " << v[i].returnPages() << endl;
            }
            else
            {
                fout << v[i].getWord() << ": " << v[i].returnPages() << endl;
            }
        }

    }
    else
        cout << "Error in file output" << endl;

}
