#ifndef DSVECTOR_H
#define DSVECTOR_H
#include <iostream>
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
    T& operator[](const T&);
    //~DSVector();//destructor



   void pushBack(const T& val);
   T getElement(int i);
    //void remove();
   void resize(const DSVector<T>& );
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

    data = new T[rhs.size];
    for(int i = 0; i < rhs.size; i++)
        data[i] = rhs.data[i];

    return *this;
}

template <typename T>
T& DSVector<T>::operator[](const T& i)
{
    return this->data[i];
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
T DSVector<T>::getElement(int i) //Return val at i
{
    return data[i];
}

template <typename T>
void DSVector<T>::pushBack(const T& val) //Add element to data then incriment size.
{

    if(size == capacity)
        cout << "Resize this" <<endl;
        //resize(this);
    else
    {
        data[size] = val;
        size ++;
    }
}

template <typename T>
void DSVector<T>::resize(const DSVector<T> &)
{
    DSVector<T> *temp = new DSVector<T>;

    temp->capacity = this->capacity + 20;
    temp->size = this->size;
    for(int i =0; i <this->size; i ++)
        temp->data[i] = this->data[i];
    cout << temp[0] << endl;

    //this->data = temp->data;
    //delete[] temp;

}

//template <typename T>
//DSVector<T>::~DSVector()
//{
//    if(this->data != nullptr)

//}



#endif // DSVECTOR_H
