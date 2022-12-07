#include "../head/Global.h"
#include "../head/Descripteur_image.h"

void main()
{
    IMAGE img;
    String Erreur;
    String Path = "../DATA_FIL_ROUGE_DEV/TEST_RGB/01.txt";

    printf("\nLecture de la matrice\n");
    img = Lire_image(&Erreur,Path);
    printf("Nb_ligne = %d\nNb_colonne = %d\nNb_composante = %d\n",img.Nb_Ligne,img.Nb_Colonne,img.Nb_composante);
    printf("1er element = %d\nDernier element = %d\n",img.adr_Matrice[0][0],img.adr_Matrice[img.Nb_Ligne*img.Nb_composante -1][img.Nb_Colonne -1]);

    printf("\nPretraitement\n");
    img = Pre_traitement(img);
    printf("Nb_ligne = %d\nNb_colonne = %d\nNb_composante = %d\n",img.Nb_Ligne,img.Nb_Colonne,img.Nb_composante);
    printf("1er element = %d\nDernier element = %d\n",img.adr_Matrice[0][0],img.adr_Matrice[img.Nb_Ligne -1][img.Nb_Colonne -1]);

}