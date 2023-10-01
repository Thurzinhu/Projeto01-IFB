# Acertou miseravi

Este projeto foi desenvolvido com o intuito de servir como objeto de avaliação para o professor da disciplina de Programação de Computadores 1.

A ideia principal do projeto é implementar uma calculadora que realize cálculos com números inteiros muito grandes.

## Especificação de Entrada

A primeira linha de entrada consiste em um inteiro `N`, que representa o número de operações a serem executadas. As próximas `N` linhas contêm cada uma dois números inteiros `A` e `B` separados por um espaço. 

As restrições para `A` e `B` são as seguintes:  `0 <= A, B <= 10^500`
Cada linha também contém um inteiro `O`, onde `1 <= O <= 3`. Segue o siginificado de cada valor de `O`:

- `1`: Adição
- `2`: Subtração
- `3`: Multiplicação


## Exemplo

| Entrada       | Saída |
|---------------                 |-------                     |
| 3                              |                            |
|289304657819283746 198764532987625412 3|57503505202594706221186003188153352|
|167283984753264758 827381098756432172 2|-660097114003167414|
|281948392098463782 172839483017362738 1|454787875115826520|
| ...           | ...   |

## Implementação

Como não é possível armazenar números tão grandes usando tipos de dados convencionais (por exemplo, `int`), a solução envolve armazenar esses números como texto (`strings`) e realizar os cálculos dígito por dígito. Essa abordagem permite a manipulação de números extremamente grandes em cálculos.

## Compilação
Para compilar o programa basta utilizar o comando : 
~~~C
make 
~~~
e para execução
~~~C
make run
~~~

## Nota final
Gostei muito de desenvolver o projeto, foi desafiador e ao mesmo tempo divertido de fazer. Consolidei conhecimentos acerca de loops e strings e percebi o quanto a modularização é importate conforme o projeto foi tomando proporções maiores.

## Autor

Este código foi inteiramente desenvolvido por Arthur Andrade D'olival, estudante da Instituição IFB, cursando Bacharelado em Ciência da Computação.
