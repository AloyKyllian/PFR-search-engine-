//
// AUTEUR :
//          YASMINE ALLAL
// DERNIERE VERSION :
//    15/01/2023

#include "indexation_gene.h"

int main()
{
    ELEMENT_texte element_temp;
    printf("HELLO AVANT TEXTE");
    fflush(stdout);
    element_temp.descripteur_texte = descripteur_texte_finale("../DATA_FIL_ROUGE_DEV/Textes/29-Ligue_des_champions___Lyon.xml", 5, element_temp.descripteur_texte);
    printf("HELLO AVANT TEXTE");
    fflush(stdout);
    // MARCHE PAS
    //_____________
    for (int x = 0; x < 5; x++)
    {
        printf("%s    |    %d\n", element_temp.descripteur_texte.tab_mot[x], element_temp.descripteur_texte.tab_app[x]);
    }
    //_______________
}