run: main.c aluno.c listaAluno.c 
	gcc -ggdb -std=c99 -Wall -Werror -o main *.c

clean:
	rm -f *.o main core main

test: 
	valgrind --leak-check=full --show-leak-kinds=all ./main entrada.txt -s