# Fait par YOUSSERA ACHACHERA
# Le 23/01/2023

all: RechercheMot libRechercheMot.so

RechercheMot: rechercheMot.o tstRechercheMot.o
	gcc -o RechercheMot.out rechercheMot.o tstRechercheMot.o -lm

rechercheMot.o: ../RechercheMot/rechercheMot.c ../RechercheMot/rechercheMot.h
	gcc -c ../RechercheMot/rechercheMot.c

tstRechercheMot.o: ../RechercheMot/tstRechercheMot.c
	gcc -c ../RechercheMot/tstRechercheMot.c

libRechercheMot.so: rechercheMot.o
	gcc -Wall -Wextra -Werror -pedantic -shared -o libRechercheMot.so rechercheMot.o -ljna

run: RechercheMot libRechercheMot.so
	javac -d ../RechercheMot -cp /home/youss/PFR/PFR/lib/jna-master/dist/jna.jar ../RechercheMot/*.java
	java -Djna.library.path=.:/home/youss/PFR/PFR/lib/jna-master/dist/jna.jar -cp ../RechercheMot RechercheMot

clean:
	rm -rf *.o RechercheMot.out libRechercheMot.so
