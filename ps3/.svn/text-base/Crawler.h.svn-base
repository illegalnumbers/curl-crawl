/*Crawler 
 *
 *CS3505
 *Compiled by: Team Amurica
 *Date: Spring 11
 *
 *Header file for the crawler class
 */

#ifndef __CRAWLER_H
#define __CRAWLER_H 

#include <string> 
#include <stdlib.h> 
#include <vector>
#include "Dictionary.h"
#include "Domain.h"
#include "Webpage.h"
#include <queue>
#include <list>

using namespace std;

class Crawler {
 public:
  queue<string, list<string> >* URLs; // The list of URLs to process
  Dictionary* dictionary;
  Domain* domain;
  Webpage* currentWebPage;

  //initialize
  Crawler(queue<string, list<string> >* URLs)
    {
      this->URLs = URLs;
      domain = new Domain();
    }

  //destructor
  ~Crawler()
    {

    }

  /*Method which handles all of the crawling events
   *This method will call read() on the first element of the URLs vector
   *It will call parse() after the HTML is read in successfully
   *It will then remove the URL that was just read from the URLs vector
   *
   *Input: none
   *Output: none
   */
  void crawl();

  /*Method to handle reading in the HTML from a given URL
   *
   *Input: A URL as a string, a pointer to a string variable, which will hold the HTML
   *Output: True if the webpage was read successfully, false otherwise
   */
  bool read(string URL, string* HTML);
  
  /*Method to handle parsing the HTML code
   *This method will find <a href> tags, <img> tags, spell check words and count words
   *
   *Input: A string containing a URL
   *Output: none
   */
  void parse(string* HTML);

   /*Callback method for the curl reader
   *
   *Input: None
   *Output: Size of data processed
   */
  //int writer(char *data, size_t size, size_t nmemb, string *HTML);

};

#endif
