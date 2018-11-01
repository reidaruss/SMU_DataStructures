#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>

using namespace std;

template<class T>
class ListNode
{
    template<class U> friend class LinkedList;
private:
    ListNode<T>* next;
    ListNode<T>* prev;
    T payload;
public:
    ListNode(T val);

};



template<class T>
class LinkedList
{
private:
    ListNode<T>* head, *tail;
    int length;
    ListNode<T>* curr;

public:
    LinkedList();
    T& operator[](int i);
    LinkedList& operator=(const LinkedList<T>& rhs);
    void insert(T val);
    void insertAt(int pos, T val);
    void removeAt(int pos);
    void removeFront();
    void removeBack();
    void addBack(T val);
    void addFront(T val);
    void resetIterator();
    int getLen();
    bool contains(string val);
    LinkedList<T> getNext();
    void clear();
    bool isEmpty();



};

template <typename T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    tail = nullptr;
    length = 0;
    curr = nullptr;
}

template <typename T>
int LinkedList<T>::getLen()
{
    return length;
}


template <typename T>
ListNode<T>::ListNode(T val):next(nullptr),prev(nullptr),payload(val){}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rhs)
{
    if(head != nullptr)
        this->clear();
    ListNode<T>* curr = rhs.head;
    while(curr != nullptr)
    {
        addBack(curr->payload);
        curr = curr->next;
    }
}

template <typename T>
T& LinkedList<T>::operator[](int i)
{
    if(i >= length)
        cerr << "op[] Unable to access. Out of scope" << endl;
    else if(i == 0)
    {
        curr = head;
        return curr->payload;
    }
    else
    {
        curr = head;
        if(curr == nullptr)
        {
            return curr->payload;
        }

        while(curr->next != nullptr && i > 0)
        {
            curr = curr->next;
            i--;
        }
        return curr->payload;
    }
}



template <typename T>
void LinkedList<T>::insert(T val)
{
    if(head == nullptr)
    {
        head = new ListNode<T>(val);
        tail = head;
        length++;
    }
    else
    {
        tail->next = new ListNode<T>(val);
        tail->next->prev = tail;
        tail = tail->next;
        length++;
    }
}
template <typename T>
void LinkedList<T>::addFront(T val)
{
    if(head == nullptr)
    {
        head = new ListNode<T>(val);
        tail = head;
        length++;
    }
    else
    {
        curr = head;
        head = new ListNode<T>(val);
        head->next = curr;
        curr->prev = head;
    }


}

template <typename T>
void LinkedList<T>::addBack(T val)
{
    if(tail == nullptr)
    {
        head = new ListNode<T>(val);
        tail = head;
        length++;
    }
    else
    {
        curr = tail;
        tail = new ListNode<T>(val);
        tail->prev = curr;
        curr->next = tail;
        length++;
    }


}

template <typename T>
void LinkedList<T>::insertAt(int pos, T val)
{
    ListNode<T>* curr = head;
    if(curr == nullptr)
    {
        addFront(val);
        return;
    }
    while(curr->next != nullptr && pos-1 > 0)
    {
        curr = curr->next;
        pos--;
    }
    if(curr == head)
        addFront(val);
    else if(curr == tail)
        addBack(val);
    else
    {
        ListNode<T>* temp = new ListNode<T>(val);
        temp->prev = curr;
        temp->next = curr->next;
        curr->next->prev = temp;
        curr->next = temp;
        length++;
    }
}

template <typename T>
void LinkedList<T>::removeAt(int pos)
{
    if(pos >=length)
        throw "Out of range.";
    ListNode<T>* curr = head;
    while(pos > 0)
    {
        curr = curr->next;
        pos--;
    }
    if(curr == head)
        removeFront();
    //else if(curr == tail)
        //removeBack();
    else
    {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        delete curr;
        length--;

    }
}

template <typename T>
void LinkedList<T>::removeFront()
{
    if(head == nullptr)
        return;
    if(head == tail)
    {
        delete head;
        head = nullptr;
        tail = nullptr;
        length--;
    }
    else
    {
        head = head->next;
        delete head->prev;
        head->prev = nullptr;
        length--;
    }
}
template <typename T>
void LinkedList<T>::removeBack()
{
    if(tail == nullptr)
        return;
    if(head == tail)
    {
        delete tail;
        head = nullptr;
        tail = nullptr;
        length--;

    }
    else
    {
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
        length--;
    }
}

template <typename T>
void LinkedList<T>::clear()
{
    while(length != 0)
        removeBack();
}

template <typename T>
bool LinkedList<T>::isEmpty()
{
   if(head == nullptr && tail == nullptr)
       return true;
   else
       return false;
}

template <typename T>
bool LinkedList<T>::contains(string val)
{
//    for(int i = 0; i < length; i++)
//        if(data[i] == val)
//            return true;
//        return false;

}



template <typename T>
void LinkedList<T>::resetIterator()
{
    curr = head;
}

//template <typename T>
//LinkedList<T> LinkedList<T>::getNext()
//{
//    curr = curr->next;
//    return *curr;
//}
#endif // LINKEDLIST_H
