/**
 * Implementation for the Heap<E> class
 * @author Aaron Cao
 * @since 2017-02-16
 * Course: CS3102.01
 * Programming Project #: 1
 * Instructor: Dr. Duncan
 * @see Heap.h
 */

#include "Heap.h"

using namespace std;

template <typename E>
Heap<E>::Heap()
{
   // compiler-generated code .. no need to implement this
}

template <typename E>
Heap<E>::~Heap()
{
   while(tree.size() > 0)
      tree.pop_back();
}

template <typename E>
bool Heap<E>::isEmpty() const
{
   return tree.empty();
}

template<typename E>
void Heap<E>::insert(E item)
{
   tree.push_back(item);
   int place = tree.size()-1;
   int parent = (place-1)/2;
   while (parent >= 0 && tree[place] > tree[parent])
   {
      swap(place, parent);
      place = parent;
      parent = (place-1)/2;
   }
}

template<typename E>
E Heap<E>::remove() throw (HeapException)
{
   E removed = tree[0];
   tree[0] = tree[tree.size()-1];
   int sizeOf = tree.size()-1;
   reheapify(0, sizeOf);
   return removed;
}

template<typename E>
E& Heap<E>::peek() throw (HeapException)
{
   return tree[0];
}

template<typename E>
int Heap<E>::size()const
{
   return tree.size();
}

template<typename E>
void Heap<E>::swap(int place, int parent)
{
   E temp;
   temp = tree[place];
   tree[place] = tree[parent];
   tree[parent] = temp;
}

template<typename E>
void Heap<E>::reheapify(int root, int eSize)
{
   int maxChild, rightChild, leftChild;
   leftChild = 2*root+1;
   rightChild = 2*root+2;

   if (leftChild == eSize)
      maxChild = leftChild;
   else
   {
      if (tree[leftChild] <= tree[rightChild])
         maxChild = rightChild;
      else
         maxChild = leftChild;
   }
   if (tree[root] < tree[maxChild])
   {
      swap(root, maxChild);
      reheapify(maxChild, eSize);
   }
}


