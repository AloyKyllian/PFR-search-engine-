tst : ../Config/Global.o ../Config/Config.o test.c 
	gcc -c Descripteur_image.c
	gcc -c tst_descripteur_image.c
	gcc -o tst_descripteur_image.out ../Config/Global.o ../Config/Config.o Descripteur_image.o tst_descripteur_image.o -lm

clean :
	rm -rf *.o
