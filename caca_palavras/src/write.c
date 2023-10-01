#include <stdio.h>
#include <string.h>
#include "../include/word_hunt.h"
#include "../include/write.h"

// printando palavra encontrada
void print_word(int palavra_idx, int coordenadas[N][2], palavra palavras[M])
{
    // mudando status da palavra para encontrada
    palavras[palavra_idx].status = 1;
    
    // printando palavra e a localização das letras
    printf("%s ", palavras[palavra_idx].letras);
                   
    for (int i = 0, length = strlen(palavras[palavra_idx].letras); i < length; i++)
    {
        if (i + 1 == length)
        {
            printf("(%i, %i)", coordenadas[i][0], coordenadas[i][1]);
        }
        else
        {
            printf("(%i, %i) ", coordenadas[i][0], coordenadas[i][1]);
        }
    }
                        
    printf("\n");
}