/****************************************************
*  ASSIGNMENT #2
*   Node.h
*    Location for Node class
*
*   Author: Jeremy Butt (201527710)
*           jeremybutt@mun.ca
****************************************************/



template <class T>
class Node{



public:
    Node<T>* next_; //store pointer to next list node
    T data_;  // data within the node
    int count_; //count of the data entries within the node

    //****************************
    //  Member Function Definitions
    //
    //****************************

    // Constructor [Not required]
    Node(){
    }

    //Destructor
    ~Node(){
      this->data_ = 0;
      this->count_ = 0;
      this->next_ = nullptr;
      delete this->next_;
    }
};
