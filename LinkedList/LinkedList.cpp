// 04.02.2016

#include "LinkedList.h"

template <class T>
LinkedList<T>:: LinkedList()
{
   header = new Node<T>;
   trailer = new Node<T>;

   init();
}

template <class T>
LinkedList<T>:: LinkedList(LinkedList<T>& lis)
{
    header = new Node<T>;
    trailer = new Node<T>;
    init();

    Node<T>* here = lis.header;

    while (here->getNext() != lis.trailer)
    {
        here = here->getNext();
        append(here->getData());
    }
}

template <class T>
LinkedList<T>:: ~LinkedList()
{
    removeAll();
}

template <class T>
void LinkedList<T>:: next()
{
    if (currNode != trailer)
        currNode = currNode->getNext();
}

template <class T>
void LinkedList<T>:: prev()
{
    if (currNode != header->getNext())
        currNode = currNode->getPrev();
}

template <class T>
void LinkedList<T>:: moveToStart()
{
    currNode = header->getNext();
}

template <class T>
void LinkedList<T>:: moveToEnd()
{
    currNode = trailer;
}

template <class T>
void LinkedList<T>:: moveToPos(int pos)
{
    if (pos <= currSize)
    {
        currNode = header;

        for (int i = 0; i < pos+1; i++)
            currNode = currNode->getNext();
    }
}

template <class T>
int LinkedList<T>:: length() const
{
    return currSize;
}

template <class T>
T LinkedList<T>:: value() const
{
    return currNode->getData();
}

template <class T>
bool LinkedList<T>:: empty() const
{
    return (header->getNext() == trailer);
}

template <class T>
void LinkedList<T>:: append(T elem)
{
    Node <T>* newNode = new Node<T>(elem, trailer, trailer->getPrev());

    trailer->getPrev()->setNext(newNode);
    trailer->setPrev(newNode);

    if (currNode == trailer)
        currNode = newNode;

    currSize++;
}

template <class T>
void LinkedList<T>:: insert (const T& elem)
{
    insert(currNode, elem);
    currNode = currNode->getPrev();
}

template <class T>
Node<T>* LinkedList<T>:: getCurrNode() const
{
    return currNode;
}

template <class T>
T LinkedList<T>:: remove()
{
    Node<T>* tmp = currNode->getNext();
    T tmpInt = currNode->getData();

    currNode->getPrev()->setNext(currNode->getNext());
    currNode->getNext()->setPrev(currNode->getPrev());

    delete currNode;
    currNode = tmp;

    currSize--;

    return tmpInt;
}

template <class T>
void LinkedList<T>:: clear()
{
    Node<T>* here = header->getNext();

    while (here != trailer)
    {
        Node<T>* toDelete = here;
        here = here->getNext();
        delete toDelete;
    }

    init();
}


template <class T>
Node<T>* LinkedList<T>:: end() const
{
    return (trailer);
}

template <class T>
void LinkedList<T>:: insert(Node<T>* beforeMe, const T& elem)
{

    Node <T>* newNode;
    newNode = new Node<T>(elem, beforeMe, beforeMe->getPrev());
    beforeMe->getPrev()->setNext(newNode);
    beforeMe->setPrev(newNode);

    currSize ++;
}

template <class T>
void LinkedList<T>:: removeAll()
{
    clear();
    delete header;
    delete trailer;
}

template <class T>
void LinkedList<T>:: init()
{
    currSize = 0;
    header -> setNext(trailer);
    trailer -> setPrev(header);

    header -> setPrev(NULL);
    trailer -> setNext(NULL);

    currNode = trailer;
}
