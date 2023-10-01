#include <stdio.h>
#include <string.h>
#include "../include/word_hunt.h"
#include "../include/write.h"

void find(palavra palavras[M], char tabuleiro[N][N])
{
    // interando sobre cada linha do tabuleiro
    // saindo do loop se a string começa com o char NUL
    for (int i = 0; i < N && tabuleiro[i][0] != '\0'; i++)
    {
        // interando sobre cada coluna do tabuleiro
        // saindo do loop quando ultrapassar as barreiras da matriz
        for (int j = 0; j < N && tabuleiro[i][j] != '\0'; j++)
        {
            // interando sobre todas as palavras que devem ser encontradas
            for (int k = 0; k < M && palavras[k].letras[0] != '\0'; k++)
            {
                // checando se a letra atual corresponde a primeira letra 
                // de alguma das palavras e se tal palavra ainda não foi encontrada
                if ((palavras[k].letras[0] == tabuleiro[i][j]) && (palavras[k].status == 0))
                {
                    int coordenadas[N][2];

                    // salvando coordenadas da primeira letra
                    coordenadas[0][0] = i;
                    coordenadas[0][1] = j;

                    // encontrada a primeira letra checa-se as redondezas
                    check_square(palavras, k, coordenadas, tabuleiro);
                }
            }
        }
    }
}

void check_square(palavra palavras[M], int palavra_idx, int coordenadas[N][2], char tabuleiro[N][N])
{
    // definindo linhas e colunas de fim e início e, assim, delimitando
    // uma área de busca pela segunda letra da palavra
    int linha_inicial = coordenadas[0][0] - 1, linha_final = coordenadas[0][0] + 1;
    int coluna_inicial = coordenadas[0][1] - 1, coluna_final = coordenadas[0][1] + 1;

    for (int i = linha_inicial; i <= linha_final; i++)
    {
        for (int j = coluna_inicial; j <= coluna_final; j++)
        {
            // se ultrapassarmos a barreira do tabuleiro do caça palavras
            // o loop vai para o proximo caso
            if ((i < 0) || (j < 0) || (tabuleiro[i][0] == '\0') || (tabuleiro[i][j] == '\0')
                || ((i == coordenadas[0][0]) && (j == coordenadas[0][1])))
            {
                continue;
            }
            
            // se encontrarmos a segunda letra dentro do bloco
            // analizamos o caso
            else if (tabuleiro[i][j] == palavras[palavra_idx].letras[1])
            {
                coordenadas[1][0] = i;
                coordenadas[1][1] = j;
                
                // checando se a palavra foi encontrada
                if (check_word(palavras, palavra_idx, coordenadas, tabuleiro))
                {
                    print_word(palavra_idx, coordenadas, palavras);
                }
            }
        }
    }
}

// baseando-se nas coordenadas da primeira e da segunda letra 
// checa-se se é possível encontrar a palavra por esse caminho 
int check_word(palavra palavras[M], int palavra_idx, int coordenadas[N][2], char tabuleiro[N][N])
{
    // definindo valores da linha e coluna iniciais assim como da linha e coluna atuais, 
    // além da variação das linhas e das colunas
    int linha_inicial = coordenadas[0][0], linha_atual = coordenadas[1][0],
        coluna_inicial = coordenadas[0][1], coluna_atual = coordenadas[1][1],
        variacao_linha = linha_atual - linha_inicial, variacao_coluna = coluna_atual - coluna_inicial;

    for (int i = 2, length = strlen(palavras[palavra_idx].letras); i < length; i++)
    {
        // valores da linha e coluna atuais se atualizam conforme a variação das linhas e colunas
        linha_atual += variacao_linha;
        coluna_atual += variacao_coluna;
        
        // se a posição atual na matriz não condiz com a letra
        // i-ésima letra da palavra retorna-se falso  
        if (tabuleiro[linha_atual][coluna_atual] != palavras[palavra_idx].letras[i])
        {
            return 0;
        }
        
        // guardando as coordenadas de cada letra da palavra
        else
        {
            coordenadas[i][0] = linha_atual;
            coordenadas[i][1] = coluna_atual;
        }

    }
    return 1;
}