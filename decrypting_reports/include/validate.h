#ifndef VALIDATE_H
#define VALIDATE_H

#include "./read.h"

void validate_arguments(int argc, char *argv[], FILE **input, FILE **output);
void check_malloc(void *ptr);
void cleanup(FILE *input, FILE *output, WordValue *words, int *indexes, int *alphabet, LetterValue *answer);

#endif