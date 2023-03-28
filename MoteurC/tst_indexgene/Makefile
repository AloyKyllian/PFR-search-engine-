 # Fait par YASMINE ALLAL
 # Le 23/01/2023
inde : Global.o Config.o element.o Pile.o descripteur_texte.o  descripteur_audio.o  Descripteur_image.o indexation_gene.o tst_indexgene.o
	gcc -o inde.out Global.o Config.o indexation_gene.o element.o  descripteur_texte.o  descripteur_audio.o  Descripteur_image.o  Pile.o tst_indexgene.o -lm

Global.o : ../Gestion-Config/Global.c ../Gestion-Config/Global.h 
	gcc -c -g ../Gestion-Config/Global.c

Config.o : ../Gestion-Config/Config.c ../Gestion-Config/Config.h 
	gcc -c -g ../Gestion-Config/Config.c

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

tst_indexgene.o : tst_indexgene.c
	gcc -c -g tst_indexgene.c

clean :
	rm -rf *.o