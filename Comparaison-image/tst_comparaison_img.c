#include "Comparaison-image.h"

void main()
{
    tab_similaire *Tab;
    int erreur;
    int Nb_ligne;

    Tab = Comparaison_descripteur_image(&erreur, "Recueil_descripteur.txt", "../descripteur_image/DATA_FIL_ROUGE_DEV/TEST_RGB/01.txt", 2, &Nb_ligne);
    
    printf("Test de comparaison de 1 image a %d autres", Nb_ligne);
    for (int i = 0; i < Nb_ligne; i++)
    {
        printf("\nId: %d Pourcentage: %d", Tab[i].id, Tab[i].pourcentage);
    }
}