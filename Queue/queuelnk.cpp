#include "queuelnk.h"
#include <iostream>

using namespace std;

template <class DT>
QueueNode<DT>::QueueNode(const DT& nodeData, QueueNode* nextPtr)
{
    dataItem = nodeData;
    next = nextPtr;
}

template <class DT>
Queue<DT>::Queue(int ignored)
{
    front = nullptr;
    rear = nullptr;
}

template<class DT>
Queue<DT>::~Queue()
{
    clear();
}

template<class DT>
void Queue<DT>::enqueue(const DT& newDataItem)
{
    QueueNode<DT>* newNode = new QueueNode<DT>(newDataItem, nullptr);
    if (front == nullptr)
        front = newNode;
    else
        rear->next = newNode;
    rear = newNode;
}

template<class DT>
DT Queue<DT>::dequeue()
{
    if (isEmpty() == true)
    {
        cout << "Empty Queue" << "\n";
        return NULL;
    }
    else
    {
        QueueNode<DT>* tmp = front;
        DT value = front->dataItem;
        front = front->next;
        delete tmp;
        return value;
    }
}

template <class DT>
void Queue<DT>::clear()
{
    QueueNode<DT>* tmp;
    while (front != nullptr)
    {
        tmp = front;
        front = front->next;
        delete tmp;
    }
}

template<class DT>
bool Queue<DT>::isEmpty() const
{
    if (front == nullptr)
        return true;
    else
        return false;
}

template<class DT>
bool Queue<DT>::isFull() const
{
    QueueNode<DT>* test = new QueueNode<DT>(0,nullptr);
    if (test == NULL)
        return true;
    delete test;
    return false;
}

template<class DT>
void Queue<DT>::showStructure() const
{
    QueueNode<DT>* p;   // Iterates through the queue

    if (front == nullptr)
        cout << "Empty queue" << endl;
    else
    {
        cout << "front ";
        for (p = front; p != nullptr; p = p->next)
            cout << p->dataItem << " ";
        cout << "rear" << endl;
    }
}