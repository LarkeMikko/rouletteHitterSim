#include <iostream>
#include "functions.h"
#include "Random.h"

void runSimulation(int iterations, double singleHitDamage)
{
    int lowerHitCount{ 0 };
    int higherHitCount{ 0 };
    double totalDamage{ 0 };

    simulateAndPrintReport(iterations, singleHitDamage, higherHitCount, lowerHitCount, totalDamage);
}

void simulateAndPrintReport(int iterations, double singleHitDamage, int higherHitCount, int lowerHitCount, double totalDamage)
{
    std::cout << "Starting simulation for " << iterations << " iterations with " << singleHitDamage << " as damage from single hit\n";
    for (int i{ 0 }; i < iterations; i++)

    {
        int roll{ Random::get(0,1) };
        if (roll == 1)
        {
            ++higherHitCount;
            totalDamage += singleHitDamage * 2;
        }
        else
        {
            ++lowerHitCount;
            totalDamage += singleHitDamage * 0.5;
        }
    }
    std::cout << "Simulation finished, printing results\n";
    printReport(iterations, singleHitDamage, higherHitCount, lowerHitCount, totalDamage);
}

void printReport(int iterations, double singleHitDamage, int higherHitCount, int lowerHitCount, double totalDamage)
{
    std::cout << "Damage from single hit: " << singleHitDamage << "\n";
    std::cout << "Iterations: " << iterations << "\n";
    std::cout << "Ratio between high and low rolls: " << higherHitCount << "(h) : " << lowerHitCount << "(l)\n";
    double avgDamagePerHit{ totalDamage / iterations };
    std::cout << "Average damage per hit: " << avgDamagePerHit << "\n";
    std::cout << "Change in percents: " << (avgDamagePerHit > singleHitDamage ? "+" : "-") << changeInPercentage(singleHitDamage, avgDamagePerHit) << "%\n";
    std::cout << "\n";
}

double changeInPercentage(double baseHitDamage, double modifiedDamage)
{
    if (baseHitDamage <= modifiedDamage) return (modifiedDamage * 100 / baseHitDamage) - 100;
    else return 100 * (baseHitDamage - modifiedDamage) / baseHitDamage;
}