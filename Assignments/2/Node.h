template <class T>
class Node{

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
    T get_data();
    int get_count();
    void update_count(int count);
}
