#include<iostream>
#include<string>

template <class ItemType>
struct QueueNode
{
    ItemType info;
    int priority;
    QueueNode<ItemType>* next;
};

class FullPriorityQueue
{};

class EmptyPriorityQueue
{};

template <class ItemType>
class PriorityQueue
{
    
public:
    
    PriorityQueue();
    // Class constructor.
    
    PriorityQueue(int max);
    // Parameterized Constructor
    
    ~PriorityQueue();
    // Class Destructor
    void makeEmpty();
    // Function: Initializes the queue to an empty state.
    // Post: queue is empty.
    
    bool isEmpty() const;
    // Function: Determines whether the queue is empty.
    // Post: Function value = (queue is empty)
    
    bool isFull() const;
    // Function: Determines whether the queue is full.
    // Post: Function value = (queue is full)
    
    void enqueue(ItemType item, int priority = 1);
    // Function: add item to queue
    // Post: newItem added to queue ++length
    
    void dequeue(ItemType& item);
    // Function: removes item from queue
    // Post: item removed from queue --lengrh
    
    int length();
    // Function: returns number of items in queue
    
    ItemType peek();
    // Function: returns info of front item
    
    int peekPriority();
    // Function: returns priority of front item
    
    void printQueue();
    // Function: prints items in queue
    
private:
    
    QueueNode<ItemType>* front;
    QueueNode<ItemType>* rear;
    int queueLength;
    
};

