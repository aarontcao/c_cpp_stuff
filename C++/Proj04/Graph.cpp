/**
 * Implementation file for the directed graph ADT
 * @author Duncan, Aaron Cao
 * @since 04-18-2017
 * @see Graph.h
*/

#include "Graph.h"
#include <queue>
#include <stack>
#include <cstdlib>

using namespace std;

/* nested Vertex class definitions */

template<typename E>
Graph<E>::Vertex::Vertex(E s)
{
   pNextVertex = NULL;
   data = s;
   inDeg = 0;
   outDeg = 0;
   pEdge = NULL;
   processed = 0;
}

/* nested Edge class definitions */
template<typename E>
Graph<E>::Edge::Edge(double wt)
{
   destination = NULL;
   weight = wt;
   pNextEdge = NULL;
}

/* Outer Graph class definitions */
template <typename E>
Graph<E>::Graph()
{
   first = NULL;
   order = 0;
}

template <typename E> 
Graph<E>::~Graph()
{
   Edge* edgePtr;
   Vertex* vertexPtr;
   vertexPtr = first;
   while (first)
   {
      vertexPtr = first;
      while(vertexPtr->pEdge)
      {
         edgePtr = vertexPtr->pEdge;
         vertexPtr->pEdge = edgePtr->pNextEdge;
         delete edgePtr;
      }
      first = vertexPtr->pNextVertex;
      delete vertexPtr;
   }
}

template <typename E> 
void Graph<E>::insertVertex(E obj)
{
   Vertex* newPtr;
   Vertex* locPtr;
   Vertex* predPtr;

   assert(isVertex(obj) == false);
   newPtr = new Vertex(obj);
   newPtr->pNextVertex = NULL;
   newPtr->data = obj;
   newPtr->inDeg = 0;
   newPtr->outDeg = 0;
   newPtr->processed = 0;
   newPtr->pEdge = NULL;
   locPtr = first;
   predPtr = NULL;
   while (locPtr != NULL && obj > locPtr->data)
   {
      predPtr = locPtr;
      locPtr = locPtr->pNextVertex;
   }
   /*key already exist. */
   if (locPtr != NULL && obj==locPtr->data)
   {
      locPtr->data = obj;
      delete newPtr;
      return;
   }
   /* insert before first vertex */
   if (predPtr == NULL)
      first = newPtr;
   else
      predPtr->pNextVertex = newPtr;
   newPtr->pNextVertex = locPtr;
   order++;
}

template <typename E> 
void Graph<E>::deleteVertex(E key)
{
   Vertex* tmp;
   Vertex* predPtr;
   Vertex* walkPtr;
   if (isEmpty())
      return;
   predPtr = NULL;
   walkPtr = first;  
   /* does vertex exist */
   while (walkPtr != NULL && key > walkPtr->data)
   {  
      predPtr = walkPtr;
      walkPtr = walkPtr->pNextVertex;
   }
   if (walkPtr == NULL || key != walkPtr->data)
      return;
   /* vertex found. Test degree */
   if ((walkPtr->inDeg > 0) || (walkPtr->outDeg > 0))
      return;
   /* OK to delete */
   if (predPtr == NULL)
   {
      tmp = first;
      first = walkPtr->pNextVertex;
      delete tmp;
   }
   else
   {
      tmp = predPtr->pNextVertex;
      predPtr->pNextVertex = walkPtr->pNextVertex;
      delete tmp;
   }
   order--;
}

template <typename E> 
void Graph<E>::insertEdge(E fromKey, E toKey, double weight)
{
   Edge* tmpEdge;
   Edge* newEdge;
   Edge* pred;
   Vertex* tmpFrom;
   Vertex* tmpTo;
   if (isEmpty())
      return;

   newEdge = new Edge(weight);
   /* check whether originating vertex exists */
   tmpFrom = first;
   while (tmpFrom != NULL && fromKey > tmpFrom->data)
      tmpFrom = tmpFrom->pNextVertex;
   if (tmpFrom == NULL || fromKey != tmpFrom->data)
      return; 
   /* locate destination vertex */
   tmpTo = first;
   while (tmpTo != NULL && toKey > tmpTo->data)
      tmpTo = tmpTo->pNextVertex;
   if (tmpTo == NULL || toKey != tmpTo->data)
      return;
   /*check if edge already exists */
   tmpEdge = tmpFrom->pEdge;
   while (tmpEdge != NULL && tmpEdge->destination != tmpTo)
      tmpEdge = tmpEdge->pNextEdge;
   if (tmpEdge != NULL && tmpEdge->destination != NULL)
      return;
   tmpFrom->outDeg++;
   tmpTo->inDeg++;
   newEdge->destination = tmpTo;
   newEdge->weight = weight;
   newEdge->pNextEdge = NULL;
   if (tmpFrom->pEdge == NULL)
   {
      tmpFrom->pEdge = newEdge;
      return;
   }
   pred = NULL;
   tmpEdge = tmpFrom->pEdge;
   while (tmpEdge != NULL && tmpEdge->destination != tmpTo)
   {
      pred = tmpEdge;
      tmpEdge = tmpEdge->pNextEdge;
   }
   if (pred == NULL)
      tmpFrom->pEdge = newEdge;
   else
     pred->pNextEdge = newEdge;
   newEdge->pNextEdge = tmpEdge;
}

