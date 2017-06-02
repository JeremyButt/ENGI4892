class Node<class T>{

private:
    T data_;
    int count_;
    Node* next_;
    Node* prev_;

public:
    // Constructor
    Node(T data, Node* next, Node* prev);

    //Destructor
    ~Node();

    //Member Functions
    get_data();
    get_count();
    update_count();
}
