lexico: ./src/lexical.l
	# bison -o ./src/syntax.tab.c -dy ./src/syntax.y
	flex -o ./src/lex.yy.c ./src/lexical.l
	gcc ./src/lex.yy.c -o tradutor -Wall

sintatico: ./src/lexical.l ./src/syntax.y
	bison -o ./src/syntax.tab.c -dy ./src/syntax.y
	flex -o ./src/lex.yy.c ./src/lexical.l
	gcc ./src/lex.yy.c ./src/syntax.tab.c -o tradutor -Wall

run:
	./tradutor ./tests/test_correct1.c
