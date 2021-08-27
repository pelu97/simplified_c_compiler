Um arquivo make foi incluído para facilitar a compilação do tradutor. Basta utilizar o comando make na pasta principal.
Caso ocorra algum problema com o arquivo Make, os comandos podem ser executados manualmente em um terminal:

    flex -o ./src/lex.yy.c ./src/analyser.l
    gcc ./src/lex.yy.c -o tradutor -Wall

As versões dos programas utilizados foram as seguintes:
–Flex: flex 2.6.4
–Make: GNU Make 4.2.1
–GCC: 11.2.0 compilado do código fonte
–OS: Linux 5.8.0-63-generic 20.04.1-Ubuntu
