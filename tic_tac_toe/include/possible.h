#ifndef POSSIBLE_H
#define POSSIBLE_H

int checkWin(char board[][BOARD_SIZE]);
void possibleGames(FILE *file, char board[][BOARD_SIZE], FILE *outfile);

#endif