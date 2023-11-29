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
Daniel Saad
01/01/1850
danielsaad
981a16abd878e773ba98c10fd55db367a05f807f2eb5b5c3f2b86efbb218e2e3
03/11/2023
---
Marcus Vinicius
02/02/1950
marquinhos
65e84be33532fb784c48129675f9eff3a682b27168c0ea744b2cf58ee02337c5
20/10/2023
---
Cleidison Santos
24/12/2000
cleidison
d58d736c7a967fb5f307951932734f8b0594725faa5011dbb66a8c538e635fb6
10/5/2021
---      
~~~

### Arquivo de senhas
~~~
swordfish
flamengo
letmein
irobot
qwerty
~~~

### Output
~~~
marquinhos
qwerty
Marcus Vinicius
02/02/1950
---
cleidison
flamengo
Cleidison Soares
24/12/2000
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