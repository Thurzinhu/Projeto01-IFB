#include <stdio.h>
#include <stdlib.h>
#include "../include/validate.h"

int validate(int argc, char *argv[], FILE **inptr, time **times)
{
    // checando uso correto
    if (argc != 3)
    {
        printf("Uso: ./campeonato arquivo_entrada arquivo_saida\n");
        return 0;
    }

    *inptr = fopen(argv[1], "r");

    // checando erros
    if (*inptr == NULL)
    {
        printf("Nao foi possivel abrir o arquivo de entrada\n");
        return 0;
    }

    // alocando memória para os times
    *times = malloc(sizeof(time) * MAX_TEAMS);
    if (*times == NULL)
    {
        printf("Error\n");
        return 1;
    }
    return 1;
}