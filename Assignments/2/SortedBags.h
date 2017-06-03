#include <iostream>
#define SortedBags_H

template <class T>
class SortedBags{
private:
    Node<T>* head=nullptr;
    Node<T>* tail=nullptr;
    int size=0;

public:



    //****************************
    //  Member Function Definitions
    //
    //****************************

    SortedBags(){
      this->head = nullptr;
      this->tail = nullptr;
      this->size = 0;
    }

    ~SortedBags(){
      this->head = nullptr;
      this->tail = nullptr;
      delete this->head;
      delete this->tail;
    }

    void insert(T data){
      if(findItemAddress(data) != nullptr){
        Node<T>* temp = new Node<T>;
        temp = findItemAddress(data);
        temp->count_ = getOccur(data);
      }else{
/*        Node<T>* temp = new Node<T>;
        temp->data_ = data;
        temp->count_ = getOccur(data);
        temp->next_ = head;
        this->head=temp;
*/      //std::cout << findItemPosition(data) << std::endl;
      insertAt(findItemPosition(data), data);
      }
      this->size++;
    }

    void insertAt(int n, T data){
      Node<T>* prev = new Node<T>;
      Node<T>* curr = new Node<T>;
      Node<T>* temp = new Node<T>;
      curr=this->head;
      for(int i=1;i<n;i++){
        prev=curr;
        curr=curr->next_;
      }
      temp->count_ = getOccur(data);
      temp->data_=data;
      prev->next_=temp;
      temp->next_=curr;
      if(curr==nullptr){
        this->tail = temp;
      }
      if(this->head == curr){
        this->head = temp;
      }
    }

    void RM_spec(){

    }

    void RM_all(){

    }

    int get_size(){
      return this->size;
    }

    int getOccur(T data){
      Node<T>* temp = new Node<T>;
      int count = 1;
      temp=head;
      while(temp!=nullptr){
        std::cout<< std::endl<<count << std::endl << data<< std::endl  ;
        if(temp->data_ == data){
          count++;
        }
        temp=temp->next_;
      }
      return count;
    }

    bool bagEmpty(){
      if(this->head  == nullptr && this-> tail == nullptr){
        return true;
      }
      return false;
    }

    Node<T>* findItemAddress(T data){
      Node<T>* temp = new Node<T>;
      temp=head;
      while(temp!=nullptr){
        if(temp->data_ == data){
          return temp;
        }
        temp=temp->next_;
      }
      return nullptr;
    }

    int findItemPosition(T data){
      int position = 1;
      Node<T>* prev = new Node<T>;
      Node<T>* curr = new Node<T>;
      Node<T>* temp = new Node<T>;
      if((this->head == nullptr) || (this->head->data_ > data)){
        return position;
      }
      curr=this->head;
      while(curr!=nullptr){
        prev=curr;
        curr=curr->next_;
        position++;
        if((prev->data_<data && curr==nullptr) || (prev->data_<data && curr->data_ >data)){
          return position;
        }
      }
      return 1;
    }

    void display(){
      auto* temp = new Node<T>;
      temp=head;
      while(temp!=nullptr){
        std::cout << "[Data: " << temp->get_data() << " Count: "  << temp->get_count() << "] " <<  "\t";
        temp=temp->next_;
      }
    }


};
