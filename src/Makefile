config : Config.c Global.c tst_config.c 
	gcc -c Config.c 
	gcc -c Global.c 
	gcc -c tst_config.c
	gcc -o tst_Config.exe Config.o Global.o tst_config.o -lm
	gcc -o tst_Config.out Config.o Global.o tst_config.o -lm

testpile : element.c Pile.c testpile.c
	gcc -c element.c
	gcc -c Pile.c
	gcc -c testpile.c
	gcc -o testpile.out element.o Pile.o testpile.o
	
clean :
	rm -rf *.o