#include "bubble.hpp"
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

//method that swaps integers
void Swap(int *a, int *b)
{
    int temp = *a; //temporary integer that points to contents of int a
    *a=*b; //a then points to contents of int b
    *b=temp; //int b then points to what is stored in the temporary integer
}
void bubbleSort(vector<Car> &cars){
    bool swap = true; //boolean value to run loop

    for (int i=0; i<cars.size()-1; i++)
    {
        for(int j=0; j<cars.size()-i-1; j++)
        {
            if (cars[j].id > cars[j+1].id)
            {
                Swap(&cars[j].id, &cars[j+1].id);
            }
        }
    }
}