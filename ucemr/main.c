/*
Heru Handika
1 August 2020
Tools for UCE labwork
*/

#include <stdio.h>
#include <stdlib.h>

#include "cli.h"
#include "utils.h"

int main(void) {
    unsigned int user_input;
    user_input = main_prompts();
    system("clear");

    switch(user_input) {
        case 1: bead_cleanup_prompts();
                break;
        case 2: qubit_prompts(); break;
        case 3: pre_library_prompts();
                break;
        default: invalid_input();
    }

    return EXIT_SUCCESS;
}

