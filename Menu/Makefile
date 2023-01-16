menu : Global.o Config.o ../indexgene/element.o ../indexgene/Pile.o ../indexgene/descripteur_texte.o  ../indexgene/descripteur_audio.o  ../indexgene/Descripteur_image.o ../indexgene/indexation_gene.o Login.o Connexion.o FichierExist.o Mot.o Menu.o tst_menu.o
	gcc -o Global.o Config.o ../indexgene/element.o ../indexgene/Pile.o ../indexgene/descripteur_texte.o  ../indexgene/descripteur_audio.o  ../indexgene/Descripteur_image.o ../indexgene/indexation_gene.o Login.o Connexion.o FichierExist.o Mot.o Menu.o tst_menu.o -lm

Global.o : ../Gestion-Config/Global.c ../Gestion-Config/Global.h 
	gcc -c ../Gestion-Config/Global.c

Config.o : ../Gestion-Config/Config.c ../Gestion-Config/Config.h 
	gcc -c ../Gestion-Config/Config.c

Login.o : ../Login/Login.c ../Login/Login.h 
	gcc -c ../Login/Login.c

Connexion.o : ../Connexion/Connexion.c ../Connexion/Connexion.h 
	gcc -c ../Connexion/Connexion.c

FichierExist.o : ../Menu/FichierExist.c ../Menu/FichierExist.h 
	gcc -c ../Menu/FichierExist.c

Mot.o : ../RechercheMot/rechercheMot.c ../RechercheMot/rechercheMot.h
	gcc -c -Wall ../RechercheMot/rechercheMot.c

Menu.o : ../Menu/Menu.c ../Menu/Menu.h 
	gcc -c -Wall ../Menu/Menu.c

tst_menu.o : ../Menu/tst_menu.c
	gcc -c ../Menu/tst_menu.c

clean :
	rm -rf *.o