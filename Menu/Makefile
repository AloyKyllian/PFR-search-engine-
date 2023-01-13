menu : Global.o Config.o Login.o Connexion.o FichierExist.o RechercheMot.o Menu.o main.o
	gcc -o menu.out Global.o Config.o Login.o Connexion.o FichierExist.o RechercheMot.o Menu.o main.o -lm

Global.o : ../Global/Global.c ../Global/Global.h 
	gcc -c ../Global/Global.c

Config.o : ../Config/Config.c ../Config/Config.h 
	gcc -c ../Config/Config.c

Login.o : ../Login/Login.c ../Login/Login.h 
	gcc -c ../Login/Login.c

Connexion.o : ../Connexion/Connexion.c ../Connexion/Connexion.h 
	gcc -c ../Connexion/Connexion.c

FichierExist.o : ../Menu/FichierExist.c ../Menu/FichierExist.h 
	gcc -c ../Menu/FichierExist.c

RechercheMot.o : ../RechercheMot/rechercheMot.c ../RechercheMot/rechercheMot.h
	gcc -c ../RechercheMot/rechercheMot.c

Menu.o : ../Menu/Menu.c ../Menu/Menu.h 
	gcc -c ../Menu/Menu.c

main.o : ../Menu/main.c
	gcc -c ../Menu/main.c

clean :
	rm -rf *.o