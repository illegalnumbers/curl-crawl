#include "LinkedList.h"

void LinkedList::incCount()
{
  count++;
}


void LinkedList::goToFront()
{
  current = front;
}

void LinkedList::goToBack()
{
  current = back;
}

string LinkedList::peekNext()
{
  if (current == back) {
    return "";
  }
  return current->getNext()->getData();
}

string LinkedList::peekPrevious()
{
  if (current == front) {
    return "";
  }
  return current->getPrevious()->getData();
}

string LinkedList::goNext()
{
  if (current != back) {
    current = current->getNext();
    return current->getData();
  }

  return "";
}

string LinkedList::goPrevious()
{
  if (current != front) {
    current = current->getPrevious();
    return current->getData();
  }

  return "";
}

void LinkedList::removeCurrent()
{
  // If you are at the front...
  if (current == front) {
    front = current->getNext();
    delete current;
    current = front;

    size --;

    return;
  }

  // If you are at the back...
  if (current == back) {
    back = current->getPrevious();
    delete current;
    current = back;

    size--;

    return;
  }

  // Otherwise...
  current->getPrevious()->setNext(current->getNext());
  current->getNext()->setPrevious(current->getPrevious());

  LL_Node* newCurrent = current->getNext();
  delete current;
  current = newCurrent;

  size--;
}

int LinkedList::getSize()
{
  return size;
}

int LinkedList::getCount(string data)
{
  goToFront();
  while(current->getData().compare(data)!=0)
    {
      string temp = goNext();
    }
  return current->count;
}

void LinkedList::addToCount(string data)
{
  goToFront();
  while(current->getData().compare(data)!=0)
    {
      string temp = goNext();
    }
  current->count++;
}

void LinkedList::add(string data)
{
  LL_Node* newNode = new LL_Node(NULL, back, data);

  if (size == 0) {
    front = back = current = newNode;
    size++;

    return;
  }

  back->setNext(newNode);
  back = newNode;

  size++;
}

string LinkedList::getCurrent()
{
  return this->current->getData();
}
