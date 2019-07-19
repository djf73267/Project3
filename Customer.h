#include <string>
#include <iostream>

using namespace std;

class Customer{
    
private:
    
    string name;
    int arrival;
    int service;
    int wait;
    
public:
    
    Customer();
    //class constructor
    
    Customer(string n, int a, int s);
    //Parametrized Constructor
    
    ~Customer();
    //Destructor
    
    string getName();
    //Function: returns name
    
    int getArrival();
    //Function: returns arrival
    
    int getService();
    //Function: returns service
    
    int getWait();
    //Function: returns wait
    
    void setName(string n);
    //Function: sets name to parameter n
    //Post: name = n
    
    void setArrival(int a);
    //Function: sets arrival to parameter a
    //Post: arrival = a
    
    void setService(int s);
    //Function: sets arrival to parameter s
    //Post: service = s
    
    void setWait(int w);
    //Function: sets wait to parameter w
    //Post: wait = w
   
    
};

 ostream & operator<<(ostream & os, Customer & c);
//Function: prints customer objects
