/*Output 
 *
 *CS3505
 *Compiled by: Team Amurica (Ben Nelson, Carlos Brenneisen, Tucker McKnight, Scott Stromberg)
 *Date: Spring 11
 *
 *Header file for the output class
 */

#ifndef __OUTPUT_H
#define __OUTPUT_H 

#include <string> 
#include <iostream>
#include <fstream>
#include <stdlib.h> 
#include <vector>
#include "Word_Count.h" 
using namespace std;

class output{
 public:
  //initialize
  output()
    {
      ofstream outFile("results.html");
    }

  //destructor
  ~output()
    {

    }


  //BEN; should this method take in a webpage class and use that to display? or a helper method to do all the work or something? this seems like a ridiculously ungangly 
  //BEN; parameter line...
  /*Method to get the results of the webcrawler and format them for outputting purposes
   *
   *Input: The top words found, a word that was searched for, webpages containing that word, a list of images, the total number of webpages found, and the # of mispelled words
   *Output: To an HTML file
   */
  void printthings(vector<string> words, vector<string> webpages, vector<string> images, vector<string> mostmispelled, string ranking, string queryword, int size, int spell, int wpi, int misperpage);

 private:
  ofstream outFile; //the stream used for outputting the html file
  string outputstring; //the string that will be outputted to the file

  /*Method to display all the words used and the number of times they are used
   *
   *Input: Word Count object - contains a hash table with all the words
   *Output: Statistics
   */
  void displaywords(Word_Count words);

  /*Method to handle opening and closing of the file
   *
   *Input: none
   *Output: none
   */
  void write();
};

#endif
