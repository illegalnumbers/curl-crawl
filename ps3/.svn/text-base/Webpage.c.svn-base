#include "Webpage.h"
#include <sstream>
#include <iostream>

string Webpage::toString()
{
  string output = "";
  stringstream ss;
  
  output += "URL: " + url + "\n";
  ss.str("");
  ss << wordCount;
  output += "Word count: " + ss.str() + "\n";
  ss.str("");
  ss << misspelledWordCount;
  output += "Misspelled word count: " + ss.str() + "\n";
  ss.str("");
  ss << imageCount;
  output += "Image count: " + ss.str() + "\n";
  output += "Links: \n";
  
  for(unsigned int i = 0; i < links.size(); i++)
  {
    output += " " + links[i] + "\n";
  }
  
  return output;
}
