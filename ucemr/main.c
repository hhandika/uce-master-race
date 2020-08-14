/*
Heru Handika
1 August 2020
Tools for UCE labwork
*/

#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int main(void) {
    unsigned int userInput = 0;
    unsigned int sampleSize = 0;

    printf("UCEMR v0.0.1\n\n");
    printf("What would you like to do?\n\n");
    printf("1. Bead Cleanup\n");
    printf("2. Qubit\n\n");
    printf("Enter your choice (the number only):\n");
    printf("> ");
    scanf("%d", &userInput);

    system("clear"); // Clear console.

    if (userInput == 1) {
        printf("1. Dilute to ethanol 80 percent\n"      
            "2. Make TE solution\n"
            "3. Timer 5 minutes\n"
            "4. Timer 10 minutes\n"
            "5. Do nothing\n"
            "6. Back to main menu\n\n");
        printf(">");
        scanf("%d", &userInput);
        system("clear");

            if (userInput == 1) {
                unsigned int volume = 0;
                sampleSize = getSampleSize();
                printf("Desired volume per sample (µL): ");
                scanf("%d", &volume);

                // Calculate concentration
                calculateEthanol80(sampleSize, volume);
            } else if (userInput == 2) {
                printf("TE (10 mM Tris-HCl, 1 mM EDTA) recipe:\n\n");
                printf("1. UV a canonical tube.\n"
                    "2. Add 500 µL 1 M Tris pH8\n" 
                    "3. Add 100 µL 0.5 M EDTA\n"
                    "4. Fill conical to 50 mL mark with dH20\n\n");
                printf("Credit: Mark T. Swanson\n");
            } else if (userInput == 3) {
                // Time in seconds
                timer(300);
            } else if (userInput == 4) {
                timer(600);
            } else if (userInput == 5) {
                exit(0);
            } else if (userInput == 6) {
                main();
            }else {
                printf("Invalid inputs\n");
            }

    } else if (userInput == 2) {
        sampleSize = getSampleSize();
        calculateQubitSolution(sampleSize);
        
    } else {
        printf("Invalid inputs\n");
    }

    return EXIT_SUCCESS;
}

unsigned int getSampleSize(void) {
    unsigned int sampleSize = 0;
    // Get user inputs
    printf("Sample size: ");
    scanf("%d", &sampleSize);
    
    return sampleSize;
}