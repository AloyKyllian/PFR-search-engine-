test_audio2 : descript_audio.c Global.c
	gcc -c Global.c 
	gcc -c descript_audio.c 
	gcc -o test_audio2.exe Global.o descript_audio.o -lm
	rm -rf *.o
	./test_audio2.exe 




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

testpile : element.c Pile.c testpile.c
	gcc -c element.c
	gcc -c Pile.c
	gcc -c testpile.c
	gcc -o testpile.out element.o Pile.o testpile.o

inde : element.c indexation_gene.c testindexgeneral.c
	gcc -c element.c
	gcc -Wall -c indexation_gene.c
	gcc -Wall -c testindexgeneral.c
	gcc -Wall -o inde.out element.o indexation_gene.o testindexgeneral.o
	
clean :
	rm -rf *.o
