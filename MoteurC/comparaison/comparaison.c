/**
 * Fait par Loic Maignan, Hugo Lestrade, Kyllian Aloy
 * 
 * Le 23/01/2023
 * 
*/



#include "comparaison.h"

float comparaison(int val_lu, descri_audio descripteur_comparé, int ligne, int intervalle, descri_audio descri, float fenetre)
{
    float pourcentage, max = 0;
    descripteur_comparé.ligne = ligne;
    descripteur_comparé.colonne = intervalle;

    for (int intnbr = 0; intnbr <= descripteur_comparé.ligne - descri.ligne; intnbr++)
    {
        int comparateur = 0;
        for (unsigned i = 0; i < descri.ligne; ++i)
        {
            for (unsigned j = 0; j < descri.colonne; ++j)
            {
                if (descripteur_comparé.tab[i + intnbr][j] - descri.tab[i][j] > 0)
                    comparateur += descripteur_comparé.tab[i + intnbr][j] - descri.tab[i][j];
                else
                    comparateur += descri.tab[i][j] - descripteur_comparé.tab[i + intnbr][j];
            }
        }
        pourcentage = comparateur / (fenetre * 4.) * 100;
        pourcentage = 100 - pourcentage;
        if (pourcentage > max)
        {
            max = pourcentage;
        }
    }
printf("%f",max);
    return max;
}

tab_similaire *comparaison_audio(int fenetre, int intervalle, char *chemin_fichier, char *chemin_descripteur_audio, int *erreur, int *Nb_ligne)
{
    int id;
    descri_audio descri;

    int ligne;

    ligne = getligne(chemin_fichier, erreur);
    printf("LLLAAAAA   %s",chemin_fichier);
    descri = Descripteur_audio(fenetre, intervalle, chemin_fichier, erreur);

    float pourcentage;
    float max = 0;
    tab_similaire *tab = (tab_similaire *)malloc(sizeof(tab_similaire));
    if (tab == NULL)
    {
        return NULL;
    }
    int nbr_val;
    int val_lu;
    FILE *fichier = NULL;
     printf("\n%s",chemin_descripteur_audio);
    fichier = fopen(chemin_descripteur_audio, "r");
    if (fichier == NULL)
    {
        *erreur = 7;
    }
    int nbr_ligne;

    int i = 0;

    descri_audio descripteur_compare;

    descripteur_compare.colonne = intervalle;

    while (fscanf(fichier, "%d %d", &tab[i].id, &nbr_ligne) != EOF)
    {
        descripteur_compare.ligne = nbr_ligne;
        descripteur_compare.tab = malloc(descripteur_compare.ligne * sizeof(*descripteur_compare.tab)); // creation du tableau
        for (int i = 0; i < descripteur_compare.ligne; i++)
        {
            descripteur_compare.tab[i] = malloc(intervalle * sizeof(descripteur_compare.tab));
        }

        for (int lig = 0; lig < descripteur_compare.ligne; lig++)
        {
            for (int col = 0; col < intervalle; col++)
            {
                fscanf(fichier, "%d", &descripteur_compare.tab[lig][col]);
                //printf("%d\n",descri.tab[lig][col]);
            }
        }
       
        pourcentage = comparaison(val_lu, descripteur_compare, descripteur_compare.ligne, intervalle, descri, fenetre);
        tab[i].pourcentage = pourcentage;

        for (int i = 0; i < descripteur_compare.ligne; i++) // creation des colonne du tableau
        {
            free(descripteur_compare.tab[i]);
        }
        free(descripteur_compare.tab);

        i++;
        tab = (tab_similaire *)realloc(tab, (i + 1) * sizeof(tab_similaire));

    }
    fclose(fichier);

    for (int i = 0; i < descri.ligne; i++) // creation des colonne du tableau
    {
        free(descri.tab[i]);
    }
    free(descri.tab);

    // Triage des fichiers par ordre de similariter
    for (int cpt = 0; cpt < i; cpt++)
    {
        for (int j = 0; j < i; j++)
        {

            if (tab[cpt].pourcentage > tab[j].pourcentage)
            {
                int tmpid = tab[cpt].id;
                float tmppour = tab[cpt].pourcentage;
                tab[cpt].id = tab[j].id;
                tab[cpt].pourcentage = tab[j].pourcentage;
                tab[j].id = tmpid;
                tab[j].pourcentage = tmppour;
            }
        }
    }
    *Nb_ligne = i;

    return tab;
}

