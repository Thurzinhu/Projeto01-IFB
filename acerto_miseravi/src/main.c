#include <stdio.h>
#include "../include/operations.h"

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
                add(num_1, num_2);
                break;
            case 2:
                sub(num_1, num_2);
                break;
            case 3:
                mult(num_1, num_2);
                break;
        }
    }

    return 0;
}