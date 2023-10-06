#include <stdio.h>
#include "../include/operators/logical_operators.h"

// retorna true se valor de rx == ry
int beq(int registers[], int rx, int ry)
{
    return registers[rx] == registers[ry] ? 1 : 0;
}

// retorna true se valor de rx > ry
int blt(int registers[], int rx, int ry)
{
    return registers[rx] < registers[ry] ? 1 : 0;
}