#include <stdio.h>
#include <stdlib.h>

#include "cli.h"

#define CONSOLE_BOLD "\033[1m"
#define CONSOLE_RESET "\033[0m"

/**** END-REPAIR AND A-TAILING ****/
void calculate_erat(int sample_size) {
    const float kSampleErr = 1.0; // Extra for pipetting errors
    const float kDna = 12.5;
    const float kErAtBuffer = 1.75;
    const float kErAtEnzyme = 0.75;
    char * volume = "Volume";

    float final_samples = (float) sample_size + kSampleErr;
    float buffer_volume = final_samples * kErAtBuffer;
    float enzyme_volume = final_samples * kErAtEnzyme;
    float per_sample_mix = kErAtBuffer + kErAtEnzyme;
    float total_per_sample = per_sample_mix + kDna;

    system("clear");
    printf(CONSOLE_BOLD "End Repair and A-Tailing\n" CONSOLE_RESET);
    printf("\nNo. of samples: %u\n\n", sample_size);
    printf("------------------------------------------\n");
    printf("Component                      %10s\n", 
            volume);
    printf("------------------------------------------\n");
    printf("DNA                            %8.2f µL\n", 
            kDna);
    printf("Master mix:\n");
    printf("End Repair & A-Tailing Buffer  %8.2f µL\n", 
            buffer_volume);
    printf("End Repair & A-Tailing Enzyme  %8.2f µL\n",
            enzyme_volume);
    printf("------------------------------------------\n");
    printf("Master mix volume per sample   %8.2f µL\n",
            per_sample_mix);
    printf("Total volume per sample        %8.2f µL\n",
            total_per_sample);
    printf("------------------------------------------\n");
    show_notes(final_samples, kSampleErr);
    exit_prompts();
}

/**** ADAPTER LIGATION ****/
void calculate_adapter_solution(unsigned int sample_size) {
    const float kSampleErr = 1.0;
    const float kErAtProduct = 15.0;
    const float kdWater = 1.25;
    const float kLigBuffer = 7.5;
    const float kDNALigase = 2.5;
    const float kStubs = 1.25;
    char * volume = "Volume";

    float final_samples = (float) sample_size + kSampleErr;
    float water_volume = final_samples * kdWater;
    float ligbuff_volume = final_samples * kLigBuffer;
    float dnalig_volume = final_samples * kDNALigase;
    float stubs_volume = final_samples * kStubs;
    float per_sample_mix = kdWater + kLigBuffer + kDNALigase + kStubs;
    float total_per_sample = per_sample_mix + kErAtProduct;

    system("clear");
    printf(CONSOLE_BOLD "Adapter Ligation\n" CONSOLE_RESET);
    printf("\nNo. of samples: %u\n\n", sample_size);
    printf("------------------------------------------\n");
    printf("Component                      %10s\n", 
            volume);
    printf("------------------------------------------\n");
    printf("End Repair & A-Tailing product %8.2f µL\n",
            kErAtProduct);
    printf("Maste mix:\n");
    printf("PCR-grade water                %8.2f µL\n",
            water_volume);
    printf("Ligation buffer                %8.2f µL\n",
            ligbuff_volume);
    printf("DNA Ligase                     %8.2f µL\n",
            dnalig_volume);
    printf("Stubs 15mm                     %8.2f µL\n",
            stubs_volume);
    printf("------------------------------------------\n");
    printf("Master mix volume per sample   %8.2f µL\n",
            per_sample_mix);
    printf("Total volume per sample        %8.2f µL\n",
            total_per_sample);
    printf("------------------------------------------\n");
    show_notes(final_samples, kSampleErr);
    exit_prompts();
}

/**** POST-LIGATION CLEANUP ****/
void show_post_ligation_solution(void) {
    const float kLigProduct = 27.5;
    const float kBead = 27.5;
    char * volume = "Volume";

    float total_volume = kLigProduct + kBead;
    system("clear");
    printf(CONSOLE_BOLD "Post-Ligation Cleanup\n\n" CONSOLE_RESET);
    printf("------------------------------------------------\n");
    printf("Component                              %8s\n", 
        volume);
    printf("------------------------------------------------\n");
    printf("Adapter Ligation reaction product      %6.2f µL\n",
            kLigProduct);
    printf("Bead                              %6.2f µL\n",
            kBead);
    printf("------------------------------------------------\n");
    printf("Total volume                           %6.2f µL\n",
            total_volume);
    printf("------------------------------------------------\n");
    
    exit_prompts();
}
