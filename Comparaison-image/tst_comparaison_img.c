#include "Comparaison-image.h"

void main()
{
    tab_similaire *tab;
    int erreur;
    printf("Test de comparaison de 1 image a 2 autres\nLa 1er doit etre identique");
    tab = Comparaison_descripteur_image(&erreur,"Recueil_descripteur.txt","../descripteur_image/DATA_FIL_ROUGE_DEV/TEST_RGB/01.txt",2);
}