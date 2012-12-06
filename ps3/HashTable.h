/**
 * Hashtable.h
 * Authors: Tucker McKnight & Scott Stromberg
 * Date: January 29th, 2011
 */

#ifndef __HASHTABLE_H
#define __HASHTABLE_H
#include <string>
#include "LinkedList.h"

using namespace std;

class HashTable
{

 public:

  unsigned int size;
  int arrayLength;
  LinkedList** table;

  /**
   * Constructor
   */
  HashTable(int tableSize)
    {
      table = new LinkedList*[tableSize];
      arrayLength = tableSize;
      size = 0;
    }

  /**
   * Constructor
   */
  HashTable()
    {
      table = new LinkedList*[200000];
      arrayLength = 200000;
      size = 0;
    }

  /**
   * Destructor
   */
  ~HashTable()
    {
      delete table;
    }

  void add(string data);
  void remove(string data);
  bool contains(string data);
  int getSize();
  int getWordCount(string word);

 private:
  int hash(string data);

};
#endif
