Um arquivo make foi incluído para facilitar a compilação do tradutor. Basta utilizar o comando

    make semantico

na pasta principal.

Caso ocorra algum problema com o arquivo Make, os comandos podem ser executados manualmente em um terminal:

            bison -o ./src/syntax.tab.c -d ./src/syntax.y
            flex -o ./src/lex.yy.c ./src/lexical.l
            gcc -c ./src/base.c -o ./src/base.o
            gcc -c ./src/symbol_table.c -o ./src/symbol_table.o
            gcc -c ./src/scope.c -o ./src/scope.o
            gcc -c ./src/tree.c -o ./src/tree.o
            gcc -c ./src/semantic.c -o ./src/semantic.o
            gcc -g ./src/lex.yy.c ./src/syntax.tab.c ./src/base.o ./src/symbol_table.o ./src/scope.o ./src/tree.o ./src/semantic.o -o tradutor -Wall

As versões dos programas utilizados foram as seguintes:
–Flex: flex 2.6.4
-Bison: GNU Bison 3.7.5 compilado do código fonte
–Make: GNU Make 4.2.1
–GCC: 11.2.0 compilado do código fonte
–OS: Linux 5.8.0-63-generic 20.04.1-Ubuntu
