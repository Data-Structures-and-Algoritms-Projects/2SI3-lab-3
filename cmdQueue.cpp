#include "cmdQueue.h"

#include <iostream>
using namespace std;

// Available Data Members from cmdQueue.h

// You must implement the array-based circular queue as discussed in class

// You must NOT use any existing data structures such as Lists to design the queue.


cmdQueue::cmdQueue()
{
    // Constructor
    capacity = DEFAULT_CAPACITY;
    queue = new char[capacity];
    size = 0;
    front = 0;
    end = 0;

}

cmdQueue::cmdQueue(int cap)
{
    // Additional Constructor
    capacity = cap;
    queue = new char[capacity];
    size = 0;
    front = 0;
    end = 0;
}

cmdQueue::~cmdQueue()
{
    // Destructor
    delete[] queue;
    
}

void cmdQueue::enqueue(char thisCmd)
{
    // Enqueue into Circular Queue
    if (size == capacity - 1)
    {
        cout << "Queue is full. Cannot enqueue." << endl;
        return;
    }
    else
    {
        queue[front] = thisCmd;
        front++;
        size++;
        if (front == capacity)
            front = 0;
        return;
    }


}

char cmdQueue::dequeue()
{
    // Dequeue from Circular Queue
    if (size == 0)
    {
        cout << "Queue is empty. Cannot dequeue." << endl;
        return '\0';
    
    }
    else{
        char thisCmd = queue[end];
        end++;
        size--;
        if (end == capacity)
        end = 0;
        return thisCmd;
    }

}

int cmdQueue::getSize() const
{
    // Return the size of the Queue
    return size;
    
}

void cmdQueue::clearQueue()
{
    // Remove all elements from the Queue
    size = 0;
    front = 0;
    end = 0;

}

void cmdQueue::printMe() const
{
    // NOT GRADED
    //  Print the contents of the Queue
    
    // IMPORTANT: USE THIS METHOD FOR DEBUGGING!!!
}