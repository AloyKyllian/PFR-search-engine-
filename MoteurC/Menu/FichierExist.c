//
// AUTEUR :
//          YOUSSERA ACHACHERA
// DERNIERE VERSION :
//    15/12/2022
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Fonction pour vérifier l'existence d'un fichier 
int FichierExist(char chemin[100])
{   //Ouverture du fichier en mode lecture/écriture
    FILE * fichier = fopen(chemin, "r+");
 //Vérification de l'existence du fichier
	if (fichier == NULL)
	{
        return -1; //Retourner une valeur négative en cas d'erreur
	}
	else
	{
    	fclose(fichier);
        return 1;//Retourner une valeur positive en cas de succès
	}
}
//Fonction pour vérifier l'extension d'un fichier
int VerifExtension(char chemin[100],char extension[4]){
    char *i = strrchr(chemin, '.'); // recherche le dernier point dans le chemin
    if(i != NULL) {
        i++; // on passe le point
        //Comparaison de l'extension avec celle passée en paramètre
        if(strcmp(i, extension) == 0) {
            return 1;
        }
    }
    //Retourner une valeur négative en cas d'erreur
    return -1;
}