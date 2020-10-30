#include "collections.h"

template <class T>
void List<T>::add(T* value)
{
    if (!this -> head)
    {
        this -> head = new Node<T>(value);
    }
    else
    {
        Node<T>* last = this -> head;

        while (last -> next)
        {
            last = last -> next;
        }

        last -> next = new Node<T>(value, last);
    }
    
}

template <class T>
void List<T>::remove(int index)
{
    Node<T>* toDelete = this -> head;

    while (index > 0 && toDelete)
    {
        index--;
        toDelete = toDelete -> next;
    }

    if (toDelete)
    {
        toDelete -> previous -> next = toDelete -> next;
        delete toDelete;
    }
}