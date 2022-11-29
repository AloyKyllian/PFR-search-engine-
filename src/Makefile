
config : Config.c Global.c tst_config.c 
	gcc -c Config.c 
	gcc -c Global.c 
	gcc -c tst_config.c
	gcc -o tst_Config.out Config.o Global.o tst_config.o -lm
	rm -rf *.o
	./tst_Config.out