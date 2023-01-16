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
    printf("max : %f \n", max);

    return max;
}

tab_similaire *comparaison_audio(int seuil, int fenetre, int intervalle, char *chemin_descripteur_compare, char *chemin_descripteur_audio)
{

    int erreur;
    int id;
    descri_audio descri;

    int ligne;

    // getligne ici
    ligne=getligne(chemin_descripteur_compare,&erreur);
    descri = Descripteur_audio(fenetre, intervalle, chemin_descripteur_compare, &erreur);

    float verif_seuil;
    float max = 0;
    tab_similaire *tab = malloc(100 * sizeof(tab_similaire));
    if (tab == NULL)
    {
        return NULL;
    }
    int nbr_val;
    int val_lu;
    FILE *fichier = NULL;
    fichier = fopen("../descrripteur_texte_type.txt", "r");
    if (fichier == NULL)
    {
        erreur = 7;
    }

    int nbr_ligne;

    int i = 0;

    descri_audio descripteur_compare;

    descripteur_compare.colonne = intervalle;

    while (fscanf(fichier, "%d %d", &tab[i].id, &nbr_ligne) != EOF)
    {
        descripteur_compare.ligne = nbr_ligne;
        i++;
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
            }
        }

        verif_seuil = comparaison(val_lu, descripteur_compare, descripteur_compare.ligne, intervalle, descri, fenetre);
        if (verif_seuil > seuil)
            tab[i].pourcentage = verif_seuil;

        for (int i = 0; i < descripteur_compare.ligne; i++) // creation des colonne du tableau
        {
            free(descripteur_compare.tab[i]);
        }
        free(descripteur_compare.tab);
    }
    fclose(fichier);

    for (int i = 0; i < descri.ligne; i++) // creation des colonne du tableau
    {
        free(descri.tab[i]);
    }
    free(descri.tab);

    tab_similaire *tab_finale = malloc(i * sizeof(tab_similaire));

    for (int y = 0; y < i; y++)
    {
        tab_finale[y].id = 0;
        tab_finale[y].pourcentage = 0;
    }

    /* trie a voir !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        int idx;

        printf(" i = %d   \n",i);

        for(int y=0;y<i;y++)
        {
            max=0;
            for(int l=0;l<i;l++)
            {
                if(tab[l].pourcentage>max)
                {
                    max=tab[l].pourcentage;
                    id=tab[l].id;
                    idx=l;
                }
            }

            tab[idx].pourcentage=0;
            tab[idx].id=0;

            tab_finale[y].pourcentage=max;
            tab_finale[y].id=id;
        }
    */

    free(tab);

    return tab_finale;
}

tab_similaire* comparaison_texte(int nbr_mot,char* chemin_fichier_a_compare,char* chemin_descripteur,int * Erreur,int seuil)
{
char * mot_lu;
int id_lu;    
int comp=0;
float cpt=0;
int j=0;
float pourc=0;
DESCRIPTEUR_TEXTE tab1;
DESCRIPTEUR_TEXTE tab2;
String temp;
tab_similaire *tab=NULL;
tab2.tab_mot = malloc(nbr_mot * sizeof(*tab2.tab_mot));//creation du tableau
tab2.tab_app = malloc(nbr_mot * sizeof(*tab2.tab_app));//creation du tableau
tab1=descripteur_texte_finale(chemin_fichier_a_compare,nbr_mot,tab1);

    tab = (tab_similaire *)malloc(nbr_mot * sizeof(tab_similaire));
    if(tab2.tab_mot !=NULL && tab2.tab_app != NULL && tab != NULL)              //Vérification allocation malloc
    {
        FILE* fichierD = NULL;
       
        
        int cpt_sort = 0;
        fichierD = fopen(chemin_descripteur, "r");                           //Ouverture du texte à traiter
        if(fichierD==NULL)
        {
            *Erreur = 7;                                                //Erreur lors de l'ouverture d'un fichier
            exit(1);
        }
        while(fscanf(fichierD,"%d",&id_lu)!=EOF)
        {
            cpt=0;
            tab[j].id=id_lu;                                        //Récupération de l'ID
            for(int i=0;i<nbr_mot;i++)
            {
                fscanf(fichierD,"%s %d",tab2.tab_mot[i],&tab2.tab_app[i]);      //Remplir un tableau avec les mots et leur nombre d'apparition présent dans les descripteurs
        
            }
            j++;
            for(int v =0;v<nbr_mot; v++)
            {
                for(int y=0;y<nbr_mot;y++)
                {   
                    if(strcmp(tab1.tab_mot[v],tab2.tab_mot[y])==0)                      //Comparaison des deux tableaux pour trouver les mots en commun
                    {
                        printf("%s ",tab2.tab_mot[y]);
                        printf("%d\n",tab2.tab_app[y]);
                        comp = abs(tab1.tab_app[v]-tab2.tab_app[y]);                    //Valeur absolue entre le nombre d'apparition de chaque tableau pour le meme mot
                        if(0<comp<3)
                        {
                            cpt++;                                                      //Si le mot apparaît à 3 près pour les deux textes on augmente un compteur
                        }
                    }
                 }
            } 
            pourc=cpt/nbr_mot *100; 
            if(pourc > seuil)
            {
            tab[j].pourcentage= cpt/nbr_mot *100;                                     // Calcul pourcentage nombre de mot correspondant / nombre de mot total *100
            //printf("Similarite : %f pourcent", tab[j].pourcentage);
            }   
            
        }
        fclose(fichierD);
        for (int c = 0; c < cpt_sort; c++)
                {
                    for (int d = 0; d < cpt_sort; d++)
                    {
                        if (tab[c].pourcentage < tab[d].pourcentage)
                        {
                            float tmpid = tab[c].id;
                            float tmppour = tab[c].pourcentage;                     // Classement des pourcentages dans l'ordre drécroissants
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
        *Erreur=1;                      //Erreur Allocation
        exit(1);
    }
    return tab;
}

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