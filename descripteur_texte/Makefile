
config : Config.c Global.c tst_config.c 
	gcc -c Config.c 
	gcc -c Global.c 
	gcc -c tst_config.c
	gcc -o tst_Config.out Config.o Global.o tst_config.o -lm
	rm -rf *.o
	./tst_Config.out


Descripteur_texte : Config.c Global.c descripteur_texte.c test_descipteur_texte.c descripteur_texte.h
	gcc -c Config.c 
	gcc -c Global.c 
	gcc -c descripteur_texte.c
	gcc -o descripteur_texte.exe Config.o Global.o descripteur_texte.o -lm
	rm -rf *.o
	./descripteur_texte.exe