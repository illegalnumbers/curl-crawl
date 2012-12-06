/**
 * LinkedList.h
 * CS3505
 * Authors: Tucker McKnight & Scott Stromberg
 * Date: January 27, 2011
 *
 * A class representing a linked list. Only one element
 * in the list can be "seen" at one time, and elements
 * must be traversed one at a time in either direction.
 */

#include <string>
#include <stdlib.h>
#include "LL_Node.h"

#ifndef __LINKEDLIST_H
#define __LINKEDLIST_H

using namespace std;

class LinkedList
{
 public:

  /**
   * Constructor
   */
  LinkedList()
    {
      front = NULL;
      back = NULL;
      current = NULL;
      size = 0;
    }

  /**
   * Destructor
   */
  ~LinkedList()
    {
	current = front;
	while (current != back) {
	  current = front->getNext();
	  delete &front;
	  front = current;
	}
	delete &back; // ask about this (need to delete current?)
    }

  int getCount(string word);

  /**
   * Function go to front
   * 
   * Sets the front of the list as the current
   * location being looked at.
   */
  void goToFront();

  /**
   * Function go to back
   *
   * Sets the back of the list as the current
   * location being looked at.
   */
  void goToBack();

  /**
   * Function peeknext
   *
   * Returns the value of the element after the current
   * one, but does not move the cursor to that element.
   */
  string peekNext();

  /**
   * Function peek previous
   *
   * Returns the value of the element before the current
   * one, but does not move the cursor to that element.
   */
  string peekPrevious();

  /**
   * Function go next
   *
   * Moves to the next element and returns its value.
   */
  string goNext();

  /**
   * Function go previous
   *
   * Moves to the previous element and returns its value.
   */
  string goPrevious();

  /**
   * Function remove current
   *
   * Deletes the current element in the list. Updates
   * other elements' pointers as necessary.
   */
  void removeCurrent();

  /**
   * Function get current
   *
   * Returns the value of the current element.
   */
  string getCurrent();

  /**
   * Function size
   *
   * Returns how many elements are in the list.
   */
  int getSize();

  /**
   * Function add
   *
   * Adds an element to the end of the list.
   */
  void add(string data);

  /**
   *Function addToCount
   *
   *Adds to the count(the number of times a word has been used) of a word
   */
  void addToCount(string data);

  /**
   *Function incCount
   *
   *Increments count
   */
  void incCount();

 private:
  int size;
  int count;
  LL_Node* front;
  LL_Node* back;
  LL_Node* current;

};
#endif
