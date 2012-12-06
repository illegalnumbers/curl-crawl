#include "Domain.h"

int Domain::uniquePageCount() {
  return this->hashTable->getSize();
}

int Domain::uniqueLinkCount() {
	return this->graph->getSize();
}

int Domain::totalMisspelledWords() {
	return this->misspellCount;
}

int Domain::totalImages() {
	return this->imageCount;
}

bool Domain::contains(string url) {
  return this->hashTable->contains(url);
}

bool Domain::addLink(Webpage* source, Webpage* target) {
  // Flag whether or not the page is already found on the domain.
  // If it hasn't been found already, return true so that the 
  // crawler knows to add the page to the queue of pages to crawl.
  bool crawlTarget = false;
  
  if (!this->hashTable->contains(target->url)) {
    crawlTarget = true; // If it's not in the hash table, 
    // it hasn't been found yet.
    this->hashTable->add(target->url);
  }
  
  // Increment domain's image count. (Note that it isn't necessary to
  // add the source page's image count, because it's already been added 
  // when its own source page was crawled and it was a target.
  this->imageCount += target->imageCount;
  
  // Increment domain's misspelled word count.
  this->misspellCount += target->misspelledWordCount;
  
  Link newLink = Link(source, target);
  this->graph->addLink(newLink); // Add the discovered link to the graph.
  
  return crawlTarget;
}
