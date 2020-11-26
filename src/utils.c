/*
Heru Handika
1 August 2020
A library for for calculator functions
MIT License
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "cli.h"

#define CONSOLE_YELLOW "\033[0;33m"
#define CONSOLE_BOLD "\033[1m"
#define CONSOLE_RESET "\033[0m"

void dilute_etoh_80(unsigned int sample_size, unsigned int vol_per_sample) {
    const float kEthanol80 = .8;
    const unsigned int kWashes = 2; // Two washes
    const unsigned int pippettingOverhead = 2;

    // Add overhead to allow pippetting errors.
    float total_samples = (float) (sample_size + pippettingOverhead) * kWashes; 
    float total_vol = total_samples * vol_per_sample;
    float final_etoh = total_vol * kEthanol80;
    float water_vol = total_vol - final_etoh;


    char * volume = "Volume";
    system("clear");
    printf(CONSOLE_BOLD "Ethanol 80 Percent Solution\n\n" CONSOLE_RESET);
    printf("No. of samples: %u\n", sample_size);
    printf("Extra samples for pipetting: %u\n", pippettingOverhead);
    printf("Total samples calculated (2 washes): %.f\n", total_samples);
    printf("Volume per samples: %.1f µL\n\n", (float) vol_per_sample);
    printf("------------------------------------------\n");
    printf("Component                      %10s\n", 
            volume);
    printf("------------------------------------------\n");
    printf("Ethanol                        %8.1f µL\n", final_etoh);
    printf("PCR-grade water                %8.1f µL\n", water_vol);
    printf("------------------------------------------\n");
    printf("Total volume                   %8.1f µL\n", total_vol);
    printf("------------------------------------------\n");
    exit_prompts();
}

void calculate_qubit_solution(int sample_size) {
    const float kBuffer = 199.0;
    const float kReagent = 1.0;
    const float kSampleErr = 1.0; // Pippetting errors
    const float kStandard = 2.0;

    float total_samples = (float) sample_size + kSampleErr + kStandard;
    float buffer_vol = total_samples * kBuffer;
    float reagent_vol = total_samples * kReagent;
    float total_vol = buffer_vol + reagent_vol;

    char * volume = "Volume";
    system("clear");
    printf(CONSOLE_BOLD "Ethanol 80 Percent Solution\n\n" CONSOLE_RESET);
    printf("No. of samples: %u\n", sample_size);
    printf("Total calculated: %.f\n\n", total_samples);
    printf("-----------------------------------------\n");
    printf("Component                      %9s\n", 
            volume);
    printf("-----------------------------------------\n");
    printf("Buffer                        %8.1f µL\n", buffer_vol);
    printf("Qubit reagent                 %8.1f µL\n", reagent_vol);
    printf("-----------------------------------------\n");
    printf("Total master mix volume       %8.1f µL\n", total_vol);
    printf("-----------------------------------------\n");
    printf(CONSOLE_YELLOW);
    printf("\nNotes:\n");
    printf("Total samples include %.f standards\n", 
            kStandard);
    printf("and %.f extra for pippetting errors.\n", kSampleErr);
    printf(CONSOLE_RESET);
    exit_prompts();
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
    exit_prompts();
}
