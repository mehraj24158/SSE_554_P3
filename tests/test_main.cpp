#include "gtest/gtest.h"
#include <thread>
#include "src/lib/car.hpp"
#include "src/lib/engine.hpp"
#include "src/lib/frame.hpp"
#include "src/lib/tire.hpp"
#include "src/lib/operations.hpp"
#include "stack"

// // For example vector of 5 cars randomly generated
// // loop through each car and a seperate vector containing each thread will install the neccessary part
// //  
// // Details:
// // First create a vector with cars
// // second create threads that point to functions which installs a particular car part
// // Third Loop through the vector of cars and, within the loop, pass the car object
// // Cars should come out complete and can be validated easily. 

TEST(EmptyCar, EngineInstall){
    Car one;
    Car* P = &one;
    std::thread engine(EngineInstaller, std::ref(P));
    engine.join();
    ASSERT_TRUE(&P->engine != NULL);
    // ASSERT_EQ("Hello", "Hello");
};

TEST(EmptyCar, FrameInstall){
  
    Car one;
    Car* P = &one;
    std::thread frame(FrameInstaller, std::ref(P));
    frame.join();
    ASSERT_TRUE(&P->frame != NULL);
};

TEST(EmptyCar, TireInstall){
    Car one;
    Car* P = &one;
    std::thread tire(TireInstaller, std::ref(P));
    tire.join();
    ASSERT_TRUE(&P->tire!= NULL);
    ASSERT_TRUE(P->tire.size()==4) << P->tire.size() << " Number of tires";
};

TEST(EmptyCar, CompleteInstall){
    Car one;
    Car* P = &one;
    std::thread engine(EngineInstaller, std::ref(P));
    std::thread frame(FrameInstaller, std::ref(P));
    std::thread tire(TireInstaller, std::ref(P));
    engine.join();
    frame.join();
    tire.join();
    ASSERT_TRUE(&P->engine != NULL);
    ASSERT_TRUE(&P->frame != NULL);
    ASSERT_TRUE(&P->tire!= NULL);
    ASSERT_TRUE(P->tire.size()==4) << P->tire.size() << " Number of tires";
};

TEST(EmptyCar, VectorCompleteInstall){
    std::vector<Car*> cars;

    for(int i = 0; i<10; i++)
    {
        Car one;
        Car* P = &one;
        cars.push_back(P);
    }
    
    std::thread engine(EngineInstallerVect, std::ref(cars));
    std::thread frame(FrameInstallerVect, std::ref(cars));
    std::thread tire(TireInstallerVect, std::ref(cars));

    engine.join();
    frame.join();
    tire.join();

    for(Car* P: cars)
    {
        ASSERT_TRUE(&P->engine != NULL);
        ASSERT_TRUE(&P->frame != NULL);
        ASSERT_TRUE(&P->tire!= NULL);
        ASSERT_TRUE(P->tire.size()==4) << P->tire.size() << " Number of tires";
    }
};

// Fixture, contains 100 default cars
// use Test_F(Inventory, Test-name) to use
class Inventory: public ::testing::Test 
{
    protected:
        std::vector<Car*> cars;

        void SetUp()
        {
            for(int i = 0; i<100; i++)
            {
                Car one;
                Car* P = &one;
                cars.push_back(P);
            }

            std::thread engine(EngineInstallerVect, std::ref(cars));
            std::thread frame(FrameInstallerVect, std::ref(cars));
            std::thread tire(TireInstallerVect, std::ref(cars));

            engine.join();
            frame.join();
            tire.join();
        }    
};

// Recall new cars with a stack
TEST_F(Inventory, Recall)
{
    std::stack<Car*> car_stack;

    // Manufactured car records are stored in stack
    for(Car* i : cars)
    {
        car_stack.push(i);
    }

    std::stack<Car*> recall_list;

    // Recall last 20 cars
    for(int i = 0; i<20; i++)
    {
        recall_list.push(car_stack.top());
        car_stack.pop();
    }
};

//Ship cars off the assembly line with a shipping queue
TEST_F(Inventory, Ship)
{
    std::stack<Car*> car_queue;

    // Manufactured car records are stored in stack
    for(Car* i : cars)
    {
        car_queue.push(i);
    }

    std::stack<Car*> ship_list;

    for(int i = 0; i<20; i++)
    {
        ship_list.push(car_queue.top());
        car_queue.pop();
    }
};

//Sort Cars by their price
// TEST_F(Inventory, Heap)