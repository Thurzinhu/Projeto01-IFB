#include <stdio.h>
#include "../include/read.h"
#include "../include/possible.h"
#include "../include/write.h"

// definindo player para O uma vez que ele sempre
// inicia as jogadas
char PLAYER = 'O';

// avaliando todos os jogos possíveis
void possibleGames(FILE *infile, char board[][BOARD_SIZE], FILE *outfile)
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            // se o campo estiver em branco o jogador
            // da vez realiza sua jogada nele
            if (board[i][j] == 'B')
            {
                board[i][j] = PLAYER;

                // checando se o jogador 'O' ganhou com essa
                // jogada
                if (checkWin(board))
                {
                    // printando caso no arquivo de saída
                    printBoard(outfile, board);
                }

                // se não tiver ganho continua-se até não 
                // sobrarem mais campos em branco
                else
                {
                    // trocando o jogador atual e analizando os
                    // demais casos
                    PLAYER = (PLAYER == 'O' ? 'X' : 'O');
                    possibleGames(infile, board, outfile);
                }

                // após o jogador ter ganho ou todos os casos
                // terem sido analizados o campo volta a sua
                // condição inicial
                board[i][j] = 'B';
            }
        }
    }

    // após o loop a troca do jogador é
    // desfeita
    PLAYER = (PLAYER == 'O' ? 'X' : 'O');
}

// analizando todos os casos de vitória possíveis
int checkWin(char board[][BOARD_SIZE])
{
    // checando se o jogador 'O' venceu em alguma
    // das linhas ou colunas
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] == 'O')
        {
            return 1;
        }
        else if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] == 'O')
        {
            return 1;
        }
    }

    // checando as diagonais
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == 'O')
    {
        return 1;
    }

    else if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] == 'O')
    {
        return 1;
    }
    
    // se ele não ganhar em nenhum dos casos retorna-se
    // falso
    return 0;
}