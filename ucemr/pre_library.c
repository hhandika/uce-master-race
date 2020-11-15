#include <stdio.h>


/**** END-REPAIR AND A-TAILING ****/
void calculate_erat(int sample_size) {
    const float kSample = 2.0;
    const float dna = 12.5;
    const float er_at_buffer = 1.75;
    const float er_at_enzyme = 0.75;
    
    float final_samples = (float) sample_size + kSample;

    printf("\n");
    printf("|Component                      |Volume     |\n");
    printf("|-------------------------------------------|\n");
    printf("|DNA                            |%.2fµL     |\n", dna);
    printf("|End Repair & A-Tailing Buffer  |%.2fµL     |\n", 
            final_samples * er_at_buffer);
    printf("|End Repair & A-Tailing Enzyme  |%.2fµL     |\n",
            final_samples * er_at_enzyme);
    printf("\n");
}

/**** ADAPTER LIGATION ****/
void calculate_adapter_solution(int sample_size) {
    const float kSample = 1.0;
    const float kErEtProduct = 15.0;
    const float kdWater = 1.25;
    const float kLigBuffer = 7.5;
    const float kDNALigase = 2.5;
    const float kStubs = 1.25;

    float final_samples = (float) sample_size + kSample;

    printf("\n");
    printf("|Component                      |Volume      |\n");
    printf("|--------------------------------------------|\n");
    printf("|End Repair & A-Tailing product |%.2fµL     |\n",
            kErEtProduct);
    printf("|PCR-grade water                |%.2fµL     |\n",
            final_samples * kdWater);
    printf("|Ligation buffer                |%.2fµL     |\n",
            final_samples * kLigBuffer);
    printf("|DNA Ligase                     |%.2fµL     |\n",
            final_samples * kDNALigase);
    printf("|Stubs 15mm                     |%.2fµL     |\n",
            final_samples * kStubs);
    printf("\n");
    
}

/**** SHARED FUNCTIONS ****/
