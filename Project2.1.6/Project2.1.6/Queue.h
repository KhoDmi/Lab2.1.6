#pragma once
#include <cassert>
using namespace std;


template<typename T=double>
class Queue
{
public:
    Queue(int = 100);
    virtual ~Queue();

    virtual void Push(T&);
    virtual void Pop();
    virtual void getQueue();
protected:
    T* queuePtr;
    int sizeofQueue;
    int begin;
    int end;
    int curNumofEl;
};



template<typename T>
Queue<T>::Queue(int sizeofQueue) : sizeofQueue(sizeofQueue), begin(0), end(0), curNumofEl(0)
{
    queuePtr = new T[sizeofQueue + 1];
}



template<typename T>
void Queue<T>::Push(T& newEl)
{
    assert(curNumofEl < sizeofQueue);
    queuePtr[end++] = newEl;
    curNumofEl++;
    if (end > sizeofQueue)
        end -= sizeofQueue + 1;
}



template<typename T>
void Queue<T>::Pop()
{
    assert(curNumofEl > 0);
    T returnValue = queuePtr[begin++];
    curNumofEl--;
    if (begin > sizeofQueue)
        begin -= sizeofQueue + 1;
    cout << "1st element in the queue is: " << returnValue << endl;
}

template<typename T>
void Queue<T>::getQueue()
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

template<typename T>
Queue<T>::~Queue()
{
    delete[] queuePtr;
}







