//
// AUTEUR :
//          YOUSSERA ACHACHERA
// DERNIERE VERSION :
//    23/01/2023
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../LireResultatRecherche/LireResultat.h"

int LireResultat(tab_similaire *tabResultat, int nbElement, char *type, char *requete, char *tabFileName[], int nombre_mot_cle, int similarite)
{

    int erreur;
    int element_tableauRes = 0;
    // affichage des resultat de recherche par mot cle :
    printf("\nLes resultats pour votre recherche :\n");
    if (strstr(type, "rechercheMot"))
    {
        printf("\nRequete mot-clé : \"%s\"\n", requete);
        printf("\nRésultats (fichier -> occurrences) :\n");
        if (nbElement == 0)
        {
            printf("\nCe mot ne figure pas dans notre base de données\n");
        }
        else
        {
            // Appel de la fonction lire_chemin pour afficher les résultats de recherche par mot clé
            element_tableauRes = lire_chemin(tabResultat, tabFileName, nbElement, "rechercheMot", nombre_mot_cle, similarite, &erreur);
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
        { // Appel de la fonction lire_chemin pour afficher les résultats de comparaison de texte
            element_tableauRes = lire_chemin(tabResultat, tabFileName, nbElement, type, nombre_mot_cle, similarite, &erreur);
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
            // Appel de la fonction lire_chemin pour afficher les résultats de comparaison d'image
            element_tableauRes = lire_chemin(tabResultat, tabFileName, nbElement, type, nombre_mot_cle, similarite, &erreur);
        }
    }
    // affichage des resultat de comparaison Audio :
    if (strstr(type, "audio"))
    {

        printf("\nRequete son : \"%s\"\n", requete);
        printf("\nRésultats :\n");
        if (nbElement == 0)
        {
            printf("\nAucun mot en communs n'a été trouvé dans notre base de données\n");
        }
        else
        {
            // Appel de la fonction lire_chemin pour afficher les résultats de comparaison d'audio
            element_tableauRes = lire_chemin(tabResultat, tabFileName, nbElement, type, nombre_mot_cle, similarite, &erreur);
        }
    }
    return element_tableauRes;
}

int lire_chemin(tab_similaire *tabResultat, char *tabFileName[], int nbElement, char *type, int nombre_mot_cle, int similarite, int *erreur)
{
    FILE *fichier = NULL;
    FILE *fichier1 = NULL;
    // allocation de mémoire pour stocker les résultats dans un tableau
    ELEMENT *base = (ELEMENT *)malloc((nbElement + 1) * sizeof(ELEMENT));
    ELEMENT *base2 = (ELEMENT *)malloc((nbElement + 1) * sizeof(ELEMENT));
    int ligne = 0;
    int l = 0;
    if (strcmp(type, "rechercheMot") == 0)
    {
        int y = 0;
        // ouverture du fichier liste base texte pour avoir le chemin du fichier qui correspond a l'id
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
                    if (tabResultat[i].pourcentage >= tabResultat[0].pourcentage * similarite / 100)
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
                            tabFileName[l] = filename;
                            printf("\n[%d] %s\t ->%d\n", l + 1, filename, (int)tabResultat[i].pourcentage);
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
                    if (tabResultat[i].pourcentage > (int)(similarite * nombre_mot_cle) / 100)
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
                            tabFileName[l] = filename;
                            printf("\n[%d] %s\t ->%d\n", l + 1, filename, (int)(tabResultat[i].pourcentage * nombre_mot_cle) / 100);
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
                    if (tabResultat[i].pourcentage > similarite)
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
                            recup_CheminPour_Affichage("audio", filename);
                            tabFileName[l] = filename;
                            printf("\n[%d] %s\t ->%.2f%%\n", l + 1, filename, tabResultat[i].pourcentage);
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
                    if (tabResultat[i].pourcentage >= similarite)
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
                            recup_CheminPour_Affichage("nb", filename);
                            tabFileName[l] = filename;
                            printf("\n[%d] %s\t ->%.2f%%\n", l + 1, filename, tabResultat[i].pourcentage);
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
            while (fscanf(fichier, "%d | %s\n", &base2[ligne].id, base2[ligne].CHEMIN) != EOF)
            {
                ligne++;
            }

            for (int i = 0; i <= nbElement; i++)
            {
                for (int y = 0; y <= nbElement; y++)
                {
                    if (tabResultat[i].pourcentage >= similarite)
                    {
                        if (tabResultat[i].id == base2[y].id)
                        {
                            char *filename = strrchr(base2[y].CHEMIN, '/');
                            if (filename)
                            {
                                filename++;
                            }
                            else
                            {
                                filename = base2[y].CHEMIN;
                            }
                            recup_CheminPour_Affichage("rgb", filename);
                            tabFileName[i] = filename;
                            printf("\n[%d] %s\t ->%.2f%%\n", l + 1, filename, tabResultat[i].pourcentage);
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
    FILE *image;
    char choix[100];
    char choixRQ[100];
    char numero_fichier[100] = "10000";
    char lire[100];
    char cheminBase[100];
    char *rmDroit = "chmod o-w ";
    char *addDroit = "chmod o+w ";
    char commande[1000];

    if (strcmp(type, "texte") == 0)
    {
        strcpy(lire, "gedit ");
        strcpy(cheminBase, "../DATA_FIL_ROUGE_DEV/Textes/");
        // afin de visualiser le premier fichier resultat on enleve les droits
        strcpy(commande, rmDroit);
        strcat(commande, cheminBase);
        strcat(commande, tabFileName[0]);
        system(commande);

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
    }

    if (strcmp(type, "image") == 0)
    {
        strcpy(lire, "eog ");
        strcpy(cheminBase, "../DATA_FIL_ROUGE_DEV/IMG_et_AUDIO/TEST_RGB/");
        strcat(cheminBase, tabFileName[0]);
        recup_CheminPour_Affichage("rgb", cheminBase);
        image = fopen(cheminBase, "r");
        if (image != NULL)
        {
            fclose(image);
            strcpy(commande, lire);
            strcat(commande, cheminBase);
            system(commande);
        }
        else
        {
            strcpy(cheminBase, "../DATA_FIL_ROUGE_DEV/IMG_et_AUDIO/TEST_NB/");
            strcat(cheminBase, tabFileName[0]);
            recup_CheminPour_Affichage("nb", cheminBase);
            strcpy(commande, lire);
            strcat(commande, cheminBase);
            system(commande);
        }
    }
    if (strcmp(type, "audio") == 0)
    {
        strcpy(lire, "vlc ");
        strcpy(cheminBase, "../DATA_FIL_ROUGE_DEV/IMG_et_AUDIO/TEST_SON/");
        strcat(cheminBase, tabFileName[0]);
        fflush(stdout);
        recup_CheminPour_Affichage(type, cheminBase);
        fflush(stdout);
        strcpy(commande, lire);
        strcat(commande, cheminBase);
        system(commande);
    }

    if (nbElement != 0)
    {
        strcpy(choix, "CHOIX");
        while (choix[0] != '2' || choix[0] != '1')
        {
            if (nbElement == 1)
                printf("\nVoulez vous revisionner ce fichier ?\n[1] Oui\n[2] Non\n");
            if (nbElement > 1)
                printf("\nVoulez vous visionner un autre fichier ?\n[1] Oui\n[2] Non\n");

            scanf("%s", choix);
            if (choix[0] == '2')
            {
                while (choixRQ[0] != 'R' && choixRQ[0] != 'Q')
                {
                    printf("\nVoulez vous revenir au \"Menu Recherche\" ou quitter le programme?\n[R] Retour\n[Q] Quitter\n");
                    scanf("%s", choixRQ);
                    if (choixRQ[0] != 'R' && choixRQ[0] != 'Q')
                    {
                        printf("\nCe choix ne figure pas dans la liste !\n");
                    }
                }
                return choixRQ[0];
            }
            if (choix[0] == '1')
            {
                strcpy(numero_fichier, "1000000");
                while (atoi(numero_fichier) > nbElement)
                {
                    printf("\nEntrez le numero de fichier que vous voulez visualiser, ou R pour un retour vers \"Menu Recherche\"\n");
                    scanf("%s", numero_fichier);
                    if (numero_fichier[0] == 'R')
                        return numero_fichier[0];
                    if (atoi(numero_fichier) > nbElement)
                        printf("\nCe choix de fichier ne figure pas dans la liste\n");
                }

                if (strcmp(type, "audio") == 0)
                {
                    strcpy(lire, "vlc ");
                    fflush(stdout);
                    strcpy(cheminBase, "../DATA_FIL_ROUGE_DEV/IMG_et_AUDIO/TEST_SON/");
                    printf(" [(atoi(numero_fichier))-1]: %s\n", tabFileName[(atoi(numero_fichier)) - 1]);
                    strcat(cheminBase, tabFileName[(atoi(numero_fichier)) - 1]);
                    fflush(stdout);
                    recup_CheminPour_Affichage(type, cheminBase);
                    fflush(stdout);
                    strcpy(commande, lire);
                    strcat(commande, cheminBase);
                    system(commande);
                }
                if (strcmp(type, "image") == 0)
                {
                    strcpy(lire, "eog ");
                    strcpy(cheminBase, "../DATA_FIL_ROUGE_DEV/IMG_et_AUDIO/TEST_RGB/");
                    strcat(cheminBase, tabFileName[(atoi(numero_fichier)) - 1]);
                    recup_CheminPour_Affichage("rgb", cheminBase);
                    image = fopen(cheminBase, "r");
                    if (image != NULL)
                    {
                        fclose(image);
                        strcpy(commande, lire);
                        strcat(commande, cheminBase);
                        system(commande);
                    }
                    else
                    {
                        strcpy(cheminBase, "../DATA_FIL_ROUGE_DEV/IMG_et_AUDIO/TEST_NB/");
                        strcat(cheminBase, tabFileName[(atoi(numero_fichier)) - 1]);
                        recup_CheminPour_Affichage("nb", cheminBase);
                        strcpy(commande, lire);
                        strcat(commande, cheminBase);
                        system(commande);
                    }
                }
                if (strcmp(type, "texte") == 0)
                {
                    strcpy(lire, "gedit ");
                    strcpy(cheminBase, "../DATA_FIL_ROUGE_DEV/Textes/");
                    // afin de visualiser le premier fichier resultat on enleve les droits
                    strcpy(commande, rmDroit);
                    strcat(commande, cheminBase);
                    strcat(commande, tabFileName[(atoi(numero_fichier)) - 1]);
                    system(commande);

                    // on l'ouvre pour que l'utilisateur le visualise
                    strcpy(commande, lire);
                    strcat(commande, cheminBase);
                    strcat(commande, tabFileName[(atoi(numero_fichier)) - 1]);
                    system(commande);

                    // on remet les permissions d'ecriture sur le fichier
                    strcpy(commande, addDroit);
                    strcat(commande, cheminBase);
                    strcat(commande, tabFileName[(atoi(numero_fichier)) - 1]);
                    system(commande);
                }

                else
                {
                    printf("\nCe choix n'existe pas, Réessayez\n");
                }
            }
        }
        return 'R';
    }
}

void recup_CheminPour_Affichage(char *type, char *chemin)
{
    char *extension = strrchr(chemin, '.');
    if (extension != NULL && strcmp(type, "rgb") == 0)
    {
        strcpy(extension, ".jpg");
    }
    if (extension != NULL && strcmp(type, "texte") == 0)
    {
        strcpy(extension, ".txt");
    }
    if (extension != NULL && strcmp(type, "nb") == 0)
    {
        strcpy(extension, ".bmp");
    }
    if (extension != NULL && strcmp(type, "audio") == 0)
    {
        strcpy(extension, ".wav");
    }
}
