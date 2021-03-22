#include "gtest/gtest.h"
#include <thread>
#include "src/lib/car.hpp"
#include "src/lib/engine.hpp"
#include "src/lib/frame.hpp"
#include "src/lib/tire.hpp"
#include "src/lib/operations.hpp"
#include "stack"
#include "queue"

// Uncomment this to make sure google test fails corectly
// TEST(fail_this_test, fail){
//     ASSERT_EQ(0, 1);
// };


TEST(EmptyCar, EngineInstall){
    Car one;
    Car* P = &one;
    std::thread engine(EngineInstaller, std::ref(P));
    engine.join();
    ASSERT_TRUE(&P->engine != NULL);
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
    std::vector<Car> cars;

    for(int i = 0; i<10; i++)
    {
        Car one;
        cars.push_back(one);
    }
    
    std::thread engine(EngineInstallerVect, std::ref(cars));
    std::thread frame(FrameInstallerVect, std::ref(cars));
    std::thread tire(TireInstallerVect, std::ref(cars));

    engine.join();
    frame.join();
    tire.join();

    for(Car c: cars)
    {
        ASSERT_TRUE(&c.engine != NULL);
        ASSERT_TRUE(&c.frame != NULL);
        ASSERT_TRUE(&c.tire!= NULL);
        ASSERT_TRUE(c.tire.size()==4) << c.tire.size() << " Number of tires";
    }
};

// Fixture, contains 100 default cars
// use Test_F(Inventory, Test-name) to use

class Inventory: public ::testing::Test 
{
    protected:
        std::vector<Car> cars;

        virtual void SetUp()
        { 
            for(int i = 0; i<5; i++)
            {
                Car c;
                c.price = rand() % 15000 + 20000;
                c.id = i;
                cars.push_back(c);
            }
            std::thread engine(EngineInstallerVect, std::ref(cars));
            std::thread frame(FrameInstallerVect, std::ref(cars));
            std::thread tire(TireInstallerVect, std::ref(cars));

            engine.join();
            frame.join();
            tire.join();
        }    

        virtual void TearDown()
        {
            cars.clear();
        }
};

TEST_F(Inventory, init)
{
    for(int i = 0; i<cars.size(); i++)
    {
        ASSERT_EQ(cars[i].id, i) <<" Expected "<< i << " but actual is " << cars[0].id << " "; 
    }
};

// Recall new cars with a stack
TEST_F(Inventory, Stack_Recall)
{
    std::stack<Car> recall_stack;

    // Manufactured car records are stored in stack
    for(Car c : cars)
    {
        recall_stack.push(c);
    }

    // Recall last 3 cars
    for(int i = 0; i<3; i++)
    {
        Car c = recall_stack.top();
        ASSERT_EQ(c.id, 4-i) << "Actual Car ID = " << c.id << ", Expected Car ID " << 5-i;
        recall_stack.pop();
    }
};

//Ship cars off the assembly line with a shipping queue
TEST_F(Inventory, Shipping_Queue)
{
    std::queue<Car> car_queue;

    // Order information is stored in a Queue
    for(Car c : cars)
    {
        car_queue.push(c);
    }

    std::stack<Car> delivered_list;

    for(int i = 0; i<3; i++)
    {
        delivered_list.push(car_queue.front());
        car_queue.pop();
    }
};

// Sort Cars by their price
// TEST_F(Inventory, Heap_Sort)
// {
//     std::make_heap(cars.begin(), cars.end(), greater_than_car_price());
//     std::cout << "The minimum element of heap is : ";  
//     std::cout << cars.front() << endl; 
// };