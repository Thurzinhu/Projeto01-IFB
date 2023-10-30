#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "../include/read.h"

#define MAX_INTERATIONS 100000
#define NUM_MEMORY 1000
#define NUM_REGISTERS 32
#define NUM_FUNCTIONS 13
#define REGISTER 'R'

// ponteiro para operações aritméticas, lógicas, de memória e de atribuição
typedef void (*funcPtr) (int registers[], int memory[], int rx, int ry, int rz, int integer, int *is_true, int register_count);

// dicionário que relaciona o nome da função ao seu respectivo ponteiro
typedef struct 
{
    char *name;
    funcPtr function;
}
functionDict;

void executeCommand(char command[], char current_instruction[], int position, int *instruction_address);
void getCommand(char command[], char current_instruction[], int *position);
void getRegistersIndex(char current_instruction[], int registers_index[], int position, int *integer);
void interpret(char instructions[][MAX_CHAR], int rows);
void skipCharactes(char current_instruction[], int *position);
int stoi(char current_instruction[], int *position);

#endif