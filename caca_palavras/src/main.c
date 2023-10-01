#include "../include/read.h"
#include "../include/word_hunt.h"
#include "../include/write.h"

int main()
{
    palavra words[M];
    char board[N][N];
    
    // lendo input
    read(words, board);

    // iniciando busca
    find(words, board);
}