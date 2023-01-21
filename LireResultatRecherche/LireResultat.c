#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../LireResultatRecherche/LireResultat.h"

void LireResultat(tab_similaire *tabResultat, int nbElement, char *type, char *requete, char *tabFileName[],int nombre_mot_cle, int seuil, int similarite,int *nombreElementTabFIN)
{

    int erreur;
    int element_tableauRes = 0;
    printf("\nverifie les element du tableau\n");
    for (int w = 0; w < nbElement; w++)
    {
        printf("\nID=%d, nb=%f\n", tabResultat[w].id, tabResultat[w].pourcentage);
    }

    // affichage des resultat de recherche par mot cle :
    printf("\nLes resultat pour votre recherche :\n");
    if (strstr(type, "rechercheMot"))
    {
        printf("\nRequete mot-cle : \"%s\"\n", requete);
        printf("\nRésultats (fichier -> occurrences) :\n");
        if (nbElement == 0)
        {
            printf("\nCe mot ne figure pas dans notre base de données\n");
        }
        else
        {
            element_tableauRes =lire_chemin(tabResultat, tabFileName, nbElement, "rechercheMot",nombre_mot_cle, seuil, similarite, &erreur);
        }
    }

    // affichage des resultat de comparaison texte :
    if (strstr(type, "texte"))
    {
        printf("\nRequete fichier : \"%s\"\n", requete);
        printf("\nRésultats (fichier -> nombre de mots-clés communs) :\n");
        if (nbElement == 0)
        {
            printf("\nAucun mot en communs n'a été trouvé dans notre base de données\n");
        }
        else
        {
            element_tableauRes =lire_chemin(tabResultat, tabFileName, nbElement, type,nombre_mot_cle, seuil, similarite, &erreur);
        }
    }

    // affichage des resultat de comparaison Image :
    if (strstr(type, "image"))
    {
        printf("\nRequete image : \"%s\"\n", requete);
        printf("\nRésultats :\n");
        if (nbElement == 0)
        {
            printf("\nAucune image similaire n'a été trouvé dans notre base de données\n");
        }
        else
        {
            element_tableauRes =lire_chemin(tabResultat, tabFileName, nbElement, type,nombre_mot_cle, seuil, similarite, &erreur);
        }
    }
    // affichage des resultat de comparaison Audio :
    if (strstr(type, "audio"))
    {

        printf("\nRequete son (jingle) : \"%s\"\n", requete);
        printf("\nRésultats :\n");
        if (nbElement == 0)
        {
            printf("\nAucun mot en communs n'a été trouvé dans notre base de données\n");
        }
        else
        {
            element_tableauRes =lire_chemin(tabResultat, tabFileName, nbElement, type,nombre_mot_cle, seuil, similarite, &erreur);
        }
    }
    // for (int i = 0; i < element_tableauRes; i++)
    // {
    //     printf("tab filename dans lire resultat apres lire chemin %d : %s\n", i, tabFileName[i]);
    // }
}

