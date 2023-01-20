#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int FichierExist(char chemin[100])
{   FILE * fichier = fopen(chemin, "r+");
 
	if (fichier == NULL)
	{
        return -1;//passer erreur en parametre et le rendre erreur =??
	}
	else
	{
    	//printf("Le fichier existe et on le referme aussitôt");
    	fclose(fichier);
        return 1;//passer erreur en parametre et le rendre erreur =??
	}
}

int VerifExtension(char chemin[100],char extension[4]){
    char *i=strstr(chemin,extension);
            if (i==NULL)
                return -1;//meme chose
            else
                 return 1;//meme chose
}