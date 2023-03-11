//
// AUTEUR :
//          YOUSSERA ACHACHERA
// DERNIERE VERSION :
//    23/01/2023
//

import java.io.*;
import java.util.*;

public class LireResultat {
    NavigableSet tabResultat = new TreeSet<Integer, Integer>();
    int nbElement;
    String type;
    String requete;
    ArrayList tabFileName;
    int nombre_mot_cle;
    int similarite;

    public LireResultat(TreeSet tableauResultat, int nombreElement, String typeRequete, ArrayList fileName,
            int nbMotCle, int similaritee) {
        this.tabResultat = tableauResultat;
        this.nbElement = nombreElement;
        this.type = typeRequete;
        this.tabFileName = fileName;
        this.nombre_mot_cle = nbMotCle;
        this.similarite = similaritee;
    }

    public int lireResultatFinale() {
        int erreur;
        int element_tableauRes = 0;
        // affichage des resultat de recherche par mot cle :
        System.out.println("\nLes resultats pour votre recherche :");
        if (this.type.contains("rechercheMot")) {
            System.out.printf("\nRequete mot-clé :" + this.requete + "\n");
            System.out.println("\nRésultats (fichier -> occurrences) :");
            if (this.nbElement == 0) {
                System.out.println("\nCe mot ne figure pas dans notre base de données\n");
            } else {
                // Appel de la fonction lire_chemin pour afficher les résultats de recherche par
                // mot clé
                element_tableauRes = lireChemin(this.tabResultat, this.tabFileName, this.nbElement, this.type,
                        this.nombre_mot_cle, this.similarite, this.erreur);
            }
        }

        // affichage des resultat de comparaison texte :
        if (type.contains("texte")) {
            System.out.printf("\nRequete mot-clé :" + this.requete + "\n");
            System.out.println("\nRésultats (fichier -> nombre de mots-clés communs) :");
            if (nbElement == 0) {
                System.out.println("\nAucun mot en communs n'a été trouvé dans notre base de données\n");
            } else {
                // Appel de la fonction lire_chemin pour afficher les résultats de comparaison
                // de texte
                element_tableauRes = lireChemin(this.tabResultat, this.tabFileName, this.nbElement, this.type,
                        this.nombre_mot_cle, this.similarite, this.erreur);
            }
        }

        // affichage des resultat de comparaison Image :
        if (type.contains("image")) {
            System.out.printf("\nRequete mot-clé :" + this.requete + "\n");
            System.out.println("\nRésultats :");
            if (nbElement == 0) {
                System.out.println("\nAucune image similaire n'a été trouvé dans notre base de données\n");
            } else {
                // Appel de la fonction lire_chemin pour afficher les résultats de comparaison
                // d'image
                element_tableauRes = lireChemin(this.tabResultat, this.tabFileName, this.nbElement, this.type,
                        this.nombre_mot_cle, this.similarite, this.erreur);
            }
        }
        // affichage des resultat de comparaison Audio :
        if (type.contains("audio")) {
            System.out.printf("\nRequete mot-clé :" + this.requete + "\n");
            System.out.println("\nRésultats :");
            if (nbElement == 0) {
                System.out.println("\nAucun mot en communs n'a été trouvé dans notre base de données\n");
            } else {
                // Appel de la fonction lire_chemin pour afficher les résultats de comparaison
                // d'audio
                element_tableauRes = lireChemin(tabResultat, tabFileName, nbElement, type, nombre_mot_cle, similarite,
                        erreur);
            }
        }
        return element_tableauRes;
    }

    

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
