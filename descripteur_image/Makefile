 # Fait par Loic Maignan
 # Le 23/01/2023
Descripteur_image.o :  Descripteur_image.c  Descripteur_image.h
	gcc -c -o Descripteur_image.o Descripteur_image.c

tst_descripteur_image.o : tst_descripteur_image.c Descripteur_image.h
	gcc -c -o tst_descripteur_image.o tst_descripteur_image.c

tst_descripteur_image : tst_descripteur_image.o Descripteur_image.out
	gcc -o tst_descripteur_image.exe tst_descripteur_image.o Descripteur_image.o