int lire_chemin(tab_similaire *tabResultat, char *tabFileName[], int nbElement, char *type,int nombre_mot_cle, int seuil, int similarite, int *erreur)
{
    FILE *fichier = NULL;
    FILE *fichier1 = NULL;
    ELEMENT *base = (ELEMENT *)malloc((nbElement + 1) * sizeof(ELEMENT));
    int ligne = 0;
    int l=0;
    if (strcmp(type, "rechercheMot") == 0)
    {
        int y = 0;
        fichier = fopen("../liste_base/liste_base_texte", "r");
        if (fichier != NULL)
        {
            while (fscanf(fichier, "%d | %s\n", &base[y].id, base[y].CHEMIN) != EOF)
            {
                y++;
                base = (ELEMENT *)realloc(base, (y + 1) * sizeof(ELEMENT));
            }

            for (int i = 0; i < nbElement; i++)
            {
                for (int k = 0; k < y; k++)
                {
                    if (tabResultat[i].pourcentage > seuil) 
                    {
                        if (tabResultat[i].id == base[k].id)
                        {
                            char *filename = strrchr(base[k].CHEMIN, '/');
                            if (filename)
                            {
                                filename++;
                            }
                            else
                            {
                                filename = base[k].CHEMIN;
                            }
                            tabFileName[i] = filename;
                            printf("\n[%d] %s\t ->%d\n", i + 1, filename, (int)tabResultat[i].pourcentage);
                            fflush(stdout);
                            l++;
                        }
                    }
                }
            }
            free(base);
        }
        else
        {
            *erreur = 7;
        }
        fclose(fichier);
    }

    if (strcmp(type, "texte") == 0)
    {
        fichier = fopen("../liste_base/liste_base_texte", "r");

        if (fichier != NULL)
        {
            while (fscanf(fichier, "%d | %s\n", &base[ligne].id, base[ligne].CHEMIN) != EOF)
            {
                ligne++;
            }

            for (int i = 0; i <= nbElement; i++)
            {
                for (int y = 0; y <= nbElement; y++)
                {
                    if (tabResultat[i].pourcentage > seuil) 
                    {

                        if (tabResultat[i].id == base[y].id)
                        {
                            char *filename = strrchr(base[y].CHEMIN, '/');
                            if (filename)
                            {
                                filename++;
                            }
                            else
                            {
                                filename = base[y].CHEMIN;
                            }
                            tabFileName[i] = filename;
                            printf("\n[%d] %s\t ->%d\n", i + 1, filename, (int)(tabResultat[i].pourcentage * nombre_mot_cle) / 100);
                            fflush(stdout);
                            l++;
                        }
                    }
                }
            }
            free(base);
        }
        else
        {
            *erreur = 7;
        }
        fclose(fichier);
    }

    if (strcmp(type, "audio") == 0)
    {
        fichier = fopen("../liste_base/liste_base_audio", "r");

        if (fichier != NULL)
        {
            while (fscanf(fichier, "%d | %s\n", &base[ligne].id, base[ligne].CHEMIN) != EOF)
            {
                ligne++;
            }

            for (int i = 0; i <= nbElement; i++)
            {
                for (int y = 0; y <= nbElement; y++)
                {
                    if (tabResultat[i].pourcentage > 75)
                    {
                        if (tabResultat[i].id == base[y].id)
                        {
                            char *filename = strrchr(base[y].CHEMIN, '/');
                            if (filename)
                            {
                                filename++;
                            }
                            else
                            {
                                filename = base[y].CHEMIN;
                            }
                            tabFileName[i] = filename;
                            printf("\n[%d] %s\t ->%f\n", i + 1, filename, tabResultat[i].pourcentage);
                            fflush(stdout);
                            l++;
                        }
                    }
                }
            }
            free(base);
        }
        fclose(fichier);
    }

    if (strcmp(type, "image") == 0)
    {

        fichier1 = fopen("../liste_base/liste_base_image/NB", "r");

        if (fichier1 != NULL)
        {
            while (fscanf(fichier1, "%d | %s\n", &base[ligne].id, base[ligne].CHEMIN) != EOF)
            {
                ligne++;
            }

            for (int i = 0; i <= nbElement; i++)
            {
                for (int y = 0; y <= nbElement; y++)
                {
                    if (tabResultat[i].pourcentage > 75)
                    {
                        if (tabResultat[i].id == base[y].id)
                        {
                            char *filename = strrchr(base[y].CHEMIN, '/');
                            if (filename)
                            {
                                filename++;
                            }
                            else
                            {
                                filename = base[y].CHEMIN;
                            }
                            tabFileName[i] = filename;
                            printf("\n[%d] %s\t ->%f\n", i + 1, filename, tabResultat[i].pourcentage);
                            l++;
                        }
                    }
                }
            }
        }
        fclose(fichier1);

        fichier = fopen("../liste_base/liste_base_image/RGB", "r");

        if (fichier != NULL)
        {
            while (fscanf(fichier, "%d | %s\n", &base[ligne].id, base[ligne].CHEMIN) != EOF)
            {
                ligne++;
            }

            for (int i = 0; i <= nbElement; i++)
            {
                for (int y = 0; y <= nbElement; y++)
                {
                    if (tabResultat[i].pourcentage > 75)
                    {
                        if (tabResultat[i].id == base[y].id)
                        {
                            char *filename = strrchr(base[y].CHEMIN, '/');
                            if (filename)
                            {
                                filename++;
                            }
                            else
                            {
                                filename = base[y].CHEMIN;
                            }

                            tabFileName[i] = filename;
                            printf("[%d] %s\t ->%f\n", i + 1, filename, tabResultat[i].pourcentage);
                            l++;
                        }
                    }
                }
            }
            free(base);
        }
        fclose(fichier);
    }
    return l;
}

