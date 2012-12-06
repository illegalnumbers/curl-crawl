#include <string>
#include <vector>
#include <stdlib.h>

#ifndef __WEBPAGE_H_INCLUDED__
#define __WEBPAGE_H_INCLUDED__

using namespace std;

class Webpage
{
  public:

  string toString();

  string url;
  int wordCount;
  int misspelledWordCount;
  int imageCount;
  vector<string> links;

  /**
   * Constructor
   **/

  Webpage(string url)
    {
      this->url = url;
      wordCount = 0;
      misspelledWordCount = 0;
      imageCount = 0;
    }

  Webpage(string url, int wordCount, int misspelledWordCount, int imageCount, vector<string> links)
    {
      this->url = url;
      this->wordCount = wordCount;
      this->misspelledWordCount = misspelledWordCount;
      this->imageCount = imageCount;
      this->links = links;
    }

  ~Webpage()
    {
      // Nothing to do here
    }
};

#endif
