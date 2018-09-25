#ifndef DSVECTOR_H
#define DSVECTOR_H
#include <iostream>
//#include "index.h"
using namespace std;

template <typename T>
class DSVector
{
private:
    int size;
    int capacity;
    T* data;
public:
    DSVector();
    DSVector(const DSVector<T>& v);//Copy Constructor
    DSVector& operator=(const DSVector<T>& rhs);//Overloaded Assignment Operator
    T& operator[](int i);
    ~DSVector();//destructor



   void pushBack(T val);
   T getElement(int k);
    void remove(int k);
   void resize();
   int getSize();
   int getCapacity() {return capacity;}
   void sizeInc();
};





template <typename T>
DSVector<T>::DSVector()
{
    size = 0;
    capacity = 10;
    data = new T[capacity];
}


template <typename T>
DSVector<T>& DSVector<T>::operator=(const DSVector<T>& rhs) // Overloaded assignment operator.
{
    if(data)
        delete[] data;
    size = rhs.size;
    capacity = rhs.capacity;

    data = new T[rhs.capacity];
    for(int i = 0; i < rhs.size; i++)
        data[i] = rhs.data[i];

    return *this;
}

template <typename T>
T& DSVector<T>::operator[](int i)
{
    if(i >= size)
        cerr << "op[] Unable to access. Out of scope" << endl;
    else
        return data[i];
}

template <typename T>
DSVector<T>::DSVector(const DSVector<T>& v) //Copy Constructor
{

    size = v.size;
    capacity = v.capacity;
    data = new T[capacity];
    for(int i = 0 ; i < size ; i++)
    {
        data[i] = v.data[i];
    }


}
template <typename T>
T DSVector<T>::getElement(int k) //Return value at index k
{
    return data[k];

}

template <typename T>
void DSVector<T>::sizeInc()
{
    size ++;
    if(size == capacity)
        resize();
}

template <typename T>
int DSVector<T>::getSize()
{
    return size;
}

template <typename T>
void DSVector<T>::pushBack(T val) //Add element to data then incriment size.
{
    if(size < capacity)
    {

        data[size] = val;
        size++;
    }
    else
    {
        resize();
        data[size] = val;
        size++;
    }
}

template <typename T>
void DSVector<T>::resize()
{
    capacity *= 2;
    T* temp = new T[capacity];
    for(int i =0; i <size; i ++)
        temp[i] = data[i];
    delete[] data;
    data = temp;



}

template <typename T>
DSVector<T>::~DSVector()
{
    //if(this->data != nullptr)
    delete[] data;

}

template<typename T>
void DSVector<T>::remove(int k)
{
    for(int i = 0; i < size; i ++)
        data[k] = data[k+1];
    size --;
}


#endif // DSVECTOR_H
