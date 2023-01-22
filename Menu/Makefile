menu : Global.o Erreur.o Config.o ../indexgene/element.o ../indexgene/Pile.o ../indexgene/descripteur_texte.o  ../indexgene/descripteur_audio.o  ../indexgene/Descripteur_image.o ../indexgene/indexation_gene.o Login.o Connexion.o FichierExist.o Mot.o lireResultatCompare.o Menu.o tst_menu.o
	gcc -o Global.o Erreur.o Config.o ../indexgene/element.o ../indexgene/Pile.o ../indexgene/descripteur_texte.o  ../indexgene/descripteur_audio.o  ../indexgene/Descripteur_image.o ../indexgene/indexation_gene.o Login.o Connexion.o FichierExist.o Mot.o lireResultatCompare.o Menu.o tst_menu.o -lm

Global.o : ../Gestion-Config/Global.c ../Gestion-Config/Global.h 
	gcc -c ../Gestion-Config/Global.c

Erreur.o : ../Gestion-Erreur/Erreur.c ../Gestion-Erreur/Erreur.h
	gcc -c ../Gestion-Erreur/Erreur.c

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

lireResultatCompare.o : ../LireResultatRecherche/LireResultat.c ../LireResultatRecherche/LireResultat.h
	gcc -c ../LireResultatRecherche/LireResultat.c

Menu.o : ../Menu/Menu.c ../Menu/Menu.h 
	gcc -c -Wall ../Menu/Menu.c

tst_menu.o : ../Menu/tst_menu.c
	gcc -c ../Menu/tst_menu.c

element.o : ../Element/element.c ../Element/element.h
	gcc -c -g ../Element/element.c

descripteur_texte.o : ../descripteur_texte/descripteur_texte.c ../descripteur_texte/descripteur_texte.h
	gcc -c -g ../descripteur_texte/descripteur_texte.c

descripteur_audio.o : ../descripteur_audio/descripteur_audio.c ../descripteur_audio/descripteur_audio.h
	gcc -c -g ../descripteur_audio/descripteur_audio.c

Descripteur_image.o : ../descripteur_image/Descripteur_image.c ../descripteur_image/Descripteur_image.h
	gcc -c -g ../descripteur_image/Descripteur_image.c

Pile.o : ../Pile/Pile.c ../Pile/Pile.h
	gcc -c -g ../Pile/Pile.c

indexation_gene.o : ../indexgene/indexation_gene.c ../indexgene/indexation_gene.h
	gcc -c -g ../indexgene/indexation_gene.c

clean :
	rm -rf *.o