char visualiser_fichier(char *tabFileName[], int nbElement, char *type)
{
    char *choix;
    char *choixRQ;
    char *numero_fichier = "1";
    char *lire = "gedit ";
    char *cheminBase;
    char *rmDroit = "chmod o-w ";
    char *addDroit = "chmod o+w ";
    char commande[1000];

    printf("verification des element du tab filename\n");
    for (int i = 0; i < nbElement; i++)
    {
        printf("%d = %s\n", i, tabFileName[i]);
    }

    if (strcmp(type, "texte") == 0)
    {
        cheminBase = "../DATA_FIL_ROUGE_DEV/Textes";
    }

    if (strcmp(type, "image") == 0)
    {
        cheminBase = "../DATA_FIL_ROUGE_DEV/IMG_et_AUDIO/TEST_RGB";
    }

    if (strcmp(type, "audio") == 0)
    {
        cheminBase = "../DATA_FIL_ROUGE_DEV/IMG_et_AUDIO/TEST_SON";
    }

    char *cheminBaseImgNB = "../DATA_FIL_ROUGE_DEV/IMG_et_AUDIO/TEST_NB";
    char *cheminBaseImgRGB = "../DATA_FIL_ROUGE_DEV/IMG_et_AUDIO/TEST_RGB";
    printf("---------------------REPERE---------------------------------------------\n");
    fflush(stdout);
    // afin de visualiser le premier fichier resultat on enleve les droits
    strcpy(commande, rmDroit);
    strcat(commande, cheminBase);
    strcat(commande, tabFileName[0]);
    printf("passage a system\n");
    fflush(stdout);
    system(commande);
    printf("commande rm droit %s\n", commande);

    // on l'ouvre pour que l'utilisateur le visualise
    strcpy(commande, lire);
    strcat(commande, cheminBase);
    strcat(commande, tabFileName[0]);
    system(commande);

    // on remet les permissions d'ecriture sur le fichier
    strcpy(commande, addDroit);
    strcat(commande, cheminBase);
    strcat(commande, tabFileName[0]);
    system(commande);

    while (choix[0] != '2' || choix[0] != '1')
    {
        printf("\nVoulez vous visionné un autre fichier ?\n[1] Oui\n[2] Non&\n");
        scanf("%s", choix);

        if (choix[0] == '2')
        {
            printf("\nVoulez vous revenir au Menu de recherche principale ou quitter le programme?\n[R] Retour\n[Q] Quitter\n");
            scanf("%s", choixRQ);
            return choixRQ[0];
        }

        if (choix[0] == '1')
        {
            while (((int)numero_fichier[0]) > nbElement)
            {
                printf("\nEntrer le numero de fichier que vous voulez visualiser, ou R pour un retour vers le menu de recherche texte\n");
                scanf("%s", numero_fichier);
                if (((int)(numero_fichier[0])) > nbElement || numero_fichier[0] != 'R')
                    printf("\nCe choix de fichier ne figure pas dans la liste\n");
                if (numero_fichier[0] == 'R')
                    return numero_fichier[0];
            }
            strcpy(commande, rmDroit);
            strcat(commande, cheminBase);
            strcat(commande, tabFileName[((int)(numero_fichier[0])) - 1]);
            system(commande);

            // on l'ouvre pour que l'utilisateur le visualise
            strcpy(commande, lire);
            strcat(commande, cheminBase);
            strcat(commande, tabFileName[((int)(numero_fichier[0])) - 1]);
            system(commande);

            // on remet les permissions d'ecriture sur le fichier
            strcpy(commande, addDroit);
            strcat(commande, cheminBase);
            strcat(commande, tabFileName[((int)(numero_fichier[0])) - 1]);
            system(commande);
        }

        else
        {
            printf("\nCe choix n'existe pas, veuillez faire le bon choix\n");
        }
    }
    return 'R';
}