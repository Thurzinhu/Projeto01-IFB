#include <stdio.h>
#include <stdlib.h>
#include "../include/read.h"

void read_file(FILE *input, WordValue *words, int *alphabet, int *indexes, int *distinct_letters_count)
{
    // Initialize alphabet array with 0s
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        alphabet[i] = 0;
    }

    // reading words from input file and counting distinct letters
    for (int i = 0; i < WORDS_COUNT; i++)
    {
        fscanf(input, " %s", words[i].letters);
        count_distinct_letters(alphabet, words[i].letters, indexes, distinct_letters_count);
    }

    for (int i = 0, j = 0; i < ALPHABET_SIZE; i++)
    {
        if (alphabet[i])
        {
            // adding index of current letter to indexes array
            indexes[j] = i;
            j++;
        }
    }
}

void count_distinct_letters(int *alphabet, char *word, int *indexes, int *distinct_letters_count)
{
    for (int i = 0; word[i] != '\0'; i++)
    {
        if (alphabet[get_index(word[i])] == 0)
        {
            // updating status of current letter to found  
            alphabet[get_index(word[i])] = 1;
            
            // updating total number of distinct letters
            (*distinct_letters_count)++;
        }
    }
}