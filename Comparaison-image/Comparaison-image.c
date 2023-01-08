#include "Comparaison-image.h"
#include "../descripteur_image/Descripteur_image.h"

tab_similaire *Comparaison_descripteur_image(int *Erreur, char PathRecueil[], char PathNvImg[], int Nb_Bits_Fort, int *Nb_des)
{
    // Variable
    DESCRIPTEUR_IMAGE descripteur_image;
    tab_similaire *Tab = NULL;
    
    // Creation du descripteur de la nouvelle image
    descripteur_image = Pack_Descripteur_image(Erreur, PathNvImg, Nb_Bits_Fort);
    if (*Erreur == 0)
    {
        // Allocation memoire du Tableau de similariter
        Tab = (tab_similaire *)malloc(descripteur_image.Nb_Ligne * sizeof(tab_similaire));
        if (Tab != NULL)
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
                int max;
                float TotalPourcentage;
                

                // Lecture du recueil de descripteur image
                fscanf(fichier, "%d", &debut);
                while (debut <= 0)
                {
                    TotalPourcentage = 0;
                    float PourcentageDiff[descripteur_image.Nb_Ligne];
                    for (cptval = 0; cptval < descripteur_image.Nb_Ligne; cptval++)
                    {
                        fscanf(fichier, "%d %d", &val,&val);

                        max = (descripteur_image.Bilan[cptval][1] >= val) ? descripteur_image.Bilan[cptval][1] : val;

                        // Calcul du % de difference (entre 0 et 100)
                        if(max == 0)
                        {
                            PourcentageDiff[cptval] = 0;
                        }
                        else
                        {
                            PourcentageDiff[cptval] = (float)(descripteur_image.Bilan[cptval][1] - val) / max*100;
                            if(PourcentageDiff[cptval] < 0)
                            {
                                PourcentageDiff[cptval] = -PourcentageDiff[cptval];
                            }
                            
                        }
                        TotalPourcentage = TotalPourcentage + PourcentageDiff[cptval];
                    }
                    // Affectation des id et de la moyenne des Pourcentages
                    Tab[cpt_des].id = cpt_des;
                    TotalPourcentage = 100.0 - (TotalPourcentage / cptval);
                    
                    Tab[cpt_des].pourcentage = TotalPourcentage;
                    cpt_des++;

                    // Verification s'il y a un autre descripteur
                    if (fscanf(fichier, "%d", &debut) == EOF)
                    {
                        debut = 1;
                    }
                }
                fclose(fichier);

                *Nb_des = cpt_des;

                // Triage des fichiers par ordre de similariter
                for (int i = 0; i < cpt_des; i++)
                {
                    for (int j = 0; j < cpt_des; j++)
                    {
                        if (Tab[i].pourcentage < Tab[j].pourcentage)
                        {
                            float tmpid = Tab[i].id;
                            float tmppour = Tab[i].pourcentage;
                            Tab[i].id = Tab[j].id;
                            Tab[i].pourcentage = Tab[j].pourcentage;
                            Tab[j].id = tmpid;
                            Tab[j].pourcentage = tmppour;
                        }
                    }
                }
            }
            else
            {
                *Erreur = 7;
            }
        }
        else
        {
            *Erreur = 1;
        }
    }
    return Tab;
}