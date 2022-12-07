test_audio : descripteur_audio.c Global.c
	gcc -c Global.c 
	gcc -c descripteur_audio.c 
	gcc -o test_audio.out Global.o descripteur_audio.o -lm
	rm -rf *.o
	./test_audio.out 

config : Config.c Global.c tst_config.c 
	gcc -c Config.c 
	gcc -c Global.c 
	gcc -c tst_config.c
	gcc -o tst_Config.exe Config.o Global.o tst_config.o -lm
	gcc -o tst_Config.out Config.o Global.o tst_config.o -lm
	rm -rf *.o

