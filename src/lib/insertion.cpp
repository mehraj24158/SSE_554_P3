#include "insertion.hpp"
using namespace std;



void insertionSort(vector<Car> &cars)
{
    int i, key, j;
    for (i = 1; i < cars.size(); i++)
    {
        key = cars[i].id;
        j = i - 1;
 
        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && cars[j].id > cars[i].id)
        {
            cars[j + 1] = cars[j];
            j = j - 1;
        }
        cars[j + 1] = cars[i];
    }
}
// void insertionSort(vector<Car> &cars)
// {
//     int i, j, temp; //integers instantiated for loops, temporary integer also instantiated to temporarily store car id values
//     //for loop that starts at i = 0 and runs while i is less than the size of the vector
//     for(i=1; i<cars.size(); i++)
//         {
//             temp = cars[i].id; //temporary int is equal to the id value at i
//             j = i-1; //j is then equal to the id value at i-1

//             //while j is greater than or equal to 0 AND the id value at j is greater than the temporary id value
//             while(j>=0 && cars[j].id >temp)
//             {
//                 cars[j+1]= cars[j]; //the next id value from j is then equal to the current id value
//                 j = j-1; //subtract 1 from j
//             } 
//             cars[j+1] = cars[i]; //let the car id at j+1 then equal to the temporary int
//         }
// }