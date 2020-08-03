/*
Heru Handika
1 August 2020
A library for for calculator functions
MIT License
*/

#include <stdio.h>

void calculateEthanol80(int sampleSize, int perSampleConcentration) {
    const float ethanol80 = .8;
    const int twoWashes = 2;
    const int pippettingOverhead = 2;

    float totalVolume = 0.0;
    float finalEthanol = 0.0;
    float finalWater = 0.0;

    // Add overhead to allow pippetting errors.
    sampleSize = (sampleSize + pippettingOverhead) * twoWashes; 
    totalVolume = sampleSize * perSampleConcentration;
    finalEthanol = totalVolume * ethanol80;
    finalWater = totalVolume - finalEthanol;

    printf("\n");
    printf("Final solution:\n");
    printf("Ethanol = %.2f µL\n", finalEthanol);
    printf("dH2O = %.2f µL\n", finalWater);
}
