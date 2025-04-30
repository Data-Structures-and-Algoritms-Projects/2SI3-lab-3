#include "objPosStack.h"
#include "objPosSHLinkedList.h"

#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

// Available Data Members from objPosStack.h (Must Review)
//
//      objPosList* myList
//      
//  This is the polymorphic list pointer to the underlying List data structure to
//   support all Stack functionalities
//
//  You should use the provided objPosSHLinkedList as your main design param (Singly with Header)


objPosStack::objPosStack()
{
    // Constructor   
    myList = new objPosSHLinkedList();

}


objPosStack::~objPosStack()
{
    // Destructor
    delete myList;

}


void objPosStack::populateRandomElements(int size)
{
    // This function generates the number of randomly generated objPos instances with uninitialized
    //  x-y coordinate on the Stack, then sort them in ascending order using the digit of 10
    //  of the **number** field in objPos instances.

    // Implementation done.  You'd have to implement the following two private helper functions above.
    srand(time(NULL));
    generateObjects(size);
    sortByTenScoreBS();   // bubble sort
}




// private helper function
void objPosStack::generateObjects(int count)
{
    // Generate and pushes individual objPos isntances with randomly generated Prefix, Number, and Symbol.
    // The total number of generated instances is capped by input variable **count**.
    
    // 1. Generate Prefix A-Z and a-z.  Alphabetic characters only.
    // 2. Generate Number [0, 99]
    // 3. Leave Symbol as *
    // Push every randomly generately objPos into the Stack.
    for (int i = 0; i < count; i++)
    {
        objPos temp;
        char c = 'A' + (rand() % 26);
        char d = 'a' + (rand() % 26);
        temp.setPF(count % 2 == 0 ? c : d);
        temp.setNum(rand() % 100);
        temp.setSym('*');
        temp.setX(0);
        temp.setY(0);
        push(temp);
    }

}


// private helper function
void objPosStack::sortByTenScoreBS()
{
    // Use BUBBLE or SELECTION SORT to sort all the objPos instances in the Stack in ascending order using the doigit of 10
    //  of the **number** field of objPos.

    // You can use the relevant insertion, removal, getter, and setter methods from the objPosSHLinkedList interface
    //  to complete the sorting operations.
    bool swapped = true;
    while (swapped)
    {
        swapped = false;
        for(int i = 0; i < myList->getSize() - 1; i++)
        {
            objPos temp = myList->get(i);
            objPos next = myList->get(i + 1);
            if ((temp.getNum()/10) % 10 > (next.getNum()/10) % 10)
            {
                myList->remove(i);
                myList->insert(next, i);
                myList->remove(i + 1);
                myList->insert(temp, i + 1);
                swapped = true;
            }
        }
    }


    

}




void objPosStack::push(const objPos &thisPos) const
{
    // Push thisPos on to the Stack.
    myList->insertHead(thisPos);

}

objPos objPosStack::pop()
{
    // Pop the top element of the Stack.
    //  If the Stack is empty, return objPos(-99, 0, 0, 0, 0)
    return myList->removeHead();
    
}

objPos objPosStack::top()
{
    // Return the top element of the Stack without removing it
    //  If the Stack is empty, return objPos(-99, 0, 0, 0, 0)
    return myList->getHead();
    
}

int objPosStack::size()
{
    // Return the size of the Stack 
    //  Think about which objPosSHLinkedList method can realize this operation.
    return myList->getSize();

}

void objPosStack::printMe()
{
    // NOT GRADED
    //  Print the contents of the Stack

    // IMPORTANT: USE THIS METHOD FOR DEBUGGING!!!
    
}