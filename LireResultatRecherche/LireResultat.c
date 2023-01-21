#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../LireResultatRecherche/LireResultat.h"

void LireResultat(tab_similaire *tabResultat, int nbElement, char *type, char *requete, char *tabFileName[], int nombre_mot_cle, int similarite)
{
    
    int erreur;
    int max = 0;
    printf("\nverifie les element du tableau\n");
    for (int w = 0; w < nbElement && tabResultat[w].pourcentage >= similarite ; w++)
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
            lire_chemin( tabResultat, nbElement, type, nombre_mot_cle, similarite, &erreur);
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
            lire_chemin( tabResultat, nbElement, type, nombre_mot_cle, similarite, &erreur);
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
            lire_chemin( tabResultat, nbElement, type, nombre_mot_cle, similarite, &erreur);
        }
    }
}

void lire_chemin(tab_similaire *tabResultat, int nbElement, char *type, int nombre_mot_cle, int similarite, int *erreur)
{
    FILE *fichier = NULL;
    FILE *fichier1 = NULL;
    ELEMENT element;
    if (strcmp(type, "texte") == 0 || strcmp(type, "rechercheMot") == 0)
    {
        ELEMENT *base = (ELEMENT *)malloc(sizeof(ELEMENT));
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
                        if (strcmp(type, "rechercheMot") == 0 && tabResultat[i].pourcentage > 1)
                            printf("[%d] %s\t ->%d\n", i + 1, filename, (int)tabResultat[i].pourcentage);
                        if (strcmp(type, "texte") == 0 && tabResultat[i].pourcentage > 1)
                            printf("[%d] %s\t ->%d\n", i + 1, filename, (int)(tabResultat[i].pourcentage * nombre_mot_cle) / 100);
                    }
                }
            }
        }
        else
        {
            *erreur = 7;
        }
        fclose(fichier);
        free(base);
    }

    if (strcmp(type, "audio") == 0)
    {
        ELEMENT *base = (ELEMENT *)malloc(sizeof(ELEMENT));
        fichier = fopen("../liste_base/liste_base_audio", "r");
        int y = 0;
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
                    if (tabResultat[i].id == base[k].id)
                    {
                        char *filename = strrchr(base[k].CHEMIN, '/');
                        if (filename)
                        {
                            filename++;
                        }
                        else
                        {
                            filename = base[y].CHEMIN;
                        }
                        if (tabResultat[i].pourcentage >= similarite)
                            printf("[%d] %s\t ->%f\n", i + 1, filename, tabResultat[i].pourcentage);
                    }
                }
            }
            
            
        }
        fclose(fichier);
        free(base);
    }

    if (strcmp(type, "image") == 0)
    {
        ELEMENT *base = (ELEMENT *)malloc(sizeof(ELEMENT));
        int y = 0;
        fichier1 = fopen("../liste_base/liste_base_image/NB", "r");
        if (fichier1 != NULL)
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
                        if (tabResultat[i].pourcentage >= similarite)
                            printf("[%d] %s\t ->%f\n", i + 1, filename, tabResultat[i].pourcentage);
                    }
                }
            }
        }
        fclose(fichier1);
        free(base);
        ELEMENT *base2 = (ELEMENT *)malloc(sizeof(ELEMENT));
        int l=0;
        fichier = fopen("../liste_base/liste_base_image/RGB", "r");
        if (fichier != NULL)
        {
            while (fscanf(fichier, "%d | %s\n", &base2[l].id, base2[l].CHEMIN) != EOF)
            {
                l++;
                base2 = (ELEMENT *)realloc(base2, (l + 1) * sizeof(ELEMENT));
                
            }

            for (int i = 0; i < nbElement; i++)
            {
                for (int k = 0; k < l; k++)
                {
                    if (tabResultat[i].id == base2[k].id)
                    {
                        char *filename = strrchr(base2[k].CHEMIN, '/');
                        if (filename)
                        {
                            filename++;
                        }
                        else
                        {
                            filename = base2[k].CHEMIN;
                        }
                        if (tabResultat[i].pourcentage >= similarite)
                            printf("[%d] %s\t ->%f\n", i + 1, filename, tabResultat[i].pourcentage);
                    }
                }
            }
            
        }
        fclose(fichier);
        
        free(base2);
    }
}

// void affichage(PILE *IDchemin, tab_similaire *tabResultat, char *tabFileName[])
// {
//     PILE temp = *IDchemin;
//     int maxLength = 0, l = 0;
//     do
//     {
//         char *filename = strrchr((*temp).element.CHEMIN, '/');
//         if (filename)
//         {
//             filename++;
//         }
//         else
//         {
//             filename = (*temp).element.CHEMIN;
//         }
//         maxLength = fmax(maxLength, strlen(filename));
//         temp = (*temp).suiv;
//     } while (temp != NULL);

//     temp = *IDchemin;
//     l = 0;
//     do
//     {
//         char *filename = strrchr((*temp).element.CHEMIN, '/');
//         if (filename)
//         {
//             tabFileName[l] = filename;
//             printf("\n file name :%s et l=%d\n", tabFileName[l], l);
//             filename++;
//         }
//         else
//         {
//             filename = (*temp).element.CHEMIN;
//         }
//         int spaces = maxLength - strlen(filename);

//         printf("[%d] %s%*s ->%f\n", l + 1, filename, spaces, "", tabResultat[l].pourcentage);
//         temp = (*temp).suiv;
//         l++;
//     } while (temp != NULL);
//     *IDchemin = temp;
// }