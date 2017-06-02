#include <iostream>
#include "SortedBags.h"

using namespace std;
using namespace SortedBags;

SortedBags(){
  Node* this->head = nullptr;
  Node* this->tail = nullptr;
  int this->size = 0;
}

~Node(){
  Node* this->head = nullptr;
  Node* this->tail = nullptr;
  delete this->head;
  delete this->tail;
}

void insert(){

}
void RM_spec(){

}
void RM_all(){

}
int get_size(){

}
int getOccur(){

}
bool bagEmpty(){

}
bool findItem(){

}
void print(){

}
