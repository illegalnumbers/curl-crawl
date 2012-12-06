#include "HashTable.h"

void HashTable::add(string data)
{
  int location = hash(data);
  if (!contains(data)) {

  if (table[location] == NULL) {
    table[location] = new LinkedList();
  }

   table[location]->add(data); 
   table[location]->addToCount(data);
   size++;
  }
   table[location]->addToCount(data);
}

int HashTable::getWordCount(string word)
{
  int location = hash(word);
  if(table[location] != NULL)
    {
     return table[location]->getCount(word);
    }
  else
    return 0;
}

void HashTable::remove(string data)
{
  int location = hash(data);
  if (table[location] != NULL) {

    table[location]->goToFront();
    for (int i = 0; i < table[location]->getSize(); i++) {
      if (table[location]->getCurrent().compare(data) == 0) {
	table[location]->removeCurrent();
	size--;
	return;
      }
      table[location]->goNext();
    }
  }
}

bool HashTable::contains(string data)
{
  unsigned int location = hash(data);
  if (table[location] != NULL) {

    table[location]->goToFront();
    for (int i = 0; i < table[location]->getSize(); i++) {
      if (table[location]->getCurrent().compare(data) == 0) {
	return true;
      }
      table[location]->goNext();
    }
  }
  return false;
}

int HashTable::getSize()
{
  return size;
}

/**
 * Function hash
 * 
 * This method will return an integer that is generated from
 * the provided string.
 * 
 * The algorithm for this hash function was
 * created by Dan Bernstein, which he posted in a newsgroup
 * called comp.lang.c.
 */
int HashTable::hash(string data)
{
  unsigned long hash = 37;
  for (int i = 0; i < data.length(); i++) {
    hash = hash * (int)data[i];
  }

  return hash % (arrayLength);
}
