#include <stdio.h>
#include "../include/rank.h"

// ranqueando times
void rank(time times[], int num_times)
{
    // usando selection-sort para ordenar os
    // times baseado nos pontos
    for (int i = 0; i < num_times - 1; i++)
    {
        for (int j = num_times - 1; j > i; j--)
        {
            if (times[i].pontos < times[j].pontos)
            {
                // trocando posição dos times
                swap_teams(times, i, j);
            }
        }
    }

    // verificando empates em número de pontos e, caso
    // haja, compara-se os outros campos para desempate
    int swap;
    do
    {
        swap = 0;
        for (int i = 0; i < num_times - 1; i++)
        {
            // número de pontos iguais utiliza-se saldo de gols
            if (times[i].pontos == times[i + 1].pontos)
            {
                if (times[i].saldo_gols < times[i + 1].saldo_gols)
                {
                    swap_teams(times, i, i + 1);
                    swap = 1;
                }
                // número de pontos e saldo de gols iguais utiliza-se
                // os gols a favor
                else if (times[i].saldo_gols == times[i + 1].saldo_gols)
                {
                    if (times[i].gols_a_favor < times[i + 1].gols_a_favor)
                    {
                        swap_teams(times, i, i + 1);
                        swap = 1;
                    }
                    else if (times[i].gols_a_favor == times[i + 1].gols_a_favor)
                    {
                        // número de pontos, saldo de gols e gols a favor iguais
                        // utiliza-se gols contra
                        if (times[i].gols_contra > times[i + 1].gols_contra)
                        {
                            swap_teams(times, i, i + 1);
                            swap = 1;
                        }
                    }
                }
            }
        }
    }
    while(swap != 0);
}

// troca as posições de determinados times
void swap_teams(time times[], int i, int j)
{
    time aux = times[i];
    times[i] = times[j];
    times[j] = aux;
}