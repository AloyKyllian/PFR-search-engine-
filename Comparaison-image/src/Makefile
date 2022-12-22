config : Config.c Global.c tst_config.c 
	gcc -c Config.c 
	gcc -c Global.c 
	gcc -c tst_config.c
	gcc -o tst_Config.exe Config.o Global.o tst_config.o -lm
	gcc -o tst_Config.out Config.o Global.o tst_config.o -lm
Descripteur_image :  Descripteur_image.c Global.c tst_descripteur_image.c 
	gcc -c Global.c 
	gcc -c Descripteur_image.c
	gcc -c tst_descripteur_image.c
	gcc -o tst_descripteur_image.exe Global.o Descripteur_image.o tst_descripteur_image.o -lm
	gcc -o tst_descripteur_image.out Global.o Descripteur_image.o tst_descripteur_image.o -lm
Comparaison_image :  Descripteur_image.c Global.c tst_descripteur_image.c Comparaison_image.c tst_comparaison_img.c
	gcc -c Global.c 
	gcc -c Descripteur_image.c
	gcc -c Comparaison_image.c
	gcc -c tst_comparaison_img.c
	gcc -o tst_comparaison_img.exe Global.o Descripteur_image.o tst_comparaison_img.o Comparaison_image.o -lm
	gcc -o tst_comparaison_img.out Global.o Descripteur_image.o tst_comparaison_img.o Comparaison_image.o -lm