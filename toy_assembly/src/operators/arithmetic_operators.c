#include <stdio.h>
#include "../include/operators/arithmetic_operators.h"

// implementação das funções aritméticas
void add(int registers[], int rx, int ry, int rz)
{
    registers[rx] = registers[ry] + registers[rz];
}

void sub(int registers[], int rx, int ry, int rz)
{
    registers[rx] = registers[ry] - registers[rz];
}

void div(int registers[], int rx, int ry, int rz)
{
    registers[rx] = registers[ry] / registers[rz];
}

void mul(int registers[], int rx, int ry, int rz)
{
    registers[rx] = registers[ry] - registers[rz];
}

void mod(int registers[], int rx, int ry, int rz)
{
    int aux = ry % rz;
    registers[rx] = (aux < 0) ? (aux) + rz : (aux);
}