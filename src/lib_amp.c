#include <stdio.h>

#include "cli.h"

/**** Library Amplification ****/
void calculate_lib_amp_reaction(int sample_size) {
    const float kSample = 1.0;
    const float kHotStart = 25.0;
    const float kPrimeri5 = 2.5;
    const float kPrimeri7 = 2.5;
    const float kWater = 5.0;
    const float kDNALib = 15.0;

    float final_samples = (float) sample_size + kSample;

    char * volume = "Volume";
    printf("Library Amplification Reaction\n\n");
    printf("-----------------------------------------------\n");
    printf("Component                      %15s\n", 
            volume);
    printf("-----------------------------------------------\n");
    printf("Adapter-ligated library             %8.2f µL\n",
            kDNALib);
    printf("Master Mix:\n");
    printf("2x KAPA HiFi Hotstar ReadyMix       %8.2f µL\n",
            kHotStart * final_samples);
    printf("Primer mix i5                       %8.2f µL\n",
            kPrimeri5 * final_samples);
    printf("Primer mix i7                       %8.2f µL\n",
            kPrimeri7 * final_samples);
    printf("PCR-grade water                     %8.2f µL\n",
            kWater * final_samples);
    printf("-----------------------------------------------\n");

    exit_prompts();
}


/**** Post-Amplification Cleanup ****/
void show_cleanup_reaction(void) {
    const float kLibProduct = 50.0;
    const float kBead = 50;

    float total_volume = kLibProduct + kBead;
    char * volume = "Volume";
    printf("Post-Amplification Cleanup\n\n");
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
