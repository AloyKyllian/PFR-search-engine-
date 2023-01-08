#include "Descripteur_image.h"

void main()
{
    // Variable
    IMAGE img;
    DESCRIPTEUR_IMAGE descripteur_image;
    int Erreur;
    char Path[] = "DATA_FIL_ROUGE_DEV/TEST_RGB/01.txt";
    int Nb_Bit_Fort = 2;
    int total = 0;

    printf("\nLecture de la matrice\n");
    img = Lire_image(&Erreur,Path);
    printf("Nb_ligne = %d\nNb_colonne = %d\nNb_composante = %d\n",img.Nb_Ligne,img.Nb_Colonne,img.Nb_composante);
    printf("1er element rouge = %d\n1er element vert = %d\n1er element bleu = %d\n",img.adr_Matrice[0][0],img.adr_Matrice[img.Nb_Ligne][0],img.adr_Matrice[img.Nb_Ligne*2][0]);

    printf("\nPretraitement\n");
    img = Pre_traitement(&Erreur,img,Nb_Bit_Fort);
    printf("Nb_composante = %d\n",img.Nb_composante);
    printf("1er element = %d\n",img.adr_Matrice[0][0]);

    descripteur_image = Creation_Discripteur(&Erreur,img,Nb_Bit_Fort);
    printf("Nb_ligne = %d\nNb_Colonne = %d\n",descripteur_image.Nb_Ligne,descripteur_image.Nb_Colonne);

    printf("\nAffichage du tableau descripteur\n");
    for(int i = 0; i < pow(2,Nb_Bit_Fort*img.Nb_composante); i++ )
    {

        printf("Val n %d = %d Quantity = %d\n",i,descripteur_image.Bilan[i][0],descripteur_image.Bilan[i][1]);
        total = total+descripteur_image.Bilan[i][1];
    }
    printf("\nTotal de valeur = %d\n",total);
    total = 0;

    DESCRIPTEUR_IMAGE di;
    printf("\nTest du Pack\n");
    di = Pack_Descripteur_image(&Erreur,Path,Nb_Bit_Fort);
    
     printf("\nAffichage du tableau descripteur du pack\n");
    for(int i = 0; i < pow(2,Nb_Bit_Fort*img.Nb_composante); i++ )
    {
        printf("Val n %d = %d Quantity = %d\n",i,descripteur_image.Bilan[i][0],descripteur_image.Bilan[i][1]);  
        total = total+descripteur_image.Bilan[i][1];
    }
    printf("\nTotal de valeur = %d\n",total);

}