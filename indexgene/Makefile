clean :
	rm -rf *.o

inde : ../Element/element.o ../Pile/Pile.o ../Gestion-Config/Global.o ../Gestion-Config/Config.o ../descripteur_image/Descripteur_image.o ../descripteur_audio/descripteur_audio.o indexation_gene.c testindexgeneral.c
	gcc -Wall -c indexation_gene.c
	gcc -Wall -c testindexgeneral.c
	gcc -Wall -o inde.out ../Element/element.o ../Pile/Pile.o ../Gestion-Config/Global.o ../Gestion-Config/Config.o ../descripteur_image/Descripteur_image.o ../descripteur_audio/descripteur_audio.o indexation_gene.o testindexgeneral.o -lm

generale : ../Gestion-Config/Config.c ../Gestion-Config/Global.c ../Element/element.c ../descripteur_texte/descripteur_texte.c ../descripteur_audio/descripteur_audio.c ../descripteur_image/Descripteur_image.c ../Pile/Pile.c indexation_gene.c testindexgeneral.c
	gcc -g -c ../Gestion-Config/Config.c
	gcc -g -c ../Gestion-Config/Global.c
	gcc -g -c ../Element/element.c
	gcc -g -c ../descripteur_texte/descripteur_texte.c
	gcc -g -c ../descripteur_audio/descripteur_audio.c
	gcc -g -c ../descripteur_image/Descripteur_image.c
	gcc -g -c ../Pile/Pile.c
	gcc -g -c indexation_gene.c
	gcc -g -c testindexgeneral.c
	gcc -Wall -o inde.out Config.o element.o Pile.o Global.o descripteur_texte.o Descripteur_image.o descripteur_audio.o indexation_gene.o testindexgeneral.o -lm
	valgrind --leak-check=full --show-leak-kinds=all ./inde.out
	