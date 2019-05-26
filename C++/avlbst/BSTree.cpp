/**
 * Models an binary search tree.
 * @param <E> data type of elements of the tree
 * @author Duncan, Aaron Cao
 * Course: CS3102.01
 * Programming Project #: 2
 * @since 03-15-2017
 * @see BSTree.h
*/

#include "BSTree.h"
#include <cstdlib>
#include <iostream>
#include <queue>

using namespace std;

/* Nested Node class definitions */

template <typename E>
BSTree<E>::Node::Node(E s)
{
   data = s;
   left = NULL;
   right = NULL;
}

/* Outer BSTree class definitions */

template <typename E>
BSTree<E>::BSTree()
{
   root = NULL;
   count = 0;
}

template <typename E>
BSTree<E>::~BSTree()
{
   recDestroy(root);
}

template <typename E>
bool BSTree<E>::isEmpty() const
{
   return root == NULL;
}

template<typename E>
void BSTree<E>::insert(E item)
{
   Node* tmp;
   Node* newnode = new Node(item);
   /* If it is the first node in the tree */
   if (isEmpty())
   {
      root = newnode;
      count++;
      return;
   }
   /*find where it should go */
   tmp = root;
   while (1)
   {
      if (tmp->data == item)
      { /* Key already exists. */
         tmp->data = item;
         delete newnode; /* don’t need it */
         return;
      }
      else if (tmp->data > item)
      {
         if (!(tmp->left))
         {
            /* If the key is less than tmp */
            tmp->left = newnode;
            count++;
            return;
         }
         else
         {
            /* continue searching for insertion pt. */
            tmp = tmp->left;
         }
      }
      else
      {
         if (!(tmp->right))
         {
            /* If the key is greater than tmp */
            tmp->right = newnode;
            count++;
            return;
         }
         else
         /* continue searching for insertion point*/
            tmp = tmp->right;
      }
   }
}

template<typename E>
bool BSTree<E>::inTree(E item) const
{
   Node* tmp;
   if (isEmpty())
      return false;
   /*find where it is */
   tmp = root;
   while (1)
   {
      if (tmp->data == item)
         return true;
      if (tmp->data > item)
      {
         if (!(tmp->left))
            return false;
         /* continue searching */
         tmp = tmp->left;
      }
      else
      {
         if (!(tmp->right))
            return false;
         /* continue searching for insertion pt. */
         tmp = tmp->right;
      }
   }
}

template<typename E>
void BSTree<E>::remove(const E& item)
{
   Node* nodeptr;
   nodeptr = search(item);
   if (nodeptr)
   {
      remove(nodeptr);
      count--;
   }
}

template<typename E>
const E& BSTree<E>::retrieve(const E& key) const throw (BSTreeException)
{
   Node* tmp;
   if (isEmpty())
      throw BSTreeException("Binary Search Tree Exception: tree empty on retrieve()");
   tmp = root;
   while(tmp)
   {
      if (tmp->data == key)
         return tmp->data;
      if (tmp->data > key)
         tmp = tmp->left;
      else
         tmp = tmp->right;
   }
   if (tmp == NULL)
      throw BSTreeException("Binary Search Tree Exception: key does not exist on retrieve()");
   return tmp->data;
}

template<typename E>
void BSTree<E>::traverse(FuncType func)
{
   traverse(root,func);
}

template<typename E>
int BSTree<E>::size() const
{
   return count;
}

template<typename E>
int BSTree<E>::height() const
{
   return height(root);
}

template<typename E>
int BSTree<E>::depth(const E& item) const
{
   int depth = 0;
   Node* ptr = root;
   while (ptr -> data != item)
   {
      if (item < ptr -> data)
      {
         ptr = ptr -> left;
         depth++;
      }
      else if (item > ptr -> data)
      {
         ptr = ptr -> right;
         depthVal++;
      }
      else if (item == ptr -> data)
         return depth;
      else
         return -1-depth;
   }
   return depth;
}
     

template<typename E>
void BSTree<E>::recDestroy(Node* root)
{
   if (root)
   {
      if (root->left) recDestroy(root->left);
      if (root->right) recDestroy(root->right);
      delete root;
   }
}

template<typename E>
typename BSTree<E>::Node* BSTree<E>::findParent(Node* node)
{
   Node* tmp;
   tmp = root;
   if (tmp == node)
      return NULL;
   while(1)
   {
      assert(tmp->data != node->data);
      if (tmp->data > node->data)
      {
         assert(tmp->left != NULL);
         if (tmp->left == node)
            return tmp;
         tmp = tmp->left;
      }
      else
      {
         assert(tmp->right != NULL);
         if (tmp->right == node)
            return tmp;
         tmp = tmp->right;
      }
   }
}

template<typename E>
void BSTree<E>::traverse(Node* node, FuncType func)
{
   if (node)
   {
      traverse(node->left,func);
      func(node->data);
      traverse(node->right,func);
   }
}


template<typename E>
typename BSTree<E>::Node* BSTree<E>::search(const E& item)
{
   Node* tmp;
   tmp = root;
   while(tmp)
   {
      if (tmp->data == item)
         return tmp;
      if (tmp->data > item)
         tmp = tmp->left;
      else
         tmp = tmp->right;
   }
   return tmp;
}

template<typename E>
bool BSTree<E>::remove(Node* node)
{
   E data;
   Node* parent;
   Node* replacement;
   parent = findParent(node);
   
   if (node->left && node->right)
   {
      replacement = node->right;
      while (replacement->left)
         replacement = replacement->left;
      data = replacement->data;
      remove(replacement);
      node->data = data;
      return true;
   }
   else
   {
      if (node->left)
           replacement = node->left;
      else if (node->right)
           replacement = node->right;
      else
           replacement = NULL;
      if (!parent)
         root = replacement;
      else if (parent->left == node)
         parent->left = replacement;
      else
         parent->right = replacement;
      delete node;
      return true;
   }
}

template<typename E>
int BSTree<E>::height(Node* node) const
{
   if (node == NULL)
      return -1;
    
   int leftSub = height(node->left);
   int rightSub = height(node->right);
   if (leftSub > rightSub)
      return leftSub + 1;
   else
      return rightSub + 1;
}

template<typename E>
void BSTree<E>::levelTraverse(FuncType func)
{
   if (isEmpty())
      return;
   Node* ptr = root;
   queue<Node*> treeLevel;
   treeLevel.push(root);
   while (!treeLevel.empty())
   {
      ptr = treeLevel.front();
      treeLevel.pop();
      func(ptr -> data);
      if (ptr -> left)
         treeLevel.push(ptr -> left);
      if (ptr -> right)
         treeLevel.push(ptr -> right);
   }
}