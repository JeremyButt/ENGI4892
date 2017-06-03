template <class T>
class Node{

private:
    


public:
    Node<T>* next_;
    T data_;
    int count_;

    //****************************
    //  Member Function Definitions
    //
    //****************************

    // Constructor
    Node(){
    }

    //Destructor
    ~Node(){
      this->data_ = 0;
      this->count_ = 0;
      this->next_ = nullptr;
      delete this->next_;
    }

    //Member Functions
    T get_data(){
      return this->data_;
    }
    int get_count(){
      return this->count_;
    }
    void update_count(int count){
      this->count_=count;
    }

};
