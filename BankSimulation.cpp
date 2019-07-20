#include "Customer.cpp"
#include "QueType.cpp"
#include "PriorityQueue.cpp"
#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int main(){
    
    QueType<Customer> waitQueue;
    int numTellers;
    string command;
    ifstream file;
    file.open("input.txt"); //opening file
    
    
    while(file >> command)//loop
    {
        
        if(command == "numTellers")//conditional
        {
            file >> numTellers;
        }
        else{
            
            string line;
            int a, s;
            file >> line;
            file >> a;
            file >> line;
            file >> s;
            Customer temp(command, a, s);
            waitQueue.Enqueue(temp);
        }
    }
    file.close();
    
    
    PriorityQueue<Customer> bQueue;
    int totalWait = 0;
    while((bQueue.length() < numTellers) && (!waitQueue.IsEmpty()))//loop
    {
        Customer temp;
        waitQueue.Dequeue(temp);//dequeue from wait queue
        int AS = temp.getArrival() + temp.getService();
        bQueue.enqueue(temp, AS);//enqueue to bQueue
    }
    
    while((!bQueue.isEmpty()) || (!waitQueue.IsEmpty()))//loop
    {
        if((bQueue.length() < numTellers) && (!waitQueue.IsEmpty()))//conditional
        {
            Customer temp;
            waitQueue.Dequeue(temp);//dequeue from wait queue
            temp.setWait(totalWait);
            int ASW = temp.getArrival() + temp.getService() + temp.getWait();
            bQueue.enqueue(temp, ASW);//enqueue to bQueue
        }
        else
        {
            Customer temp;
            bQueue.dequeue(temp);//dequeue from bQueue
            if(!waitQueue.IsEmpty())//conditional
            {
                Customer frontItem = waitQueue.peek();
                totalWait = temp.getArrival() + temp.getService() + temp.getWait() - frontItem.getArrival();
            }
            cout << temp;
        }
    }
    double numLines = 0;
    string line;
    ifstream myfile("input.txt");
    
    while (getline(myfile, line))//loop
    {
        ++numLines;
    }
    numLines = numLines - 2.0;
    double average = totalWait/numLines;
    cout << "Average waiting time: " << average << endl;
    
    return EXIT_SUCCESS;
}


