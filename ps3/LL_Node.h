#ifndef LL_NODE_H
#define LL_NODE_H

#include <string>
#include <stdlib.h>

using namespace std;

class LL_Node
{
 public:
  void setNext(LL_Node* next);
  void setPrevious(LL_Node* previous);
  void setData(string data);
  LL_Node* getNext();
  LL_Node* getPrevious();
  string getData();
  int count;

  /**
   * Constructor
   **/

  LL_Node(LL_Node* next, LL_Node* previous, string data)
    {
      this->next = next;
      this->previous = previous;
      this->data = data;
      count = 0;
    }

  ~LL_Node()
    {
      
    }

 private:
  LL_Node* next;
  LL_Node* previous;
  string data;  
};
#endif
