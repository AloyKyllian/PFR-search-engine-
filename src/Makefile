config : Config.c Global.c tst_config.c 
	gcc -c Config.c 
	gcc -c Global.c 
	gcc -c tst_config.c
	gcc -o tst_Config.exe Config.o Global.o tst_config.o -lm
	gcc -o tst_Config.out Config.o Global.o tst_config.o -lm

login : Login.c Global.c tst_login.c 
	gcc -c Login.c 
	gcc -c Global.c 
	gcc -c tst_login.c
	gcc -o tst_login.out Login.o Global.o tst_login.o -lm

connexion : Login.c Global.c Connexion.c tst_connexion.c 
	gcc -c Login.c 
	gcc -c Connexion.c
	gcc -c Global.c 
	gcc -c tst_connexion.c
	gcc -o tst_connexion.out Login.o Connexion.o Global.o tst_connexion.o -lm