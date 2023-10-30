#include <stdio.h>
#include "../include/operators/assignment_operators.h"

void mov(int registers[], int memory[], int rx, int ry, int rz, int integer, int *is_true, int register_count)
{
    // movendo conteúdo do registrador ry para rx
    if (register_count == 2)
    {
        registers[rx] = registers[ry];
    }

    // movendo valor inteiro para registrador rx
    else
    {
        registers[rx] = integer;
    }
}