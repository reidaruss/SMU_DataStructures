#include "stack.h"

Stack::Stack()
{
    size = 0;
}


string& Stack::operator[](int i)
{
    if(i >= size)
        cerr << "op[] Unable to access. Out of scope" << endl;
    else
        return data[i];
}

void Stack::push(string val)
{
    data.addBack(val);
    size ++;
}

void Stack::pop() //change this to a void. the return is only for tests
{
    //string temp = data[data.getLen() - 1]; // or string temp = peek();
    data.removeBack();        //do this next
    size--;
    //return temp;
}

bool Stack::isEmpty()
{
    return(data.getLen() == 0);
}

bool Stack::contains(string val)
{
    for(int i = 0; i < data.getLen(); i++)
        if(data[i] == val)
            return true;
    return false;

}

string Stack::peek()
{
    return data[size - 1]; //faster with data.last();
}

int Stack::getSize()
{
    return size;
}
