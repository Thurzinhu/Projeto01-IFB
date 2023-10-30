#include <stdio.h>
#include "../include/operators/memory_operators.h"

// carrega o conteúdo de memoria[ry] para o registrador rx
void load(int registers[], int memory[], int rx, int ry, int rz, int integer, int *is_true, int register_count)
{
    registers[rx] = memory[ry];
}

// carrega o conteúdo de rx para memoria[ry]
void store(int registers[], int memory[], int rx, int ry, int rz, int integer, int *is_true, int register_count)
{
    memory[ry] = registers[rx];
}