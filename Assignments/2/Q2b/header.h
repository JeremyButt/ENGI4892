#include <iostream>
using namespace std;

struct Node{
  int data;
  struct Node* next;
};

class Queue {
public:
   // c'tor and d'tor
   Queue() { }
   virtual ~Queue() { }
    // pre-condition:  given an integer 'e'
    // post-condition: the queue will contain 'e' at one end of the data structure
    virtual void enqueue(int e) = 0;
    // pre-condition:  queue must not be empty
    // post-condition: the integer at the other end of the data structure is returned,
    //                 and also removed from the structure
    virtual int dequeue() = 0;
    virtual bool isEmpty() const = 0;
    virtual void print() const = 0;
};

class LLQueue : public Queue{

public:
  Node* rear_;  // node to point to rear
  Node* front_; // node to point to the front

  // c'tor and d'tor
  LLQueue(){
    this->rear_ = nullptr;  //initialize to nullptr
    this->front_ = nullptr; //initialize to nullptr
  }

  ~LLQueue(){
    this->rear_ = nullptr; //set to nullptr
    this->front_ = nullptr; //set to nullptr
    delete this->rear_; //delete
    delete this->front_;  //delete
  }

  // pre-condition:  given an integer 'e'
  // post-condition: the queue will contain 'e' at one end of the data structure
  virtual void enqueue(int e) override{
    Node* temp = new Node; // temp node
    temp->data = e; //set data
    temp->next = nullptr; // set next
    //if front null, queue empty (node is new front)
    if(this->front_ == nullptr){
      this->front_ = temp;  // temp is new front
    }else{
      this->rear_->next = temp; //place behind front
    }

    this->rear_ = temp; //update rear to be new node
  }

  // pre-condition:  queue must not be empty
  // post-condition: the integer at the other end of the data structure is returned,
  //                 and also removed from the structure
  virtual int dequeue() override{
    int tempData; //temp data var
    Node* temp = new Node;  //temp node
    // if front is null then empty
    if(this->front_ == nullptr){
      cout << "The LLQueue is empty!" << endl;
      return 0; // nothing to dequeue
    }else{
      temp = this->front_;  //temp to front
      this->front_ = this->front_->next;  // move front to be next in queue
      tempData = temp->data;  // get the data that was dequeued
      delete temp;  // delete temp node
      return tempData;  // return tempdata
    }
  }

  // pre-condition:  queue must not be empty
  // post-condition: return size of queue
  int getSize(){
    // front is empty, queue is empty
    if(this->front_ == nullptr){
      return 0;
    }
    Node* temp = this->front_; // temp node set to front
    int count = 0;
    //go through queuue counting all nodes
    while(temp != nullptr){
      count++;
      temp = temp->next;
    }
    return count; // return final count
  }

  // pre-condition:  queue must not be empty
  // post-condition: Bool to show if queue is empty or not
  virtual bool isEmpty() const override{
    if(this->front_ == nullptr){
      return true;
    }else{
      return false;
    }
  }

  // pre-condition:  queue must not be empty
  // post-condition: prints out the contents of hte queue.
  virtual void print() const override{
    Node* temp = new Node;  // temp node
    temp = this->front_;  // set temp to the front node
    // if front is null then the queue is empty
    if(this->front_ == nullptr){
      cout << "The LLQueue is empty!" << endl;
    }else{
      cout << "[ ";
      //while not at end
      while(temp!=nullptr){
        // print out the data
        cout << temp->data << " ";
        temp = temp->next;
      }
      cout << "]" << endl;
    }
  }
};
