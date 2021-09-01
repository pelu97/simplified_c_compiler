lexico: ./src/lexical.l
	# bison -o ./src/syntax.tab.c -dy ./src/syntax.y
	flex -o ./src/lex.yy.c ./src/lexical.l
	gcc ./src/lex.yy.c -o tradutor -Wall

sintatico: ./src/lexical.l ./src/syntax.y
	bison -o ./src/syntax.tab.c -dy ./src/syntax.y
	flex -o ./src/lex.yy.c ./src/lexical.l
	gcc -c ./src/base.c -o ./src/base.o
	gcc -c ./src/symbol_table.c -o ./src/symbol_table.o
	gcc ./src/lex.yy.c ./src/syntax.tab.c ./src/base.o ./src/symbol_table.o -o tradutor -Wall

run_correct1:
	./tradutor ./tests/test_correct1.c

run_correct2:
	./tradutor ./tests/test_correct2.c

run_correct3:
	./tradutor ./tests/test_correct3.c

run_wrong1:
	./tradutor ./tests/test_wrong1.c

debug_syntax:
	bison -o ./src/syntax.tab.c -dy ./src/syntax.y -Wcounterexamples


debug_symbol_table: ./src/symbol_table.h ./src/symbol_table.c ./src/debug_symbol_table.c
	gcc -c ./src/symbol_table.c -o ./src/symbol_table.o
	gcc ./src/debug_symbol_table.c ./src/symbol_table.o -o debug_symbol_table -Wall
