 # Fait par Kyllian Aloy
 # Le 23/01/2023
descripteur_audio : descripteur_audio.o test_descripteur_audio.o
	gcc -o test_descripteur_audio.out descripteur_audio.o test_descripteur_audio.o

descripteur_audio.o : descripteur_audio.c 
	gcc -c descripteur_audio.c 

test_descripteur_audio.o : test_descripteur_audio.c
	gcc -c test_descripteur_audio.c

clean :
	rm -rf *.o
	

