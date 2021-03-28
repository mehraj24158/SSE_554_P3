#include "binarySearch.hpp"
using namespace std; 

int binarySearch(vector<Car> cars, int id)
 {
     int l = cars.front().id;
     int r = cars.back().id;

     while( l <= r)
     { 
        int x = 1 + (r-1)/2; 

        if(cars[x].id == id)
            return x; 

        if(cars[x].id< id)
            l = x+1;

        else 
            r = x -1;   
    }
    return -1; 
 }