tab_similaire *comparaison_texte(int nbr_mot, char *chemin_fichier_a_compare, char *chemin_descripteur, int *Erreur, int *Nb_ligne)
{
    char *mot_lu;
    int id_lu;
    int comp = 0;
    int cpt = 0;
    int j = 0;
    DESCRIPTEUR_TEXTE tab1;
    DESCRIPTEUR_TEXTE tab2;
    String temp;
    tab_similaire *tab = NULL;
    tab2.tab_mot = malloc(nbr_mot * sizeof(*tab2.tab_mot)); // creation du tableau
    tab2.tab_app = malloc(nbr_mot * sizeof(*tab2.tab_app)); // creation du tableau
    tab1 = descripteur_texte_finale(chemin_fichier_a_compare, nbr_mot, tab1);

    tab = (tab_similaire *)malloc(1000 * sizeof(tab_similaire));
    if (tab2.tab_mot != NULL && tab2.tab_app != NULL && tab != NULL) // Vérification allocation malloc
    {
        FILE *fichierD = NULL;

        int cpt_sort = 0;
        fichierD = fopen(chemin_descripteur, "r"); // Ouverture du texte à traiter
        if (fichierD == NULL)
        {
            *Erreur = 7; // Erreur lors de l'ouverture d'un fichier
            exit(1);
        }
        while (fscanf(fichierD, "%d", &id_lu) != EOF)
        {
            cpt = 0;
            tab[j].id = id_lu; // Récupération de l'ID
            for (int i = 0; i < nbr_mot; i++)
            {
                fscanf(fichierD, "%s    |    %d", tab2.tab_mot[i], &tab2.tab_app[i]); // Remplir un tableau avec les mots et leur nombre d'apparition présent dans les descripteurs
                // if(strcmp(tab2.tab_mot[i],"NO_DATAdjfghsdk")!=0)
                //  strcpy(tab2.tab_mot[i],"");
            }

            for (int v = 0; v < nbr_mot; v++)
            {
                for (int y = 0; y < nbr_mot; y++)
                {

                    if (strcmp(tab1.tab_mot[v], tab2.tab_mot[y]) == 0 && strcmp(tab1.tab_mot[v], "NO_DATAdjfghsdk") != 0) // Comparaison des deux tableaux pour trouver les mots en commun
                    {
                        comp = abs(tab1.tab_app[v] - tab2.tab_app[y]); // Valeur absolue entre le nombre d'apparition de chaque tableau pour le meme mot
                        if (0 <= comp && comp < 3)
                        {
                            cpt++; // Si le mot apparaît à 3 près pour les deux textes on augmente un compteur
                        }
                    }
                }
            }
            tab[j].pourcentage = (float)cpt / nbr_mot * 100; // Calcul pourcentage nombre de mot correspondant / nombre de mot total *100
            j++;
        }
        fclose(fichierD);
        cpt_sort = j;
        for (int c = 0; c < cpt_sort; c++)
        {
            for (int d = 0; d < cpt_sort; d++)
            {
                if (tab[c].pourcentage > tab[d].pourcentage)
                {
                    int tmpid = tab[c].id;
                    float tmppour = tab[c].pourcentage; // Classement des pourcentages dans l'ordre drécroissants
                    tab[c].id = tab[d].id;
                    tab[c].pourcentage = tab[d].pourcentage;
                    tab[d].id = tmpid;
                    tab[d].pourcentage = tmppour;
                }
            }
        }
    }
    else
    {
        *Erreur = 1; // Erreur Allocation
        exit(1);
    }

    *Nb_ligne = j;
    return tab;
}

