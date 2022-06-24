/***********************************************************************
 * Header:
 *    PRIORITY QUEUE
 * Summary:
 *    Our custom implementation of std::priority_queue
 *      __       ____       ____         __
 *     /  |    .'    '.   .'    '.   _  / /
 *     `| |   |  .--.  | |  .--.  | (_)/ /
 *      | |   | |    | | | |    | |   / / _
 *     _| |_  |  `--'  | |  `--'  |  / / (_)
 *    |_____|  '.____.'   '.____.'  /_/
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
template<class T>
class priority_queue
{
   friend class ::TestPQueue; // give the unit test class access to the privates
   template <class TT>
   friend void swap(priority_queue<TT>& lhs, priority_queue<TT>& rhs);
public:

   //
   // construct
   //
   priority_queue() 
   {
   }
   priority_queue(const priority_queue &  rhs)  
   {
       container = rhs.container;
   }
   priority_queue(priority_queue && rhs)  
   {
       container = std::move(rhs.container);
   }
   template <class Iterator>
   priority_queue(Iterator first, Iterator last) 
   {
       container.reserve(last-first);
       for(auto it = first; it!= last; it++)
           container.push_back(*it);
       
   }
   explicit priority_queue (custom::vector<T> && rhs) 
   {
       container = std::move(rhs);
   }
   explicit priority_queue (custom::vector<T>& rhs)
   {
       container = rhs;
   }
    
  ~priority_queue() {}

   //
   // Access
   //
   const T & top() const;

   //
   // Insert
   //
   void  push(const T& t);
   void  push(T&& t);     

   //
   // Remove
   //
   void  pop(); 

   //
   // Status
   //
   size_t size()  const 
   { 
      return container.size();
   }
   bool empty() const 
   { 
      return container.size() == 0 ;
   }
   
private:

   bool percolateDown(size_t indexHeap);      // fix heap from index down. This is a heap index!

   custom::vector<T> container; 

};

/************************************************
 * P QUEUE :: TOP
 * Get the maximum item from the heap: the top item.
 ***********************************************/
template <class T>
const T & priority_queue <T> :: top() const
{
    return container.front();
}

/**********************************************
 * P QUEUE :: POP
 * Delete the top item from the heap.
 **********************************************/
template <class T>
void priority_queue <T> :: pop()
{
    
}

/*****************************************
 * P QUEUE :: PUSH
 * Add a new element to the heap, reallocating as necessary
 ****************************************/
template <class T>
void priority_queue <T> :: push(const T & t)
{
    container.push_back(t);
    std:: cout << container.size() << std::endl;
    size_t parentIndex = (size_t) (container.size()-1)/ 2;
    while(parentIndex !=0)
    {
        percolateDown(parentIndex);
        parentIndex = (size_t) parentIndex / 2;
    }

}
template <class T>
void priority_queue <T> :: push(T && t)
{
}

/************************************************
 * P QUEUE :: PERCOLATE DOWN
 * The item at the passed index may be out of heap
 * order. Take care of that little detail!
 * Return TRUE if anything changed.
 ************************************************/
template <class T>
bool priority_queue <T> :: percolateDown(size_t indexHeap)
{
    bool  valueChanged = false;
    if(indexHeap >= container.size()-1)
        return 0;
    


    size_t childLeft = indexHeap * 2;
    size_t childRight = indexHeap * 2 + 1;
    
    childLeft -= 1;
    childRight -= 1;

    size_t indexBigger = 0;
    // Find Bigger Child
    

    if (container[childLeft] < container[childRight])
    {
       indexBigger = childRight;
    }
    else
    {
       indexBigger = childLeft;
    }

    if (container[indexHeap - 1] < container[indexBigger])
    {

       std::swap(container[indexHeap-1], container[indexBigger]);
       valueChanged = true;
       percolateDown(indexBigger+1);
    }
    return valueChanged;
}


/************************************************
 * SWAP
 * Swap the contents of two priority queues
 ************************************************/
template <class T>
inline void swap(custom::priority_queue <T>& lhs,
                 custom::priority_queue <T>& rhs)
{
    lhs.container.swap(rhs.container);
}

};

