#include <stdio.h>
#include <stdlib.h>
#include "../include/possible.h"

void find_max_sum(WordValue *words, LetterValue *answer, int *alphabet, int *indexes, int size, int index, int *max)
{
    if (index == size)
    {
        // when all letters have been assigned a value we convert the words to numbers
        convert(words, answer, alphabet, indexes, size, max);
        return;
    }

    for (int i = MAX_DIGIT; i >= 0; i--)
    {
        // updating value of current letter
        alphabet[indexes[index]] = i;

        // recursive call
        find_max_sum(words, answer, alphabet, indexes, size, index + 1, max);
    }
}

void convert(WordValue *words, LetterValue *answer, int *alphabet, int *indexes, int size, int *max)
{
    for (int i = 0; i < WORDS_COUNT; i++)
    {
        // checking if any of the words first letter is 0
        // if so the values are not valid
        if (alphabet[get_index(words[i].letters[0])] == 0 && words[i].letters[1] != '\0')
        {
            return;
        }
    }

    for (int i = 0; i < WORDS_COUNT; i++)
    {
        // resetting value
        words[i].value = 0;

        // converting word to number        
        for (int j = 0; words[i].letters[j] != '\0'; j++)
        {
            words[i].value = words[i].value * 10 + alphabet[get_index(words[i].letters[j])];
        }
    }

    // checking if the sum is valid and if it is the maximum
    if (words[0].value + words[1].value == words[2].value && words[2].value > *max)
    {
        // updating max
        *max = words[2].value;

        // copying solution to answer
        for (int i = 0; i < size; i++)
        {
            answer[i].letter = indexes[i] + 'A';
            answer[i].value = alphabet[indexes[i]];
        }
    }
}