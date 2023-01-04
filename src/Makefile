config : Config.c Global.c tst_config.c 
	gcc -c Config.c 
	gcc -c Global.c 
	gcc -c tst_config.c
	gcc -o tst_Config.exe Config.o Global.o tst_config.o -lm
	gcc -o tst_Config.out Config.o Global.o tst_config.o -lm
	rm -rf *.o

login : Login.c Global.c tst_login.c 
	gcc -c Login.c 
	gcc -c Global.c 
	gcc -c tst_login.c
	gcc -o tst_login.out Login.o Global.o tst_login.o -lm
	rm -rf *.o

connexion : Login.c Global.c Connexion.c tst_connexion.c 
	gcc -c Login.c 
	gcc -c Connexion.c
	gcc -c Global.c 
	gcc -c tst_connexion.c
	gcc -o tst_connexion.out Login.o Connexion.o Global.o tst_connexion.o -lm
	rm -rf *.o

menu : Global.c Config.c Login.c Connexion.c FichierExist.c Menu.c main.c    
	gcc -c Global.c
	gcc -c Config.c 
	gcc -c Login.c 
	gcc -c Connexion.c
	gcc -c FichierExist.c
	gcc -c Menu.c
	gcc -c main.c
	gcc -o menu.out Global.o Config.o Login.o Connexion.o  FichierExist.o Menu.o main.o -lm
	rm -rf *.o
	./menu.out



clean : 
	rm -rf *.o