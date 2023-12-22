#ifndef READ_H
#define READ_H

#define get_index(letter) (letter - 'A')

#define WORDS_COUNT 3
#define MAX_SIZE 9
#define MAX_DISTINCT_LETTERS 7
#define ALPHABET_SIZE 26

typedef struct
{
    char letters[MAX_SIZE];
    int value;
}
WordValue;

typedef struct 
{
    char letter;
    int value;
}
LetterValue;

void read_file(FILE *input, WordValue *words, int *alphabet, int *indexes, int *distinct_letters_count);
void count_distinct_letters(int *alphabet, char *word, int *indexes, int *distinct_letters_count);

#endif