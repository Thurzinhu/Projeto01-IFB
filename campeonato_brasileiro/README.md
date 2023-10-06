# Campeonato brasileiro

Este projeto foi desenvolvido com o intuito de consolidar habilidades de programação com ponteiros e arquivos.

A ideia principal do projeto é implementar um programa que receba os resultados das partidas de um campeonato e exiba a tabela em um arquivo.

## Especificação de Entrada

A primeira linha de entrada do arquivo que contém os resultados de todas as rodadas contém um inteiro `N` que representa a quantidade de times que disputaram esse campeonato. As próximas `N` linhas contém cada o nome de um clube. As linhas que seguem contém o resultado de todas as partidas por rodada, sendo cada rodada separada por um marcador.

## Restrições
A quantidade `T` de times deve ser menor ou igual a 20 e o nome do clube `C` não pode exceder 20 caracteres. `1 <= T, C <= 20`

## Exemplo

### Input
~~~
4
juventude
cuiaba
flamengo
internacional
---
juventude 2 x 3 internacional
cuiaba 5 x 5 flamengo
---
juventude 0 x 5 flamengo
internacional 0 x 1 cuiaba
---
juventude 4 x 0 cuiaba
flamengo 5 x 0 internacional
---
internacional 1 x 0 juventude
flamengo 4 x 5 cuiaba
---
flamengo 5 x 4 juventude
cuiaba 2 x 1 internacional
---
cuiaba 3 x 5 juventude
internacional 1 x 5 flamengo
---        
~~~ 

### Output
~~~
P		Clube		  PT PJ VIT SG GM GC
01 flamengo           13 06 04 014 29 15
02 cuiaba             10 06 03 -03 16 19
03 juventude          06 06 02 -02 15 17
04 internacional      06 06 02 -09 06 15
~~~

## Modularização
### O programa foi dividido em cinco módulos: 
- O primeiro é responsável por validar o input
- O segundo lê as informações do arquivo de entrada
- O terceiro atualiza os atributos de cada time
- O quarto ranqueia os times 
- O quinto é responsável por imprimir a tabela no arquivo de saída

## Compilação
Para compilar o programa basta utilizar o comando : 
~~~C
make
~~~
e para execução
~~~C
make run
~~~

Para mudar o arquivo de leitura, basta alterar a variável INFILE no arquivo makefile para o nome do arquivo desejado.

## Autor

Este código foi inteiramente desenvolvido por Arthur Andrade D'olival, estudante da Instituição IFB, cursando Bacharelado em Ciência da Computação.