descripteur_audio : descripteur_audio.o test_descripteur_audio.o
	gcc -o test_descripteur_audio.out descripteur_audio.o test_descripteur_audio.o
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./test_descripteur_audio.out

descripteur_audio.o : descripteur_audio.c 
	gcc -c -g descripteur_audio.c 

test_descripteur_audio.o : test_descripteur_audio.c
	gcc -c -g test_descripteur_audio.c

clean :
	rm -rf *.o
	

