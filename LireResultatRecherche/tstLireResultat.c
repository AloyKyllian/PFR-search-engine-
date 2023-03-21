//
// AUTEUR :
//          YOUSSERA ACHACHERA
// DERNIERE VERSION :
//    10/01/2023
//
#include <stdint.h>
#include <stdio.h>
#include "../LireResultatRecherche/LireResultat.h"

int main()
{
    tabRes *tabResultat = malloc(100 * sizeof(tabRes));
    char *type = "rechercheMot";
    char *cheminBase = "../DATA_FIL_ROUGE_DEV/Textes";
    char *choix = "1";
    int nb_cle=10;
    int nb_Element_Tab=10;
    int nombre_mot_cle=10;
    int similarite=75;
    tabResultat[0].id = -0;
    tabResultat[0].pourcentage = 35;
    tabResultat[1].id = -9;
    tabResultat[1].pourcentage = 30;
    tabResultat[2].id = -10;
    tabResultat[2].pourcentage = 20;
    int nbElement = 3;
    char *tabFileName[nbElement];
    nb_Element_Tab=LireResultat(tabResultat, nbElement, type, "soleil", tabFileName,nb_cle,similarite);
    if (nb_Element_Tab > 0)
                {

                    printf("[R] Retour\n\nPensez à fermer l'editeur de texte apres l'avoir consulté pour poursuivre votre activité\n");
                    choix[0] = visualiser_fichier(tabFileName, nb_Element_Tab, "texte");
                }
                if (strcmp(choix, "Q") == 0)
                {
                    printf("\n\t\033[0;31mVous avez quitté le programme\033[0m\n\n\n\n");
                    exit(EXIT_SUCCESS);
                }
    
    
    free(tabResultat);
}