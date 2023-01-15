menu : Global.o Config.o Login.o Connexion.o FichierExist.o Mot.o Menu.o tst_menu.o indexation_gene.o  element.o  descripteur_texte.o  descripteur_audio.o  Descripteur_image.o  Pile.o
	gcc -o menu.out Global.o Config.o Login.o Connexion.o FichierExist.o rechercheMot.o Menu.o tst_menu.o indexation_gene.o element.o  descripteur_texte.o  descripteur_audio.o  Descripteur_image.o  Pile.o -lm
	valgrind --leak-check=full --show-leak-kinds=all -s ./menu.out


Global.o : ../Gestion-Config/Global.c ../Gestion-Config/Global.h 
	gcc -c -g ../Gestion-Config/Global.c

Config.o : ../Gestion-Config/Config.c ../Gestion-Config/Config.h 
	gcc -c -g ../Gestion-Config/Config.c

Login.o : ../Login/Login.c ../Login/Login.h 
	gcc -c -g ../Login/Login.c

Connexion.o : ../Connexion/Connexion.c ../Connexion/Connexion.h 
	gcc -c -g ../Connexion/Connexion.c

FichierExist.o : ../Menu/FichierExist.c ../Menu/FichierExist.h 
	gcc -c -g ../Menu/FichierExist.c

Mot.o : ../RechercheMot/rechercheMot.c ../RechercheMot/rechercheMot.h
	gcc -c -g -Wall ../RechercheMot/rechercheMot.c

Menu.o : ../Menu/Menu.c ../Menu/Menu.h 
	gcc -c -g -Wall ../Menu/Menu.c

tst_menu.o : ../Menu/tst_menu.c
	gcc -c -g ../Menu/tst_menu.c

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