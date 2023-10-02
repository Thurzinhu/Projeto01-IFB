#include <stdio.h>
#include <stdlib.h>
#include "../include/validate.h"
#include "../include/read.h"
#include "../include/update.h"
#include "../include/rank.h"
#include "../include/write.h"

int main(int argc, char *argv[])
{
    time *times;
    FILE *infile = NULL;
    int num_times = 0, rodadas = 0;

    // checando se o input é válido
    if (validate(argc, argv, &infile, &times))
    {
        read_file(times, infile, &num_times, &rodadas);
    }
    else
    {
        return 2;
    }

    // ranquiando times
    rank(times, num_times);

    // imprimindo resultados no arquivo de saída
    output_file(argv, times, rodadas, num_times);

    // liberando memória alocada
    free(times);
}