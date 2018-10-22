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
    void addBack(T val);
    void addFront(T val);
    void resetIterator();
    int getLen();



};

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
        //clear();
    ListNode<T>* curr = rhs.head;
    while(curr != nullptr)
    {
        addBack(curr->data);
        curr = curr->next;
    }
}

template <typename T>
T& LinkedList<T>::operator[](int i)
{
    if(i >= length)
        cerr << "op[] Unable to access. Out of scope" << endl;
    else
    {
        ListNode<T>* curr = head;
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
    }
    else
    {
        tail->next = new ListNode<T>(val);
        tail->next->prev = tail;
        tail = tail->next;
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
    while(curr->next != nullptr && pos > 0)
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
void LinkedList<T>::resetIterator()
{
    curr = head;
}
#endif // LINKEDLIST_H
