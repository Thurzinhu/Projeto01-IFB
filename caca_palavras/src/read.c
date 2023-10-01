#include <stdio.h>
#include "../include/word_hunt.h"
#include "../include/read.h"

void read(palavra palavras[M], char tabuleiro[N][N])
{
    int n, m;

    // lendo dimensão do tabuleiro e quantidade de palavras
    scanf("%i", &n);
    scanf("%i", &m);

    // guardando palavras a serem encontras
    for (int i = 0; i < m; i++)
    {
        scanf("%s", palavras[i].letras);
    }

    // lendo linhas do tabuleiro
    for (int i = 0; i < n; i++)
    {
        scanf("%s", tabuleiro[i]);
    }
}