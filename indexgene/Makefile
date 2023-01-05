clean :
	rm -rf *.o

inde : ../Element/element.o ../Pile/Pile.o ../Gestion-Config/Global.o ../Gestion-Config/Config.o ../descripteur_image/Descripteur_image.o ../descript_audio/descript_audio.o indexation_gene.c testindexgeneral.c
	gcc -Wall -c indexation_gene.c
	gcc -Wall -c testindexgeneral.c
	gcc -Wall -o inde.out ../Element/element.o ../Pile/Pile.o ../Gestion-Config/Global.o ../Gestion-Config/Config.o ../descripteur_image/Descripteur_image.o ../descript_audio/descript_audio.o indexation_gene.o testindexgeneral.o -lm

generale : ../Gestion-Config/Config.c ../Gestion-Config/Global.c ../Element/element.c ../descripteur_texte/descripteur_texte.c ../descript_audio/descript_audio.c ../descripteur_image/Descripteur_image.c ../Pile/Pile.c indexation_gene.c testindexgeneral.c
	gcc -c ../Gestion-Config/Config.c
	gcc -c ../Gestion-Config/Global.c
	gcc -c ../Element/element.c
	gcc -c ../descripteur_texte/descripteur_texte.c
	gcc -c ../descript_audio/descript_audio.c
	gcc -c ../descripteur_image/Descripteur_image.c
	gcc -c ../Pile/Pile.c
	gcc -c indexation_gene.c
	gcc -c testindexgeneral.c
	gcc -Wall -o inde.out Config.o element.o Pile.o Global.o descripteur_texte.o Descripteur_image.o descript_audio.o indexation_gene.o testindexgeneral.o -lm