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
  Node* rear_;
  Node* front_;
  LLQueue(){
    this->rear_ = nullptr;
    this->front_ = nullptr;
  }

  ~LLQueue(){
    this->rear_ = nullptr;
    this->front_ = nullptr;
    delete this;
  }

  virtual void enqueue(int e) override{
    Node* temp = new Node;
    temp->data = e;
    temp->next = nullptr;
    if(this->front_ == nullptr){
      this->front_ = temp;
    }else{
      this->rear_->next = temp;
    }

    this->rear_ = temp;
  }

  virtual int dequeue() override{
    int tempData;
    Node* temp = new Node;
    if(this->front_ == nullptr){
      cout << "The LLQueue is empty!" << endl;
      return 0;
    }else{
      temp = this->front_;
      this->front_ = this->front_->next;
      tempData = temp->data;
      delete temp;
      return tempData;
    }
  }

  virtual bool isEmpty() const override{
    if(this->front_ == nullptr){
      return true;
    }else{
      return false;
    }
  }

  virtual void print() const override{
    Node* temp = new Node;
    temp = this->front_;
    if(this->front_ == nullptr){
      cout << "The LLQueue is empty!" << endl;
    }else{
      cout << "[ ";
      while(temp!=nullptr){
        cout << temp->data << " ";
        temp = temp->next;
      }
      cout << "]" << endl;
    }
  }
};
