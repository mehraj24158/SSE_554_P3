#include "linearSearch.hpp"
using namespace std; 


int search(int arr[], int n, int id)
{  
    for (int i = 0; i<n; i++)
    {
        if(arr[i] == id)
            return i; 
    }
    return -1; 
}



