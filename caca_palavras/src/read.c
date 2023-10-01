#include <stdio.h>
#include "../include/word_hunt.h"
#include "../include/read.h"

void read(palavra PALAVRAS[M], char MATRIZ[N][N])
{
    int n, m;

    // lendo dimensão da matriz
    // e quantidade de palavras
    scanf("%i", &n);
    scanf("%i", &m);

    // guardando palavras a serem
    // encontras na variavel global
    for (int i = 0; i < m; i++)
    {
        scanf("%s", PALAVRAS[i].letras);
    }

    // lendo matriz e guardando na
    // variavel global
    for (int i = 0; i < n; i++)
    {
        scanf("%s", MATRIZ[i]);
    }
}