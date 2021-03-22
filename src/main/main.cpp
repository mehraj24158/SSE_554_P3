#include <iostream>
#include "src/lib/car.hpp"
#include <thread>
#include "src/lib/operations.hpp"

int main() 
{
    std::vector<Car> cars;
    for(int i = 0; i<5; i++)
    {
        Car c;
        c.id = i;
        cars.push_back(c);
        std::cout << cars[i].id << " ";
    }
    
    for(Car c: cars)
    {
        std::cout << c.id;
    }

    std::thread engine(TireInstallerVect2, std::ref(cars));
    for(Car c: cars)
    {   
        if(&(c.engine) != NULL)
        {
            std::cout<< c.id << " Engine Present";
        }

    }


}