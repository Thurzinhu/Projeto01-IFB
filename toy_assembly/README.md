# Toy Assembly

Este projeto foi desenvolvido com o intuito de servir como objeto de avaliação para o professor da disciplina de Programação de Computadores 1.

A ideia principal do projeto é implementar um interpretador Assembly na linguagem de programação C.

## Especificação de Entrada

A primeira linha de entrada contém um inteiro `N` que representa a quantidade de instruções Assembly. As próximas `N` linhas contém cada uma instrução. Segue a tabela de instruções:

| Instrução              | Descrição                                                                                                      |
|------------------------|----------------------------------------------------------------------------------------------------------------|
| `MOV RX INTEIRO`       | Atribui a `RX` o valor do `INTEIRO`.                                                                         |
| `MOV RX RY`            | Atribui a `RX` o valor de `RY`.                                                                              |
| `ADD RX RY RZ`         | Soma os valores de `RY` e `RZ` e armazena o resultado em `RX`.                                                |
| `SUB RX RY RZ`         | Subtrai `RZ` de `RY` e armazena o resultado em `RX`.                                                         |
| `MUL RX RY RZ`         | Multiplica `RY` por `RZ` e armazena o resultado em `RX`.                                                      |
| `DIV RX RY RZ`         | Divide `RY` por `RZ` e armazena o resultado em `RX`. A divisão é inteira, ou seja, a parte fracionária é desprezada. |
| `MOD RX RY RZ`         | Toma o resultado de `RY` mod `RZ` e armazena o resultado em `RX`. O resultado `RX` da operação de mod é sempre `0 ≤ RX < RZ`. |
| `BEQ RX RY ENDERECO`   | O fluxo do programa é direcionado para a instrução que ocupa a linha de número `ENDERECO` caso `RX` seja igual a `RY`. |
| `BLT RX RY ENDERECO`   | O fluxo do programa é direcionado para a instrução que ocupa a linha de número `ENDERECO` caso `RX` seja menor que `RY`. |
| `JMP ENDERECO`         | O fluxo do programa é direcionado para a instrução que ocupa a linha de número `ENDERECO`. |
| `LOAD RX RY`           | Carrega o conteúdo de `memoria[RY]` para o registrador `RX`. |
| `STORE RX RY`          | Carrega o conteúdo de `RX` para `memoria[RY]`. |
| `PRINT RX`             | Imprime uma linha na tela com o valor de `RX`. |
|`EXIT`                    | Encerra o programa             |

## Restrições
O número `N` de instruções é menor ou igual a cem e é garantido que o programa é sintaticamente correto. `1 <= N <= 100`

## Exemplo

### Input
~~~
16
MOV R0 1
MOV R1 1
MOV R2 2
MOV R3 2
MOV R4 10
MOV R5 1
PRINT R0
PRINT R1
BEQ R3 R4 15
ADD R2 R1 R0
PRINT R2
MOV R0 R1
MOV R1 R2
ADD R3 R3 R5
JMP 8
EXIT       
~~~ 

### Output
~~~
1
1
2
3
5
8
13
21
34
55
~~~

## Modularização
### O programa foi dividido em quatro módulos: 
- O primeiro é responsável por realizar a leitura das instruções
- O segundo interpreta as instruções lidas
- O terceiro imprime o valor contido no registrador especificado
- O quarto realiza as operações aritméticas, lógicas, na memória e de atribuição

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