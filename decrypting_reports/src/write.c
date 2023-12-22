#include <stdio.h>
#include <stdlib.h>
#include "../include/write.h"

void write_file(FILE *output, LetterValue *answer, int size, int max)
{
    // no solution
    if (max == -1)
    {
        fprintf(output, "%i\n", max);
    }
    else
    {
        fprintf(output, "%i\n", max);
        
        // printing solution
        for (int i = 0; i < size; i++)
        {
            fprintf(output, "%c:%i\n", answer[i].letter, answer[i].value);
        }
    }
}