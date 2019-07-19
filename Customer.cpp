#include "Customer.h"
#include <string>
#include <iostream>

Customer::Customer()
//Default constructor
//Paraemters: string name, int arrival, int service, int wait
{
    name = "";
    arrival = 0;
    service = 0;
    wait = 0;
}

Customer::Customer(string n, int a, int s)
//Parameterized Constructor
//Parameters:string name, int arrival, int service, int wait
{
    name = n;
    arrival = a;
    service = s;
    wait = 0;
}

Customer::~Customer()
//Destructor
{
    name = "";
    arrival = 0;
    service = 0;
    wait = 0;
}

string Customer::getName()
//returns name
{
    return name;
}

int Customer::getArrival()
//returns arrival time
{
    return arrival;
}

int Customer::getService()
//returns service time
{
    return service;
}

int Customer:: getWait()
//returns wait time
{
    return wait;
}

void Customer::setName(string n)
//Setting name to parameter
//Parameters: String n
{
    name = n;
}

void Customer::setArrival(int a)
//Setting arrival time to parameter
//Parameters: int a
{
    arrival = a;
}

void Customer::setService(int s)
//Setting service time to parameter
//Parameters: int s
{
    service = s;
}

void Customer::setWait(int w)
//Setting wait time to parameter
//Parameters: int w
{
    wait = w;
}

ostream & operator<<(ostream & os, Customer & c)
//Print function that prints customer object to cout
//Parameters: output stream, customer& c
{
    os << c.getName() << " " << c.getWait() << " wait service " << (c.getService() + c.getArrival() + c.getWait()) <<endl;

    return os;
}
