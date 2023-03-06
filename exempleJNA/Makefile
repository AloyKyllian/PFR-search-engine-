# Fait par YOUSSERA ACHACHERA
# Le 23/01/2023

all: exempleJNA tst.so

exempleJNA: test.o testMain.o
	gcc -o exempleJNA.out test.o testMain.o -lm

test.o: test.c test.h
	gcc -c test.c

testMain.o: testMain.c
	gcc -c testMain.c

tst.so: test.o
	gcc -Wall -Wextra -Werror -pedantic -shared -o tst.so test.o -ljna

run: exempleJNA tst.so
	javac -d ../exempleJNA -cp /home/youss/PFR/PFR/lib/jna-master/dist/jna.jar ../exempleJNA/*.java
	java -Djna.library.path=.:/home/youss/PFR/PFR/lib/jna-master/dist/jna.jar -cp ../exempleJNA exempleJNA

clean:
	rm -rf *.o exempleJNA.out tst.so
