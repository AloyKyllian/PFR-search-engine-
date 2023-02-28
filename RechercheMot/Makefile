 # Fait par YOUSSERA ACHACHERA
 # Le 23/01/2023
RechercheMot : rechercheMot.o tstRechercheMot.o
	gcc -o RechercheMot.out rechercheMot.o tstRechercheMot.o -lm

rechercheTexte.o : ../RechercheMot/rechercheMot.c ../RechercheMot/rechercheMot.h
	gcc -c ../RechercheMot/rechercheMot.c

tstRechercheTexte.o : ../RechercheMot/tstRechercheMot.c
	gcc -c tstRechercheMot.c

clean : 
	rm -rf *.o