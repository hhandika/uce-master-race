#ifndef CLI_H_
#define CLI_H_

void main_prompts(void);
void bead_cleanup_prompts();
void qubit_prompts(void);
void pre_library_prompts(void);
void library_prompts(void);
void invalid_input();
void exit_prompts(void);
void show_notes(float total_samples, float pipetting_errors);

#endif
