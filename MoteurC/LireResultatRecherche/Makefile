 # Fait par YOUSSERA ACHACHERA 
 # Le 23/01/2023

Lire : element.o Pile.o LireResultat.o tstLireResultat.o
	gcc -o Lire.out element.o Pile.o LireResultat.o tstLireResultat.o -lm

element.o : ../Element/element.c ../Element/element.h
	gcc -c ../Element/element.c

Pile.o : ../Pile/Pile.c ../Pile/Pile.h
	gcc -c ../Pile/Pile.c

LireResultat.o : LireResultat.c LireResultat.h
	gcc -c LireResultat.c

tstLireResultat.o : tstLireResultat.c
	gcc -c tstLireResultat.c

clean : 
	rm -rf *.o