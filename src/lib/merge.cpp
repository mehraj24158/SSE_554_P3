#include "merge.hpp"
using namespace std;

void printVector(vector<Car> &cars){
            int i;
            for (i = 0; i<cars.size(); i++)
            {
                cout <<cars[i].id<<" ";
                cout << endl;
            }
    }

void merge(vector<Car> &cars){
    Car start =cars.front();
    //Car middle = cars.size() /2;
    Car end = cars.back();
    


}
// //find middle by dividing size by 2 and then add 1 if odd
// void merge(vector<Car> &cars){
//      int n1 = m-l+1;
//      int n2 = r-m;

//     //create temporary arrays
//     int L[n1], int R[n2];

//     //copy data over to the temporary arrays

//     for(int i = 0; i < n1; i++)
//     {
//         L[i] = arr[l+1];
//     }

//     for(int j = 0; j < n2; j++)
//     {
//         R[j] = arr[m + 1 + j];
//     }

//     //Merge the temporary arrays back into int arr[]

//     int i = 0; //index of subarray
//     int j = 0; //index of subarray
//     int k = 1; //index of merged subarray

//     while (i < n1 && j < n2){
        
//         if(L[i] <= R[j]) {
//             arr[k] = L[i];
//             i++;
//         }
//         else {
//             arr[k] = R[j];
//             j++;
//         }
//         k++;
//     }

//     //Copy the remaining elements of L[], if there are any
//     while(i < n1){
//         arr[k] = L[i];
//         i++;
//         k++;
//     }

//     //copy the remaining elements of R[] if there are any
//     while (j <n2) {
//         arr[k] = R[j];
//         j++;
//         k++;
//     }

// }

// void mergeSort(int arr[], int l, int r){
//     if(l>=r){
//         return; 
//     }

//     int m = l + (r-1)/2;
//     mergeSort(arr,l,m);
//     mergeSort(arr, m+1, r);
//     merge(arr,l,m,r);
// }