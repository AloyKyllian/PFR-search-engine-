inde : ../Element/element.o ../Pile/Pile.o ../Config/Global.o ../Config/Config.o ../descripteur_image/Descripteur_image.o ../descript_audio/descript_audio.o indexation_gene.c testindexgeneral.c
	gcc -Wall -c indexation_gene.c
	gcc -Wall -c testindexgeneral.c
	gcc -Wall -o inde.out ../Element/element.o ../Pile/Pile.o ../Config/Global.o ../Config/Config.o ../descripteur_image/Descripteur_image.o ../descript_audio/descript_audio.o indexation_gene.o testindexgeneral.o -lm
	
clean :
	rm -rf *.o
