#ifndef POSSIBLE_H
#define POSSIBLE_H

#define MAX_DIGIT 9

#include "./read.h"

void find_max_sum(WordValue *words, LetterValue *answer, int *alphabet, int *indexes, int size, int index, int *max);
void convert(WordValue *words, LetterValue *answer, int *alphabet, int *indexes, int size, int *max);

#endif 