#include "binarySearch.h"
using namespace std; 

int binarySearch(int arr[],int l, int r, int id)
{
    while( l <= r)
    { 
        int x = 1 + (r-1)/2; 

    if(arr[x] == id)
        return x; 
    
    if(arr[x]< id)
        1 = x+1;

    else 
        r = x -1;   
    }
    return -1; 
}