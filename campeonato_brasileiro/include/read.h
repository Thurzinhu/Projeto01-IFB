#ifndef READ_H
#define READ_H

// definindo número máximo de caracteres
// de nomes de time para 20
#define MAX_CHAR 21
#define MAX_TEAMS 20

// definindo struct time
typedef struct
{
    char clube[MAX_CHAR];
    int pontos;
    int vitorias;
    int saldo_gols;
    int gols_a_favor;
    int gols_contra;
}
time;

void read_file(time times[], FILE *inptr, int *num_times, int *rodadas);

#endif