main:	main.o scanner.o game.o
	gcc -Wall -g -o main main.o scanner.o game.o

scanner.o:	scanner.c scanner.h
	gcc -Wall -g -c scanner.c

main.o:	main.c scanner.h game.h
	gcc -Wall -g -c main.c

game.o:	game.c game.h
	gcc -Wall -g -c game.c

clean:	
	rm -f *.o main
