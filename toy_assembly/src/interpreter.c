#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/print.h"
#include "../include/interpreter.h"
#include "../include/operators/arithmetic_operators.h"
#include "../include/operators/assignment_operators.h"
#include "../include/operators/logical_operators.h"
#include "../include/operators/memory_operators.h"

functionDict functionTable[] = {
    {"MOV", mov},
    {"ADD", add},
    {"SUB", sub},
    {"DIV", my_div},
    {"MUL", mul},
    {"MOD", mod},
    {"JMP", jmp},
    {"BEQ", beq},
    {"BLT", blt},
    {"LOAD", load},
    {"STORE", store},
    {"PRINT", print}
};

int register_count;

// criando array de registrados e de memória e inizializando todos eles como 0
int registers[NUM_REGISTERS] = {0}, memory[NUM_MEMORY] = {0};

void interpret(char instructions[][MAX_CHAR], int rows)
{
    // interpretando cada instrução
    int instruction_address = 0;
    for (int i = 0; i < MAX_INTERATIONS && instruction_address < rows; i++)
    {
        char command[MAX_CHAR];
        int position = 0;

        // obtendo comando
        getCommand(command, instructions[instruction_address], &position);

        // reiniciando contagem de registradores
        register_count = 0;

        executeCommand(command, instructions[instruction_address], position, &instruction_address);
    }
}

// definindo função a ser executada
void executeCommand(char command[], char current_instruction[], int position, int *instruction_address)
{
    // parando execução do programa
    if (strcmp(command, "EXIT") == 0)
    {
        exit(0);
    }

    // array do index dos registrados e valor inteiro
    int registers_index[] = {0, 0, 0};
    int integer;

    // pegando os indíces de cada registrador e o valor inteiro caso haja
    getRegistersIndex(current_instruction, registers_index, position, &integer);
    int rx = registers_index[0], ry = registers_index[1], rz = registers_index[2];

    // variável que armazena o resultado de operações lógicas
    int is_true = 0;

    // avaliando função a ser executada
    for (int i = 0; i < NUM_FUNCTIONS; i++)
    {
        if (strcmp(command, functionTable[i].name) == 0)
        {
            functionTable[i].function(registers, memory, rx, ry, rz, integer, &is_true, register_count);
            break;
        }
    }

    // atualizando endereço da instrução
    if (is_true)
    {
        (*instruction_address) = integer;
    }
    else
    {
        (*instruction_address)++;
    }
}

// obtendo os indíces de cada registrador informados na instrução
void getRegistersIndex(char current_instruction[], int registers_index[], int position, int *integer)
{
    int i = 0;
    while (current_instruction[position] != '\0')
    {
        // pulando caracteres que não são números
        skipCharactes(current_instruction, &position);

        if (current_instruction[position - 1] == REGISTER)
        {
            // guardando índice do registrador
            registers_index[i] = stoi(current_instruction, &position);
            i++;
        }
        else
        {
            // guardando inteiro
            (*integer) = stoi(current_instruction, &position);
        }
    }
}

// pulando carácteres irrelevantes e contando número de registradores
void skipCharactes(char current_instruction[], int *position)
{
    while (!isdigit(current_instruction[*position]))
    {
        if (current_instruction[*position] == REGISTER)
        {
            register_count++;
        }
        (*position)++;
    }
}

// transformando número de string para inteiro
int stoi(char current_instruction[], int *position)
{
    int n = 0, sign = (current_instruction[*position - 1] == '-') ? -1 : 1;
    while (isdigit(current_instruction[*position]))
    {
        n *= 10;
        n += current_instruction[*position] - '0';
        (*position)++;
    }

    return sign == 1 ? n : -n;
}

// obtendo o comando da instrução atual
void getCommand(char command[], char current_instruction[], int *position)
{
    // começando do primeiro carácter da string até encontrar um espaço
    // ou chegar em seu fim
    while (current_instruction[*position] != ' ' && current_instruction[*position] != '\0')
    {
        command[*position] = current_instruction[*position];
        (*position)++;
    }

    command[*position] = '\0';
}