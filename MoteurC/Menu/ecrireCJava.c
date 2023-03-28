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
#include "../chemin.h"

void ecrireCJava(tab_similaire tabResultat[], int nombreElement, int erreurImage, int erreurAudio, int erreurTexte, int erreurIndex)
{
    // system("cat fichiertest.txt");
    char chemin[100] = pontCJ;
    FILE *fichierCJava = NULL;
    fichierCJava = fopen(chemin, "w");
    if (fichierCJava != NULL)
    {
                if (erreurImage != 0 || erreurAudio != 0 || erreurTexte != 0 || erreurIndex != 0)
                {        fprintf(fichierCJava, "ERREUR : img :%d aud :%d txt:%d ind:%d\n", erreurImage, erreurAudio, erreurTexte, erreurIndex);}

        if (tabResultat != NULL)
        {
            for (int i = 0; i < nombreElement; i++)
            {
                //printf("%d %d\n", tabResultat[i].id, (int)tabResultat[i].pourcentage);
                fprintf(fichierCJava, "%d %d\n", tabResultat[i].id, (int)tabResultat[i].pourcentage);
            }
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
