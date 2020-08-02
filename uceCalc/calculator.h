/*
Heru Handika
1 August 2020
A library for for calculator functions
MIT License
*/

#include <stdio.h>

void calculateEthanol80(int sampleSize, int perSampleConcentration) {
    const float ethanol80 = .8;

    float totalVolume = 0.0;
    float finalEthanol = 0.0;
    float finalWater = 0.0;

    sampleSize += 1; // Add overhead to allow pippetting errors.
    totalVolume = sampleSize * perSampleConcentration;
    finalEthanol = totalVolume * ethanol80;
    finalWater = totalVolume - finalEthanol;

    printf("\n");
    printf("Final Elution:\n");
    printf("Ethanol = %.2f\n", finalEthanol);
    printf("Water = %.2f\n", finalWater);
}
