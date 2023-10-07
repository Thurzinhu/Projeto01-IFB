#include <stdio.h>
#include "../include/validate.h"
#include "../include/read.h"
#include "../include/possible.h"

int main(int argc, char *argv[])
{
    FILE *inptr = NULL;
    if (!validateInput(argc, argv, &inptr))
    {
        return 1;
    }

    // lendo tabuleiro do arquivo de entrada
    char board[BOARD_SIZE][BOARD_SIZE];
    readFile(inptr, board);

    // abrindo arquivo de saída
    FILE *outptr = fopen(argv[2], "w"); 
    if (outptr == NULL)
    {
        return 2;
    }
    
    // analizando todos os casos possíveis de vitória
    // do player O
    possibleGames(inptr, board, outptr);

    // fechando arquivos
    fclose(inptr);
    fclose(outptr);

    return 0;
}