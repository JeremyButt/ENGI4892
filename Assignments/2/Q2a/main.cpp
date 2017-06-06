#include <iostream>
#include "header.h"
using namespace std;


int main(int argc, char const *argv[]) {
  LLQueue* queue = new LLQueue();

  queue->enqueue(2);
  queue->enqueue(3);
  queue->enqueue(1);
  queue->print(); // 231
  queue->enqueue(6);
  queue->enqueue(5);
  queue->print(); //23165
  cout << queue->dequeue() << " has been dequeued! " << endl;
  cout << queue->dequeue() << " has been dequeued! " << endl;
  queue->print(); //165
  if(queue->isEmpty()){
    cout << "LLQueue is empty!" <<endl;
  }else{
    cout << "LLQueue is not empty!" <<endl;
  }
  cout << queue->dequeue() << " has been dequeued! " << endl;
  cout << queue->dequeue() << " has been dequeued! " << endl;
  cout << queue->dequeue() << " has been dequeued! " << endl;
  if(queue->isEmpty()){
    cout << "LLQueue is empty!" <<endl;
  }else{
    cout << "LLQueue is not empty!" <<endl;
  }

  return 0;
}
