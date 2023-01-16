Descripteur_image.o : ../descripteur_image/Descripteur_image.c ../descripteur_image/Descripteur_image.h
	gcc -c -o ../descripteur_image/Descripteur_image.o ../descripteur_image/Descripteur_image.c

Comparaison-image.o :  Comparaison_image.c Comparaison_image.h ../descripteur_image/Descripteur_image.h
	gcc -c -o Comparaison-image.o Comparaison-image.c

tst_comparaison_img.o : tst_comparaison_img.c Comparaison_image.h
	gcc -c -o tst_comparaison_img.o tst_comparaison_img.c

tst_comparaison_img : tst_comparaison_img.o Comparaison-image.o ../descripteur_image/Descripteur_image.o
	gcc -o tst_comparaison_img.exe ../descripteur_image/Descripteur_image.o tst_comparaison_img.o Comparaison-image.o