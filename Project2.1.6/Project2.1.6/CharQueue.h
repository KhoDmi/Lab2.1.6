#pragma once
#include <cassert>
using namespace std;

#include"Queue.h"

template<>
class Queue<char>
{
public:
    Queue(int = 100);
    ~Queue();

    virtual void Push();
    virtual void Pop();
    virtual void getQueue();
private:
    char* queuePtr;
    const int sizeofQueue;
    int begin;
    int end;
    int curNumofEl;
};


Queue<char>::Queue(int sizeofQueue) : sizeofQueue(sizeofQueue), begin(0), end(0), curNumofEl(0)
{
    queuePtr = new char[sizeofQueue + 1];
}




void Queue<char>::Push()
{
	cin.clear();
	string num;
	cin >> num;
    int i = 0;
	while (num[i])
	{
        assert(curNumofEl < sizeofQueue);
        queuePtr[end++] = num[i];
        curNumofEl++;
        if (end > sizeofQueue)
            end -= sizeofQueue + 1;
        i++;
	}
}



void Queue<char>::Pop()
{
    assert(curNumofEl > 0);
    char returnValue = queuePtr[begin++];
    curNumofEl--;
    if (begin > sizeofQueue)
        begin -= sizeofQueue + 1;
    cout << "1st element in the queue is: " << returnValue << endl;
}


void Queue<char>::getQueue()
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


Queue<char>::~Queue()
{
    delete[] queuePtr;
}



