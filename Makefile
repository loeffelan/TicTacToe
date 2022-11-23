TicTacToe: Main.o
	gcc Main.o -o TicTacToe;

Main.o: Main.c
	gcc -c Main.c;

clean: 
	rm *.o TicTacToe

clean.o:
	rm *.o

run: TicTacToe
	make;
	clear;
	./TicTacToe;
