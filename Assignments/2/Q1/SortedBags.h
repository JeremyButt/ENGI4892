/****************************************************
*  ASSIGNMENT #2
*   SortedBags.h
*    Location for SortedBags class
*
*   Author: Jeremy Butt (201527710)
*           jeremybutt@mun.ca
****************************************************/


#include <iostream>
#define SortedBags_H

template <class T>
class SortedBags{
private:
    Node<T>* head=nullptr;  //stores Node pointer to the head of the linked list
    Node<T>* tail=nullptr;  //stores Node pointer to the tail of the linked list
    int size=0; //storesthe size of the linked list

public:
    //****************************
    //  Member Function
    //****************************

    //Constructor [Not Required]
    SortedBags(){
      this->head = nullptr;
      this->tail = nullptr;
      this->size = 0;
    }

    //Destructor
    ~SortedBags(){
      this->head = nullptr;
      this->tail = nullptr;
      delete this->head;
      delete this->tail;
    }

    // pre-condition: T data input data which is the data to be placed in the node
    // post-condition: VOID
    void insert(T data){
      //if already entry for the data find it and update count
      if(findItemAddress(data) != nullptr){
        Node<T>* temp = new Node<T>;
        temp = findItemAddress(data);
        temp->count_++;
      }else{
        //else insert new entry in a correctly sorted position
        insertAt(SortPosition(data), data);
      }
      this->size++; //increase size of list for easy access and quick reporting
    }

    // pre-condition: int n place to be placed within the linked list
    // pre-condition: T data input data which is the data to be placed in the node
    // post-condition: VOID
    void insertAt(int n, T data){
      //create temp nodes to open viewing window into linked list.
      Node<T>* prev = new Node<T>;  //previous node
      Node<T>* curr = new Node<T>;  //current node
      Node<T>* temp = new Node<T>;  //temp node
      curr=this->head;
      //loop through to location to place new entry
      for(int i=1;i<n;i++){
        prev=curr;
        curr=curr->next_;
      }
      temp->count_ = 1;  //update count
      temp->data_=data; //input data
      prev->next_=temp; //update link
      temp->next_=curr; //update link

      //update head and tail if required
      if(curr==nullptr){
        this->tail = temp;
      }
      if(this->head == curr){
        this->head = temp;
      }
    }

    // pre-condition: T data input data which is the data to be placed in the node
    // post-condition: VOID
    void RM_spec(T data){
      // Temp node
      Node<T>* temp = new Node<T>;
      temp = findItemAddress(data);
      //if multiple count in one node, decrement node count
      if(temp->count_>1){
        temp->count_--;
        this->size--;//update list size
      }else{
        //else delete node
        deleteAt(findItemPosition(data));
        this->size--; //update list size
      }
    }

    // pre-condition: T data input data which is the data to be placed in the node
    // post-condition: VOID
    void RM_all(T data){
      // loop while occurance is larger than or equal to one
      while(getOccur(data)>=1){
        RM_spec(data);  //remove one node/count at time
      }
    }

    // pre-condition: T data input data which is the data to be placed in the node
    // post-condition: VOID
    void deleteAt(int pos){
    //create temp nodes to open viewing window into linked list.
    Node<T>* curr = new Node<T>;  //current node
    Node<T>* prev = new Node<T>;  //previous node
    curr=head;
    //loop through list to get to position
    for(int i=1;i<pos;i++){
      prev=curr;
      curr=curr->next_;
    }
    // remove connection
    prev->next_=curr->next_;
  }

    // pre-condition: N/A
    // post-condition: int size of sorted bag (linked list)
    int get_size(){
      return this->size;  // return member var
    }

    // pre-condition: T data input data which is the data to be placed in the node
    // post-condition: int number of occurances of that data entry within the list
    int getOccur(T data){
      //temp node
      Node<T>* temp = new Node<T>;
      int count = 0;
      temp=head;
      //while not at end of list
      while(temp!=nullptr){
        if(temp->data_ == data){
          count++;  //if node found add to count
        }
        temp=temp->next_;
      }
      return count;
    }

    // pre-condition: N/a
    // post-condition: bool if the bag is empty
    bool bagEmpty(){
      //if head and tail are null then empty
      if(this->head  == nullptr && this-> tail == nullptr){
        return true;
      }
      return false;
    }

    // pre-condition: T data input data which is the data to be placed in the node
    // post-condition: bool if data is a node within the list/bag
    bool inBag(T data){
      //temp node
      Node<T>* temp = new Node<T>;
      temp=head;
      //while not at end of list
      while(temp!=nullptr){
        if(temp->data_ == data){
          return true;  // if found return true
        }
        temp=temp->next_;
      }
      return false; //if not return false
    }

    // pre-condition: T data input data which is the data to be placed in the node
    // post-condition: Node<T>* pointer to the found node in the linked list
    Node<T>* findItemAddress(T data){
      //temp node
      Node<T>* temp = new Node<T>;
      temp=head;
      //while not at end of list
      while(temp!=nullptr){
        if(temp->data_ == data){
          return temp;   // return pointer
        }
        temp=temp->next_;
      }
      return nullptr;
    }

    // pre-condition: T data input data which is the data to be placed in the node
    // post-condition: int position in linked list
    int findItemPosition(T data){
      //temp node
      Node<T>* temp = new Node<T>;
      int pos = 1;
      temp=head;
      //while not at end
      while(temp!=nullptr){
        if(temp->data_ == data){
          return pos; //return position
        }
        temp=temp->next_;
        pos++;
      }
      return 0;
    }

    // pre-condition: T data input data which is the data to be placed in the node
    // post-condition: int position in linked list that the node must got to be sorted properly
    int SortPosition(T data){
      int position = 1; //position
      //create temp nodes to open viewing window into linked list.
      Node<T>* prev = new Node<T>;  //previous node
      Node<T>* curr = new Node<T>;  //current node
      Node<T>* temp = new Node<T>;  //temp node
      //if at head or head is greater, return head position
      if((this->head == nullptr) || (this->head->data_ > data)){
        return position;
      }
      curr=this->head;
      //loop though list
      while(curr!=nullptr){
        prev=curr;
        curr=curr->next_;
        position++;
        //find position where data is in the middle of curr and prev
        if((prev->data_<data && curr==nullptr) || (prev->data_<data && curr->data_ >data)){
          return position;
        }
      }
      return 1;
    }

    // pre-condition: N/A
    // post-condition: VOID (displays contents of bag/list)
    void display(){
      Node<T>* temp = new Node<T>;
      temp=head;
      //while not at end
      while(temp!=nullptr){
        //print out content
        std::cout << "[Data: " << temp->data_ << " Count: "  << temp->count_ << "] " <<  "\t";
        temp=temp->next_;
      }
    }


};
