#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "../include/read.h"

#define MAX_INTERATIONS 100000
#define NUM_MEMORY 1000
#define NUM_REGISTERS 32
#define NUM_FUNCTIONS 13
#define REGISTER 'R'

int definePath(char instruction[], char cur_instruction[], int pos, int *instruction_address);
void getMainInstruction(char main_instruction[], char cur_instruction[], int *pos);
void getRegistersIndex(char instruction[], int pos, int idx[]);
void interpret(char instructions[][MAX_CHAR], int rows);
void skipCharactes(char instruction[], int *pos);
int stoi(char instruction[], int *pos);

#endif