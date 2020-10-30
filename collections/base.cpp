#include "collections.h"

template <class T>
Node<T>::Node()
{
    value = nullptr;
    next = nullptr;
    previous = nullptr;
};

template <class T>
Node<T>::Node(T* value) : Node<T>::Node()
{
    this -> value = value;
};

template <class T>
Node<T>::Node(T* value, Node<T>* previous)
{
    this -> value = value;
    this -> previous = previous;
}

template <class T>
Node<T>::Node(T* value, Node<T>* previous, Node<T>* next)
{
    this -> next = next;
    this -> value = value;
    this -> previous = previous;
}

template <class T>
Iterator<T>::Iterator(Node<T>* startNode)
{
    initial = new Node<T>();
    initial.next = startNode;
    current = initial;
}

template <class T>
Iterator<T>::~Iterator()
{
    delete initial;
}

template <class T>
bool Iterator<T>::hasNext()
{
    return current -> next;
}

template <class T>
bool Iterator<T>::hasPrevious()
{
    return current -> previous;
}

template <class T>
T* Iterator<T>::next()
{
    T* valuePtr = current -> value;
    
    current = current -> next;
    return valuePtr;
}

template <class T>
T* Iterator<T>::getCurrent()
{
    return current -> value;
}


template <class T>
T* Iterator<T>::previous()
{
    T* valuePtr = current -> value;
    
    current = current -> previous;
    return valuePtr;
}

template <class T>
Collection<T>::Collection()
{
    head = nullptr;
    count = 0;
}

template <class T>
Collection<T>::~Collection()
{
    while (head != nullptr)
    {
        T* newHead = head -> next;

        delete head;
        head = newHead;
    }
}

template <class T>
int Collection<T>::getSize()
{
    return count;
}

template <class T>
Iterator<T> Collection<T>::getIterator()
{
    return Iterator<T>(head);
}