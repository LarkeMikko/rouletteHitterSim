// gambleHitterSim.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "functions.h"

namespace Constants
{
    constexpr int iterations{ 1000 };
    constexpr double singleHitDamage{ 10 };
}

int main()
{
    std::cout << "Simple gambler pico simulator\n\n";

    runSimulation(Constants::iterations, Constants::singleHitDamage);

    runSimulation(5'000, Constants::singleHitDamage);
    runSimulation(10'000, Constants::singleHitDamage);
    runSimulation(15'000, Constants::singleHitDamage);

    runSimulation(Constants::iterations, 100);
    runSimulation(Constants::iterations, 1000);
    runSimulation(Constants::iterations, 3000);

}


