#include <stdio.h>
#include "../include/validate.h"

int validate(int argc, char *argv[], FILE **inptr)
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

    return 1;
}