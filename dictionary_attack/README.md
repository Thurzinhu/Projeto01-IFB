# Dictionary Attack

Este projeto foi desenvolvido com o intuito de servir como objeto de avaliação para o professor da disciplina de Programação de Computadores 1.

O objetivo principal é implementar um programa que leia dados de usuários de um arquivo e senhas fracas de outro arquivo. O programa então criptografa as senhas fracas usando o algoritmo SHA-256 e verifica se algum usuário utiliza essas senhas. Se sim, os dados da pessoa com a senha quebrada são impressos em um arquivo de saída.

## Especificação de Entrada

O programa recebe três nomes de arquivos via linha de comando.

### Primeiro Arquivo (Usuários)
Contém informações dos usuários no seguinte formato:

| Campo                    | Restrição                                 |
| ------------------------ | ----------------------------------------- |
| Nome Completo            | Até 50 caracteres                         |
| Data de Nascimento       | DD/MM/AAAA                                |
| Login                    | Até 20 caracteres                         |
| Senha Criptografada      | SHA-256 (64 caracteres)                   |
| Última Alteração de Senha| DD/MM/AAAA                                |
| ---                      | ---                                       |

### Segundo Arquivo (Senhas Fracas)
Contém senhas fracas, uma por linha.

### Terceiro Arquivo (Relatório)
Nome do arquivo que conterá dados dos usuários com senhas quebradas:

| Campo                 |
| --------------------- |
| Login                 |
| Senha em Claro        |
| Nome Completo         |
| Data de Nascimento    |

## Exemplo

### Arquivo de Usuários
~~~
Virginia
1/7/2022
ronaldrodriguez
b6f8d434a847fb0f0c1a8d9b936b8ca952e224f205a55f4ba9b2c20f88fdc9e7
21/6/2011
---
Kimberly
2/2/2007
josephwhite
04e77bf8f95cb3e1a36a59d1e93857c411930db646b46c218a0352e432023cf2
12/10/2012
---
Michelle
16/7/2017
jonathanthomas
fcc3a23fc7232cc89c7cb0f23d8774fefb73d7dc2ab22e6a1b6b8b202b4dcc91
4/3/2000
---
Matthew
14/5/2019
susanthompson
a92f6bdb75789bccc118adfcf704029aa58063c604bab4fcdd9cd126ef9b69af
7/12/2005
---
Michael
28/3/2019
thomaslopez
408c7c5887a0f3905767754f424989b0089c14ac502d7f851d11b31ea2d1baa6
24/8/2012
---  
~~~

### Arquivo de senhas
~~~
martin
sv48A
princess
CLvTyd77
mustang
7J25eFU3
canada
1BBOzmQRHJQ
~~~

### Output
~~~
ronaldrodriguez
martin
Virginia
1/7/2022
---
josephwhite
princess
Kimberly
2/2/2007
---
susanthompson
mustang
Matthew
14/5/2019
---
thomaslopez
canada
Michael
28/3/2019
---
~~~

## Observações

- A array de usuários deve ser alocada dinamicamente.
- O algoritmo SHA-256 é usado nas senhas fracas.

## Modularização

### Módulo de Leitura
Responsável por ler os arquivos de usuários e senhas fracas, armazenando os dados em uma estrutura adequada.

### Módulo de Saída
Gera o relatório de quebras, formatando as informações dos usuários com senhas comprometidas.

### Módulo Criptográfico
Aplica a função SHA256 para criptografar as senhas fracas.

### Módulo de Quebra
Quebra as senhas comparando os hashes das senhas criptografadas com as senhas fracas.

### Módulo Principal
Coordena a execução do programa, chamando os outros módulos.

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