#include "stack.h"

//Stack::Stack()
//{

//}

template <typename T>
LinkedList<T>& Stack::operator[](int i)
{
    if(i >= size)
        cerr << "op[] Unable to access. Out of scope" << endl;
    else
        return data[i];
}

void Stack::push(string val)
{
    //data.addToBack(val);
}

string Stack::pop()
{
    string temp = data[data.getLen() - 1]; // or string temp = peek();
    //data.removeBack();
    return temp;
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
    return data[data.getLen() - 1]; //faster with data.last();
}
