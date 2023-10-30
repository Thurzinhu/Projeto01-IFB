#include <stdio.h>
#include "../include/read.h"
#include "../include/interpreter.h"

void read(char instructions[][MAX_CHAR], int *rows)
{
    // lendo a quantidade de linhas de código
    scanf("%i", rows);
    
    // matriz de instruções
    for (int i = 0; i < *rows; i++)
    {
        scanf(" %[^\n]s", instructions[i]);
    }
}