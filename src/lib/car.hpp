#pragma once
#include "tire.hpp"
#include "frame.hpp"
#include "engine.hpp"
#include <vector>


class Car
{   
public:
    //attributes
    vector<Tire*> tire;
    Frame frame;
    Engine engine;

    int id;

    //constructors
    Car();
};