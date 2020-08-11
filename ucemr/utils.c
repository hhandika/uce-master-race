/*
Heru Handika
1 August 2020
A library for for calculator functions
MIT License
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

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

void calculateQubitSolution(int sampleSize) {
    const unsigned int kBuffer = 199;
    const unsigned int kReagent = 1;
    const unsigned int kSampleSize = 2; // Add two extra for pippetting overhead.
    const unsigned int kStandard = 2;

    unsigned int totalSamples = sampleSize + kSampleSize + kStandard;
    unsigned int buffer = totalSamples * kBuffer;
    unsigned int reagent = totalSamples * kReagent;

    printf("\n");
    printf("Buffer = %i µL\n", buffer);
    printf("Qubit reagent = %i µL\n", reagent);
    printf("\nNotes:\n");
    printf("Total samples %i including %i standards and %i extras for pippetting errors.\n", 
            totalSamples, kStandard, kSampleSize);
}

void timer(int time) {
    int seconds = 0;
    int minutes = 0;

    while (time >= 0) {
        system("clear");
        seconds = time % 60;
        minutes = time/60;
        printf("%d:%d\n", minutes, seconds);
        sleep(1);
        time--;
    }
}