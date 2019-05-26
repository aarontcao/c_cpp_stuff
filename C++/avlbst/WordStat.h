/**
 * Tracks a word and its frequency
 * @author William Duncan
 * Course: CS3102.01
 * Programming Project #: 2
 * @since 03-15-2017
 */

#ifndef WORDSTAT_H
#define	WORDSTAT_H

#include <string>
#include <iostream>
    
using namespace std;


class WordStat 
{
private:
    /**
     * a word
     */
   string word;
   /**
    * the frequency count
    */
   int count;    
public:
   /**
    * Creates a word and sets its count to 0
    */
   WordStat()
   {
      word = " ";
      count = 0;
   }

   /**
    * Creates a WordStat and set its initial count to
    * the specified value.
    * @param aWord a word
    * @param aCount the frequency
    */
   WordStat(string aWord, int aCount)
   {
      word = aWord;
      count = aCount;
   }
  
   /**
    * Gives this word
    * @return a word
    */
   string getWord() const
   {
      return word;
   }

   /**
    * Gives the frequency
    * @return the frequency of this word
   */
   int  getCount() const
   {
      return count;
   }

   /**
    * Increase the frequency of this word by the
    * specified value
    * @param increment the value by which the frequency
    * is increased.
   */
   void updateCount(long increment)
   {
      count = count + increment;
   }

   /**
    * Determines whether two WordStat objects are equivalent
    * @param w1 a WordStat object
    * @param w2 a WordStat object
    * @return true when the specified WordStat objects contain
    * the same word.
    */
   friend bool operator==(const WordStat& w1, const WordStat& w2);
   /**
    * Determines whether two WordStat objects are not equivalent
    * @param w1 a WordStat object
    * @param w2 a WordStat object
    * @return true when the specified WordStat objects do not contain
    * the same word.
    */   
   friend bool operator!=(const WordStat& w1, const WordStat& w2);
   /**
    * Determines whether the word in one WordStat object comes after the
    * word in another WordStat object
    * @param w1 a WordStat object
    * @param w2 a WordStat object
    * @return true when the word in the first WordStat object comes after
    * the word in the second.
    */   
   friend bool operator>(const WordStat& w1, const WordStat& w2);
   /**
    * Determines whether the word in one WordStat object comes before the
    * word in another WordStat object
    * @param w1 a WordStat object
    * @param w2 a WordStat object
    * @return true when the word in the first WordStat object comes before
    * the word in the second.
    */      
   friend bool operator<(const WordStat& w1, const WordStat& w2);
   /**
    * Determines whether the word in one WordStat object comes after the
    * or is the same as the word in another WordStat object
    * @param w1 a WordStat object
    * @param w2 a WordStat object
    * @return true when the word in the first WordStat object comes after
    * or is the same as the word in the second.
    */      
   friend bool operator>=(const WordStat& w1, const WordStat& w2);
   /**
    * Determines whether the word in one WordStat object comes before the
    * or is the same as the word in another WordStat object
    * @param w1 a WordStat object
    * @param w2 a WordStat object
    * @return true when the word in the first WordStat object comes before
    * or is the same as the word in the second.
    */      
   friend bool operator<=(const WordStat& w1, const WordStat& w2);
};

bool operator==(const WordStat& w1, const WordStat& w2)
{   
   return w1.word == w2.word;
}   

bool operator!=(const WordStat& w1, const WordStat& w2)
{   
   return w1.word != w2.word;
}   

bool operator>(const WordStat& w1, const WordStat& w2)
{   
   return w1.word > w2.word;
}   

bool operator<(const WordStat& w1, const WordStat& w2)
{   
   return w1.word < w2.word;
}   

bool operator>=(const WordStat& w1, const WordStat& w2)
{   
   return w1.word >= w2.word;
}   

bool operator<=(const WordStat& w1, const WordStat& w2)
{   
   return w1.word <= w2.word;
}   

#endif	/* WORDSTAT_H */

