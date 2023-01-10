descripteur_audio : descripteur_audio.c
	gcc -g -c descripteur_audio.c 
	gcc -g -c test_descripteur_audio.c
	gcc -o test_descripteur_audio.out descripteur_audio.o test_descripteur_audio.o
	valgrind --leak-check=full --show-leak-kinds=all ./test_descripteur_audio.out
	
clean :
	rm -rf *.o
