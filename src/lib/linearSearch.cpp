#include "linearSearch.hpp"
using namespace std; 


int linear_search(vector<Car> cars, int id)
{  
    for (int i = 0; i<cars.size(); i++)
    {
        if(cars[i].id == id)
            return i; 
    }
    return -1; 
}



