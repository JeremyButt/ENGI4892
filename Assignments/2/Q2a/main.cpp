#include <iostream>
using namespace std;


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
    
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
