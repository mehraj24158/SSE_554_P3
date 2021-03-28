#include <iostream>
#include <thread>
#include <algorithm>
#include "src/lib/car.hpp"
#include "src/lib/operations.hpp"
#include "src/lib/bubble.hpp"
#include "src/lib/insertion.hpp"
#include "src/lib/merge.hpp"

int main() 
{
    std::vector<Car> cars;
    for(int i = 0; i<10; i++)
    {
        Car c;
        // c.price = rand() % 15000 + 20000;
        c.price = 20000*(i+1);
        c.id = rand() % 10 + i;
        cars.push_back(c);
    }
    std::thread engine(EngineInstallerVect, std::ref(cars));
    std::thread frame(FrameInstallerVect, std::ref(cars));
    std::thread tire(TireInstallerVect, std::ref(cars));

    engine.join();
    frame.join();
    tire.join();

    // std::make_heap(cars.begin(), cars.end(), greater_than_car_price());
    // std::cout << "The minimum element of heap is : ";  
    // std::cout << cars.front().price << endl; 
    // std::cout << "The maximum element of heap is : ";  
    // std::cout << cars.back().price << endl; 
    for(Car c: cars)
    {
        std::cout << c.id << " ";
    }

    std::cout << endl;

    // bubbleSort(cars);
    // for(Car c: cars)
    // {
    //     std::cout << c.id << " ";
    // }

    // insertionSort(cars);
    // for(Car c: cars)
    // {
    //     std::cout << c.id << " ";
    // }
    std::cout << "hello world";
    // mergeSort(cars, cars.front(), cars.back());

    for(Car c: cars)
    {
        std::cout << c.id << " ";
    }

    std::cout << "hello world";

    std::cout << cars.size() << "Car Vect Size ";


}