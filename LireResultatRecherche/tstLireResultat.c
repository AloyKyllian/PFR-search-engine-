#include <stdint.h>
#include <stdio.h>
#include "../LireResultatRecherche/LireResultat.h"

int main()
{
    tabRes *tabResultat = malloc(100 * sizeof(tabRes));
    char *type = "rechercheMot";
    char *lire = "gedit ";
    char *cheminBase = "../DATA_FIL_ROUGE_DEV/Textes";
    char *choix = "1";
    char *commande=(char*)malloc(500);
    tabResultat[0].id = -0;
    tabResultat[0].pourcentage = 35;
    tabResultat[1].id = -9;
    tabResultat[1].pourcentage = 30;
    tabResultat[2].id = -10;
    tabResultat[2].pourcentage = 20;
    int nbElement = 3;
    char *tabFileName[nbElement];
    LireResultat(tabResultat, nbElement, type, "soleil", tabFileName);
    strcpy(commande, lire);
    strcat(commande,cheminBase);
    strcat(commande, tabFileName[0]);
    printf("\ncommande 1 %s\n", commande);
    system(commande);
    free(commande);
    printf("si vous voulez visualisé un autre fichier veuillez taper son numero [numero], sinon [R] pour retour au menu recherche\n");
    scanf("%s", choix);
    if(atoi(choix[0])>nbElement){
       printf("Ce fichier ne figure pas dans la liste\n");
    }
    else{
        strcpy(commande, lire);
        strcat(commande,cheminBase);
        strcat(commande, tabFileName[choix[0]-1]);
        printf("\n%s\n", commande);
        system(commande);
    }
    free(tabResultat);
}