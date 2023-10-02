#include <stdio.h>
#include <string.h>
#include "../include/update.h"

void get_points(int gols[], int pontos[])
{
    // vitória time 1
    if (gols[0] > gols[1])
    {
        pontos[0] = 3;
        pontos[1] = 0;
    }
    // vitória time 2
    else if (gols[0] < gols[1])
    {
        pontos[0] = 0;
        pontos[1] = 3;
    }
    // empate
    else
    {
        pontos[0] = 1;
        pontos[1] = 1;
    }
}

// atualizando os status de cada time de 
// acordo com cada jogo
void update_status(char equipes[][MAX_CHAR], time times[], int gols[], int pontos[], int num_times)
{
    // variável para quebrar o loop quando
    // os dados dos dois times forem atualizados
    int skip = 0;

    for (int i = 0; i < num_times; i++)
    {
        // comparando o primeiro time com a variável
        // global de times, caso os nomes sejam iguais os status
        // desse clube são atualizados
        if (strcmp(equipes[0], times[i].clube) == 0)
        {
            times[i].pontos += pontos[0];
            times[i].gols_a_favor += gols[0];
            times[i].gols_contra += gols[1];
            times[i].saldo_gols += gols[0] - gols[1];
            if (pontos[0] == 3)
            {
                times[i].vitorias += 1;
            }

            // status de um dos times atualizado
            skip++;
        }

        // comparando o segundo time com a variável
        // global de times, caso os nomes sejam iguais os status
        // desse clube são atualizados
        else if (strcmp(equipes[1], times[i].clube) == 0)
        {
            times[i].pontos += pontos[1];
            times[i].gols_a_favor += gols[1];
            times[i].gols_contra += gols[0];
            times[i].saldo_gols += gols[1] - gols[0];
            if (pontos[1] == 3)
            {
                times[i].vitorias += 1;
            }

            // status de um dos times atualizado
            skip++;
        }

        // status de ambos os times foram atualizados,
        // quebra-se o loop
        if (skip == 2)
        {
            break;
        }
    }
}