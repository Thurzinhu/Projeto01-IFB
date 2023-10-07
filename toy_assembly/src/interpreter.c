#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "../include/interpreter.h"
#include "../include/operators/arithmetic_operators.h"
#include "../include/operators/assignment_operators.h"
#include "../include/operators/logical_operators.h"
#include "../include/operators/memory_operators.h"
#include "../include/write.h"

enum functions {
    EXIT,
    JMP,
    MOV,
    PRINT,
    ADD,
    SUB,
    DIV,
    MUL,
    MOD,
    BEQ,
    BLT,
    LOAD,
    STORE
};

const char *function_names[] = {
    "EXIT", "JMP", "MOV", "PRINT", "ADD",  "SUB",   "DIV",
    "MUL",  "MOD", "BEQ", "BLT",   "LOAD", "STORE",
};

int register_count, sign;

// criando array de registrados e de memória e inizializando todos eles
int registers[NUM_REGISTERS] = {0}, memory[NUM_MEMORY] = {0};

void interpret(char instructions[][MAX_CHAR], int rows)
{
    // interpretando cada instrução
    int instruction_address = 0;
    for (int i = 0; i < MAX_INTERATIONS && instruction_address < rows; i++)
    {
        char main_instruction[MAX_CHAR];
        int pos = 0;

        // obtendo função principal
        getMainInstruction(main_instruction, instructions[instruction_address], &pos);

        // reiniciando contagem de registradores
        register_count = 0;

        // definindo sinal do inteiro
        sign = 1;

        // executando função principal e indo para próxima instrução
        int run = definePath(main_instruction, instructions[instruction_address], pos, &instruction_address);
        if (!run)
        {
            // caso a instrução seja EXIT saimos do loop
            break;
        }
        else if (run == 1)
        {
            instruction_address++;
        }
    }
}

// definindo função a ser executada
int definePath(char instruction[], char cur_instruction[], int pos, int *instruction_address)
{
    if (strcmp(instruction, "EXIT") == 0)
    {
        return 0;
    }

    // array de registrados
    int registers_indexes[] = {0, 0, 0};
    
    // pegando os indíces de cada registrador
    getRegistersIndex(cur_instruction, pos, registers_indexes);

    // avaliando função a ser executada
    int function_idx;
    for (function_idx = 0; function_idx < NUM_FUNCTIONS; function_idx++)
    {
        if (strcmp(instruction, function_names[function_idx]) == 0)
        {
            break;
        }
    }

    // realizando função correspondente
    switch (function_idx) 
    {
        case JMP:
            *instruction_address = registers_indexes[0];
            return 2;
        
        case MOV:
            (register_count == 2)
            ? mov(registers, registers_indexes[0], registers_indexes[1])
            : movInt(registers, registers_indexes[0], registers_indexes[1] * sign);
            break;

        case PRINT:
            write(registers, registers_indexes[0]);
            break;

        case ADD:
            add(registers, registers_indexes[0], registers_indexes[1], registers_indexes[2]);
            break;
            
        case SUB:
            sub(registers, registers_indexes[0], registers_indexes[1], registers_indexes[2]);
            break;
            
        case DIV:
            div(registers, registers_indexes[0], registers_indexes[1], registers_indexes[2]);
            break;
            
        case MUL:
            mul(registers, registers_indexes[0], registers_indexes[1], registers_indexes[2]);
            break;
        
        case MOD:
            mod(registers, registers_indexes[0], registers_indexes[1], registers_indexes[2]);
            break;    

        case BEQ:
            // endereço da instrução atualizado se a comparação for verdadeira
            if (beq(registers, registers_indexes[0], registers_indexes[1]))
            {
                *instruction_address = registers_indexes[2];
                return 2;
            }
            break;
            
        case BLT:
            // endereço da instrução atualizado se a comparação for verdadeira
            if (blt(registers, registers_indexes[0], registers_indexes[1]))
            {
                *instruction_address = registers_indexes[2];
                return 2;
            }
            break;

        case LOAD:
            load(registers, memory, registers_indexes[0], registers_indexes[1]);
            break;

        case STORE:
            store(registers, memory, registers_indexes[0], registers_indexes[1]);
            break;
    }

    // retorna-se um para ir à próxima instrução
    return 1;
}

// obtendo os indíces de cada registrador informados na instrução
void getRegistersIndex(char instruction[], int pos, int idx[])
{
    int num_registers = 3;
    for (int i = 0; i < num_registers; i++)
    {
        // pulando caracteres que não são números
        skipCharactes(instruction, &pos);

        // transformando string para int
        idx[i] = stoi(instruction, &pos);

        // saindo da função se a string não tiver mais caracters
        if (instruction[pos] == '\0')
        {
            return;
        }
    }
}

// pulando carácteres irrelevantes e contando número de registradores
void skipCharactes(char instruction[], int *pos)
{
    while (!isdigit(instruction[*pos]))
    {
        if (instruction[*pos] == REGISTER)
        {
            register_count++;
        }
        else if (instruction[*pos] == '-')
        {
            sign = -1;
        }
        (*pos)++;
    }
}

// transformando número do registrador de string para inteiro
int stoi(char instruction[], int *pos)
{
    int n = 0;
    while (isdigit(instruction[*pos]))
    {
        n *= 10;
        n += instruction[*pos] - '0';
        (*pos)++;
    }

    return n;
}

// obtendo a instrução principal
void getMainInstruction(char main_instruction[], char cur_instruction[], int *pos)
{
    // começando do primeiro carácter da string até encontrar um espaço
    // ou chegar em seu fim  
    while (cur_instruction[*pos] != ' ' && cur_instruction[*pos] != '\0')
    {
        main_instruction[*pos] = cur_instruction[*pos];
        (*pos)++;
    }

    main_instruction[*pos] = '\0';
}