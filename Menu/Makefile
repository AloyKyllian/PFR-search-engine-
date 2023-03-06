# Fait par YASMINE ALLAL YOUSSERA ACHACHERA LOIC MAIGNAN HUGO LESTRADE KYLLIAN ALOY
# Le 23/01/2023
CC=gcc
CFLAGS=-c -g -Wall
LDFLAGS=-lm

.PHONY: clean

PFResearch : Global.o Erreur.o Config.o element.o Pile.o descripteur_texte.o descripteur_audio.o Descripteur_image.o indexation_gene.o Login.o Connexion.o FichierExist.o rechercheMot.o comparaison.o LireResultat.o Menu.o tst_menu.o
	$(CC) $(LDFLAGS) $^ -o $@

Global.o : ../Gestion-Config/Global.c ../Gestion-Config/Global.h 
	$(CC) $(CFLAGS) $< -o $@

Erreur.o : ../Gestion-Erreur/Erreur.c ../Gestion-Erreur/Erreur.h
	$(CC) $(CFLAGS) $< -o $@

Config.o : ../Gestion-Config/Config.c ../Gestion-Config/Config.h 
	$(CC) $(CFLAGS) $< -o $@

Login.o : ../Login/Login.c ../Login/Login.h 
	$(CC) $(CFLAGS) $< -o $@

Connexion.o : ../Connexion/Connexion.c ../Connexion/Connexion.h 
	$(CC) $(CFLAGS) $< -o $@

FichierExist.o : ../Menu/FichierExist.c ../Menu/FichierExist.h 
	$(CC) $(CFLAGS) $< -o $@

rechercheMot.o : ../RechercheMot/rechercheMot.c ../RechercheMot/rechercheMot.h
	$(CC) $(CFLAGS) $< -o $@

LireResultat.o : ../LireResultatRecherche/LireResultat.c ../LireResultatRecherche/LireResultat.h
	$(CC) $(CFLAGS) $< -o $@

comparaison.o : ../comparaison/comparaison.c ../comparaison/comparaison.h 
	$(CC) $(CFLAGS) $< -o $@

Menu.o : ../Menu/Menu.c ../Menu/Menu.h 
	$(CC) $(CFLAGS) $< -o $@

tst_menu.o : ../Menu/tst_menu.c
	$(CC) $(CFLAGS) $< -o $@

element.o : ../Element/element.c ../Element/element.h
	$(CC) $(CFLAGS) $< -o $@

descripteur_texte.o : ../descripteur_texte/descripteur_texte.c ../descripteur_texte/descripteur_texte.h
	$(CC) $(CFLAGS) $< -o $@

descripteur_audio.o : ../descripteur_audio/descripteur_audio.c ../descripteur_audio/descripteur_audio.h
	$(CC) $(CFLAGS) $< -o $@

Descripteur_image.o : ../descripteur_image/Descripteur_image.c ../descripteur_image/Descripteur_image.h
	$(CC) $(CFLAGS) $< -o $@

Pile.o : ../Pile/Pile.c ../Pile/Pile.h
	$(CC) $(CFLAGS) $< -o $@

indexation_gene.o : ../indexgene/indexation_gene.c ../indexgene/indexation_gene.h
	$(CC) $(CFLAGS) $< -o $@

clean :
	rm -rf *.o PFResearch.out
