//
// AUTEUR :
//          YOUSSERA ACHACHERA
// DERNIERE VERSION :
//    15/12/2022
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int FichierExist(char chemin[100])
{   FILE * fichier = fopen(chemin, "r+");
 
	if (fichier == NULL)
	{
        return -1;//passer erreur en parametre
	}
	else
	{
    	fclose(fichier);
        return 1;//passer erreur en parametre
	}
}

int VerifExtension(char chemin[100],char extension[4]){
    char *i = strrchr(chemin, '.'); // recherche le dernier point dans le chemin
    if(i != NULL) {
        i++; // on passe le point
        if(strcmp(i, extension) == 0) {
            return 1;
        }
    }
    return -1;
}