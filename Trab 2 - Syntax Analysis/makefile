lexico: ./src/lexical.l
	flex -o ./src/lex.yy.c ./src/lexical.l
	# bison -d ./src/syntax.y
	gcc ./src/lex.yy.c -o tradutor -Wall
