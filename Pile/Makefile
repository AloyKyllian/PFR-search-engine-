testpile : ../Element/element.o Pile.c testpile.c
	gcc -c Pile.c
	gcc -c testpile.c
	gcc -Wall -o testpile.out ../Element/element.o Pile.o testpile.o
	
clean :
	rm -rf *.o
