#include "PriorityQueue.h"

using namespace std;


template<class ItemType>
PriorityQueue<ItemType>::PriorityQueue()
// default argument constructor
// Post: length initialized front AND rear pointer set to null
{
    queueLength = 0;
    front = NULL;
    rear = NULL;
}



template<class ItemType>
PriorityQueue<ItemType>::~PriorityQueue()
// destructor
// Post: calls MakeEmptyFunction
{
    makeEmpty();
}

template<class ItemType>
void PriorityQueue<ItemType>::makeEmpty()
//Iterative loop until front is NULL delete front pointer set rear to NULL
{
    QueueNode<ItemType> * temp = front;
    while(front != NULL) //loop
    {
        front = front -> next;
        delete temp;
    }
    rear = NULL;
}

template<class ItemType>
bool PriorityQueue<ItemType>::isEmpty() const
// Post: Returns true if front is null; false otherwise.
{
    return (front == NULL);
}


template<class ItemType>
bool PriorityQueue<ItemType>::isFull() const
// Post: Returns true if the Length is equal to cap; false otherwise.
{
    QueueNode<ItemType> * test;
    try
    {
        test = new QueueNode<ItemType>;
        delete test;
        return false;
    }
    catch(bad_alloc exception)
    {
        return true;
    }
}

template<class ItemType>
void PriorityQueue<ItemType>::enqueue(ItemType newitem, int priority)
// Post: If queue is not full newItem is checked whether the priority is higher than previous node then added
//       increment length ++
//       otherwise a FullList exception is thrown.
{
    if(isFull())
    {
        throw FullPriorityQueue();
    }
    else
    {
        QueueNode<ItemType> * temp;
        QueueNode<ItemType> * queNode;
        temp = new QueueNode<ItemType>;
        temp->info = newitem;
        temp->priority = priority;
        
        if(isEmpty())
        {
            temp -> next = NULL;
            front = rear = temp;
        }
        else
        {
            QueueNode<ItemType> * holder;
            queNode = front;
            holder = front;
            bool found = false;
            
            if(priority < queNode -> priority)
            {
                temp -> next = queNode;
                front = temp;
            }
            else
            {
                while(queNode != NULL)
                {
                    if(priority < queNode -> priority)
                    {
                        temp -> next = queNode;
                        holder -> next = temp;
                        found = true;
                        break;
                    }
                    holder = queNode;
                    queNode = queNode -> next;
                }
                if(!found)
                {
                    temp -> next = NULL;
                    rear -> next = temp;
                    rear = temp;
                }
            }
        }
        queueLength++;
    }
}

template<class ItemType>
void PriorityQueue<ItemType>::dequeue(ItemType & item)
// Post: If List is empty EmptyList exception is thrown
//       else remove item from list and decrement length
{
    if(isEmpty())
    {
        throw EmptyPriorityQueue();
    }
    else
    {
        QueueNode<ItemType> * temp = front;
        ItemType itemAlt = front -> info;
        front = front -> next;
        if(front == NULL)
        {
            rear = NULL;
        }
        free(temp);
        queueLength--;
        item = itemAlt;
    }
}

template<class ItemType>
int PriorityQueue<ItemType>::length()
// Post: return number of elements in the queue
{
    return queueLength;
}

template<class ItemType>
ItemType PriorityQueue<ItemType>::peek()
// Post: if empty throw exception
//       return info of front node
{
    if(isEmpty())
    {
        throw EmptyPriorityQueue();
    }
    else{
       
        return front -> info;
    }
}

template<class ItemType>
int PriorityQueue<ItemType>::peekPriority()
// Post: if empty throw exception
//       else return priority of the front node
{
    if(isEmpty())
    {
        throw EmptyPriorityQueue();
    }
    else
    {
        return front ->priority;
    }
}

template<class ItemType>
void PriorityQueue<ItemType>::printQueue()
// Post: if empty throw exception
//       else temp node will iterate and print info till null
{
    QueueNode<ItemType> * temp = front;
    if (isEmpty())
    {
        throw EmptyPriorityQueue();
    }
    else
    {
        while(temp != NULL)
        {
            cout << temp -> info << " ";
            temp = temp -> next;
        }
    }
}
