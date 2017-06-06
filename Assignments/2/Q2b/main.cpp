#include <iostream>
#include "header.h"
using namespace std;

// Pure virtual abstract base class representing a minimal stack
class Stack {
public:
    // c'tor and d'tor
    Stack() { }
    virtual ~Stack() { }
    // pre-condition:  given an integer 'e'
    // post-condition: the stack will contain 'e' at the top of the data structure
    virtual void push(int e) = 0;
    // pre-condition:  stack must not be empty
    // post-condition: the integer at the top of the data structure is returned,
    //                 and also removed from the structure
    virtual int pop() = 0;
    virtual bool isEmpty() const = 0;
    virtual void print() const = 0;
};

class QueueStack : public Stack{
private:
    LLQueue* IN;  // queue to store the stack
    LLQueue* OUT; // temp queue for popping

public:
    // c'tor and d'tor
    QueueStack(){
      this->IN = new LLQueue(); // initialize
      this->OUT = new LLQueue(); // initialize
    }

    ~QueueStack(){
      this->IN = nullptr; // nullptr
      this->OUT = nullptr;  // nullptr
      delete this->IN;  //deallocate
      delete this->OUT; //deallocate
    }

    virtual void push(int e) override{
      //put e into node in queue
      this->IN->enqueue(e);
    }

    // pre-condition:  stack must not be empty
    // post-condition: the integer at the top of the data structure is returned,
    //                 and also removed from the structure
    virtual int pop() override{
      Node* temp = new Node; //temp node
      int var = 0;  //temp var
      temp = this->IN->front_;  // set temp to front
      // loop and move all nodes but the last node to temp queue
      while(this->IN->getSize() > 1){
        this->OUT->enqueue(this->IN->dequeue());
        temp = this->IN->front_;  // go to the front of the new IN queue
      }
      var = this->IN->dequeue();  //  set var to the last dequeued node data.
      this->IN = this->OUT; // Copy OUT temp to IN to record the "stack"
      this->OUT = new LLQueue();  // reinitialize the OUT queue to empty
      return var; // return the last dequeued node data
    }

    virtual bool isEmpty() const override{
      return this->IN->isEmpty(); // check if the IN queue is
    }

    virtual void print() const override{
      this->IN->print();  // print out the queue
    }
};

int main(int argc, char const *argv[]) {

  QueueStack* stack = new QueueStack(); // new queue stack
  stack->push(4); //push onto stack
  stack->push(3); //push onto stack
  stack->push(2); //push onto stack
  stack->push(1); //push onto stack

  stack->print(); // print out the stack

  cout << stack->pop() << " has been popped! " << endl; // pop off top node
  cout << stack->pop() << " has been popped! " << endl; // pop off top node
  cout << stack->pop() << " has been popped! " << endl; // pop off top node
  stack->print(); // print out the stack

  stack->push(6); //push onto stack
  stack->push(8); //push onto stack
  stack->print(); // print out the stack
  // check if stack is empty
  if(stack->isEmpty()){
    cout << "QueueStack is empty!" <<endl;
  }else{
    cout << "QueueStack is not empty!" <<endl;
  }
  cout << stack->pop() << " has been popped! " << endl; // pop off top node
  cout << stack->pop() << " has been popped! " << endl; // pop off top node
  cout << stack->pop() << " has been popped! " << endl; // pop off top node
  stack->print(); // print out the stack
  // check if stack is empty
  if(stack->isEmpty()){
    cout << "QueueStack is empty!" <<endl;
  }else{
    cout << "QueueStack is not empty!" <<endl;
  }
  delete stack; // deallocated stack
  return 0;
}
