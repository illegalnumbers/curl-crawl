/* Output
 *
 * CS3505
 * Compiled by Team Amurica (Ben Nelson, Carlos Brenneisen, Tucker McKnight, Scott Stromberg)
 * Date: Spring 11
 *
 * Outputs the result of running the webcrawler to a text file
 */
#include "output.h"
#include <vector>
#include <sstream>

  /*Method to add the statistics to a string that will be made into an html file
   *
   *Input: Vector containing top words, String containing desired word/phrase, Vector containing relevant web sites
   *int which specifies the number of sites found
   *Output: To HTML File
   */
void output::printthings(vector<string> words, vector<string> webpages, vector<string> images, vector<string> mostmispelled, string ranking, string queryword, int size, int spell, int wpi, int misperpage)
{  

  //BEN; writing a simple helper method for tag's and tag appending might be useful for this method, just a thought.
  //variables used for converting ints to strings
  string s; 
  std::stringstream out;

  //puts the opening html tags into the output string
   outputstring += "<html>";
   outputstring += "<head>";
   outputstring += "<title>Results</title>";
   outputstring += "</head>";
   outputstring += "<body>";

   //Print the number of webpages found 
   out << size; //converts the size int to a string and puts it in 's'
   s = out.str();
   outputstring +="<p>Webcrawler man found ";
   outputstring += s;
   outputstring += " webpages!";
   outputstring += "<br>";

   //Prints the ratio of words to image for the domain
   out.str(""); //clears the stream
   out << wpi;
   s = out.str();
   outputstring += "There were ";
   outputstring += s;
   outputstring += " words per image.";

   /*
   //prints the top words used on the site
   outputstring +="<p>The top words on the site you searched are: ";
   outputstring += "<br>";
   for(int i = 0; i < topwords.size(); i++)
   {
     outputstring +="<p>";
     outputstring += topwords[i];
     outputstring += "<br>";
   }
   outputstring +="<br>";
   */

   //prints the word the user searched for and all the webpages the word is found on
   outputstring +="<p>You searched for the word/phrase '";
   outputstring += queryword;
   outputstring += "'. It is found on these webpages: ";
   outputstring +="<br>";
   for(int j = 0; j < webpages.size(); j++) //Adds the web pages that have the queryword to the string that will be printed
   {
     outputstring +="<p>";
     outputstring += webpages[j];
     outputstring += "<br>";
   }
   outputstring +="<br>";

   //prints how many words were mispelled in the domain
   out.str("");
   out << spell;
   s = out.str();
   outputstring +="<p>There were ";
   outputstring += s;
   outputstring += " words mispelled within this domain";
   outputstring += "<br>";

   //prints the most often mispelled words
   outputstring+="The most often mispelled words are: ";
   outputstring +="<br>";
   for(int w = 0; w < mostmispelled.size(); w++)
   {
     outputstring +="<p>";
     outputstring += mostmispelled[w];
     outputstring += "<br>";
   }
   outputstring +="<br>";

   //prints the domain's literacy rating
   outputstring +="<p>The literacy ranking of this site is: ";
   outputstring += ranking;
   outputstring += "<br>";

   // displaywords(words);

   //Makes a collage of images that are used in the domain searched
   outputstring +="<p>Here's a collage of images that were used in the domain!";
   outputstring +="<br>";
   int rowcounter = 0; //keeps track of how many images are in the current row
   for(int k = 0; k < images.size(); k++)
   {
     outputstring += "<img src=\"";
     outputstring += images[k];
     outputstring += "\" width=200 height=200>";
     rowcounter++;
     if(rowcounter==8) //once there are 8 images in the row, start a new row (otherwise the page would be too wide)
     {
       outputstring += "<br>";
       rowcounter = 0;
     }
   }

   //inserts the ending html tags
   outputstring += "</body>";
   outputstring += "</html>";

   write();
}

  /*Method to write the file.
   *
   *Input: none (uses member variable)
   *Output: none (writes to the stream member variable)
   */

//BEN; this method should be easy to write though i don't think it neccessarily belongs in this class. i keep thinking a statistics class is in order where we
//BEN; can combine and use everything from the crawlers data. though maybe since its so late in the project thats just a pipe dream at this point. meh, somebody
//BEN; else should put in some input
void output::displaywords(Word_Count words)
{
  vector<string> wordlist; //vector that will contain all the words used
  vector<int> counts; //vector that will contain the amount of time each word is used

  words.getWordsAndCount(wordlist, counts);//pass by reference: populate wordlist and counts with all the words used and their counts

  for(int i =0; i < wordlist.size(); i++)//iterate through all the words
    {
      outputstring += wordlist[i];//add the word to the output string
      outputstring += ": ";

      string s; 
      std::stringstream out;

      out << counts[i]; //converts the count int to a string and puts it in 's'
      s = out.str();
      outputstring += s; //add the current word's count to the output string
      outputstring +="<br>"; //new line

      delete &out; //we need to delete these or else...
      delete &s;
    }
}

void output::write()
{
    outFile.open("results.html", ios::out);//opens the file

    if (!outFile) { //error checking
      cerr << "Can't open output file results.html" << endl;
      exit(1);
      // cout << (char*)&outputstring;
    }
    const char *p;
    p = outputstring.c_str();

    outFile.write(p, outputstring.size()); //writes to file
    outFile.close();//closes the file
}
