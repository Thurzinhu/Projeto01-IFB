#include <stdio.h>
#include <string.h>
#include "../include/read.h"
#include "../include/update.h"

void read_file(time times[], FILE *inptr, int *num_times, int *rodadas)
{
    // guardando número de times
    fscanf(inptr, "%i", num_times);
    initialize_teams(times, *num_times);

    // calculando número de rodadas  
    *rodadas = (*num_times - 1) * 2;

    // lendo nome dos times
    char buffer[MAX_CHAR];
    for (int i = 0; i < *num_times; i++)
    {
        // atualizando array global de times
        fscanf(inptr, "%s", buffer);
        strcpy(times[i].clube, buffer);
    }

    // lendo resultado das partidas de
    // cada rodada
    for (int i = 0; i < *rodadas; i++)
    {
        // lendo o separador '---' 
        fscanf(inptr, "%s", buffer);
        for (int j = 0; j < *num_times / 2; j++)
        {
            int gols[2];
            char equipes[2][MAX_CHAR];
            // lendo nome do primeiro time e os
            // gols
            fscanf(inptr, "%s", equipes[0]);
            fscanf(inptr, "%i", &gols[0]);

            // pulando caracteres entre os times ' x ' 
            fseek(inptr, sizeof(char) * 3, SEEK_CUR);

            // lendo os gols do segundo time e seu
            // nome
            fscanf(inptr, "%i", &gols[1]);
            fscanf(inptr, "%s", equipes[1]);

            // definindo pontos de cada time
            int pontos[2];
            get_points(gols, pontos);

            // atualizando status de cada time
            update_status(equipes, times, gols, pontos, *num_times);
        }
    }

    // fechando arquivo de entrada
    fclose(inptr);
}

// inizializando todos os campos de cada time 
void initialize_teams(time times[], int num_times)
{
    for (int i = 0; i < num_times; i++)
    {
        times[i].pontos = 0;
        times[i].vitorias = 0;
        times[i].saldo_gols = 0;
        times[i].gols_a_favor = 0;
        times[i].gols_contra = 0;
    }
}