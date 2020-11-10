#pragma once
#include <cassert>
using namespace std;

#include"Queue.h"

template<typename T1>
class IntQueue : Queue<int>
{
public:
    IntQueue(int = 100);
    ~IntQueue();

    virtual void Push(T1&);
    virtual void Pop();
    virtual void getQueue();
};



template<typename T1>
IntQueue<T1>::IntQueue(int size)
{
    sizeofQueue = size;
    begin = end = curNumofEl = 0;
    queuePtr = new T1[sizeofQueue + 1];
}



template<typename T1>
void IntQueue<T1>::Push(T1& newEl)
{
    assert(curNumofEl < sizeofQueue);
    queuePtr[end++] = newEl;
    curNumofEl++;
    if (end > sizeofQueue)
        end -= sizeofQueue + 1;
}



template<typename T1>
void IntQueue<T1>::Pop()
{
    assert(curNumofEl > 0);
    T1 returnValue = queuePtr[begin++];
    curNumofEl--;
    if (begin > sizeofQueue)
        begin -= sizeofQueue + 1;
    cout << "1st element in the queue is integer number : " << returnValue << endl;
}

template<typename T1>
void IntQueue<T1>::getQueue()
{
    cout << "Queue is: " << endl;
    if (end == begin)
        cout << "empty" << endl;
    else
    {
        for (int i = begin; i < end; i++)
            cout << queuePtr[i] << " ";
        cout << endl;
    }
}

template<typename T1>
IntQueue<T1>::~IntQueue()
{
    
}



