#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../LireResultatRecherche/LireResultat.h"

void LireResultat(tab_similaire *tabResultat, int nbElement, char *type, char *requete, char *tabFileName[], int nombre_mot_cle, int similarite)
{

    int erreur;
    int max = 0;
    // printf("\nverifie les element du tableau\n");
    // for (int w = 0; w < nbElement && tabResultat[w].pourcentage >= similarite ; w++)
    // {
    //     printf("\nID=%d, nb=%f\n", tabResultat[w].id, tabResultat[w].pourcentage);
    // }

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
            lire_chemin(tabResultat, nbElement, "rechercheMot", nombre_mot_cle, similarite, &erreur);
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
            lire_chemin(tabResultat, nbElement, type, nombre_mot_cle, similarite, &erreur);
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
            lire_chemin(tabResultat, nbElement, type, nombre_mot_cle, similarite, &erreur);
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
            lire_chemin(tabResultat, nbElement, type, nombre_mot_cle, similarite, &erreur);
        }
    }
}

void lire_chemin(tab_similaire *tabResultat, int nbElement, char *type, int nombre_mot_cle, int similarite, int *erreur)
{
    FILE *fichier = NULL;
    FILE *fichier1 = NULL;
    ELEMENT element;
    ELEMENT *base = (ELEMENT *)malloc((nbElement + 1) * sizeof(ELEMENT));
    int ligne = 0;
    int nbEl=nbElement;
    
    if (strcmp(type, "texte") == 0 || strcmp(type, "rechercheMot") == 0)
    {
        fichier = fopen("../liste_base/liste_base_texte", "r");

        if (fichier != NULL)
        {
            while (fscanf(fichier, "%d | %s\n", &base[ligne].id, base[ligne].CHEMIN) != EOF)
            {
                ligne++;
            }
            if(strcmp(type, "rechercheMot") == 0)
                nbElement=ligne;

            for (int i = 0; i <= nbEl; i++)
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
                            // printf("\n----------------REPERE--------------\n");
                            if (strcmp(type, "rechercheMot") == 0 && tabResultat[i].pourcentage > 1)
                                printf("[%d] %s\t ->%d\n", i + 1, filename, (int)tabResultat[i].pourcentage);
                            if (strcmp(type, "texte") == 0 && tabResultat[i].pourcentage > 1)
                                printf("[%d] %s\t ->%d\n", i + 1, filename, (int)(tabResultat[i].pourcentage * nombre_mot_cle) / 100);
                            fflush(stdout);
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
                        // printf("\n----------------REPERE--------------\n");
                        printf("[%d] %s\t ->%f\n", i + 1, filename, tabResultat[i].pourcentage);
                        fflush(stdout);
                    }
                }
            }
            free(base);
        }
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
                        // printf("\n----------------REPERE--------------\n");
                        printf("[%d] %s\t ->%f\n", i + 1, filename, tabResultat[i].pourcentage);
                        fflush(stdout);
                    }
                }
            }
            free(base);
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
                        // printf("\n----------------REPERE--------------\n");
                        printf("[%d] %s\t ->%f\n", i + 1, filename, tabResultat[i].pourcentage);
                        fflush(stdout);
                    }
                }
            }
            free(base);
        }
        fclose(fichier);
    }

    // printf("affichage de pile dans lire_chemin\n");
    // affichePILE(*pourchemin);
    // fclose(fichier);
}