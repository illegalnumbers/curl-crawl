/*
 *Word Count Header File
 *
 *Written by: Team Amurica (Ben Nelson, Carlos Brenneisen, Tucker McKnight, Scott Stromberg)
 *February, 2011
 *
 *Defines methods and the constructor for Word Count
 *
 */
#ifndef __WORD_COUNT_H
#define __WORD_COUNT_H
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include "HashTable.h"
       
using namespace std;
      
class Word_Count { 
  public:          
  Word_Count()
    {
      words = HashTable(); //used to store the words
    }

  ~Word_Count()
    {
      delete &words;
    }
         void       add_word( string word ); // count this word 
         int        get_word_count( string word ); // how often was this word seen? 
         void       get_top_words( vector<string> &word_list, vector<int> &counts, int count=50);
	 void       getWordsAndCount(vector<string> &wordlist, vector<int>&counts);
	 // return separate lists (in descending order) of most frequent words. 

 
  private: 
	 HashTable words;

}; 
#endif
