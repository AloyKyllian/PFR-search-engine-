# Fait par YOUSSERA ACHACHERA
# Le 23/01/2023

RechercheMot : rechercheTexte.o tstRechercheTexte.o
	gcc -o RechercheMot.out rechercheTexte.o tstRechercheTexte.o -lm

rechercheTexte.o : ../RechercheTexte/rechercheTexte.c ../RechercheTexte/rechercheTexte.h
	gcc -c ../RechercheTexte/rechercheTexte.c

tstRechercheTexte.o : ../RechercheTexte/tstRechercheTexte.c
	gcc -c tstRechercheTexte.c

clean : 
	rm -rf *.o
