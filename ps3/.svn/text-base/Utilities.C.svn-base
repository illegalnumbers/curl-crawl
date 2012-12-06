#include <algorithm>
#include <cctype>
#include <string>
#include <vector>

using namespace std;

/*Callback method for the curl reader
 *
 *Input: Pointer to data received, size of data received, pointer to buffer string
 *Output: Size of data processed
 */
int writer(char *data, size_t size, size_t nmemb, string* buffer)
{
  int result = 0;
  
  if(buffer != NULL) {
    buffer->append(data, size * nmemb);
    result = size * nmemb;
  }
  
  return result;
} 

/*Formats URLs to be consistent
 *
 *Input: URL as a string
 *Output: Formatted URL
 */
string formatURL(string URL)
{
  if(URL.find("http://") == string::npos)
  {
    if(URL.find("www.") == string::npos)
      URL = "http://www." + URL;
    else
      URL = "http://" + URL;
  }
  else
  {
    if(URL.find("www.") == string::npos)
      URL = URL.insert(7, "www.");
  }

  if(URL.at(URL.length() - 1) == '/')
    URL = URL.substr(0, URL.length() - 1);

  // Find the location of a ../, indicating to go up
  // one directory.
  int dotDotSlash = URL.find("../");

  while (dotDotSlash != string::npos) {
    for (int i = dotDotSlash; i > 0; i--) {
      if (URL[i] == '/') {
	URL.erase(i, (dotDotSlash + 2 - i));
	break;
      }
    }
    int dotDotSlash = URL.find("../");
  }

  return URL;
} 

// Temporary find in vector method
bool findInVector(vector<string>* vectorToUse, string stringToFind)
{
  for(int i = 0; i < vectorToUse->size(); i++)
    {
      if(vectorToUse->at(i).compare(stringToFind) == 0)
	return true;
    }

  return false;
}


/*Replaces an instance of a string within a string
 *
 *Input: string to search in, string to replace, string to replace with
 *Output: modified string
 */
string replaceInString(string stringToModify, string stringToReplace, string stringToReplaceWith)
{
  int numCharsToReplace = stringToReplace.length();
  int replaceIndex = stringToModify.find(stringToReplace);

  while(replaceIndex != string::npos)
    {
      // replaceIndex = replaceIndex - 1;

      stringToModify = stringToModify.erase(replaceIndex, numCharsToReplace);
      stringToModify.insert(replaceIndex, stringToReplaceWith);

      replaceIndex = stringToModify.find(stringToReplace);
    }

  return stringToModify;
} 

/*Returns the integer that is the position after a specified tag is found
 *
 *Input: A pointer to the HTML string, the starting position, the tag to find
 *Output: The position after the specified tag is found
 */
int findMatchingTag(string* HTML, int startingPos, string tag)
{
  while(startingPos < HTML->length())
    {
      while(HTML->at(startingPos) != tag[0])
	{
	  if(HTML->at(startingPos) == '<' && HTML->at(startingPos + 1) == 's' && HTML->at(startingPos+2) == 'c' && HTML->at(startingPos+3) == 'r' && HTML->at(startingPos+4) == 'i' && HTML->at(startingPos+5) == 'p' && HTML->at(startingPos+6) == 't')
	    startingPos = findMatchingTag(HTML, startingPos + 6, "/script");
	    else if(HTML->at(startingPos) == '<' && HTML->at(startingPos + 1) == 's' && HTML->at(startingPos+2) == 't' && HTML->at(startingPos+3) == 'y' && HTML->at(startingPos+4) == 'l' && HTML->at(startingPos+5) == 'e')
	      startingPos = findMatchingTag(HTML, startingPos + 5, "/style");
	    else
	      startingPos++;
	}

      startingPos++;
      int tagPos = 1;

      while(tagPos < tag.length())
	{
	  if(HTML->at(startingPos) == tag[tagPos])
	    {
	      tagPos++;
	      startingPos++;

	      if(tagPos == tag.length())
		return startingPos;
	    }
	  else
	    tagPos = tag.length();
	}
    }

  return string::npos;
} 

/*Splits string based on a given character
 *
 *Input: String to be split, character to split
 *Output: Vector of split strings
 */
vector<string> splitString(string toSplit, string splitBy)
{
  vector<string> words;
  int splitIndex = toSplit.length();

  std::transform(toSplit.begin(), toSplit.end(), toSplit.begin(), (int(*)(int))tolower);

  while(toSplit.length() > 0)
    {
      splitIndex = toSplit.find(splitBy);

      if(splitIndex != string::npos)
	{
	  string word = toSplit.substr(0, splitIndex);
	  toSplit = toSplit.substr(splitIndex + 1);

	  if(word.compare("") != 0)
	    words.push_back(word);
	}
      else {
	words.push_back(toSplit);
	break;
      }
    }

  return words;
} 
