//
// AUTEUR :
//          YOUSSERA ACHACHERA
// DERNIERE VERSION :
//    13/03/2023
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "comparaison.h"

typedef struct
{
    int id;
    float pourcentage;
} tab_similaire;

void ecrireCJava(tab_similaire tabResultat[], int nombreElement){
    char chemin[100] = ""; 
    FILE *fichierCJava=NULL;
    fichierCJava=fopen(chemin,"w");
    if (fichierCJava != NULL)
    {
        for(int i = 0; i < nombreElement; i++){
            fprintf(fichierCJava, "id=%d, pourcentage=%.2f\n", tabResultat[i].id, tabResultat[i].pourcentage);
        }
        fclose(fichierCJava);
    }
}

int main(){
    tab_similaire tabResultat[3];
    tabResultat[0].id=-1;
    tabResultat[0].pourcentage=20;
    tabResultat[1].id=-12;
    tabResultat[1].pourcentage=12;
    ecrireCJava(tabResultat,2);
    return 0;
}