
// Name: Anna Mairaj
// Complier:  g++
// File type: client program client2.cpp
//===========================================================

using namespace std;
#include <iostream>
#include <stdlib.h>
#include <string>
#include "queue.h"

// Purpose of the program: Generate all possible strings with characters A,B,C using queue
// Algorithm: We can start with ”A”, ”B”, and ”C” in the queue.
// We can start with ”A”, ”B”, and ”C” in the queue.
// Loop – Do the following Repeatedly:
// 1. Remove a string and display it.
// 2. Add the string + ”?”
// 3. Add the string + ”?”
// 4. Add the string + ”?”
// Eventually, the queue will overflow.

int main()
{
  queue q; // created instance of the queue
           //   place "A", "B", "C" in the queue
  q.add("A");
  q.add("B");
  q.add("C");

  //  while loop -- indefinitely while(true)
  while (true)
  {
    try
    {
      string str; //local var to store removed element
      q.remove(str);
      cout << str << endl; //output removed element
      q.add(str + "A"); //append with each letter
      q.add(str + "B");
      q.add(str + "C");
    }catch (queue::Overflow& e) 
    {
      cout << "Queue is full, cannot add more elements." << endl;
      break; //End loop in case of Overflow
    }
    catch (queue::Underflow& e)
    {
      cout << "Queue is empty, nothing to remove." << endl;
      break; //End loop in case of Underflow
    }
  }

  return 0;
}

