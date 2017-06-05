#include <iostream>
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

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
