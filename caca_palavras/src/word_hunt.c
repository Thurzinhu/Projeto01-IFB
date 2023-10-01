#include <stdio.h>
#include "../include/word_hunt.h"

void find(palavra PALAVRAS, int MATRIZ[N][N])
{
    for (int i = 0; i < N; i++)
    {
        // saindo do loop se a string
        // começa com o char NUL
        if (MATRIZ[i][0] == '\0')
        {
            break;
        }

        for (int j = 0; j < N; j++)
        {
            // saindo do loop quando ultrapassar
            // as barreiras da matriz
            if (MATRIZ[i][j] == '\0')
            {
                break;
            }

            for (int k = 0; k < M; k++)
            {
                // checando se a letra atual corresponde
                // a primeira letra de alguma das palavras
                // e se tal palavra ainda não foi encontrada
                if ((PALAVRAS[k].letras[0] == MATRIZ[i][j]) && (PALAVRAS[k].status == 0))
                {
                    int COORDENADAS[N][2] = {0};
                    COORDENADAS[0][0] = i;
                    COORDENADAS[0][1] = j;
                    check_square(k, COORDENADAS);
                }

                // se a palavra começar por NUL o loop
                // é quebrado
                else if (PALAVRAS[k].letras[0] == '\0')
                {
                    break;
                }
            }
        }
    }
}

void check_square(int palavra_idx, int COORDENADAS[N][2])
{
    // definindo linhas e colunas de fim e inicio
    int linha_in = COORDENADAS[0][0] - 1, linha_fin = COORDENADAS[0][0] + 1;
    int coluna_in = COORDENADAS[0][1] - 1, coluna_fin = COORDENADAS[0][1] + 1;

    for (int i = linha_in; i <= linha_fin; i++)
    {
        for (int j = coluna_in; j <= coluna_fin; j++)
        {
            // se ultrapassarmos a barreira da matriz
            // o loop vai para o proximo caso
            if ((i < 0) || (j < 0) || (MATRIZ[i][0] == '\0') || (MATRIZ[i][j] == '\0')
                || ((i == COORDENADAS[0][0]) && (j == COORDENADAS[0][1])))
            {
                continue;
            }
            
            // se encontrarmos a segunda letra dentro do bloco
            // analizamos o caso
            else if (MATRIZ[i][j] == PALAVRAS[palavra_idx].letras[1])
            {
                COORDENADAS[1][0] = i;
                COORDENADAS[1][1] = j;
                
                // checando se a palavra foi encontrada
                if (check_word(palavra_idx))
                {
                    print_word(palavra_idx);
                }
            }
        }
    }
}

// baseando-se nas coordenadas da primeira e da
// segunda letra checa-se se é possível encontrar a
// palavra por esse caminho 
int check_word(int palavra_idx, int COORDENADAS[N][2], int MATRIZ[N][N])
{
    // definindo valores da linha e coluna iniciais assim como
    // da linha e coluna atuais, além da variação das linhas e das
    // colunas
    int linha_in = COORDENADAS[0][0], linha_at = COORDENADAS[1][0],
        coluna_in = COORDENADAS[0][1], coluna_at = COORDENADAS[1][1],
        variacao_linha = linha_at - linha_in, variacao_coluna = coluna_at - coluna_in;

    int length = strlen(PALAVRAS[palavra_idx].letras);
    for (int i = 2; i < length; i++)
    {
        // valores da linha e coluna atuais se atualizam
        // conforme a variação das linhas e colunas
        linha_at += variacao_linha;
        coluna_at += variacao_coluna;
        
        // se a posição atual na matriz não condiz com a letra
        // de posição 'i' da palavra retorna-se falso  
        if (MATRIZ[linha_at][coluna_at] != PALAVRAS[palavra_idx].letras[i])
        {
            return 0;
        }
        
        // guardando as coordenadas de cada letra da palavra
        else
        {
            COORDENADAS[i][0] = linha_at;
            COORDENADAS[i][1] = coluna_at;
        }

    }
    return 1;
}