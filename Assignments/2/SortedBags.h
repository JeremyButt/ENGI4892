class SortedBags{
private:
    Node* head;
    Node* tail;
    int size;

public:
    //Constructor
    SortedBags();

    //Destructor
    ~SortedBags();

    //Member Functions
    void insert();
    void RM_spec();
    void RM_all();
    int get_size();
    int getOccur();
    bool bagEmpty();
    bool findItem();
    void print();
}
