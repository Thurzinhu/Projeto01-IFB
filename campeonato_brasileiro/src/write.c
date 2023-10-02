#include <stdio.h>
#include "../include/write.h"

// imprimindo resultados para arquivo de saída
void output_file(char *argv[], time times[], int rodadas, int num_times)
{
    FILE *outptr = fopen(argv[2], "w");

    fprintf(outptr, "P\t\tClube\t\t  PT PJ VIT SG GM GC\n");
    for (int i = 0; i < num_times; i++)
    {
        fprintf(outptr, "%02d %-18s ", i + 1, times[i].clube);

        fprintf(outptr, "%02d %02d %02d %03d %02d %02d\n", times[i].pontos, rodadas, times[i].vitorias,
                times[i].saldo_gols, times[i].gols_a_favor, times[i].gols_contra);
    }

    // fechando arquivo de saída
    fclose(outptr);
}