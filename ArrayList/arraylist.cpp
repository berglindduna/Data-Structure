// 21.01.2016

#include "arraylist.h"
#include <assert.h>

template<class T>
ArrayList<T>::ArrayList(int size)
{
    maxSize = size;
    currSize = 0;
    moveToStart();
    arr = new T[maxSize];
}

template<class T>
ArrayList<T>::~ArrayList()
{
    delete [] arr;
}

template<class T>
void ArrayList<T>::append(T elem)
{
    if(currSize == maxSize)
    {
        maxSize = maxSize * 2;
        T* newArr;
        newArr = new T[maxSize];

        for (int i = 0; i < currSize; i++)
            newArr[i] = arr[i];

        delete [] arr;
        arr = newArr;
    }

    arr[currSize] = elem;
    currSize++;
}


template<class T>
void ArrayList<T>::insert(T elem)
{
     if(currSize == maxSize)
    {
        maxSize = maxSize * 2;
        T* newArr;
        newArr = new T[maxSize];

        for (int i = 0; i < currSize; i++)
            newArr[i] = arr[i];

        delete [] arr;
        arr = newArr;
    }

    currSize++;
    T tmp = arr[currElemPos];

    for (int i = currElemPos; i < (currSize - 1); i++)
    {
        T tmp2 = arr[i + 1];
        arr[i + 1] = tmp;
        tmp = tmp2;
    }

    arr[currElemPos] = elem;
}

template<class T>
void ArrayList<T>::next()
{
    if (currElemPos < currSize)
        currElemPos++;
}

template<class T>
void ArrayList<T>::prev()
{
    if (currElemPos > 0)
        currElemPos--;
}

template<class T>
void ArrayList<T>::moveToStart()
{
    currElemPos = 0;
}

template<class T>
void ArrayList<T>::moveToEnd()
{
    currElemPos = currSize;
}

template<class T>
void ArrayList<T>::moveToPos( int pos )
{
    currElemPos = pos;
}

template<class T>
void ArrayList<T>::remove()
{
    currSize -= 1;

    for (int i=currElemPos; i< currSize; i++)
        arr[i] = arr[i+1];
}

template<class T>
void ArrayList<T>::clear()
{
    T* newArr;
    newArr = new T[maxSize];
    delete [] arr;
    arr = newArr;
    moveToStart();
    currSize = 0;
}

template<class T>
int ArrayList<T>::length() const
{
    return currSize;
}

template<class T>
int ArrayList<T>::currPos() const
{
    return currElemPos;
}

template<class T>
T ArrayList<T>::value() const
{
    assert(currElemPos >=0 &&  currElemPos < currSize); // No current element
    return arr[currElemPos];
}
