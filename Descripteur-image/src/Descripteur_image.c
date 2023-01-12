#include "../head/Global.h"
#include "../head/Descripteur_image.h"

IMAGE Lire_image(int *Erreur, String Path)
{
    // Variable
    IMAGE img;
    FILE *fichier = NULL;

    // Ouvre le .txt et copy la matrice
    strcpy(img.Path, Path);
    fichier = fopen(Path, "r");
    if (fichier != NULL)
    {
        *Erreur = 0;

        fscanf(fichier, "%d %d %d", &img.Nb_Ligne, &img.Nb_Colonne, &img.Nb_composante);

        img.adr_Matrice = malloc(img.Nb_Ligne * img.Nb_composante * sizeof(*img.adr_Matrice));
        for (int i = 0; i < img.Nb_Ligne * img.Nb_composante; i++)
        {
            img.adr_Matrice[i] = malloc(img.Nb_Colonne * sizeof(**img.adr_Matrice));
        }
        if (img.adr_Matrice != NULL)
        {
            for (int cptligne = 0; cptligne < img.Nb_Ligne * img.Nb_composante; cptligne++)
            {
                for (int cptcolonne = 0; cptcolonne < img.Nb_Colonne; cptcolonne++)
                {
                    fscanf(fichier, "%d", &img.adr_Matrice[cptligne][cptcolonne]);
                }
            }
        }
        else
        {
            *Erreur = 1;
        }
    }
    else
    {
        *Erreur = 7;
    }
    return img;
}

IMAGE Pre_traitement(int *Erreur, IMAGE img, int Nb_Bit_Fort)
{
    // Variables
    int **Nv_mat;
    int bitR = 0;
    int bitG = 0;
    int bitB = 0;
    int masque = 0x80;
    int Nb_Bit_Total = Nb_Bit_Fort * img.Nb_composante;

    // Allocation mémoire du tableau 2D
    Nv_mat = malloc(img.Nb_Ligne * sizeof(*Nv_mat));
    for (int i = 0; i < img.Nb_Ligne; i++)
    {
        Nv_mat[i] = malloc(img.Nb_Colonne * sizeof(**Nv_mat));
    }
    if (Nv_mat != NULL)
    {
        *Erreur = 0;

        // Remplissage de la matrice avec les pixel traiter
        for (int cptligne = 0; cptligne < img.Nb_Ligne; cptligne++)
        {
            for (int cptcolonne = 0; cptcolonne < img.Nb_Colonne; cptcolonne++)
            {
                Nv_mat[cptligne][cptcolonne] = 0;
                for (int cptbit = 0; cptbit < Nb_Bit_Fort; cptbit++)
                {
                    // Decalage du bit en posistion 0
                    bitR = ((img.adr_Matrice[cptligne][cptcolonne] & (masque >> cptbit))) >> (7 - cptbit);
                    if (img.Nb_composante == 3)
                    {
                        bitG = ((img.adr_Matrice[cptligne + img.Nb_Ligne][cptcolonne] & (masque >> cptbit))) >> (7 - cptbit);
                        bitB = ((img.adr_Matrice[cptligne + img.Nb_Ligne * 2][cptcolonne] & (masque >> cptbit))) >> (7 - cptbit);
                    }
                    
                    // Remplissage de la matrice et decalage du bit à la bonne position
                    Nv_mat[cptligne][cptcolonne] = Nv_mat[cptligne][cptcolonne] | bitR << (Nb_Bit_Total - (cptbit + 1)) | bitG << (Nb_Bit_Total - Nb_Bit_Fort - (cptbit + 1)) | bitB << (Nb_Bit_Total - (Nb_Bit_Fort * 2) - (cptbit + 1));
                }
            }
        }

        // Libert l'espace memoire du tableau image
        for (int cptligne = 0; cptligne < img.Nb_Ligne * img.Nb_composante; cptligne++)
        {
            free(img.adr_Matrice[cptligne]);
        }
        free(img.adr_Matrice);

        // Afectation de la matrice traiter à la structure
        img.adr_Matrice = Nv_mat;
    }
    else
    {
        *Erreur = 1;
    }

    return img;
}

DESCRIPTEUR_IMAGE Creation_Discripteur(int *Erreur, IMAGE img, int Nb_Bit_Fort)
{
    // Variable
    DESCRIPTEUR_IMAGE descripteur_image;
    int i;
    int cptligne;
    int cptcolonne;

    // Allocation memoire du tableau 2D
    strcpy(descripteur_image.Path, img.Path);
    descripteur_image.Nb_Ligne = pow(2, Nb_Bit_Fort * img.Nb_composante);
    descripteur_image.Nb_Colonne = 2;
    descripteur_image.Bilan = malloc( descripteur_image.Nb_Ligne * sizeof(*descripteur_image.Bilan));
    for (i = 0; i < pow(2, Nb_Bit_Fort * img.Nb_composante); i++)
    {
        descripteur_image.Bilan[i] = malloc(descripteur_image.Nb_Colonne * sizeof(**descripteur_image.Bilan));
    }

    // Initialisation du tableau du descripteur
    if (descripteur_image.Bilan != NULL)
    {
        *Erreur = 0;

        for (cptligne = 0; cptligne < descripteur_image.Nb_Ligne; cptligne++)
        {
            for (cptcolonne = 0; cptcolonne < descripteur_image.Nb_Colonne; cptcolonne++)
            {
                if (cptcolonne == 0)
                {
                    descripteur_image.Bilan[cptligne][cptcolonne] = cptligne;
                }
                else
                {
                    descripteur_image.Bilan[cptligne][cptcolonne] = 0;
                }
            }
        }

        // Remplissage du tableau en comptant le nombre de valeur
        for (cptligne = 0; cptligne < img.Nb_Ligne; cptligne++)
        {
            for (cptcolonne = 0; cptcolonne < img.Nb_Colonne; cptcolonne++)
            {
                descripteur_image.Bilan[img.adr_Matrice[cptligne][cptcolonne]][1]++;
            }
        }
    }
    else
    {
        *Erreur = 1;
    }

    return descripteur_image;
}