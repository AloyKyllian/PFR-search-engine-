test_comparaison : test_comparaison.o comparaison.o descripteur_audio.o descripteur_texte.o Descripteur_image.o Global.o
	gcc -o test_comparaison.out comparaison.o descripteur_audio.o descripteur_texte.o Descripteur_image.o

test_comparaison.o: tst_comparaison.c comparaison.o
	gcc -c tst_comparaison.c 

comparaison.o : comparaison.c comparaison.h 
	gcc -c comparaison.c 

descripteur_audio.o : ../descripteur_audio/descripteur_audio.c 
	gcc -c ../descripteur_audio/descripteur_audio.c

descripteur_texte.o : ../descripteur_texte/descripteur_texte.c 
	gcc -c ../descripteur_texte/descripteur_texte.c 

descripteur_image.o : ../descripteur_image/Descripteur_image.c 
	gcc -c ../descripteur_image/Descripteur_image.c

Global.o : ../Gestion-Config/Global.h
	gcc -c ../Gestion-Config/Global.h







clean :
	rm -rf *.o
	
