/* Library for user commands */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "cli.h"
#include "utils.h"

#define CONSOLE_RED "\033[0;31m"
#define CONSOLE_YELLOW "\033[0;33m"

static void bead_cleanup_options(void);
static unsigned int get_sample_size(void);
static unsigned int call_user_input();
static void dilute_ethanol_prompts();
static void make_TE_solution_prompts(void);

unsigned int main_prompts(void) {
    printf("UCEMR v0.0.1\n\n");
    printf("What would you like to do?\n\n");
    printf("1. Bead Cleanup\n");
    printf("2. Qubit\n\n");
    unsigned int user_input = call_user_input();
    return user_input;
}

static void bead_cleanup_options(void) {
    printf("1. Dilute to ethanol 80 percent\n"      
        "2. Make TE solution\n"
        "3. Timer 5 minutes\n"
        "4. Timer 10 minutes\n"
        "5. Show protocols\n"
        "6. Do nothing\n"
        "7. Back to main menu\n\n");
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
        case 6: exit(0); break;
        case 7: main_prompts(); break;
        default:
            invalid_input(); 
    }
}

void qubit_prompts(void) {
    unsigned int sampleSize = 0;
    sampleSize = get_sample_size();
    calculateQubitSolution(sampleSize);
}

/**** BEAT CLEAN UP OPTIONS ****/
static void dilute_ethanol_prompts(void) {
    unsigned int volume, sample_size;
    sample_size = get_sample_size();
    printf("Desired volume per sample (µL): ");
    scanf("%d", &volume);

    // Calculate concentration
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

/**** SHARE FUNCTIONS ****/
int invalid_input() {
    printf(CONSOLE_RED "ERROR:"
        CONSOLE_YELLOW "INVALID INPUTS\n");
    printf("Make sure the input is number only.");
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
    unsigned int sampleSize = 0;
    printf("Sample size: ");
    scanf("%d", &sampleSize);

    return sampleSize;
}