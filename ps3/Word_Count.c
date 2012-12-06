/*
 *Word Count
 *
 *Author: Team Amurica (Ben Nelson, Carlos Brenneisen, Tucker McKnight, Scott Stromberg)
 *2/4/11
 *
 *This is the class meant to return the list of top words used, and how many times they are used
 *
 */

#include "Word_Count.h"

/*
 *add_word method
 *
 *adds a word to the hash table
 */

void Word_Count::add_word(string word) 
{
  words.add(word);
}


/*
 *get_word_count method
 *
 * returns the amount of times a word has been used by using the method defined in the hash table
 */

int Word_Count::get_word_count(string word)
{
  int count = words.getWordCount(word);

  return count;
}

/*
 *Get Words and Count method
 *
 *Uses pass by reference to return all the words used and the amount of times each one was used in the form of two vectors
 */

void Word_Count::getWordsAndCount(vector<string> &wordlist, vector<int>&counts)
{
  for(int i=0; i <words.size;i++)//iterates through hash table
  {
    if(words.table[i]!=NULL)//checks to see if there is a linked list at this spot
      {
	words.table[i]->goToFront(); //makes sure that you start at the beginning of the list
	for(int j=0; j<words.table[i]->getSize();j++)//iterates through linked list
	  {
	    wordlist.push_back(words.table[i]->getCurrent());//puts the current word in 'wordlist'
	    counts.push_back(get_word_count(words.table[i]->getCurrent()));//gets the amount of times the word is used and puts it in 'counts'
	    words.table[i]->goNext();//moves the current node
	  }
      }
  }
}

/*
 *get_top_words method
 *
 *  Uses pass by reference to return the most used words and as well as the amount of times they have been used
 *  word_list will contain the top words
 *  counts will contain the amount of times each word has been used (will line up with the word_list vector)
 *  count is the number of top words to return
 *
 
void Word_Count::get_top_words(vector<string> &word_list, vector<int> &counts, int count)
{
  bool run = true; //we want to run through the initial loop...
  int i = 0; //start at the beginning oof the hash table
  int marker; //determines position in the linked list (this will be important in the second set of loops)
  while(run)
    {
      if(words.table[i] != NULL) //checks to see if there is a linked list at this spot in the has table. (If != NULL, there is a list)
	{
	  words.table[i]->goToFront();//makes sure that you are iterating from the start of the linked list
	  marker = 0; 
	  for(int k = 0; k < words.table[i]->getSize(); k++)//iterates through the linked list
	    {	      
	      word_list.push_back(words.table[i]->getCurrent()); //add the word at current position
	      counts.push_back(get_word_count(words.table[i]->getCurrent())); //add the number of times its used to count
	      if(counts.size() == count) //if you have reached the amount of words you intend to return, break out of the loop
		{
		  run = false; //we want to break out of the while loop too, not just the for loop, otherwise we would just use break
		}
	      words.table[i]->goNext(); //go to the next spot in the linked list
	      marker++;
	    }
	}
      i++; //check the next spot in the hash table
    }
  i--; //After the above loop ends, we want to start checking words at the spot right when we left

  for ( ;i< words.size; i++)//iterate through hash table
    {
      if(words.table[i] != NULL) //if there is a linked list....
	{
	  words.table[i]->goToFront();//start at the beginning
	  for(int l = 0; l < marker; l++) //can only execute the first time in this loop, as marker may not be 0
	    {
	      words.table[i]->goNext(); //Go to where the current position should be. Again, we want to start iterating at the last place we were in the previous loop
	    }
	  
	  marker = 0; //the above loop should not execute again
	  for(int k = 0; k < words.table[i]->getSize(); k++)//iterate through linked list, finding new words
	    {	      
	      for(int z = 0; z < counts.size(); z++)//iterate through the counts vector
		{
		  if(get_word_count(words.table[i]->getCurrent()) > counts[z])//if the new word we are looking at has been used more than the currently stored word... 
                   {
		     word_list.erase(word_list.begin()+z); //delete this word from word_list
		     counts.erase(counts.begin()+z); //delete its corresponding number in counts
		     word_list.push_back(words.table[i]->getCurrent());  //store the new word
		     counts.push_back(get_word_count(words.table[i]->getCurrent())); //store the amount of times it has been used
		    }
		  words.table[i]->goNext(); //go to the next spot in the list
		}
	    }
	}
    }
}
*/
