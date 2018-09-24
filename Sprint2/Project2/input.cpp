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


    while(getline(fin,str))
    {
        int k =0;
        if(str == "<-1>")         //check if the line is the end
            break;
        if(str[0] == '<')
        {
            k = 1;
            string tempstr;
            for(int i = 1; i< str.length(); i++)
            {
                if(str[i] == '>')
                {
                    temp.pushBack(tempstr);
                    break;
                }
                else
                    tempstr += str[i];
            }
        }
        if(k != 1)
        {
            for(int i = 0; i < str.length() ; i++)
            {
                if(str[i] == '[')
                {
                    string tempstr;
                    for(int j = i+1; j < str.length(); j++)
                    {
                        if(str[j] == ']')
                        {
                            transform(tempstr.begin(), tempstr.end(), tempstr.begin(),::tolower);
                            temp.pushBack(tempstr);
                            i = j +1;
                            break;
                        }
                        else
                            tempstr += str[j];
                    }
                }
                else
                {
                    string tempstr;
                    for(int j = i; j < str.length(); j++)
                    {
                        if(str[j] == ' ' || j == str.length()-1)
                        {
                            transform(tempstr.begin(), tempstr.end(), tempstr.begin(),::tolower);
                            temp.pushBack(tempstr);
                            i = j;
                            break;
                        }

                        else
                            tempstr += str[j];
                    }
                }
            }
        }


    }

    fin.close();
    for(int i = 0; i < temp.getSize(); i++)

        cout << temp[i] << endl;
}
