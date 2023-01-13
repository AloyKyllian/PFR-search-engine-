ConnexionTest : Global.o Login.o Connexion.o tst_connexion.o
	gcc -o ConnexionTest.out Global.o Login.o Connexion.o tst_connexion.o -lm

Global.o : ../Global/Global.c ../Global/Global.h 
	gcc -c ../Global/Global.c

Login.o : ../Login/Login.c ../Login/Login.h 
	gcc -c ../Login/Login.c

Connexion.o : ../Connexion/Connexion.c ../Connexion/Connexion.h 
	gcc -c ../Connexion/Connexion.c

tst_connexion.o : ../Connexion/tst_connexion.c
	gcc -c ../Connexion/tst_connexion.c

clean :
	rm -rf *.o