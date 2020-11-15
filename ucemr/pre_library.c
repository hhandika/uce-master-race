#include <stdio.h>

/**** END-REPAIR AND A-TAILING ****/
void calculate_erat(int sample_size) {
    const int kSample = 2;
    const float dna = 12.5;
    const float er_at_buffer = 1.75;
    const float er_at_enzyme = 0.75;
    
    int final_samples = sample_size * kSample;

    printf("\n");
    printf("|Component                      |Volume     |\n");
    printf("|-------------------------------------------|\n");
    printf("|DNA                            |%.2f      |\n", dna);
    printf("|End Repair & A-Tailing Buffer  |%.2f      |\n", 
            final_samples * er_at_buffer);
    printf("|End Repair & A-Tailing Enzyme  |%.2f      |\n",
            final_samples * er_at_enzyme);
    printf("\n");
}

/**** ADAPTER LIGATION ****/
void calculate_adapter_solution(int sample_size) {
    
}