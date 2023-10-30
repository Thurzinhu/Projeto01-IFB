#include <stdio.h>
#include "../include/operators/arithmetic_operators.h"

// implementação das funções aritméticas
void add(int registers[], int memory[], int rx, int ry, int rz, int integer, int *is_true, int register_count)
{
    registers[rx] = registers[ry] + registers[rz];
}

void sub(int registers[], int memory[], int rx, int ry, int rz, int integer, int *is_true, int register_count)
{
    registers[rx] = registers[ry] - registers[rz];
}

void my_div(int registers[], int memory[], int rx, int ry, int rz, int integer, int *is_true, int register_count)
{
    registers[rx] = registers[ry] / registers[rz];
}

void mul(int registers[], int memory[], int rx, int ry, int rz, int integer, int *is_true, int register_count)
{
    registers[rx] = registers[ry] * registers[rz];
}

void mod(int registers[], int memory[], int rx, int ry, int rz, int integer, int *is_true, int register_count)
{
    int aux = registers[ry] % registers[rz];
    registers[rx] = (aux < 0) ? (aux) + registers[rz] : (aux);
}