/**
 * Models a binary search tree
 * @author William Duncan
 * Course: CS3102.01
 * Programming Project #: 2
 * @since 03-15-2017
 */

#include <string>
#include <iostream>
#include <cassert>
#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include <queue>

using namespace std;

#ifndef BSTREE_H
#define BSTREE_H

using namespace std;

/* exception class*/

class BSTreeException
{
public:
   /**
    * Constructs an instance of <code>BSTreeException</code> with the
    * specified detail message.
    * @param msg the detail message.
    */    
   BSTreeException(const string& aMessage)
   {
      message = aMessage;
   }   
   /**
    * Returns a message
    * @return a message
    */   
   string what() const
   {
      return message;
   }
private:
   string message;
};

template <typename E>
class BSTree
{
private:
    typedef void (*FuncType)(const E& item);    
    class Node
    {
    public:
       /**
          Constructs a node with a given data value.
          @param s the data to store in this node
       */
       Node(E s);
    private:
       /**
        * the data in this node
        */    
       E data;
       /**
        * the left child    
        */
       Node * left;
       /**
        * the right child
        */
       Node * right;
       /**
        * To make this class accessible to BSTree
        */       
      friend class BSTree<E>;
    }; 
    /**
     * An auxiliary function that recursively free the memory
     * allocated for the nodes of this tree.
     * @param subtreeRoot a root of this subtree
     */
    void recDestroy(Node* subtreeRoot);
   /**
    * An auxiliary method the finds returns the parent of the
    * specified node.
    * @param node the root node of a subtree
    * @return a pointer to the parent of the specified node
    */
    Node* findParent(Node* node);
   /**
    * An auxiliary method that in-order traverses the subtree at the specified node
    * @param node the root of a subtree
    * @param func the function to be applied to the data in each node
    */    
    void traverse (Node* node, FuncType func);
    /**
     * An auxiliary method that deletes the specified node from this tree
     * @param node the node to be deleted
     * @return true on successful remove; false, otherwise
    */    
    bool remove(Node* node);
    /**
     * An auxiliary method that searches for the node containing the specified item.
     * @param item the item to search for in the tree
     * @return a pointer to the node containing the item or null if the item
     * is not in the tree.
     */   
    Node* search(const E& item);
    /**
     * An auxiliary method that recursively computes the height of the subtree 
     * rooted at the specified node.
     * @param node a subtree root
     * @return the height of the subtree with the specified root
     */
    int height(Node* node) const;
    /**
     * the root of this tree
     */
    Node* root;
    /**
     * the size of this tree
     */
    int count;    
public:
    /**
     * Constructs an empty binary search tree;
     */
   BSTree();

   /**
    * destructor - returns the binary search tree memory to the system;
    */
   ~BSTree();

   /**
    * Determine whether the binary search tree is empty.
    * @return this function returns true if the tree is empty;
    * otherwise, it returns false if the tree contains at least one node.
    */
   bool isEmpty() const;

   /**
    * Inserts an item into the tree.
    * @param item the value to be inserted.
    * @return none
    */
   void insert(E item);

   /**
    * Determines whether an item is in the tree.
    * @param item item with a specified search key.
    * @return true on success; false on failure.
    */
   bool inTree(E item) const;

   /**
    * Deletes an item from the tree.
    * @param item the item to be removed from this tree
    */
   void remove(const E& item);

   /**
    * returns the first item when the tree is traversed in
    * in-order.
    * @return the first(least) item in the tree; an exception
    * is generated if the tree is empty.
    */
   const E& retrieve(const E& key) const throw (BSTreeException);

   /**
    * This function traverses a binary tree in in-order
    * and calls the function Visit once for each node.
    */
   void traverse(FuncType func);

   /**
    * This method returns the size of this binary search tree.
    * @return the size of this tree
    */
   int size() const;

   /**
    * This method returns the height  of this tree.
    * @return the height of this tree
    */
   int height() const;
      
   /**
    * Computes the depth  of the specified search key in this tree.
    * @param item the search key
    * @return the depth of the specified search key if it is in the.
    * this tree. If it is not, -1-d, where d is the depth at which 
    * it would have been found it inserted in the current tree.
    */
   int depth(const E& item) const;
   
   /**
    * This function traverses the tree in level-order
    * and calls the function func once for each node.
    * @param func the function to apply to the data in each node
    */
   void levelTraverse(FuncType func);     
};
#endif
