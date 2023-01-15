#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Menu/LireResulat.h"


void LireResultat(tabRes *tabResultat, int nbElement){
    //recupere les textes grace au ID avec la fonction lire chemin 
    //les stocker dans le fichier a la place des ID
    //afficher 
    //ouvrir le premier fichier
    //voir si l'utilisaeur veut ouvrir un autre
    //for(int k=0;k<nbElement;k++){
	//	printf("ID=%d, nb=%d\n",tabResultat[k].id,tabResultat[k].pourcentage);
	//}

    printf("fct lire resultat\n");


    
}


void lire_chemin (PILE *pourchemin, String type, int * erreur)
{   
    FILE *fichier = NULL;
    ELEMENT element;
      if (strcmp(type, "texte")==0)
           fichier = fopen("../liste_base/liste_base_texte", "r");
     else if (strcmp(type, "image")==0)
           fichier = fopen("../liste_base/liste_base_image", "r");
     else
           fichier = fopen("../liste_base/liste_base_audio", "r");    
    if (fichier != NULL)
    {
            fscanf(fichier, "%d | %s\n",&element.id,element.CHEMIN);
            *pourchemin= emPILE(*pourchemin, element);
              while (! feof(fichier))
              {   
                    fscanf(fichier, "%d | %s\n",&element.id,element.CHEMIN);
                     *pourchemin= emPILE(*pourchemin, element);
                     
              } 

    }
    else
    {
        //strcpy(*erreur,"Erreur : Fichier liste base introuvable");
        *erreur=7;

    }
    fclose(fichier);
}