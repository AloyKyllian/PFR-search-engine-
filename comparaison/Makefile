test_comparaison : test_comparaison.o comparaison.o descripteur_audio.o descripteur_texte.o descripteur_image.o
	gcc -o test_comparaison.out comparaison.o ../descripteur_audio/descripteur_audio.o descripteur_audio.o descripteur_texte.o descripteur_image.o

test_comparaison.o: tst_comparaison.c comparaison.o
	gcc -c tst_comparaison.c 

comparaison.o : comparaison.c comparaison.h ../descripteur_audio/descripteur_audio.c ../descripteur_texte/descripteur_texte.c ../descripteur_image/Descripteur_image.c
	gcc -c comparaison.c 

descripteur_audio.o : ../descripteur_audio/descripteur_audio.c ../descripteur_audio/descripteur_audio.h
	gcc -c ../descripteur_audio/descripteur_audio.c

descripteur_texte.o : ../descripteur_texte/descripteur_texte.c ../descripteur_texte/descripteur_texte.h
	gcc -c ../descripteur_texte/descripteur_texte.c 

descripteur_image.o : ../descripteur_image/Descripteur_image.c ../descripteur_image/Descripteur_image.h
	gcc -c ../descripteur_image/Descripteur_image.c










clean :
	rm -rf *.o
	
