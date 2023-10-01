#ifndef WORD_HUNT_H
#define WORD_HUNT_H

#define N 80
#define M 10

// definindo struct palavra com array de chars
// e um status. status == 0 significa que a palavra
// não foi encontrada, status == 1 significa que a palavra
// foi encontrada
typedef struct 
{
    char letras[N];
    int status;
}
palavra;

// modulo de busca
void find(palavra PALAVRAS[M], char MATRIZ[N][N]);
void check_square(palavra PALAVRAS[M], int palavra_idx, int COORDENADAS[N][2], char MATRIZ[N][N]);
int check_word(palavra PALAVRAS[M], int palavra_idx, int COORDENADAS[N][2], char MATRIZ[N][N]);

#endif