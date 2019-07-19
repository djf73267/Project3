#include "QueueType.h"

template<class ItemType>
QueueType<ItemType>::QueueType()
//default constructor
//Post: cap, front, and rear is initialized
{
    cap = 501;
    items = new ItemType[cap];
    front = rear = cap - 1;
}

template<class ItemType>
QueueType<ItemType>::QueueType(int max)
//parametierized constructor
//Post: cap, front, and rear is initialized
{
    cap = max + 1;
    items = new ItemType[cap];
    front = rear = cap - 1;
}


template<class ItemType>
QueueType<ItemType>::~QueueType()
//destructor
// Post: calls MakeEmptyFunction
{
    MakeEmpty();
}

template<class ItemType>
void QueueType<ItemType>::MakeEmpty()
// Post: Front and Rear has been reset to the empty state.
{
    front = rear = cap - 1;
}

template<class ItemType>
bool QueueType<ItemType>::IsEmpty() const
//determines if the queue is Empty
//Post: returns true if front is equal to the rear
{
    return (front == rear);
}


template<class ItemType>
bool QueueType<ItemType>::IsFull() const
//determines if the queue is full
//Post: returns true if the remainder of the rear is equal to the front
{
    return ((rear + 1) % cap == front);
}

template<class ItemType>
void QueueType<ItemType>::Enqueue(ItemType newItem)
// Post: If queue is not full newItem is checked whether the priority is higher than previous node then added
//       increment length ++
//       otherwise a IsFull exception is thrown.
{
    if(!IsFull())
    {
        rear = (rear + 1) % cap;
        items[rear] = newItem;
    }
    else
    {
        throw FullQueue();
    }
}

template<class ItemType>
void QueueType<ItemType>::Dequeue(ItemType & item)
// Post: If List is empty IsEmpty exception is thrown
//       else remove item from list and decrement length
{
    if(!IsEmpty())
    {
        front = (front + 1) % cap;
        item = items[front];
    }
    else
    {
        throw EmptyQueue();
    }
}

template<class ItemType>
int QueueType<ItemType>::length()
//Post: returns length based on conditional statement
{
    if(IsFull())
    {
        return cap - 1;
    }
    else if(IsEmpty())
    {
        return 0;
    }
    else{
        return (cap + (rear - front)) % cap;
    }
}

template<class ItemType>
ItemType QueueType<ItemType>::peek()
// Post: if empty throw exception
//       return temp
{
    return items[(front + 1) % cap];
}

