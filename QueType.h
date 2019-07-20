class FullQueue{};
class EmptyQueue{};

template <class ItemType>
class QueType{
    
public:
    
    QueType();
    //class constructor
    
    QueType(int max);
    //Parameterized class constructor
    
    ~QueType();
    //Destructor
    
    void MakeEmpty();
    // Function: Initializes the queue to an empty state.
    // Post: queue is empty.
    
    bool IsEmpty() const;
    // Function: Determines whether the queue is empty.
    // Post: Function value = (queue is empty)
    
    bool IsFull() const;
    // Function: Determines whether the queue is full.
    // Post: Function value = (queue is full)
    
    void Enqueue(ItemType newItem);
    // Function: add item to queue
    // Post: newItem added to queue
    
    void Dequeue(ItemType & item);
    // Function: removes item from queue
    // Post: item removed from queue
    
    int length();
    // Function: returns number of items in queue
    
    ItemType peek();
     // Function: returns info of front item
    
private:
    
    int front;
    int rear;
    ItemType * items;
    int cap;
    
};//QueType

