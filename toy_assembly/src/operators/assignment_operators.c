#include <stdio.h>
#include "../include/operators/assignment_operators.h"

void mov(int registers[], int rx, int ry)
{
    registers[rx] = registers[ry];
}

void movInt(int registers[], int rx, int n)
{
    registers[rx] = n;
}