#include <iostream>
#include "src/lib/car.hpp"
#include <thread>
#include "src/lib/operations.hpp"
#include <algorithm>

int main() 
{
    std::vector<Car> cars;
    for(int i = 0; i<5; i++)
    {
        Car c;
        // c.price = rand() % 15000 + 20000;
        c.price = 20000*(i+1);
        c.id = i;
        cars.push_back(c);
    }
    std::thread engine(EngineInstallerVect, std::ref(cars));
    std::thread frame(FrameInstallerVect, std::ref(cars));
    std::thread tire(TireInstallerVect, std::ref(cars));

    engine.join();
    frame.join();
    tire.join();

    std::make_heap(cars.begin(), cars.end(), greater_than_car_price());
    std::cout << "The minimum element of heap is : ";  
    std::cout << cars.front().price << endl; 
    std::cout << "The maximum element of heap is : ";  
    std::cout << cars.back().price << endl; 
}