#include <stdio.h>
#include "../include/read.h"

// printando o tabuleiro para arquivo de saída
void printBoard(FILE *file, char board[][BOARD_SIZE])
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            fprintf(file, "%c", board[i][j]);
        }
        fprintf(file, "\n");
    }
    fprintf(file, "\n");
}