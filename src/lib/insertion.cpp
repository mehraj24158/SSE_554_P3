#include "insertion.hpp"
using namespace std;

//method that prints out the content of car ids in the vector
void printVector(vector<Car> &cars){
            //runs while i is less than the size of the vector
            for (int i = 0; i<cars.size(); i++) 
            {
                cout <<cars[i].id<<" ";
                cout << endl;
            }
    }

void insertionSort(vector<Car> &cars){
    int i, j, temp; //integers instantiated for loops, temporary integer also instantiated to temporarily store car id values
    //for loop that starts at i = 0 and runs while i is less than the size of the vector
    for(i=1; i<cars.size(); i++)
        {
            temp = cars[i].id; //temporary int is equal to the id value at i
            j = cars[i-1].id; //j is then equal to the id value at i-1

            //while j is greater than or equal to 0 AND the id value at j is greater than the temporary id value
            while(j>temp)
            {
                cars[i+1].id = cars[j].id; //the next id value from j is then equal to the current id value
                j = j-1; //subtract 1 from j
            } 
            cars[j+1].id = temp; //let the car id at j+1 then equal to the temporary int
        }
}