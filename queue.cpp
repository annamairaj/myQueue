
//Name: Anna Mairaj
//Complier:  g++
//File type:   queue.cpp
//===========================================================

using namespace std;
#include <iostream>
#include "queue.h"  

// constructor 
queue::queue():count(0), front(0), rear(0)
{ // initialize data members as in the notes 

}

//destructor 
queue::~queue()
{ // nothing
}

// PURPOSE: returns true if queue is empty, otherwise false - checks count
bool queue::isEmpty()
{
  return count == 0;
}

// PURPOSE: returns true if queue is full, otherwise false - checks count
bool queue::isFull()
{
   return count == MAX_SIZE;
}

// PURPOSE: if full, throws an exception Overflow
// if not full, enters an element at the rear 
// PAREMETER: provide the element (newElem) to be added
void queue::add(el_t newElem)
{ if (isFull()) {
        throw Overflow();
    }
    el[rear] = newElem;
    rear = (rear + 1) % MAX_SIZE;
    ++count;
}


// PURPOSE: if empty, throw Underflow
// if not empty, removes the front element to give it back 
// PARAMETER: provide a holder (removedElem) for the element removed (pass by ref)
void queue::remove(el_t& removedElem)
{ if (isEmpty()) {
        throw Underflow();
    }
    removedElem = el[front];
    front = (front + 1) % MAX_SIZE;
    --count;
}


// PURPOSE: if empty, throws an exception Underflow
// if not empty, give back the front element (but does not remove it)
//PARAMETER: provide a holder (theElem) for the element (pass by ref)
void queue::frontElem(el_t& theElem)
{ if (isEmpty()) 
  {
        throw Underflow();
  }
    theElem = el[front];
}

// PURPOSE: returns the current size to make it 
// accessible to the client caller
int queue::getSize()
{
  return count;
}

// PURPOSE: display everything in the queue horizontally
// from front to rear enclosed in [   ]
// if empty, displays [ empty ]
void queue::displayAll()
{  if (isEmpty()) { 
    cout << "[ empty ]" << endl; //Output for empty queue
 } else {
      int j = front; //Start from front of queue
      cout << "[";
      for (int i = 0; i <= count; i++) //Iterate through queue
  { if (i > 0) 
            {
                cout << ", "; //Print comma between elements
            }
            cout << el[j]; 
            j = (j + 1) % MAX_SIZE;  // Move to the next index with wraparound if necessary
        }
        cout << "]" << endl;  
    }  
}

// PURPOSE: if empty, throws an exception Underflow
//if queue has just 1 element, does nothing
//if queue has more than 1 element, moves the front one to the rear by
//calling remove followed by add.
void queue::goToBack()
{   
  if (isEmpty()) {
      throw Underflow(); //Exception output for empty queue
  }
  if (count > 1) {
      el_t temp; //local var
      remove(temp); 
      add(temp);
    }   
    
}




