/**
 * Performs insertions and searches, using the same data set,on a binary search
 * tree and an AVL tree to compare the empirically compare the performance of
 * these operations on the trees.
 * @author Aaron compare
 * @SEE AVLTree.cpp,BSTree.cpp, WordStat.h
 * Course: CS3102.01
 * Programming Project #: 2
 * @since 03-15-2017
 */
#include <iostream>
#include <cstdlib>  
#include <stdexcept>
#include <iomanip>
#include <fstream> 
#include "AVLTree.cpp"
#include "BSTree.cpp"
#include "WordStat.h"

using namespace std;

/**
 * Converts the specified string to uppercase
 * @param w a string
 * @return the uppercase version of the specified string
 */
string toUpper(string w)
{
   int i;
   for (i=0; i<=w.length(); i++)
      w[i] = toupper(w[i]);
   return w;
}

//Define additional auxiliary/helper functions for the main, if any, here
void traversePrint(const WordStat& word)
{
    cout << word.getWord() << setw(5) << word.getCount() << endl;
}

int main(int argc, char *argv[]) 
{
    if (argc != 2)
        return 0;
    
    AVLTree<WordStat> AyyVeeEl;
    BSTree<WordStat> Binary;
    fstream in;
    in.open(argv[1]);

    if (in.fail())
    {
        cerr << "Error opening" << argv[1] << endl;
        exit(1);
    }
    
    string line;
    while(in >> line)
    {
        line = toUpper(line);

        if(Binary.inTree(WordStat(line, 1)))
        {
            int count = Binary.retrieve(WordStat(line, 1)).getCount();
            Binary.remove(WordStat(line, 1));
            Binary.insert(WordStat(line, counter +1));
            
            AyyVeeEl.remove(WordStat(line, 1));
            AyyVeeEl.insert(WordStat(line, counter+1));
        }

        else
        {
            Binary.insert(WordStat(line, 1));
            AyyVeeEl.insert(WordStat(line, 1));
        }
    }

    in.close();
    
    cout << "Table 1:Binary Search Tree [" << argv[1] << "]" << endl;
    cout << "In-order Traversal" << endl;
    cout << "===================================" << endl;
    cout << "Word           Frequency" << endl;
    cout << "-----------------------------------" << endl;
    Binary.traverse(traversePrint);
    cout << "-----------------------------------" << endl << endl;
    
    cout << "Table 2:AVL Tree [" << argv[1] << "]" << endl;
    cout << "In-order Traversal" << endl;
    cout << "===================================" << endl;
    cout << "Word           Frequency" << endl;
    cout << "-----------------------------------" << endl;
    AyyVeeEl.traverse(traversePrint);
    cout << "-----------------------------------" << endl << endl;

    cout << "Table 3:Binary Search Tree [" << argv[1] << "]" << endl;
    cout << "Level-order Traversal" << endl;
    cout << "===================================" << endl;
    cout << "Word           Frequency" << endl;
    cout << "-----------------------------------" << endl;
    Binary.levelTraverse(traversePrint);
    cout << "-----------------------------------" << endl << endl;
    
    cout << "Table 4:AVL Tree [" << argv[1] << "]" << endl;
    cout << "Level-order Traversal" << endl;
    cout << "===================================" << endl;
    cout << "Word           Frequency" << endl;
    cout << "-----------------------------------" << endl;
    AyyVeeEl.levelTraverse(traversePrint);
    cout << "-----------------------------------" << endl << endl;

    cout << "Table 5:Number of Nodes vs Height" << endl;
    cout << "Using Data in ["<<argv[1]<<"]" << endl;
    cout << "===================================" << endl;
    cout << "Tree      #Nodes   Height" << endl;
    cout << "-----------------------------------" << endl;
    cout << "BST" << setw(7) << Binary.size() << setw(5) << Binary.height() << endl;
    cout << "AVL" << setw(7) << AyyVeeEl.size() << setw(5) << AyyVeeEl.height() << endl;
    cout << "-----------------------------------" << endl << endl;
    
    cout << "Table 6:Total Number of Nodes Accessed" << endl;
    cout << "Searching For all Words in [" << argv[1] << "]" << endl;
    cout << "==============================================" << endl;
    cout << "Tree                # Nodes           " << endl;
    cout << "----------------------------------------------" << endl;

    fstream myFile;
    myFile.open(argv[1]);

    int BinaryCount = 0;
    int AyyVeeElCount = 0;

    while(file >> line)
    {
        line = toUpper(line);
        BinaryCount += Binary.depth(WordStat(line, 1)) + 1;
        AyyVeeElCount += AyyVeeEl.depth(WordStat(line, 1)) + 1;
    }
    
    myFile.close();
    
    cout << "BST"<< setw(17) << BinaryCount << endl;
    cout << "AVL"<< setw(17) << AyyVeeElCount << endl;
    cout << "----------------------------------------------" << endl << endl;
    
    
    return 0;
}

