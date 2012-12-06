/**
 * Dictionary.h
 * Authors: Scott Stromberg & Tucker McKnight
 * Date: February 1st, 2011
 */

#include <string>
#include <vector>
#include <stdlib.h>

#include "HashTable.h"

using namespace std;

class Dictionary { 
 public: 
  /*
   * Constructor
   */
  Dictionary( string file_name )
    {
      filename = file_name;

      hashTable = new HashTable(20000);

      read_file(filename);
    }

  /*
   * Destructor
   */
  ~Dictionary()
    {
    }

  bool spelled_correctly( string word ); 
  HashTable* hashTable;

 private:
  void read_file(string file_name);
  string filename;
};
