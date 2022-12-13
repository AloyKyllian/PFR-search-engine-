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
    printf("1er element rouge = %d\n1er element vert = %d\n1er element bleu = %d\n",img.adr_Matrice[0][0],img.adr_Matrice[img.Nb_Ligne][0],img.adr_Matrice[img.Nb_Ligne*2][0]);

    printf("\nPretraitement\n");
    img = Pre_traitement(img,2);
    printf("Nb_composante = %d\n",img.Nb_composante);
    printf("1er element = %d\n",img.adr_Matrice[0][0]);

    di = Creation_Discripteur(img,2,&Erreur);
    printf("\nAffichage du tableau descripteur\n");
    for(int i =0; i < pow(2,niveau*img.Nb_composante); i++)
    {
        printf("Val = %d Quantity = %d\n",di.Bilan[i][0],di.Bilan[i][1]);
        total = total+di.Bilan[i][1];
    }
    printf("\nTotal de valeur = %d\n",total);

}