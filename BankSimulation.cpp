#include "Customer.cpp"
#include "QueueType.cpp"
#include "PriorityQueue.cpp"
#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int main(){
    
    QueueType<Customer> waitQueue;
    int numTellers;
    string command;
    ifstream file;
    file.open("inFile.txt");
    
//    double numLines = 0;
//    string line;
//
//    while (getline(file, line))
//    {
//        ++numLines;
//    }
//    numLines = numLines -1;
    
    while(file >> command)
    {
        
        if(command == "numTellers")
        {
            file >> numTellers;
        }
        else{
            
            string trash;
            int a, s;
            file >> trash;
            file >> a;
            file >> trash;
            file >> s;
            Customer temp(command, a, s);
         
            waitQueue.Enqueue(temp);
        }
    }
    file.close();
    
    
    PriorityQueue<Customer> bankQueue;
    int wait = 0;
    while((bankQueue.length() < numTellers) && (!waitQueue.IsEmpty()))
    {
        Customer temp;
        waitQueue.Dequeue(temp);
        bankQueue.enqueue(temp, (temp.getArrival() + temp.getService()));
    }
    
    while((!bankQueue.isEmpty()) || (!waitQueue.IsEmpty()))
    {
        if((bankQueue.length() < numTellers) && (!waitQueue.IsEmpty()))
        {
            Customer temp;
            waitQueue.Dequeue(temp);
            temp.setWait(wait);
            bankQueue.enqueue(temp, (temp.getArrival() + temp.getService() + temp.getWait()));
        }
        else
        {
            Customer temp;
            bankQueue.dequeue(temp);
            if(!waitQueue.IsEmpty())
            {
                Customer trash;
                trash = waitQueue.peek();
                wait = temp.getArrival() + temp.getService() + temp.getWait() - trash.getArrival();
            }
            cout << temp;
        }
    }
    double numLines = 0;
    string line;
    ifstream myfile("inFile.txt");
    
    while (getline(myfile, line))
    {
        ++numLines;
    }
    numLines = numLines - 2.0;
    cout << "Average waiting time: " << wait/numLines << endl;
    
    return EXIT_SUCCESS;
}


