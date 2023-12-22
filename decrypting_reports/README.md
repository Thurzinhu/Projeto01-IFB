# Decifrando Relatórios

Este projeto foi desenvolvido com o intuito de servir como objeto de avaliação para o professor da disciplina de Programação de Computadores 1.

O objetivo é decifrar relatórios envolvendo transações ilegais encontradas pela polícia federal na operação "Gizé". O programa recebe um arquivo de entrada com informações criptografadas sobre transações e gera um arquivo de saída com os resultados da decifração.

## Especificação de Entrada

O programa recebe dois arquivos como entrada via linha de comando.

### Arquivo de Entrada
O arquivo de entrada contém três linhas, representando as palavras A, B e C de uma transação cifrada, onde C equivale à soma de A e B. As palavras são compostas por letras maiúsculas, cada uma representando um algarismo.

As palavras não ultrapassam 8 caracteres, e o número de caracteres distintos nas três palavras é no máximo 7.

### Arquivo de Saída
O programa gera um arquivo de saída com as seguintes informações:

- A primeira linha contém o maior valor possível de C. Se não for possível decifrar a transação, o valor impresso é `-1`.

- Nas linhas subsequentes, o programa descreve a correspondência utilizada para obter os números da transação no formato `c : d`, onde c é uma letra e d é um algarismo.

## Exemplo

### Input
~~~
SEND
MORE
MONEY      
~~~

### Output
~~~
11099
D: 0
E: 9
M: 1
N: 0
O: 1
R: 9
S: 9
Y: 9
~~~

## Observações
- Letras distintas podem assumir os mesmos valores
- As palavras A, B ou C não tem zeros à esqueda, mas podem ser iguais à zero.

## Modularização

O sistema é dividido em módulos, cada um com uma tarefa específica:

- **Entrada:** Responsável por ler os relatórios de um arquivo de texto.
- **Saída:** Imprime o resultado da decifração em um arquivo de texto.
- **Processamento:** Decifra os relatórios, caso possível.
- **Tratamento de erros:** Captura erros e reporta ao usuário, se necessário.

## Compilação
Para compilar o programa basta utilizar o comando: 
~~~C
make
~~~
e para execução
~~~C
make run
~~~

## Autor

Este código foi inteiramente desenvolvido por Arthur Andrade D'olival, estudante da Instituição IFB, cursando Bacharelado em Ciência da Computação.