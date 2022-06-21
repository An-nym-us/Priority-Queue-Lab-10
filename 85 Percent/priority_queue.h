/***********************************************************************
 * Header:
 *    PRIORITY QUEUE
 * Summary:
 *    Our custom implementation of std::priority_queue
 *
 *        ____     _______        __
 *      .' __ '.  |  _____|   _  / /
 *      | (__) |  | |____    (_)/ /
 *      .`____'.  '_.____''.   / / _
 *     | (____) | | \____) |  / / (_)
 *     `.______.'  \______.' /_/
 *
 *
 *    This will contain the class definition of:
 *        priority_queue          : A class that represents a Priority Queue
 * Author
 *    <your names here>
 ************************************************************************/

#pragma once

#include <cassert>
#include "vector.h"

class TestPQueue;    // forward declaration for unit test class

namespace custom
{

/*************************************************
 * P QUEUE
 * Create a priority queue.
 *************************************************/
class priority_queue
{
   friend class ::TestPQueue; // give the unit test class access to the privates
   friend void swap(priority_queue& lhs, priority_queue& rhs);
public:

   //
   // construct
   //
   priority_queue() 
   {
   }
   priority_queue(const priority_queue &  rhs)  
   { 
   }
   priority_queue(priority_queue && rhs)  
   { 
   }
   template <class Iterator>
   priority_queue(Iterator first, Iterator last) 
   {
   }
   explicit priority_queue (custom::vector && rhs) 
   {
   }
   explicit priority_queue (custom::vector& rhs)
   {
   }
  ~priority_queue() {}

   //
   // Access
   //
   const int & top() const;

   //
   // Insert
   //
   void  push(const int& t);
   void  push(int&& t);     

   //
   // Remove
   //
   void  pop(); 

   //
   // Status
   //
   size_t size()  const 
   { 
      return 99;   
   }
   bool empty() const 
   { 
      return false;  
   }
   
private:

   bool percolateDown(size_t indexHeap);      // fix heap from index down. This is a heap index!

   custom::vector container; 

};

/************************************************
 * P QUEUE :: TOP
 * Get the maximum item from the heap: the top item.
 ***********************************************/
const int & priority_queue :: top() const
{
   return *(new int(99));
}

/**********************************************
 * P QUEUE :: POP
 * Delete the top item from the heap.
 **********************************************/
void priority_queue :: pop()
{
}

/*****************************************
 * P QUEUE :: PUSH
 * Add a new element to the heap, reallocating as necessary
 ****************************************/
void priority_queue :: push(const int & t)
{
}
void priority_queue :: push(int && t)
{
}

/************************************************
 * P QUEUE :: PERCOLATE DOWN
 * The item at the passed index may be out of heap
 * order. Take care of that little detail!
 * Return TRUE if anything changed.
 ************************************************/
bool priority_queue :: percolateDown(size_t indexHeap)
{
   return false;
}

/************************************************
 * SWAP
 * Swap the contents of two priority queues
 ************************************************/
void swap(priority_queue& lhs, priority_queue& rhs)
{
}

};
