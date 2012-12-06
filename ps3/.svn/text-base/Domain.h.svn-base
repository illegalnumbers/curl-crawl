#include "HashTable.h"
#include "Graph.h"

using namespace std;

class Domain
{

public:

  HashTable* hashTable;

  Domain(void) {
    this->hashTable = new HashTable(100000);
    this->graph = new Graph();
  }

  ~Domain(void);

  /**
   * Returns the number of unique pages stored in the
   * domain.
   */
  int uniquePageCount();
  
  /**
   * Returns the number of links found in the domain.
   */
  int uniqueLinkCount();
  
  /**
   * Returns the number of words misspelled on all
   * pages in the domain.
   */
  int totalMisspelledWords();
  
  /**
   * Returns the total number of images found on all
   * pages on the domain.
   */
  int totalImages();
  
  /**
   * Tells if the domain contains the page with the
   * URL specified.
   */
  bool contains(string url);
  
  /**
   * Adds a link to the domain's graph if necessary.
   *
   * Returns true if something was added, false otherwise.
   */
  bool addLink(Webpage* source, Webpage* target);
  
 private:
  Graph* graph;
  int misspellCount;
  int imageCount;
};

