
config : Config.c Global.c tst_config.c 
	gcc -c Config.c 
	gcc -c Global.c 
	gcc -c tst_config.c
	gcc -o tst_Config.out Config.o Global.o tst_config.o -lm
	rm -rf *.o
	./tst_Config.out


Descripteur_texte : descripteur_texte.c descripteur_texte.h comparaison_texte.c
	gcc -c comparaison_texte.c
	gcc -o comparaison_texte.exe descripteur_texte.c comparaison_texte.o -lm
	rm -rf *.o
	./comparaison_texte.exe