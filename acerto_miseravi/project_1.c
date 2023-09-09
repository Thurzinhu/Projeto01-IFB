#include <stdio.h>
#include <string.h>

// definindo tamanho máximo da string
// e um macro que transforma um caracter
// para inteiro e outro que faz o contrário
#define MAX 1004
#define stoi(num) (num - '0')
#define itos(num) (num + '0')

// definindo funções
void sum(char num_1[MAX], char num_2[MAX]);
void subtraction(char num_1[MAX], char num_2[MAX]);
void multiply(char num_1[MAX], char num_2[MAX]);
void print_result(char *result, int current);

int main(){
    // lendo número de operações
    int n;
    scanf("%i", &n);

    // criando strings dos números
    char num_1[MAX], num_2[MAX];
    for (int i = 0; i < n; i++){
        int operation;
        scanf(" %s %s %i", num_1, num_2, &operation);

        // realizando as operações
        switch (operation){
            case 1:
                sum(num_1, num_2);
                break;
            case 2:
                subtraction(num_1, num_2);
                break;
            case 3:
                multiply(num_1, num_2);
                break;
        }
    }

    return 0;
}

void sum(char num_1[MAX], char num_2[MAX]){

    // string do resultado
    char result[MAX];
    int current = MAX - 1;
    result[current] = '\0';

    // começando dos últimos caracteres de ambos os números.
    // somando digito a digito até que ambos ultrapassem seus
    // limites
    int length_num_1 = strlen(num_1), length_num_2 = strlen(num_2), aux = 0;
    for (int i = length_num_1 - 1, j = length_num_2 - 1; i >= 0 || j >= 0; i--, j--){
        int digit;
        if (i < 0){
            digit = (stoi(num_2[j]) + aux);
        } else if (j < 0){
            digit = (stoi(num_1[i]) + aux);
        } else{
            digit = (stoi(num_1[i]) + stoi(num_2[j])) + aux;
        }

        // se somarmos os digitos e o resultado for maior do que
        // dez precisamos passar a dezena para a próxima soma.
        aux = digit / 10;
        digit %= 10;

        // salvando digito na string resultado
        current--;
        result[current] = itos(digit);
    }

    // colocando o valor aux na primeira posição
    // caso ele seja diferente de 0
    if (aux){
        current--;
        result[current] = itos(aux);
    }

    print_result(result, current);
}

void subtraction(char num_1[MAX], char num_2[MAX]){
    int length_num_1 = strlen(num_1), length_num_2 = strlen(num_2);
    int greatest_1 = 1;

    // definindo o maior número
    if (length_num_1 == length_num_2){

        // analizando cada caracter de ambos os números.
        // se um for maior que o outro significa que o
        // número em questão é o maior
        for (int i = 0; i < length_num_1; i++){
            if (num_1[i] > num_2[i]){
                break;
            } else if (num_2[i] > num_1[i]){
                greatest_1 = 0;
                break;
            }
        }

    } else if (length_num_1 < length_num_2){
        // se o tamanho do primeiro for menor
        // que do segundo o segundo é o maior
        greatest_1 = 0;
    }

    // caso o primeiro número não seja o maior
    // trocamos a posição dos números, e acrescentamos
    // um sinal de negativo
    if (!greatest_1){
        char *aux = num_1;
        num_1 = num_2;
        num_2 = aux;
        length_num_1 = strlen(num_1);
        length_num_2 = strlen(num_2);
        printf("-");
    }

    // string do resultado
    char result[MAX];
    int current = MAX - 1;
    result[current] = '\0';

    // começando dos últimos caracteres de ambos os números.
    // subtraimos digito a digito até que ambos ultrapassem
    // seus limites
    for (int i = length_num_1 - 1, j = length_num_2 - 1; i >= 0 || j >= 0; i--, j--){
        int digit;
        if (i < 0){
            digit = (stoi(num_2[j]));
        } else if (j < 0){
            digit = (stoi(num_1[i]));
        } else{
            digit = (stoi(num_1[i])) - (stoi(num_2[j]));
        }

        // se ápos a subtração o digito for menor que 0
        // precisamos pegar uma dezena do digito mais próximo
        if (digit < 0){
            // adicionando uma dezena ao valor do digito
            digit += 10;

            // procurando o número mais próximo para
            // retirar a dezena
            int count = i - 1;
            while (num_1[count] == '0'){
                num_1[count] += 9;
                count--;
            }
            // retirando a dezena do número que a cedeu
            num_1[count] -= 1;
        }

        // salvando digito na string resultado
        current--;
        result[current] = itos(digit);
    }

    print_result(result, current);

}

void multiply(char num_1[MAX], char num_2[MAX]){
    // string do resultado
    char result[MAX] = {0};
    int current = MAX - 1;
    result[current] = '\0';

    // multiplicando cada digito de ambos os números
    int length_num_1 = strlen(num_1), length_num_2 = strlen(num_2);
    for (int i = length_num_2 - 1; i >= 0; i--){
        int digit, aux = 0;
        current = MAX - 1;

        // multiplicando por 10 a cada divisão
        for (int k = i; k != length_num_2 - 1; k++){
            current--;
        }

        for (int j = length_num_1 - 1; j >= 0; j--){

            digit = (stoi(num_2[i]) * stoi(num_1[j])) + aux;

            // guardando a dezena para somar na próxima
            // multiplicação
            aux = digit / 10;
            digit %= 10;

            current--;
            result[current] += digit;

            // se o valor do digito for maior que dez
            // passamos para a próxima casa
            if (result[current] >= 10){
                aux += result[current] / 10;
                result[current] %= 10;
            }
        }

        // colocando o valor aux na primeira posição
        // caso ele seja diferente de 0
        if (aux){
            current--;
            result[current] += aux;
        }
    }

    // transformando cada digito para o formato ASCII
    for (int i = current; i != MAX - 1; i++){
        result[i] = itos(result[i]);
    }

    print_result(result, current);
}

void print_result(char *result, int current){
    // pulando zeros à esquerda
    while(result[current] == '0' && result[current + 1] != '\0'){
        current++;
    }

    // printando resultado
    for (int i = current; result[i] != '\0'; i++){
        printf("%c", result[i]);
    }
    printf("\n");
}