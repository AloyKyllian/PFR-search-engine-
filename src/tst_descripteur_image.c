#include "../head/Global.h"
#include "../head/Descripteur_image.h"

void main()
{
    IMAGE img;
    DESCRIPTEUR_IMAGE di;
    String Erreur;
    String Path = "../DATA_FIL_ROUGE_DEV/TEST_RGB/01.txt";
    int niveau = 2;
    int total =0;

    printf("\nLecture de la matrice\n");
    img = Lire_image(&Erreur,Path);
    printf("Nb_ligne = %d\nNb_colonne = %d\nNb_composante = %d\n",img.Nb_Ligne,img.Nb_Colonne,img.Nb_composante);
    printf("1er element = %d\nDernier element = %d\n",img.adr_Matrice[0][0],img.adr_Matrice[img.Nb_Ligne*img.Nb_composante -1][img.Nb_Colonne -1]);

    printf("\nPretraitement\n");
    img = Pre_traitement(img);
    printf("Nb_ligne = %d\nNb_colonne = %d\nNb_composante = %d\n",img.Nb_Ligne,img.Nb_Colonne,img.Nb_composante);
    printf("1er element = %d\nDernier element = %d\n",img.adr_Matrice[0][0],img.adr_Matrice[img.Nb_Ligne -1][img.Nb_Colonne -1]);

    di = Creation_Discripteur(img,2,&Erreur);
    for(int i =0; i < pow(2,niveau*img.Nb_composante); i++)
    {
        printf("Val = %d Quantity = %d\n",di.Bilan[i][0],di.Bilan[i][1]);
        total = total+di.Bilan[i][1];
    }
    printf("Total = %d",total);

}