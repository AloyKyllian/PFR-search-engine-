config : Config.c Global.c tst_config.c 
	gcc -c Config.c 
	gcc -c Global.c 
	gcc -c tst_config.c
	gcc -o tst_Config.exe Config.o Global.o tst_config.o -lm
	gcc -o tst_Config.out Config.o Global.o tst_config.o -lm
tst : Config.c Global.c test.c 
	gcc -c Config.c 
	gcc -c Global.c 
	gcc -c Descripteur_image.c
	gcc -c tst_descripteur_image.c
	gcc -o tst_descripteur_image.exe Config.o Global.o Descripteur_image.o tst_descripteur_image.o -lm
	gcc -o tst_descripteur_image.out Config.o Global.o Descripteur_image.o tst_descripteur_image.o -lm