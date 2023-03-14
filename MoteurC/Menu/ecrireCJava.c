//
// AUTEUR :
//          YOUSSERA ACHACHERA
// DERNIERE VERSION :
//    13/03/2023
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ecrireCJava.h"

void ecrireCJava(tab_similaire tabResultat[], int nombreElement){
    char chemin[100] = "../../pontJavaC.txt"; 
    FILE *fichierCJava=NULL;
    fichierCJava=fopen(chemin,"w");
    if (fichierCJava != NULL)
    {
        for(int i = 0; i < nombreElement; i++){
            printf("%d %d\n", tabResultat[i].id, tabResultat[i].pourcentage);
            fprintf(fichierCJava, "%d %d\n", tabResultat[i].id, tabResultat[i].pourcentage);
        }
        fclose(fichierCJava);
    }
}

// int main(){
//     tab_similaire tabResultat[3];
//     tabResultat[0].id=-1;
//     tabResultat[0].pourcentage=20;
//     tabResultat[1].id=-12;
//     tabResultat[1].pourcentage=12;
//     ecrireCJava(tabResultat,2);
//     return 0;
// }