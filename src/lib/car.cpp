#include "car.hpp"

Car::Car()
{}


bool greater_than_car_price::operator()(Car* a, Car* b)
{
    if(a->price > b->price)
    {
        return true;
    }
    else   
    {
        return false;
    }
};