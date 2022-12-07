#include "../head/Global.h"
#include "../head/Descripteur_image.h"

IMAGE Lire_image(String *Erreur, String Path)
{
    IMAGE img;
    FILE *fichier = NULL;

    fichier = fopen(Path, "r");
    if (fichier != NULL)
    {
        strcpy(*Erreur,"Erreur : NULL");

        fscanf(fichier,"%d %d %d",&img.Nb_Ligne,&img.Nb_Colonne,&img.Nb_composante);
        
        img.adr_Matrice = malloc(img.Nb_Ligne*img.Nb_composante*sizeof(int*));
        for(int i = 0; i < img.Nb_Ligne*img.Nb_composante; i++)
        {
            img.adr_Matrice[i] = malloc(img.Nb_Colonne*sizeof(int));
        }
        if(img.adr_Matrice != NULL)
        {
            for(int cptligne = 0; cptligne < img.Nb_Ligne*img.Nb_composante; cptligne++)
            {
                for(int cptcolonne = 0; cptcolonne < img.Nb_Colonne; cptcolonne++)
                {
                    fscanf(fichier,"%d",&img.adr_Matrice[cptligne][cptcolonne]);
                }
            }
        }
        else
        {
            strcpy(*Erreur,"Erreur : Allocation");
        }
    }
    else
    {
        printf("Erreur : Fichier introuvable");
    }
    return img;
}

IMAGE Pre_traitement(IMAGE img)
{
    int Nv_mat[img.Nb_Ligne][img.Nb_Colonne];
    int R1,R2,G1,G2,B1,B2;
    for(int cptligne = 0; cptligne <img.Nb_Ligne; cptligne++)
    {
        for(int cptcolonne = 0; cptcolonne < img.Nb_Colonne; cptcolonne++)
        {
            R1 = (img.adr_Matrice[cptligne][cptcolonne] & 0x80)>>7-5;
            R2 = (img.adr_Matrice[cptligne][cptcolonne] & 0x40)>>6-4;
            if(img.Nb_composante == 3)
            {
                G1 = (img.adr_Matrice[cptligne*2][cptcolonne] & 0x80)>>7-3;
                G2 = (img.adr_Matrice[cptligne*2][cptcolonne] & 0x40)>>6-2;
                B1 = (img.adr_Matrice[cptligne*3][cptcolonne] & 0x80)>>7-1;
                B2 = (img.adr_Matrice[cptligne*3][cptcolonne] & 0x40)>>6;
            }
            Nv_mat[cptligne][cptcolonne] = R1+R2+G1+G2+B1+B2;
        }
    }
     
    for(int i = 0; i < img.Nb_Ligne*img.Nb_composante; i++)
    {
        free(img.adr_Matrice[i]);
    }
    free(img.adr_Matrice);
    *(img.adr_Matrice) = *Nv_mat;
    return img;
}