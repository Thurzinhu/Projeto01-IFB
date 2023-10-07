#include <stdio.h>
#include <string.h>
#include "../include/read.h"

// lendo o tabuleiro presente no arquivo
void readFile(FILE *file, char board[][BOARD_SIZE])
{
    char buffer[BOARD_SIZE + 1];
    int linha = 0;
    
    while (fscanf(file ,"%s", buffer) != EOF)
    {
        // copiando cada linha do arquivo para
        // a variável global
        strcpy(board[linha], buffer);

        linha++;
    }
}