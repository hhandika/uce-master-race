/*
Heru Handika
1 August 2020
Tools for UCE labwork
*/

#include <stdio.h>
#include <stdlib.h>
#include "calculator.h"

int main(void) {
    int userInput = 0;

    printf("What would you like to do?\n");
    printf("1. Bead Cleanup\n");
    printf("2. Qubit\n");
    printf("\n");
    printf("Enter your choice: ");
    scanf("%d", &userInput);

    system("clear"); // Clear console.

    if(userInput == 1) {
        printf("1. Dilute to ethanol 80 percent\n");
        printf("2. Make TE solution\n");
        printf("3. Do nothing\n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d", &userInput);
        system("clear");

            if(userInput == 1) {
                int sampleSize = 0;
                int volume = 0;

                // Get user inputs
                printf("Enter the sample size: ");
                scanf("%d", &sampleSize);
                printf("Enter desired volume per sample: ");
                scanf("%d", &volume);

                // Calculate concentration
                calculateEthanol80(sampleSize, volume);
            } else if (userInput == 2) {
                printf("Solution 10 mM Tris-HCl, 1 mM EDTA:\n\n");
                printf("1. UV a canonical tube.\n");
                printf("2. Add 500 µL 1 M Tris pH8\n"); 
                printf("3. Add 100 µL 0.5 M EDTA\n");
                printf("4. Fill conical to 50 mL mark with dH20\n\n");
                printf("Credit: https://www.faircloth-lab.org/\n");
            } else if (userInput == 3) {
                exit(0);
            } else {
                printf("Invalid inputs\n");
            }
    } else {
        printf("Invalid inputs\n");
    }

    return EXIT_SUCCESS;
}