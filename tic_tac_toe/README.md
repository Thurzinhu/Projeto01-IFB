# Tic Tac Toe

Este projeto foi desenvolvido com o intuito de aprofundar conhecimentos acerca de funções recursivas, além de trabalhar com ponteiros e matrizes.

A ideia principal do projeto é implementar um programa que leia a condição atual de um jogo-da-velha e imprima em um arquivo de saída todas as possibilidades de vitória do jogador `O`.

## Especificação de Entrada

O arquivo de entrada contém três linhas de texto representando um tabuleiro de jogo-da-velha contendo os carácteres `O`, `X` e `B`, onde o último representa que aquele campo está em branco. 

## Exemplo

### Input
~~~
XBO
XBB
OBX      
~~~ 

### Output
~~~
XOO
XOX
OBX

XOO
XOB
OXX

XBO
XOB
OBX

XXO
XOO
OBX

XBO
XOO
OXX

XXO
XOB
OOX

XBO
XOX
OOX
~~~

## Modularização
### O programa foi dividido em quatro módulos: 
- O primeiro é responsável por validar o Input
- O segundo realiza a leitura do tabuleiro
- O terceiro processa todos os casos de vitória possíveis de `O`
- O quarto imprime os jogos ganhos no arquivo de saída

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