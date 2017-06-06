#include <iostream>
#include "header.h"
using namespace std;


int main(int argc, char const *argv[]) {
  LLQueue* queue = new LLQueue();

  queue->enqueue(2); // add to queue
  queue->enqueue(3); // add to queue
  queue->enqueue(1);  // add to queue
  queue->print(); // 231
  queue->enqueue(6);  // add to queue
  queue->enqueue(5);  // add to queue
  queue->print(); //23165
  cout << queue->dequeue() << " has been dequeued! " << endl; //remove from queue
  cout << queue->dequeue() << " has been dequeued! " << endl; //remove from queue
  queue->print(); //165
  //find if queue is empty
  if(queue->isEmpty()){
    cout << "LLQueue is empty!" <<endl;
  }else{
    cout << "LLQueue is not empty!" <<endl;
  }
  queue->enqueue(8);  // add to queue
  queue->print();
  cout << queue->dequeue() << " has been dequeued! " << endl; //remove from queue
  cout << queue->dequeue() << " has been dequeued! " << endl; //remove from queue
  cout << queue->dequeue() << " has been dequeued! " << endl;  //remove from queue
  cout << queue->dequeue() << " has been dequeued! " << endl; //remove from queue
  queue->print();
  //find if queue is empty
  if(queue->isEmpty()){
    cout << "LLQueue is empty!" <<endl;
  }else{
    cout << "LLQueue is not empty!" <<endl;
  }

  delete queue; //done with queue so deallocate

  return 0;
}