tab_similaire *Comparaison_descripteur_image(int *Erreur, char PathRecueil[], char PathNvImg[], int Nb_Bits_Fort, int *Nb_des)
{
    // Variable
    DESCRIPTEUR_IMAGE descripteur_image;
    tab_similaire *Tab = NULL;
    int *des = NULL;

    // Creation du descripteur de la nouvelle image
    descripteur_image = Pack_Descripteur_image(Erreur, PathNvImg, Nb_Bits_Fort);

    if (*Erreur == 0)
    {
        des = (int *)malloc(sizeof(int));
        // Allocation memoire du Tableau de similariter
        Tab = (tab_similaire *)malloc(sizeof(tab_similaire));
        if (Tab != NULL && des != NULL)
        {
            FILE *fichier = NULL;
            int val = 10;
            int debut;

            fichier = fopen(PathRecueil, "r");
            if (fichier != NULL)
            {
                *Erreur = 0;
                int cptval;
                int cpt_des = 0;
                int max;
                float TotalPourcentage;
                int cpt_val = 0;

                // Lecture du recueil de descripteur image
                while (1)
                {
                    if (fscanf(fichier, "%d", &debut) == EOF)
                    {
                        cpt_des++;
                        // Allocation memoire du Tableau de similariter
                        Tab = (tab_similaire *)realloc(Tab, (cpt_des + 1) * sizeof(tab_similaire));
                        Tab[cpt_des].id = debut;

                        TotalPourcentage = 0;
                        float PourcentageDiff[descripteur_image.Nb_Ligne];
                        for (int i = 0; i < descripteur_image.Nb_Ligne; i++)
                        {
                            PourcentageDiff[i] = 0;
                        }
                        if (cpt_val == descripteur_image.Nb_Ligne) // comparer que si c'est du meme type de couleur (exemple RGB avec RGB et NB avec NB)
                        {
                            for (int i = 0; i < descripteur_image.Nb_Ligne; i++)
                            {

                                max = (descripteur_image.Bilan[i][1] >= des[i]) ? descripteur_image.Bilan[i][1] : des[i];

                                // Calcul du % de difference (entre 0 et 100)
                                if (max == 0)
                                {
                                    PourcentageDiff[i] = 0;
                                }
                                else
                                {
                                    PourcentageDiff[i] = (float)(descripteur_image.Bilan[i][1] - des[i]) / max * 100;
                                    if (PourcentageDiff[i] < 0)
                                    {
                                        PourcentageDiff[i] = -PourcentageDiff[i];
                                    }
                                }
                                TotalPourcentage = TotalPourcentage + PourcentageDiff[i];
                            }
                            Tab[cpt_des - 1].pourcentage = 100 - TotalPourcentage / cpt_val;
                        }
                        free(des);
                        des = (int *)malloc(sizeof(int));
                        cpt_val = 0;
                        break;
                    }
                    if (debut < 0) // traitement et enregistrement de id
                    {
                        cpt_des++;
                        // Allocation memoire du Tableau de similariter
                        Tab = (tab_similaire *)realloc(Tab, (cpt_des + 1) * sizeof(tab_similaire));
                        Tab[cpt_des].id = debut;

                        TotalPourcentage = 0;
                        float PourcentageDiff[descripteur_image.Nb_Ligne];
                        for (int i = 0; i < descripteur_image.Nb_Ligne; i++)
                        {
                            PourcentageDiff[i] = 0;
                        }

                        if (cpt_val == descripteur_image.Nb_Ligne) // comparer que si c'est du meme type de couleur (exemple RGB avec RGB et NB avec NB)
                        {
                            for (int i = 0; i < descripteur_image.Nb_Ligne; i++)
                            {

                                max = (descripteur_image.Bilan[i][1] >= des[i]) ? descripteur_image.Bilan[i][1] : des[i];

                                // Calcul du % de difference (entre 0 et 100)
                                if (max == 0)
                                {
                                    PourcentageDiff[i] = 0;
                                }
                                else
                                {
                                    PourcentageDiff[i] = (float)(descripteur_image.Bilan[i][1] - des[i]) / max * 100;
                                    if (PourcentageDiff[i] < 0)
                                    {
                                        PourcentageDiff[i] = -PourcentageDiff[i];
                                    }
                                }
                                TotalPourcentage = TotalPourcentage + PourcentageDiff[i];
                            }
                            Tab[cpt_des - 1].pourcentage = 100 - TotalPourcentage / cpt_val;
                        }
                        free(des);
                        des = (int *)malloc(sizeof(int));
                        cpt_val = 0;
                    }

                    else // affectation des valeurs du descripteur a un tableau
                    {
                        fscanf(fichier, "%d", &val);
                        des[cpt_val] = val;
                        cpt_val++;
                        des = (int *)realloc(des, (cpt_val + 1) * sizeof(int));
                    }
                }
                fclose(fichier);

                // traitement
                cpt_des++;
                // Allocation memoire du Tableau de similariter
                Tab = (tab_similaire *)realloc(Tab, (cpt_des + 1) * sizeof(tab_similaire));
                Tab[cpt_des].id = debut;

                TotalPourcentage = 0;
                float PourcentageDiff[descripteur_image.Nb_Ligne];
                for (int i = 0; i < descripteur_image.Nb_Ligne; i++)
                {
                    PourcentageDiff[i] = 0;
                }

                if (cpt_val == descripteur_image.Nb_Ligne) // comparer que si c'est du meme type de couleur (exemple RGB avec RGB et NB avec NB)
                {
                    for (int i = 0; i < descripteur_image.Nb_Ligne; i++)
                    {
                        max = (descripteur_image.Bilan[i][1] >= des[i]) ? descripteur_image.Bilan[i][1] : des[i];

                        // Calcul du % de difference (entre 0 et 100)
                        if (max == 0)
                        {
                            PourcentageDiff[i] = 0;
                        }
                        else
                        {
                            PourcentageDiff[i] = (float)(descripteur_image.Bilan[i][1] - des[i]) / max * 100;
                            if (PourcentageDiff[i] < 0)
                            {
                                PourcentageDiff[i] = -PourcentageDiff[i];
                            }
                        }
                        TotalPourcentage = TotalPourcentage + PourcentageDiff[i];
                    }
                    Tab[cpt_des - 1].pourcentage = TotalPourcentage / cpt_val;
                }
                else
                {
                    free(des);
                    cpt_val = 0;
                }

                *Nb_des = cpt_des;

                // Triage des fichiers par ordre de similariter
                for (int i = 0; i < cpt_des; i++)
                {
                    for (int j = 0; j < cpt_des; j++)
                    {
                        if (Tab[i].pourcentage > Tab[j].pourcentage)
                        {
                            int tmpid = Tab[i].id;
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