template <typename E> 
void Graph<E>::deleteEdge(E fromKey, E toKey)
{
   Edge* tmpEdge;
   Edge* pred;
   Vertex* tmpFrom;
   Vertex* tmpTo;
      
   /* find source vertex */
   tmpFrom = first;
   while (tmpFrom != NULL && fromKey > tmpFrom->data)
      tmpFrom = tmpFrom->pNextVertex;
   if (tmpFrom == NULL || fromKey != tmpFrom->data)
      return;
   /* locate destination vertex */
   tmpTo = first; 
   while (tmpTo != NULL && toKey >tmpTo->data)
      tmpTo = tmpTo->pNextVertex;
   if (tmpTo == NULL || toKey != tmpTo->data)
      return;
   /*check if edge does not exist */
   tmpEdge = tmpFrom->pEdge;
   pred = NULL;
   while (tmpEdge != NULL && tmpEdge->destination != tmpTo)
   {
      pred = tmpEdge;
      tmpEdge = tmpEdge->pNextEdge;
   }
   /* if edge does not exist */
   if (tmpEdge == NULL)
      return;
   /* update degrees */
   pred->pNextEdge = tmpEdge->pNextEdge;
   tmpFrom->outDeg--;
   tmpTo->inDeg--;
   delete tmpEdge;
}

template <typename E> 
double Graph<E>::retrieveEdge(E fromKey, E toKey) const throw (GraphException)
{
   Edge* tmpEdge;
   Vertex* tmpFrom;
   Vertex* tmpTo;
   /* find source vertex */
   tmpFrom = first;
   while (tmpFrom != NULL && fromKey > tmpFrom->data)
      tmpFrom = tmpFrom->pNextVertex;
   if (tmpFrom == NULL || fromKey != tmpFrom->data)
      throw GraphException("Non-existent edge - retrieveEdge().");
   /* locate destination vertex */
   tmpTo = first; 
   while (tmpTo != NULL && toKey > tmpTo->data)
      tmpTo = tmpTo->pNextVertex;
   if (tmpTo == NULL || toKey != tmpTo->data)
      throw GraphException("Non-existent edge - retrieveEdge().");
   /*check if edge does not exist */
   tmpEdge = tmpFrom->pEdge;
   while (tmpEdge != NULL && tmpEdge->destination != tmpTo)
   {
      tmpEdge = tmpEdge->pNextEdge;
   }
   /* if edge does not exist */
   if (tmpEdge == NULL)
      throw  GraphException("Non-existent edge - retrieveEdge().");
   return tmpEdge->weight; 
}

template <typename E> 
const E& Graph<E>::retrieveVertex(const E& key) const throw (GraphException)
{
   Vertex* tmp;
   if (isEmpty())
      throw GraphException("Non-existent vertex in call to retrieveVertex().");
   tmp = first;
   while (tmp != NULL && key != tmp->data)
      tmp = tmp->pNextVertex;
   if (tmp == NULL)
      throw GraphException("Non-existent vertex - retrieveVertex().");
   return tmp->data;
}

template <typename E> 
void Graph<E>::bfsTraverse(FuncType func)
{
   Vertex* walkPtr;
   Vertex* toPtr;
   queue<Vertex*> q;
   Edge* edgeWalk;  
   Vertex* tmp;
   if (isEmpty())
      return;
   walkPtr = first;
   while (walkPtr != NULL)
   {
      walkPtr->processed = 0;
      walkPtr = walkPtr->pNextVertex;
   }
   walkPtr = first;
   while (walkPtr != NULL)
   {
      if (walkPtr->processed < 2)
      {
         if (walkPtr->processed < 1)
         {
            q.push(walkPtr); 
            walkPtr->processed = 1;
         }
      }
      while (!q.empty())
      {
          tmp = q.front();
          q.pop();
          func(tmp->data);
          tmp->processed = 2;
          edgeWalk = tmp->pEdge; 
          while (edgeWalk != NULL)           
          {
              toPtr = edgeWalk->destination;
              if (toPtr->processed == 0)
              {
                  toPtr->processed = 1;
                  q.push(toPtr);
              }
              edgeWalk = edgeWalk->pNextEdge;
          }
      }
      walkPtr = walkPtr->pNextVertex;
   }
}

