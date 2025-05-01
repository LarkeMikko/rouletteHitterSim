#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void printReport(int iterations, double singleHitDamage, int higherHitCount, int lowerHitCount, double totalDamage);
void simulateAndPrintReport(int iterations, double singleHitDamage, int higherHitCount, int lowerHitCount, double totalDamage);
void runSimulation(int iterations, double singleHitDamage);
double changeInPercentage(double baseHitDamage, double modifiedDamage);

#endif