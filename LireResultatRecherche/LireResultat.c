#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../LireResultatRecherche/LireResultat.h"

void LireResultat(tab_similaire *tabResultat, int nbElement, char *type, char *requete, char *tabFileName[])
{
    PILE IDchemin;
    char *commande = (char *)malloc(200);
    strcpy(commande, "basename ");
    int erreur;
    int max = 0;
    IDchemin = init_PILE();
    // printf("verifie les element du tableau\n");
    // for(int k=0;k<nbElement && tabResultat[k].pourcentage>0;k++){
    //    printf("ID=%d, nb=%f\n",tabResultat[k].id,tabResultat[k].pourcentage);
    // }

    // affichage des resultat de recherche par mot cle :
    printf("\nLes resultat pour votre recherche :\n");
    if (strstr(type, "rechercheMot"))
    {
        lire_chemin(&IDchemin, tabResultat, nbElement, "texte", &erreur);
        printf("\nRequete mot-cle : \"%s\"\n", requete);
        printf("\nRésultats (fichier -> occurrences) :\n");
        if (nbElement == 0)
        {
            printf("\nCe mot ne figure pas dans notre base de données\n");
        }
        else
        {
            affichage(&IDchemin, tabResultat, &tabFileName[nbElement]);
        }
    }

    // affichage des resultat de comparaison texte :
    if (strstr(type, "texte"))
    {
        lire_chemin(&IDchemin, tabResultat, nbElement, type, &erreur);
        printf("\nRequete fichier : \"%s\"\n", requete);
        printf("\nRésultats (fichier -> nombre de mots-clés communs) :\n");
        if (nbElement == 0)
        {
            printf("\nAucun mot en communs n'a été trouvé dans notre base de données\n");
        }
        else
        {
            affichage(&IDchemin, tabResultat, &tabFileName[nbElement]);
        }
    }

    // affichage des resultat de comparaison Image :
    if (strstr(type, "image"))
    {
        lire_chemin(&IDchemin, tabResultat, nbElement, type, &erreur);
        printf("on check la pile apres lire_chemin\n");
        affichePILE(IDchemin);
        printf("\nRequete image : \"%s\"\n", requete);
        printf("\nRésultats :\n");
        if (nbElement == 0)
        {
            printf("\nAucune image similaire n'a été trouvé dans notre base de données\n");
        }
        else
        {
            affichage(&IDchemin, tabResultat, &tabFileName[nbElement]);
        }
    }
    // affichage des resultat de comparaison Audio :
    if (strstr(type, "audio"))
    {
        lire_chemin(&IDchemin, tabResultat, nbElement, type, &erreur);
        printf("\nRequete son (jingle) : \"%s\"\n", requete);
        printf("\nRésultats :\n");
        if (nbElement == 0)
        {
            printf("\nAucun mot en communs n'a été trouvé dans notre base de données\n");
        }
        else
        {
            // affichage(&IDchemin, tabResultat, &tabFileName[nbElement]);
        }
    }
}

void lire_chemin(PILE *pourchemin, tab_similaire *tabResultat, int nbElement, char *type, int *erreur)
{
    FILE *fichier = NULL;
    FILE *fichier1 = NULL;
    ELEMENT element;
    if (strcmp(type, "texte") == 0)
    {
        fichier = fopen("../liste_base/liste_base_texte", "r");
        if (fichier != NULL)
        {
            while (fscanf(fichier, "%d | %s\n", &element.id, element.CHEMIN) != EOF)
            {
                for (int i = 0; i < nbElement && tabResultat[i].pourcentage > 0; i++)
                {
                    if (element.id == tabResultat[i].id)
                    {
                        // printf("element id%d\n", element.id);
                        *pourchemin = emPILE(*pourchemin, element);
                    }
                }
            }
        }

        else
        {
            *erreur = 7;
        }
    }

    if (strcmp(type, "audio") == 0)
    {
        ELEMENT *base= (ELEMENT *)malloc(sizeof(ELEMENT));
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
                for (int y = 0; y < nbElement; y++)
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
                        //printf("\n----------------REPERE--------------\n");
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
            while (fscanf(fichier1, "%d | %s\n", &element.id, element.CHEMIN) != EOF)
            {
                for (int i = 0; i < nbElement && tabResultat[i].pourcentage > 0; i++)
                {
                    if (element.id == tabResultat[i].id)
                    {
                        // printf("element id%d\n", element.id);
                        *pourchemin = emPILE(*pourchemin, element);
                    }
                }
            }
        }
        fclose(fichier1);

        fichier = fopen("../liste_base/liste_base_image/RGB", "r");
        if (fichier != NULL)
        {
            while (fscanf(fichier, "%d | %s\n", &element.id, element.CHEMIN) != EOF)
            {
                for (int i = 0; i < nbElement && tabResultat[i].pourcentage > 0; i++)
                {
                    if (element.id == tabResultat[i].id)
                    {
                        // printf("element id%d\n", element.id);
                        *pourchemin = emPILE(*pourchemin, element);
                    }
                }
            }
        }
        fclose(fichier);
    }

    printf("affichage de pile dans lire_chemin\n");
    affichePILE(*pourchemin);
    fclose(fichier);
}

void affichage(PILE *IDchemin, tab_similaire *tabResultat, char *tabFileName[])
{
    PILE temp = *IDchemin;
    int maxLength = 0, l = 0;
    do
    {
        char *filename = strrchr((*temp).element.CHEMIN, '/');
        if (filename)
        {
            filename++;
        }
        else
        {
            filename = (*temp).element.CHEMIN;
        }
        maxLength = fmax(maxLength, strlen(filename));
        temp = (*temp).suiv;
    } while (temp != NULL);

    temp = *IDchemin;
    l = 0;
    do
    {
        char *filename = strrchr((*temp).element.CHEMIN, '/');
        if (filename)
        {
            tabFileName[l] = filename;
            printf("\n file name :%s et l=%d\n", tabFileName[l], l);
            filename++;
        }
        else
        {
            filename = (*temp).element.CHEMIN;
        }
        int spaces = maxLength - strlen(filename);

        printf("[%d] %s%*s ->%f\n", l + 1, filename, spaces, "", tabResultat[l].pourcentage);
        temp = (*temp).suiv;
        l++;
    } while (temp != NULL);
    *IDchemin = temp;
}