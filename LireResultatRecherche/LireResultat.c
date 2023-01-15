#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../LireResultatRecherche/LireResultat.h"


void LireResultat(tabRes *tabResultat, int nbElement, String type){
    PILE IDchemin;
    char *commande=(char*)malloc(200);
    strcpy(commande,"basename ");
    int erreur;
    int max=0;
    IDchemin=init_PILE();
    //printf("verifie les element du tableau\n");
    //for(int k=0;k<nbElement;k++){
	//    printf("ID=%d, nb=%d\n",tabResultat[k].id,tabResultat[k].pourcentage);
	//}
    lire_chemin (&IDchemin,tabResultat,nbElement,type,&erreur);
    //printf("affichage pile:\n");
    //affichePILE(IDchemin);
    //affichage pour l'utilisateur
    PILE temp = IDchemin;
    printf("Les resultat pour votre recherche :\n");
    int maxLength = 0;
    int l = 0;
    do
    {   
        char *filename = strrchr((*temp).element.CHEMIN, '/');
        if (filename) {
            filename++;
        } 
        else {
            filename = (*temp).element.CHEMIN;
        }
        maxLength = fmax(maxLength, strlen(filename));
        temp = (*temp).suiv;
    } while (temp != NULL);

    temp = IDchemin;
    l = 0;
    do
    {   
        char *filename = strrchr((*temp).element.CHEMIN, '/');
        if (filename) {
            filename++;
        } 
        else {
            filename = (*temp).element.CHEMIN;
        }
        int spaces = maxLength - strlen(filename);
        printf("%s%*s ->%d\n", filename, spaces, "",tabResultat[l].pourcentage);
        temp = (*temp).suiv;
        l++;
} while (temp != NULL);


    
}


void lire_chemin (PILE *pourchemin,tabRes *tabResultat,int nbElement, String type, int *erreur)
{   
    FILE *fichier = NULL;
    ELEMENT element;
      if (strcmp(type, "texte")==0)
           fichier = fopen("../liste_base/liste_base_texte", "r");
     else if (strcmp(type, "image")==0)
           fichier = fopen("../liste_base/liste_base_image", "r");
     else
           fichier = fopen("../liste_base/liste_base_audio", "r");    
    if (fichier != NULL){
                    while (fscanf(fichier, "%d | %s\n",&element.id,element.CHEMIN)!=EOF)
                    {   for(int i=0;i<nbElement;i++){
                            if(element.id==tabResultat[i].id){
                                *pourchemin= emPILE(*pourchemin, element);
                            }       
                        }
                    }
    }
    else{
        *erreur=7;
    }
    fclose(fichier);
}