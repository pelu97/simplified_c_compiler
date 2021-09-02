lexico: ./src/lexical.l
	# bison -o ./src/syntax.tab.c -dy ./src/syntax.y
	flex -o ./src/lex.yy.c ./src/lexical.l
	gcc ./src/lex.yy.c -o tradutor -Wall

sintatico: ./src/lexical.l ./src/syntax.y
	bison -o ./src/syntax.tab.c -dy ./src/syntax.y
	flex -o ./src/lex.yy.c ./src/lexical.l
	gcc -c ./lib/base.c -o ./lib/base.o
	gcc -c ./lib/symbol_table.c -o ./lib/symbol_table.o
	gcc -c ./lib/scope.c -o ./lib/scope.o
	gcc ./src/lex.yy.c ./src/syntax.tab.c ./lib/base.o ./lib/symbol_table.o ./lib/scope.o -o tradutor -Wall

run_correct1:
	./tradutor ./tests/test_correct1.c

run_correct2:
	./tradutor ./tests/test_correct2.c

run_correct3:
	./tradutor ./tests/test_correct3.c

run_wrong1:
	./tradutor ./tests/test_wrong1.c

run_wrong2:
	./tradutor ./tests/test_wrong2.c

debug_syntax:
	bison -o ./src/syntax.tab.c -dy ./src/syntax.y -Wcounterexamples


debug_symbol_table: ./src/symbol_table.h ./src/symbol_table.c ./src/debug_symbol_table.c
	gcc -c ./src/symbol_table.c -o ./src/symbol_table.o
	gcc ./src/debug_symbol_table.c ./src/symbol_table.o -o debug_symbol_table -Wall


debug_scope: ./src/scope.h ./src/scope.c ./src/debug_scope.c
	gcc -c ./src/scope.c -o ./src/scope.o
	gcc ./src/debug_scope.c ./src/scope.o -o debug_scope -Wall