template <typename E> 
void Graph<E>::dfsTraverse(FuncType func)
{
   Vertex* walkPtr;
   Vertex* toPtr;
   stack<Vertex*> s;
   Edge* edgeWalk;  
   Vertex* tmp;
   if (isEmpty())
      return;
   walkPtr = first;
   while(walkPtr != NULL)
   {
      walkPtr->processed = 0;
      walkPtr = walkPtr->pNextVertex;
   }
   walkPtr = first;
   while (walkPtr != NULL)
   {
      if (walkPtr->processed < 2)
      {
         if (walkPtr->processed < 1)
         {
            walkPtr->processed = 1;  
            s.push(walkPtr);
         }
         while (!s.empty())
         {

            tmp = s.top();
            edgeWalk = tmp->pEdge;
            while(edgeWalk != NULL)
            {
               toPtr = edgeWalk->destination;
               if (toPtr->processed == 0)
               {
                  toPtr->processed = 1;
                  s.push(toPtr);
                  edgeWalk = toPtr->pEdge;
               }
               else
                  edgeWalk = edgeWalk->pNextEdge;
            }
            tmp = s.top();
            s.pop();
            func(tmp->data);
            tmp->processed = 2;
         }
      }
      walkPtr = walkPtr->pNextVertex;
   }
}

template <typename E> 
bool Graph<E>::isEmpty() const
{
   return first == NULL;  
}

template <typename E> 
int Graph<E>::size() const
{
   return order;  
}

template <typename E> 
bool Graph<E>::isVertex(E key) const
{
   Vertex* tmp;
   if (isEmpty()) 
      return false;
   tmp = first;
   while (tmp != NULL && key != tmp->data)
      tmp = tmp->pNextVertex;
   if (tmp == NULL)
      return false;
   return true;
}

/*--------------------Begin Code Augmentation ---------------*/

template <typename E> 
bool Graph<E>::isEdge(E fromKey, E toKey) const
{  
   Vertex* tempPrev = first;
   Vertex* tempDest = first;
   Edge* temp = tempPrev -> pEdge;

   while (tempDest != NULL && retrieveVertex(toKey) != tempDest -> data)
      tempDest = tempDest->pNextVertex;
   if (tempDest == NULL || retrieveVertex(toKey) != tempDest->data)
      return false;

   while (tempPrev != NULL && retrieveVertex(fromKey) != tempPrev -> data)
      tempPrev = tempPrev -> pNextVertex;

   if (tempPrev == NULL || retrieveVertex(fromKey) != tempPrev -> data)
      return false;

   while (temp != NULL && temp -> destination != tempDest)
   {
      temp = temp -> pNextEdge;
   }
   return !(temp == NULL);
}


template <typename E>
bool Graph<E>::isReachable(E fromKey, E toKey) const
{
   Vertex* temp;
   Vertex* tempPrev = first;
   Vertex* tempDest = first;
   Vertex* position = tempPrev;
   Vertex* nextPtr;
   Edge* edgePosition;
   queue<Vertex*> myQueue;

   while (tempPrev != NULL && fromKey > tempPrev->data)
      tempPrev = tempPrev->pNextVertex;

   if (tempPrev == NULL || fromKey != tempPrev->data)
      return false;

   while (tempDest != NULL && toKey > tempDest->data)
      tempDest = tempDest->pNextVertex;

   if (tempDest == NULL || toKey != tempDest->data)
      return false;

   while (position != NULL)
   {
      position -> processed = 0;
      position = position -> pNextVertex;
   }

   while (position != NULL)
   {
      if (position -> processed < 2)
      {
         if (position -> processed < 1)
         {
            myQueue.push(position);
            position -> processed = 1;
         }
      }

      while (!myQueue.empty())
      {
         temp = myQueue.front();
         myQueue.pop();
         temp -> processed = 2;
         edgePosition = temp -> pEdge;
         while (edgePosition != NULL)
         {
            nextPtr = edgePosition -> destination;
            if (nextPtr -> processed == 0)
            {
               nextPtr -> processed = 1;
               myQueue.push(nextPtr);
            }
            edgePosition = edgePosition -> pNextEdge;
         }

         if (tempDest -> processed == 2)
            return true;
      }
      return false;
   }
   return false;
}


template <typename E> 
int Graph<E>::countEdges() const
{
   Vertex* tempPrev = first;
   Edge* tempEdge = tempPrev -> pEdge;
   int count = 0;

   while (tempEdge != NULL)
   {
      tempEdge = tempEdge->pNextEdge;
      count++;
   }
   return count;
}

/*--------------------End Code Augmentation ---------------*/

template <typename E> 
int Graph<E>::outDegree(E key) const throw (GraphException)
{
   Vertex* tmp;
   if (isEmpty())
      throw  GraphException("Non-existent vertex - outDegree().");
   tmp = first;
   while (tmp != NULL && key != tmp->data)
      tmp = tmp->pNextVertex;
   if (tmp == NULL)
      throw GraphException("Non-existent vertex - outDegree().");
   return tmp->outDeg;
}

template <typename E> 
int Graph<E>::inDegree(E key) const throw (GraphException)
{
   Vertex* tmp;
   if (isEmpty())
      throw  GraphException("Non-existent vertex - inDegree().");
   tmp = first;
   while (tmp != NULL && key != tmp->data)
      tmp = tmp->pNextVertex;
   if (tmp == NULL)
      throw GraphException("Non-existent vertex - inDegree().");
   return tmp->inDeg;
}

