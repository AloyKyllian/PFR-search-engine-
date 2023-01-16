test_comparaison : tst_comparaison.o comparaison.o descripteur_audio.o descripteur_texte.o Descripteur_image.o Global.o
	gcc -o test_comparaison.out tst_comparaison.o comparaison.o descripteur_audio.o descripteur_texte.o Descripteur_image.o -lm

tst_comparaison.o: tst_comparaison.c
	gcc -c tst_comparaison.c 

comparaison.o : comparaison.c comparaison.h 
	gcc -c comparaison.c 

descripteur_audio.o : ../descripteur_audio/descripteur_audio.c 
	gcc -c ../descripteur_audio/descripteur_audio.c

descripteur_texte.o : ../descripteur_texte/descripteur_texte.c 
	gcc -c ../descripteur_texte/descripteur_texte.c 

Descripteur_image.o : ../descripteur_image/Descripteur_image.c 
	gcc -c ../descripteur_image/Descripteur_image.c

Global.o : ../Gestion-Config/Global.c
	gcc -c ../Gestion-Config/Global.c







clean :
	rm -rf *.o
	
