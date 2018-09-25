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

    DSVector<Index> temp;
    ifstream fin(argv[2]);
    if(!fin)
    {
        cout << "File cannot be opened." << endl;
    }
    string str = "";

    string page;
    while(getline(fin,str))
    {

        int k =0;
        if(str == "<-1>")         //check if the line is the end
            break;
        if(str[0] == '<')         //check for new page
        {
            k = 1;      //Set for newpage line
            string tempstr;
            for(int i = 1; i< str.length(); i++)
            {
                if(str[i] == '>')   //iterate until finds >
                {
                    page = tempstr;
                    break;
                }
                else
                    tempstr += str[i];  //append temporary string until delimeter ">".
            }
        }
        if(k != 1)      //Continue if line is not a new page line.
        {
            for(int i = 0; i < str.length() ; i++)
            {

                if(str[i] == '[')
                {
                    string tempstr;
                    for(int j = i+1; j < str.length(); j++)
                    {
                        if(str[j] == ']')   //iterate until closing bracket
                        {
                            transform(tempstr.begin(), tempstr.end(), tempstr.begin(),::tolower); //Make lowercase. Used this : https://math-linux.com/c/faq-c/faq-c-stl/article/how-to-convert-string-to-lower-case-or-upper-case-in-c
                            bool tempbool = false;
                            for(int k = 0; k < temp.getSize(); k++)
                            {
                                if(tempstr == temp[k].getWord())
                                {
                                    tempbool = true;
                                    if(tempbool == true)
                                        temp[k].checkPage(page);
                                }
                            }
                            if(tempbool == false)
                            {
                                Index index;
                                index.setString(tempstr);
                                index.checkPage(page);
                                temp.pushBack(index);


                            }
                            i = j +1;       //set new i
                            break;
                        }
                        else
                            tempstr += str[j];  //append temporary string until delimeter "]".
                    }
                }
                else
                {
                    string tempstr;
                    for(int j = i; j < str.length(); j++)
                    {
                        if(str[j] == ' ' || j == str.size()-1)  //delimeter by spaces or end of line.
                        {
//                            for(int k = 0, len = tempstr.length(); k< len; k++)
//                                if(ispunct(str[k]))
//                                {
//                                    tempstr.erase(k--, 1);
//                                    len = tempstr.size();
//                                }

                            transform(tempstr.begin(), tempstr.end(), tempstr.begin(),::tolower);   //Make lowercase. Used this : https://math-linux.com/c/faq-c/faq-c-stl/article/how-to-convert-string-to-lower-case-or-upper-case-in-c
                            bool tempbool = false;
                            for(int k = 0; k < temp.getSize(); k++)
                            {
                                if(tempstr == temp[k].getWord())
                                {
                                    tempbool = true;
                                    if(tempbool == true)
                                        temp[k].checkPage(page);
                                }

                            }
                            if(tempbool == false)
                            {
                                Index index;
                                index.setString(tempstr);
                                index.checkPage(page);
                                temp.pushBack(index);
                            }

                            i = j;
                            break;
                        }
                        else
                            tempstr += str[j];  //append temp string until delim
                    }
                }
            }
        }


    }

    fin.close();
    for(int i = 0; i < temp.getSize(); i++) //remove this
        cout << temp[i].getWord() << endl;
}
