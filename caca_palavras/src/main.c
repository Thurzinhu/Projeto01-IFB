#include "../include/read.h"
#include "../include/word_hunt.h"
#include "../include/write.h"

int main()
{
    palavra words;
    int board[N][N];
    read(words, board);

    find(words, board);
}