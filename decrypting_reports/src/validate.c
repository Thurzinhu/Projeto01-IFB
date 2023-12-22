#include <stdio.h>
#include <stdlib.h>
#include "../include/validate.h"

void validate_arguments(int argc, char *argv[], FILE **input, FILE **output)
{
    if (argc != 3)
    {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
    }

    *input = fopen(argv[1], "r");
    if (*input == NULL)
    {
        printf("Could not open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    *output = fopen(argv[2], "w");
    if (*output == NULL)
    {
        printf("Could not open file %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }
}

void check_malloc(void *ptr)
{
    if (ptr == NULL)
    {
        printf("Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
}

void cleanup(FILE *input, FILE *output, WordValue *words, int *indexes, int *alphabet, LetterValue *answer)
{
    // freeing memory
    free(words);
    free(indexes);
    free(alphabet);
    free(answer);

    // closing files
    fclose(input);
    fclose(output);
}