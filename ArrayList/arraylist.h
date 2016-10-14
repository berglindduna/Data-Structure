// 21.01.16
// Implement the template class ArrayList
/* The main program first reads in a single integer, initialSize, denoting what the initial size should be.  
    The next integer, count, denotes how many elements follow, and then count values are given which comprise the list elements.  
    The above is first carried out for a list of integers and then a list of strings.*/

#ifndef ARRAYLIST_H
#define ARRAYLIST_H

template <class T>
class ArrayList
{
    public:
        ArrayList(int size);        // Constructor
        ~ArrayList();               // Destructor
        void append(T elem);     // Appends an element at the end of the list
        void insert(T elem);        // Inserts an element to the current position
        void next();                // Moves the current position one step right
        void prev();                //Moves the current position one step left
        void moveToStart();         // Set the current position to the start of the list
        void moveToEnd();           // Set the current position to the end of the list
        void moveToPos(int pos);  // Set the current position to pos
        void remove();              // Removes the element in the current position of the list
        void clear();               // Removes all the elements from the list
        int currPos() const;        // Returns the position of the current element
        int length() const;         // Returns the current length of the list
        T value() const;          //Returns the current element

    private:
        int maxSize;        // Maximum size of list
        int currSize;       // Current number of list items
        int currElemPos;    // Position of the current element of the list
        T* arr;           // A pointer to the array holding the list elements
};

#endif // ARRAYLIST_H
