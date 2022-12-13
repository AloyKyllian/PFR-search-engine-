#include "../head/Global.h"
#include "../head/Descripteur_image.h"

IMAGE Lire_image(String *Erreur, String Path)
{
    IMAGE img;
    FILE *fichier = NULL;

    strcpy(img.Path,Path);
    fichier = fopen(Path, "r");
    if (fichier != NULL)
    {
        strcpy(*Erreur,"Erreur : NULL");

        fscanf(fichier,"%d %d %d",&img.Nb_Ligne,&img.Nb_Colonne,&img.Nb_composante);
        
        img.adr_Matrice = malloc(img.Nb_Ligne*img.Nb_composante*sizeof(*img.adr_Matrice));
        for(int i = 0; i < img.Nb_Ligne*img.Nb_composante; i++)
        {
            img.adr_Matrice[i] = malloc(img.Nb_Colonne*sizeof(**img.adr_Matrice));
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
        strcpy(*Erreur,"Erreur : Fichier introuvable");
    }
    return img;
}

IMAGE Pre_traitement(IMAGE img, int Nb_bitfort )
{
    //Variables
    int **Nv_mat;
    int bitR = 0;
    int bitG = 0;
    int bitB = 0;
    int masque = 0x80;
    int taille_bit_arranger = Nb_bitfort*img.Nb_composante;

    //Allocation mémoire du tableau 2D
    Nv_mat = malloc(img.Nb_Ligne*sizeof(*Nv_mat));
    for(int i = 0; i < img.Nb_Ligne; i++)
    {
        Nv_mat[i] = malloc(img.Nb_Colonne*sizeof(**Nv_mat));
    }

    //Remplissage de la matrice avec les pixel traiter
    for(int cptligne = 0; cptligne <img.Nb_Ligne; cptligne++)
    {
        for(int cptcolonne = 0; cptcolonne < img.Nb_Colonne; cptcolonne++)
        {
            Nv_mat[cptligne][cptcolonne] = 0;
            for(int cptbit = 0; cptbit < Nb_bitfort; cptbit++)
            {
                bitR = ((img.adr_Matrice[cptligne][cptcolonne] & (masque>>cptbit)))>>(7-cptbit);
                if(img.Nb_composante == 3)
                { 
                    bitG = ((img.adr_Matrice[cptligne+img.Nb_Ligne][cptcolonne] & (masque>>cptbit)))>>(7-cptbit);
                    bitB = ((img.adr_Matrice[cptligne+img.Nb_Ligne*2][cptcolonne] & (masque>>cptbit)))>>(7-cptbit);
                }
                Nv_mat[cptligne][cptcolonne] = Nv_mat[cptligne][cptcolonne] | bitR<<(taille_bit_arranger-(cptbit+1)) | bitG<<(taille_bit_arranger-Nb_bitfort-(cptbit+1)) | bitB<<(taille_bit_arranger-(Nb_bitfort*2)-(cptbit+1));
            }
        }
    }

    //Libert l'espace memoire du tableau image
    for(int cptligne = 0; cptligne <img.Nb_Ligne*img.Nb_composante; cptligne++)
    {
        free(img.adr_Matrice[cptligne]);
    }
    free(img.adr_Matrice);

    //Afectation de la matrice traiter à la structure
    img.adr_Matrice = Nv_mat;
    return img;
}

DESCRIPTEUR_IMAGE Creation_Discripteur(IMAGE img,int Nb_bitfort, String *Erreur)
{
    DESCRIPTEUR_IMAGE di;
    strcpy(di.Path,img.Path);
    di.Bilan = malloc( pow(2,Nb_bitfort*img.Nb_composante)*sizeof(*di.Bilan));
    for(int i = 0; i < pow(2,Nb_bitfort*img.Nb_composante); i++)
    {
        di.Bilan[i] = malloc(2*sizeof(**di.Bilan));
    }
    if(di.Bilan != NULL)
    {
        for(int cptligne = 0; cptligne <pow(2,Nb_bitfort*img.Nb_composante); cptligne++)
        {
            for(int cptcolonne = 0; cptcolonne < 2; cptcolonne++)
            {
                if(cptcolonne == 0)
                {
                    di.Bilan[cptligne][cptcolonne] = cptligne;
                }
                else
                {
                    di.Bilan[cptligne][cptcolonne] = 0;
                }
            }
        }
        for(int cptligne = 0; cptligne < img.Nb_Ligne; cptligne++)
        {
            for(int cptcolonne = 0; cptcolonne < img.Nb_Colonne; cptcolonne++)
            {
                di.Bilan[img.adr_Matrice[cptligne][cptcolonne]][1]++;
            }
        }
    }
    else
    {
        strcpy(*Erreur,"Erreur : Allocation");
    }
    
    return di;
}