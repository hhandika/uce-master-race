/* Library for user commands */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "cli.h"
#include "pre_library.h"
#include "utils.h"

#define CONSOLE_RED "\033[0;31m"
#define CONSOLE_YELLOW "\033[0;33m"
#define CONSOLE_RESET "\033[0m"

static void bead_cleanup_options(void);
static void pre_library_options(void);
static unsigned int get_sample_size(void);
static unsigned int call_user_input();
static void dilute_ethanol_prompts();
static void make_TE_solution_prompts(void);

unsigned int main_prompts(void) {
    printf("UCEMR v0.0.2\n\n");
    printf("What would you like to do?\n\n");
    printf("1. Bead Cleanup\n");
    printf("2. Qubit\n");
    printf("3. Library Construction\n\n");
    unsigned int user_input = call_user_input();
    return user_input;
}

/**** BEAT CLEANUP ****/
static void bead_cleanup_options(void) {
    printf("1. Dilute to ethanol 80 percent\n"      
        "2. Make TE solution\n"
        "3. Timer 5 minutes\n"
        "4. Timer 10 minutes\n"
        "5. Show protocols\n"
        "6. Back to main menu\n"
        "7. Exit\n\n");
}

void bead_cleanup_prompts() {
    unsigned int user_input = 0;
    bead_cleanup_options();
    user_input = call_user_input();
    system("clear");

    switch(user_input) {
        case 1: dilute_ethanol_prompts(); break;
        case 2: make_TE_solution_prompts(); break;
        case 3: timer(300); break;
        case 4: timer(600); break;
        case 5: beadCleanUpProtocols(); break;
        case 6: main_prompts(); break;
        case 7: exit(0); break;
        default: invalid_input(); 
    }
}

static void dilute_ethanol_prompts(void) {
    unsigned int volume, sample_size;
    sample_size = get_sample_size();
    printf("Desired volume per sample (µL): ");
    scanf("%d", &volume);
    assert(volume > 1);
    calculateEthanol80(sample_size, volume);
}

static void make_TE_solution_prompts(void) {
    printf("TE (10 mM Tris-HCl, 1 mM EDTA) recipe:\n\n");
    printf("1. UV a canonical tube.\n"
        "2. Add 500 µL 1 M Tris pH8\n" 
        "3. Add 100 µL 0.5 M EDTA\n"
        "4. Fill conical to 50 mL mark with dH20\n\n");
    printf("Credit: Mark T. Swanson\n");
}

/**** QUBIT ****/
void qubit_prompts(void) {
    unsigned int sampleSize = 0;
    sampleSize = get_sample_size();
    calculateQubitSolution(sampleSize);
}

/**** LIBRARY CONSTRUCTION ****/
static void pre_library_options(void) {
    printf("1. End Repair and A-Tailing\n"      
        "2. Adapter Ligation\n"
        "3. Post Ligation\n"
        "4. Timer 15 minutes\n"
        "5. Timer 10 minutes\n"
        "6. Exit\n"
        "7. Back to main menu\n\n");
}

void pre_library_prompts(void) {
    unsigned int user_input, sample_size;
    pre_library_options();
    user_input = call_user_input();
    system("clear");
    sample_size = get_sample_size();
    switch(user_input) {
        case 1: calculate_erat(sample_size); 
                break;
        case 2: calculate_adapter_solution(sample_size);
                break;
        default: invalid_input();
    }
}

/**** SHARED FUNCTIONS ****/
int invalid_input() {
    printf(CONSOLE_RED "ERROR:"
        CONSOLE_YELLOW "INVALID INPUTS\n");
    printf(CONSOLE_RESET
        "Make sure the input is number only.\n");
    exit(EXIT_FAILURE);
}

static unsigned int call_user_input(){
    unsigned int user_input = 0;
    printf("Enter your choice (the number only):\n");
    printf("> ");
    scanf("%d", &user_input);
    return user_input;
}

static unsigned int get_sample_size(void) {
    unsigned int sample_size = 0;
    printf("Sample size: ");
    scanf("%d", &sample_size);
    assert(sample_size > 1);

    return sample_size;
}