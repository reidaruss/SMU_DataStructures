#include "stack.h"

Stack::Stack()
{

}


void Stack::push(string val)
{
    data.addToBack(val);
}

string Stack::pop()
{
    string temp = data[data.length - 1]; // or string temp = peek();
    data.removeBack();
    return temp;
}

bool Stack::isEmpty()
{
    return(data.length == 0);
}

bool Stack::contains(string val)
{
    for(int i = 0; i < data.length; i++)

        if(data[i] == val)
            return true;
        return false;

}

string Stack::peek()
{
    return data[data.length - 1]; //faster with data.last();
}
