#include "input.h"
#include "dsvector.h"
#include "index.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cstdlib>

using namespace std;
Input::Input(char* argv[])
{
    DSVector<string> temp;
    ifstream fin(argv[2]);
    if(!fin)
    {
        cout << "File cannot be opened." << endl;
    }
    string str = "";
    int counter = 0;

    string tempstr;
    while(getline(fin,str))
    {

        if(str == "<-1>")         //check if the line is the end
            break;


        for(int i = 0; i < str.length(); i++) //run through the line
        {


            if(str[i] == '<')
               for(int j = i+1; j < str.length()-counter; j ++)     //string to int for page number
               {
                   if(str[j] == '>')
                       break;
                    else
                       tempstr += str[j];
               }
            else if(str[i] == '[')
                for(int j = i+1; j< str.length()-counter; j++)
                {
                    if(str[j] == ']')
                        break;
                    else
                        tempstr += str[j];
                }
            else

            counter ++;

        }

        temp.pushBack(tempstr);

    }

    fin.close();
    cout << temp[0] << endl;
}
