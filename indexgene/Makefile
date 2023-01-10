inde : Global.o Config.o element.o descripteur_texte.o descripteur_audio.o descripteur_image.o pile.o indexation_gene.o testindexgeneral.o
	gcc -o inde.out Global.o Config.o element.o Pile.o descripteur_texte.o descripteur_image.o descripteur_audio.o indexation_gene.o testindexgeneral.o -lm

Global.o : ../Gestion-Config/Global.c
	gcc -c ../Gestion-Config/Global.c

Config.o : ../Gestion-Config/Config.c
	gcc -c ../Gestion-Config/Config.c

element.o : ../Element/element.c
	gcc -c ../Element/element.c

descripteur_texte.o : ../descripteur_texte/descripteur_texte.c
	gcc -c ../descripteur_texte/descripteur_texte.c

descripteur_audio.o : ../descripteur_audio/descripteur_audio.c
	gcc -c ../descripteur_audio/descripteur_audio.c

descripteur_image.o : ../descripteur_image/Descripteur_image.c
	gcc -c ../descripteur_image/Descripteur_image.c

pile.o : ../Pile/Pile.c
	gcc -c ../Pile/Pile.c

indexation_gene.o : indexation_gene.c
	gcc -c indexation_gene.c

testindexgeneral.o : testindexgeneral.c
	gcc -c testindexgeneral.c

clean :
	rm -rf *.o

