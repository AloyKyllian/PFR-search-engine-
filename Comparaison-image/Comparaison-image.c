#include "Comparaison-image.h"
#include "../descripteur_image/Descripteur_image.h"

tab_similaire *Comparaison_descripteur_image(int *Erreur, char PathRecueil[], char PathNvImg[], int Nb_Bits_Fort)
{
    // Creation du Nv descripteur img
    DESCRIPTEUR_IMAGE descripteur_image;
    descripteur_image = Pack_Descripteur_image(Erreur, PathNvImg, Nb_Bits_Fort);
    tab_similaire Tab[descripteur_image.Nb_Ligne];
    if (*Erreur == 0)
    {
        FILE *fichier = NULL;
        int val;
        int debut;

        fichier = fopen(PathRecueil, "r");
        if (fichier != NULL)
        {
            *Erreur = 0;
            int cptval;
            int cpt_des = 0;
            int TotalPourcentage;
            int PourcentageDiff[descripteur_image.Nb_Ligne];

            fscanf(fichier, "%d", &debut);
            while (debut <= 0)
            {
                TotalPourcentage = 0;
                for (cptval = 0; cptval < descripteur_image.Nb_Ligne; cptval++)
                {
                    fscanf(fichier, "%d", &val);
                    fscanf(fichier, "%d", &val);
                    PourcentageDiff[cptval] = abs((descripteur_image.Bilan[cptval][1] - val) / fmax(descripteur_image.Bilan[cptval][1], val)) * 100;
                    TotalPourcentage = TotalPourcentage + PourcentageDiff[cptval];
                }
                Tab[cpt_des].id = cpt_des;
                Tab[cpt_des].pourcentage = 100 - (TotalPourcentage / cptval);

                printf("\nId: %d Pourcentage: %d", Tab[cpt_des].id, Tab[cpt_des].pourcentage);
                cpt_des++;

                if (fscanf(fichier, "%d", &debut) == EOF)
                {
                    debut = 1;
                }
            }
            fclose(fichier);
        }
        else
        {
            *Erreur = 7;
        }
    }
}