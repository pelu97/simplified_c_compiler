lexico: ./src/lexical.l
	# bison -o ./src/syntax.tab.c -dy ./src/syntax.y
	flex -o ./src/lex.yy.c ./src/lexical.l
	gcc ./src/lex.yy.c -o tradutor -Wall

sintatico: ./src/lexical.l ./src/syntax.y ./src/base.c ./src/symbol_table.c ./src/scope.c ./src/tree.c
	bison -o ./src/syntax.tab.c -d ./src/syntax.y
	flex -o ./src/lex.yy.c ./src/lexical.l
	gcc -c ./src/base.c -o ./src/base.o
	gcc -c ./src/symbol_table.c -o ./src/symbol_table.o
	gcc -c ./src/scope.c -o ./src/scope.o
	gcc -c ./src/tree.c -o ./src/tree.o
	gcc -g ./src/lex.yy.c ./src/syntax.tab.c ./src/base.o ./src/symbol_table.o ./src/scope.o ./src/tree.o -o tradutor -Wall

semantico: ./src/lexical.l ./src/syntax.y ./src/base.c ./src/symbol_table.c ./src/scope.c ./src/tree.c ./src/semantic.c
	bison -o ./src/syntax.tab.c -d ./src/syntax.y
	flex -o ./src/lex.yy.c ./src/lexical.l
	gcc -c ./src/base.c -o ./src/base.o
	gcc -c ./src/symbol_table.c -o ./src/symbol_table.o
	gcc -c ./src/scope.c -o ./src/scope.o
	gcc -c ./src/tree.c -o ./src/tree.o
	gcc -c ./src/semantic.c -o ./src/semantic.o
	gcc -g ./src/lex.yy.c ./src/syntax.tab.c ./src/base.o ./src/symbol_table.o ./src/scope.o ./src/tree.o ./src/semantic.o -o tradutor -Wall


run_correct1:
	./tradutor ./tests/test_correct1.c

run_correct2:
	./tradutor ./tests/test_correct2.c

run_correct3:
	./tradutor ./tests/test_correct3.c

run_correct4:
	./tradutor ./tests/test_correct4.c

run_wrong1:
	./tradutor ./tests/test_wrong1.c

run_wrong2:
	./tradutor ./tests/test_wrong2.c

run_tree:
	./tradutor ./tests/test_tree.c

debug_syntax:
	bison -o ./src/syntax.tab.c -dy ./src/syntax.y -Wcounterexamples


debug_symbol_table: ./lib/symbol_table.h ./src/symbol_table.c ./src/debug_symbol_table.c
	gcc -c ./src/symbol_table.c -o ./src/symbol_table.o
	gcc ./src/debug_symbol_table.c ./src/symbol_table.o -o debug_symbol_table -Wall


debug_scope: ./lib/scope.h ./src/scope.c ./src/debug_scope.c
	gcc -c ./src/scope.c -o ./src/scope.o
	gcc ./src/debug_scope.c ./src/scope.o -o debug_scope -Wall


debug_tree: ./lib/tree.h ./src/tree.c ./src/debug_tree.c
	gcc -c ./src/tree.c -o ./src/tree.o
	gcc ./src/debug_tree.c ./src/tree.o -o debug_tree -Wall
