//--------------------------------------------------------------------
//
//  Laboratory 5                                        stackarr.cpp
//
//  SOLUTION: Array implementation of the Stack ADT
//
//--------------------------------------------------------------------
#include "stackarr.h"

//--------------------------------------------------------------------

template <class DT>
Stack<DT>::Stack(int maxNumber)
{
    maxSize = maxNumber;
    top = maxSize;
    dataItems = new DT[maxSize];
}

//--------------------------------------------------------------------

template <class DT>
Stack<DT>:: ~Stack()
{
    delete[] dataItems;
}

//--------------------------------------------------------------------

template <class DT>
void Stack<DT>::push(const DT& newDataItem)
{
    if (isFull() == true)
        cout << "Full Stack";
    else
        dataItems[--top] = newDataItem;
}

//--------------------------------------------------------------------

template <class DT>
DT Stack<DT>::pop()
{
    if (isEmpty() == true)
        cout << "Empty Stack";
    else
        return dataItems[top++];
}

//--------------------------------------------------------------------

template <class DT>
void Stack<DT>::clear()
{
    top = maxSize;
}

//--------------------------------------------------------------------

template <class DT>
bool Stack<DT>::isEmpty() const
{
    if (top == maxSize)
        return true;
    else
        return false;
}

//--------------------------------------------------------------------

template <class DT>
bool Stack<DT>::isFull() const
{
    if (top == 0)
        return true;
    else
        return false;
}

//--------------------------------------------------------------------

template < class DT >
void Stack<DT>::showStructure() const

// "Downward" array implementation. Outputs the data items in a 
// stack. If the stack is empty, outputs "Empty stack". This operation
// is intended for testing and debugging purposes only.

{
    int j;   // Loop counter

    if (top == maxSize)
        cout << "Empty stack" << endl;
    else
    {
        cout << "top = " << top << endl;
        for (j = 0; j < maxSize; j++)
            cout << j << "\t";
        cout << endl;
        for (j = 0; j < maxSize; j++)
            if (j < top)
                cout << " \t";
            else
                cout << dataItems[j] << "\t";
        cout << endl;
    }
}