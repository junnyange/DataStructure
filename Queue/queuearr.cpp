#include "queuearr.h"
#include <iostream>

using namespace std;

template < class DT >
Queue<DT>::Queue(int maxNumber)
{
    maxSize = maxNumber;
    front = -1;
    rear = -1;
    dataItems = new DT[maxSize];
}

template < class DT >
Queue<DT>::~Queue()
{
    delete[] dataItems;
}

template < class DT >
void Queue<DT>::enqueue(const DT& newDataItem)
{
    if (isFull() == true)
        cout << "Full Queue" << "\n";
    else if(front == -1) //front가 -1이라면 비어있는 상황
    {
        rear = 0;
        front = 0;
        dataItems[rear] = newDataItem;
    }
    else
    {
        rear = (rear + 1) % maxSize;
        dataItems[rear] = newDataItem;
    }
}

template < class DT >
DT Queue<DT>::dequeue()
{
    if (isEmpty() == true)
    {
        cout << "Empty Queue" << "\n";
        return NULL;
    }
    else if (front == rear) // 하나 남은 상황에서 front가 하나 더해져 버리는 것을 방지 
    {                       // 또한 빈 상태가 되므로 front를 -1로 해주어야함
        DT tmp = dataItems[front];
        front = -1;
        rear = -1;
        return tmp;
    }
    else
    {
        DT tmp = dataItems[front];
        front = (front + 1) % maxSize;
        return tmp;
    }
}

template < class DT >
void Queue<DT>::clear()
{
    front = -1;
    rear = -1;
}

template < class DT >
bool Queue<DT>::isEmpty() const
{
    if (front == -1)
        return true;
    else
        return false;
}

template < class DT >
bool Queue<DT>::isFull() const
{
    if ((rear + 1) % maxSize == front)
        return true;
    else
        return false;
}

template < class DT >
void Queue<DT>::showStructure() const
{
    int j;   // Loop counter

    if (front == -1)
        cout << "Empty queue" << endl;
    else
    {
        cout << "front = " << front << "  rear = " << rear << endl;
        for (j = 0; j < maxSize; j++)
            cout << j << "\t";
        cout << endl;
        if (rear >= front)
            for (j = 0; j < maxSize; j++)
                if ((j >= front) && (j <= rear))
                    cout << dataItems[j] << "\t";
                else
                    cout << " \t";
        else
            for (j = 0; j < maxSize; j++)
                if ((j >= front) || (j <= rear))
                    cout << dataItems[j] << "\t";
                else
                    cout << " \t";
        cout << endl;
    }

}

// In-lab operations
template < class DT >
void Queue<DT>::putFront(const DT& newDataItem)
{
    // In-lab 2
    if (isFull() == true)
        cout << "Full Queue" << "\n";
    else if(front == -1)
    {
        front = 0;
        rear = 0;
        dataItems[front] = newDataItem;
    }
    else if (front == 0) //0->7로 바꿔주어야 할 경우
    {
        front = maxSize - 1;
        dataItems[front] = newDataItem;
    }
    else
    {
        front = (front - 1) % maxSize;
        dataItems[front] = newDataItem;
    }
}

template < class DT >
DT Queue<DT>::getRear()
{
    // In-lab 2
    if (isEmpty() == true)
    {
        cout << "Empty Queue" << "\n";
        return NULL;
    }
    else if(front == rear) //하나 남은 상황
    {
        DT tmp = dataItems[rear];
        front = -1;
        rear = -1;
        return tmp;
    }
    else if (rear == 0) //0->7로 바꿔주어야 할 경우
    {
        DT tmp = dataItems[rear];
        rear = maxSize - 1;
        return tmp;
    }
    else
    {
        DT tmp = dataItems[rear];
        rear = (rear - 1) % maxSize;
        return tmp;
    }
}

template < class DT >
int Queue<DT>::getLength() const
{
    // In-lab 3
    if (front == -1)
        return 0;
    else if ((maxSize + rear - front + 1) % maxSize == 0)
        return 8;
    else
        return (maxSize + rear - front + 1) % maxSize;
}