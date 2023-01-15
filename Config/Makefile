Configuration : Global.o Config.o tst_config.o
	gcc -o Configuration.out Config.o tst_config.o -lm

Global.o : ../Global/Global.c ../Global/Global.h 
	gcc -c ../Global/Global.c

Config.o : ../Config/Config.c ../Config/Config.h 
	gcc -c ../Config/Config.c

tst_config.o : ../Config/tst_config.c
	gcc -c ../Config/tst_config.c

clean :
	rm -rf *.o