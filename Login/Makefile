LoginTest : Global.o Login.o tst_login.o
	gcc -o LoginTest.out Global.o Login.o tst_login.o -lm

Global.o : ../Global/Global.c ../Global/Global.h 
	gcc -c ../Global/Global.c

tst_login.o : ../Login/tst_login.c
	gcc -c ../Login/tst_login.c

clean :
	rm -rf *.o