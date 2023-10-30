#include <stdio.h>
#include "../include/operators/logical_operators.h"

void beq(int registers[], int memory[], int rx, int ry, int rz, int integer, int *is_true, int register_count)
{
    (*is_true) = (registers[rx] == registers[ry]);
}

void blt(int registers[], int memory[], int rx, int ry, int rz, int integer, int *is_true, int register_count)
{
    (*is_true) = (registers[rx] < registers[ry]);
}

void jmp(int registers[], int memory[], int rx, int ry, int rz, int integer, int *is_true, int register_count)
{
    (*is_true) = 1;
}