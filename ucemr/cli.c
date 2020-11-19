/* Library for user commands */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "cli.h"
#include "pre_library.h"
#include "utils.h"

#define _VERSION "v0.0.4"

#define CONSOLE_RED "\033[0;31m"
#define CONSOLE_YELLOW "\033[0;33m"
#define CONSOLE_PURPLE "\033[0;35m"
#define CONSOLE_RESET "\033[0m"

static unsigned int main_options(void);
static void bead_cleanup_options(void);
static void pre_library_options(void);
static unsigned int get_sample_size(void);
static unsigned int call_user_input();
static void dilute_ethanol_prompts();
static void make_TE_solution_prompts(void);
static void erat_prompts(void);
static void adapter_solution_prompts(void);
static void display_logo(void);

static unsigned int main_options(void) {
    printf(CONSOLE_PURPLE);
    display_logo();
    printf("UCEMR " _VERSION "\n\n");
    printf(CONSOLE_RESET);
    printf("What would you like to do?\n\n");
    printf("1. Bead Cleanup\n");
    printf("2. Qubit\n");
    printf("3. Library Construction\n");
    printf("4. Pre-Library\n");
    printf("5. Exit\n");
    printf("\n");
    unsigned int user_input = call_user_input();
    return user_input;
}

void main_prompts(void) {
    system("clear");
    unsigned int user_input;
    user_input = main_options();
    system("clear");
    switch(user_input) {
        case 1: bead_cleanup_prompts(); break;
        case 2: qubit_prompts(); break;
        case 3: pre_library_prompts(); break;
        case 4: break;
        case 5: exit(0);
        default: invalid_input();
    }
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
        case 7: exit(0);
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
    exit_prompts();
}

/**** QUBIT ****/
void qubit_prompts(void) {
    unsigned int sampleSize = 0;
    sampleSize = get_sample_size();
    calculateQubitSolution(sampleSize);
}

/**** LIBRARY CONSTRUCTION A.K.A PRE-LIBRARY ****/
static void pre_library_options(void) {
    printf("1. End Repair and A-Tailing\n"      
        "2. Adapter Ligation\n"
        "3. Post Ligation\n"
        "4. Timer 15 minutes\n"
        "5. Timer 10 minutes\n"
        "6. Back to main menu\n"
        "7. Exit\n\n");
}

void pre_library_prompts(void) {
    unsigned int user_input;
    pre_library_options();
    user_input = call_user_input();
    system("clear");
    switch(user_input) {
        case 1: erat_prompts(); break;
        case 2: adapter_solution_prompts(); break;
        case 3: show_post_ligation_solution(); break;
        case 4: timer(900); break;
        case 5: timer(600); break;
        case 6: main_prompts(); break;
        case 7: exit(0);
        default: invalid_input();
    }
}

static void erat_prompts(void) {
    unsigned int sample_size;
    sample_size = get_sample_size();
    calculate_erat(sample_size);
}

static void adapter_solution_prompts(void) {
    unsigned int sample_size;
    sample_size = get_sample_size();
    calculate_adapter_solution(sample_size);
}

/**** LIBRARY AMPLIFICATION ****/
static void library_options(void) {
    printf("1. Amplification\n"      
        "2. Post-Amplification Cleanup\n\n");
}

void library_prompts(void) {
    unsigned int user_input;
    library_options();
    user_input = call_user_input();
    system("clear");
    switch(user_input) {
        case 1: erat_prompts(); break;
        case 2: adapter_solution_prompts(); break;
        default: invalid_input();
    }
}

/**** SHARED FUNCTIONS ****/
void invalid_input(void) {
    system("clear");
    printf(CONSOLE_RED 
        "====================ERROR====================\n");
    printf(CONSOLE_YELLOW "Ups...\n");
    printf("Does not seem like you enter a valid input.\n");
    printf("Make sure the input is a number only.\n");
    printf("It should not exceed the options.\n");
    exit(EXIT_FAILURE);
}

void exit_prompts(void) {
    unsigned int user_input = 0;
    printf("\n");
    printf("0. Exit\n");
    printf("1. Back to main menu\n");

    user_input = call_user_input();
    switch (user_input) {
        case 0: exit(0);
        case 1: system("clear"); 
                main_prompts(); 
                break;
        default: invalid_input();
    }
}

static void display_logo(void) {
    printf(                                                                                 
        "                                        @          \n"
        "                 @@@          @@@@@     @     @@   \n"
        "             @    @            @       @ &@@@      \n"    
        "          @@                    @     @            \n"
        "        @           @                @             \n"  
        "@@&   @              @             @               \n" 
        "    @@@@                   &   @                   \n"
        "    @      @@@  @         @@@                      \n" 
        "   @                                               \n"                                                                     
    );
    printf("\n");
}

static unsigned int call_user_input(void){
    unsigned int user_input = 0;
    printf("Enter your choice (number only):\n");
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