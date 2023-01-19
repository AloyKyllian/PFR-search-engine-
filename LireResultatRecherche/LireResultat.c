#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../LireResultatRecherche/LireResultat.h"


void LireResultat(tabRes *tabResultat, int nbElement, char* type, char* requete,char *tabFileName[]){
    PILE IDchemin;
    char *commande=(char*)malloc(200);
    strcpy(commande,"basename ");
    int erreur;
    int max=0;
    IDchemin=init_PILE();
    printf("verifie les element du tableau\n");
    for(int k=0;k<nbElement;k++){
	   printf("ID=%d, nb=%d\n",tabResultat[k].id,tabResultat[k].pourcentage);
	}
    
    //affichage des resultat de recherche par mot cle :
    printf("\nLes resultat pour votre recherche :\n");
    if(nbElement==0){
        printf("\nRequete mot-cle : %s\n",requete);
        printf("\nRésultats (fichier -> occurrences) :\n");
        printf("\nCe mot ne figure pas dans notre base de données\n");
    }
    else{
        if(strstr(type,"rechercheMot")){
            lire_chemin (&IDchemin,tabResultat,nbElement,"texte",&erreur);
            printf("\nRequete mot-cle : \"%s\"\n",requete);
            printf("\nRésultats (fichier -> occurrences) :\n");
            affichage(&IDchemin,tabResultat,tabFileName);
        }
    }

    //affichage des resultat de comparaison texte :
    if(strstr(type,"texte")){
        lire_chemin (&IDchemin,tabResultat,nbElement,type,&erreur);
        printf("\nRequete fichier : \"%s\"\n",requete);
        printf("\nRésultats (fichier -> nombre de mots-clés communs) :\n");
        affichage(&IDchemin,tabResultat,tabFileName);   
    }

    //affichage des resultat de comparaison Image :
    if(strstr(type,"image")){
        lire_chemin (&IDchemin,tabResultat,nbElement,type,&erreur);
        printf("\nRequete image : \"%s\"\n",requete);
        printf("\nRésultats :\n");
        affichage(&IDchemin,tabResultat,tabFileName);
    }
    //affichage des resultat de comparaison Audio :
    if(strstr(type,"audio")){
        lire_chemin (&IDchemin,tabResultat,nbElement,type,&erreur);
        printf("\nRequete son (jingle) : \"%s\"\n",requete);
        printf("\nRésultats :\n");
        affichage(&IDchemin,tabResultat,tabFileName);
        
    }
    
}


void lire_chemin (PILE *pourchemin,tabRes *tabResultat,int nbElement,char* type, int *erreur)
{   
    FILE *fichier = NULL;
    ELEMENT element;
      if (strcmp(type, "texte")==0)
           fichier = fopen("../liste_base/liste_base_texte", "r");
     if (strcmp(type, "image")==0)
           fichier = fopen("../liste_base/liste_base_image", "r");
     if (strcmp(type, "audio")==0)
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

void affichage(PILE *IDchemin, tabRes *tabResultat,char *tabFileName[]){
    PILE temp = *IDchemin;
    ;
    int maxLength = 0,l=0;
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

        temp = *IDchemin;
        l = 0;
        do
        {   
            char *filename = strrchr((*temp).element.CHEMIN, '/');
            if (filename) {
                tabFileName[l]=filename;
                filename++;
            } 
            else {
                filename = (*temp).element.CHEMIN;
            }
            int spaces = maxLength - strlen(filename);
            
            printf("[%d] %s%*s ->%d\n",l+1, filename, spaces, "",tabResultat[l].pourcentage);
            temp = (*temp).suiv;
            l++;
    } while (temp != NULL);
    *IDchemin=temp;
}