#include <stdio.h>
#include <string.h>
#include "../include/word_hunt.h"
#include "../include/write.h"

// printando palavra encontrada
void print_word(int palavra_idx, int COORDENADAS[N][2], palavra PALAVRAS[M])
{
    // mudando status da palavra para encontrada
    PALAVRAS[palavra_idx].status = 1;
    
    // printando palavra e a localização das letras
    printf("%s ", PALAVRAS[palavra_idx].letras);
    
    int length = strlen(PALAVRAS[palavra_idx].letras);                    
    for (int k = 0; k < length; k++)
    {
        if (k + 1 == length)
        {
            printf("(%i, %i)", COORDENADAS[k][0], COORDENADAS[k][1]);
        }
        else
        {
            printf("(%i, %i) ", COORDENADAS[k][0], COORDENADAS[k][1]);
        }
    }
                        
    printf("\n");
}