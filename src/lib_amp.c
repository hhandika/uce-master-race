#include <stdio.h>
#include <stdlib.h>

#include "cli.h"

#define CONSOLE_BOLD "\033[1m"
#define CONSOLE_RESET "\033[0m"

/**** Library Amplification ****/
void calculate_lib_amp_reaction(int sample_size) {
    const float kSampleErr = 1.0;
    const float kHotStart = 25.0;
    const float kPrimeri5 = 2.5;
    const float kPrimeri7 = 2.5;
    const float kWater = 5.0;
    const float kDNALib = 15.0;

    float final_samples = (float) sample_size + kSampleErr;
    float hotstart_mix = kHotStart * final_samples;
    float primer_i5 = kPrimeri5 * final_samples;
    float primer_i7 = kPrimeri7 * final_samples;
    float water = kWater * final_samples;
    float per_sample_mix = kHotStart + kPrimeri5 + kPrimeri7 + kWater;
    float total_per_sample = per_sample_mix + kDNALib;


    char * volume = "Volume";
    system("clear");
    printf(CONSOLE_BOLD "Library Amplification Reaction\n" CONSOLE_RESET);
    printf("\nNo. of samples: %u\n\n", sample_size);
    printf("-----------------------------------------------\n");
    printf("Component                      %15s\n", 
            volume);
    printf("-----------------------------------------------\n");
    printf("Adapter-ligated library             %8.2f µL\n",
            kDNALib);
    printf("Master Mix:\n");
    printf("2x KAPA HiFi Hotstar ReadyMix       %8.2f µL\n",
            hotstart_mix);
    printf("Primer mix i5                       %8.2f µL\n",
            primer_i5);
    printf("Primer mix i7                       %8.2f µL\n",
            primer_i7);
    printf("PCR-grade water                     %8.2f µL\n",
            water);
    printf("-----------------------------------------------\n");
    printf("Master mix volume per sample        %8.2f µL\n",
            per_sample_mix);
    printf("Total volume per sample             %8.2f µL\n",
            total_per_sample);
    printf("-----------------------------------------------\n");
    show_notes(final_samples, kSampleErr);
    exit_prompts();
}


/**** Post-Amplification Cleanup ****/
void show_cleanup_reaction(void) {
    const float kLibProduct = 50.0;
    const float kBead = 50;

    float total_volume = kLibProduct + kBead;
    char * volume = "Volume";

    system("clear");
    printf(CONSOLE_BOLD "Post-Amplification Cleanup\n\n" CONSOLE_RESET);
    printf("---------------------------------------------------\n");
    printf("Component                      %19s\n", 
            volume);
    printf("---------------------------------------------------\n");
    printf("Library Amplification reaction product  %8.2f µL\n",
            kLibProduct);
    printf("Bead                                    %8.2f µL\n",
            kBead);
    printf("---------------------------------------------------\n");
    printf("Total volume                            %8.2f µL\n",
            total_volume);
    printf("---------------------------------------------------\n");

    exit_prompts();
}
