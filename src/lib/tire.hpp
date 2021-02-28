#pragma once
#include <iostream>
using namespace std; 

// We could probably put all of the component classes under a seperate
// folder just to clean up our file

// Can we change this class to a single tire and then have the car
// class contain a vector of tire objects. This will allow the factory to 
// access the number of tires within the car object itself, without 
// needing access to the tires class within the car class. 
class Tire{ 
public: 
    // attributes
    int size; // inches
    string modelName; 
    string completionStatus;

    // constructors
    Tire();
    // Tire(int s= 0, string mod =" ",string comStat=" ");

    // get methods
    int get_size();
    string get_model();
    string returnCompleteStatus(); 

    // set methods
    void set_size(int s);
    void set_model(string mod);
    void setCompleteStatus(string comStat);
};

