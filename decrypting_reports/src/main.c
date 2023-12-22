#include <stdio.h>
#include <stdlib.h>
#include "../include/validate.h"
#include "../include/read.h"
#include "../include/possible.h"
#include "../include/write.h"

int main(int argc, char *argv[])
{
    // declaring files 
    FILE *input, *output;

    // opening files and validating arguments
    validate_arguments(argc, argv, &input, &output);
    
    // array of the given words and their values (Initialy set to 0)
    WordValue *words = malloc(WORDS_COUNT * sizeof(WordValue));
    check_malloc(words);
    
    // array of indexes of distinct letters
    int *indexes = malloc(MAX_DISTINCT_LETTERS * sizeof(int));
    check_malloc(indexes);
    
    // holds the value of each letter
    int *alphabet = malloc(ALPHABET_SIZE * sizeof(int));
    check_malloc(alphabet);
    
    // holds total number of distinct letters
    int distinct_letters_count = 0;
    
    read_file(input, words, alphabet, indexes, &distinct_letters_count);

    // creating array to hold the solution
    LetterValue *answer = malloc(distinct_letters_count * sizeof(LetterValue));
    check_malloc(answer);

    int max = -1;

    // finding the solution
    find_max_sum(words, answer, alphabet, indexes, distinct_letters_count, 0, &max);

    // writing solution to output file
    write_file(output, answer, distinct_letters_count, max);
    
    // freeing memory and closing files
    cleanup(input, output, words, indexes, alphabet, answer);
    
    return 0;
}