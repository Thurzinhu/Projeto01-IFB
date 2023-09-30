#ifndef OPERATIONS_H
#define OPERATIONS_H

// definindo tamanho máximo da string
// e um macro que transforma um caracter
// para inteiro e outro que faz o contrário
#define MAX 1004
#define stoi(num) (num - '0')
#define itos(num) (num + '0')

// definindo funções
void add(char num_1[MAX], char num_2[MAX]);
void sub(char num_1[MAX], char num_2[MAX]);
void mult(char num_1[MAX], char num_2[MAX]);
void print_result(char *result, int current);

#endif