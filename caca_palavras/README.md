# Caça-palavras

Este projeto foi desenvolvido com o intuito de consolidar habilidades de programação com matrizes.

A ideia principal do projeto é implementar um caça-palavras.

## Especificação de Entrada

A primeira linha de entrada consiste em um inteiro `N`, que representa o tamanho do tabuleiro do caça palavras (`N x N`), seguido de um inteiro `M` que indica a quantidade de palavras a serem encontradas. As próximas `M` linhas contêm as palavras que o programa deve localizar.

## Restrições
Tanto o tabuleiro quanto as palavras são dadas em maiúsculas (ambas podem também ser dadas em minúsculas). `2 <= N <= 80` e `1 <= M <= 10`

## Exemplo

### Input
~~~
15 10
ANTARTICO
INDICO
FILA
CUPOM
LOJISTA
SALARIO
IGUAL
ATLANTICO
PACIFICO
DIREITOS
IEHAULOJISTANAE
ACOCUESGIAMFOAM
DNERIAUEEROAVSP
AUTAISFAERALEFO
AQUAAPRECOIAMSD
IIAARTAAAOOABTE
SOMTTTGAUMATRER
SMTINDICOISTOEA
VESSPAOCUPOMQEM
JESALARIOIGUALE
SENRATLANTICOCN
FVTDPOEAFDROADT
AILAAVAPACIFICO
IELAERIDTASNCLE
IQOAMAEDIREITOS        
~~~ 

### Output
~~~
LOJISTA (0, 5) (0, 6) (0, 7) (0, 8) (0, 9) (0, 10) (0, 11)
ANTARTICO (1, 0) (2, 1) (3, 2) (4, 3) (5, 4) (6, 5) (7, 6) (8, 7) (9, 8)
INDICO (7, 3) (7, 4) (7, 5) (7, 6) (7, 7) (7, 8)
CUPOM (8, 7) (8, 8) (8, 9) (8, 10) (8, 11)
SALARIO (9, 2) (9, 3) (9, 4) (9, 5) (9, 6) (9, 7) (9, 8)
IGUAL (9, 9) (9, 10) (9, 11) (9, 12) (9, 13)
ATLANTICO (10, 4) (10, 5) (10, 6) (10, 7) (10, 8) (10, 9) (10, 10) (10, 11) (10, 12)
FILA (11, 0) (12, 1) (13, 2) (14, 3)
PACIFICO (12, 7) (12, 8) (12, 9) (12, 10) (12, 11) (12, 12) (12, 13) (12, 14)
DIREITOS (14, 7) (14, 8) (14, 9) (14, 10) (14, 11) (14, 12) (14, 13) (14, 14)
~~~

## Modularização
O programa foi dividido em três módulos, o primeiro é responsável pela leitura do tabuleiro e das palavras, o segundo encarregado de encontrar as palavras e o terceiro imprime os resultados. 


## Compilação
Para compilar o programa basta utilizar o comando : 
~~~C
make
~~~
e para execução
~~~C
make run
~~~

## Autor

Este código foi inteiramente desenvolvido por Arthur Andrade D'olival, estudante da Instituição IFB, cursando Bacharelado em Ciência da Computação.
