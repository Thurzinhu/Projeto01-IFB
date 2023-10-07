#include <stdio.h>

int validateInput(int argc, char *argv[], FILE **file)
{
    // checando uso correto
    if (argc != 3)
    {
        printf("Uso: ./main arquivo_entrada arquivo_saida\n");
        return 0;
    }

    // checando se é possível abrir o arquivo informado
    *file = fopen(argv[1], "r");

    if (*file == NULL)
    {
        printf("Não foi possivél abrir o arquivo de entrada");
        return 0;
    }

    return 1;
}