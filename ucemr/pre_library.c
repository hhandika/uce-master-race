#include <stdio.h>

#include "cli.h"


/**** END-REPAIR AND A-TAILING ****/
void calculate_erat(int sample_size) {
    const float kSample = 2.0;
    const float dna = 12.5;
    const float er_at_buffer = 1.75;
    const float er_at_enzyme = 0.75;
    char * volume = "Volume";
    
    float final_samples = (float) sample_size + kSample;

    printf("\n");
    printf("|Component                      |%11s|\n", 
            volume);
    printf("|-------------------------------------------|\n");
    printf("|DNA                            |%8.2f µL|\n", dna);
    printf("|End Repair & A-Tailing Buffer  |%8.2f µL|\n", 
            final_samples * er_at_buffer);
    printf("|End Repair & A-Tailing Enzyme  |%8.2f µL|\n",
            final_samples * er_at_enzyme);

    exit_prompts();
}

/**** ADAPTER LIGATION ****/
void calculate_adapter_solution(int sample_size) {
    const float kSample = 1.0;
    const float kErEtProduct = 15.0;
    const float kdWater = 1.25;
    const float kLigBuffer = 7.5;
    const float kDNALigase = 2.5;
    const float kStubs = 1.25;
    char * volume = "Volume";

    float final_samples = (float) sample_size + kSample;

    printf("\n");
    printf("|Component                      |%11s|\n", 
            volume);
    printf("|-------------------------------------------|\n");
    printf("|End Repair & A-Tailing product |%8.2f µL|\n",
            kErEtProduct);
    printf("|PCR-grade water                |%8.2f µL|\n",
            final_samples * kdWater);
    printf("|Ligation buffer                |%8.2f µL|\n",
            final_samples * kLigBuffer);
    printf("|DNA Ligase                     |%8.2f µL|\n",
            final_samples * kDNALigase);
    printf("|Stubs 15mm                     |%8.2f µL|\n",
            final_samples * kStubs);

    exit_prompts();
}

/**** POST-LIGATION CLEANUP ****/
void show_post_ligation_solution(void) {
        const float kLigProduct = 27.5;
        const float kBead = 27.5;
        char * volume = "Volume";

        float total_volume = kLigProduct + kBead;
        printf("Post-Ligation Cleanup\n\n");
        printf("|Component                              |%9s|\n", 
            volume);
        printf("|-------------------------------------------------|\n");
        printf("|Adapter Ligation reaction product      |%6.2f µL|\n",
                kLigProduct);
        printf("|Bead                                   |%6.2f µL|\n",
                kBead);
        printf("|Total                                  |%6.2f µL|\n",
                total_volume);
        
        exit_prompts();
}
