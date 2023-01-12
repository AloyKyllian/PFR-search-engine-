test_comparaison_audio : test_comparaison_audio.o comparaison_audio.o ../descripteur_audio/descripteur_audio.o
	gcc -o test_comparaison_audio.out comparaison_audio.o ../descripteur_audio/descripteur_audio.o test_comparaison_audio.o

test_comparaison_audio.o: test_comparaison_audio.c
	gcc -c test_comparaison_audio.c 

comparaison_audio.o : comparaison_audio.c comparaison_audio.h ../descripteur_audio/descripteur_audio.c
	gcc -c comparaison_audio.c 

clean :
	rm -rf *.o
	
