//
// AUTEUR :
//          YOUSSERA ACHACHERA
// DERNIERE VERSION :
//    22/01/2023
//
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "Menu.h"

chaine_typ lire_fichier()
{
    char *ptr;
    chaine_typ chaine;
    char Chaine[] = {'\0'};
    FILE *fichier = NULL;
    fichier = fopen("Write.txt", "r");
    if (fichier != NULL)
    {
        while (fscanf(fichier, "%s\n", chaine.entiere) != EOF)
        {

            if (chaine.entiere != NULL)
            {
                ptr = strchr(chaine.entiere, '(');
                char temp[100];
                strcpy(temp, chaine.entiere);
                strcpy(&temp[strlen(chaine.entiere) - strlen(ptr)], "\0");
                strcpy(chaine.fonction, temp);
            }
        }
    }
    fclose(fichier);
    return (chaine);
}

void choixfonction()
{
    chaine_typ etat_courant = lire_fichier();
    printf("\n%s\n", etat_courant.fonction);
    // printf("%d", strcmp(etat_courant.fonction, "systemAudio"));
    //  variables a utiliser au cours du programme
    char chemin[100];
    tab_similaire tabResultat[3];
    char requete[100];
    int erreur = 0;
    int nombreElemetTab = 0;
    CONFIG config;
    char cheminDescripteurTxt[200] = "../base_descripteur/base_descripteur_texte";
    char cheminDescripteurIMG[100] = "../base_descripteur/base_descripteur_image";
    char cheminDescripteurAudio[100] = "../base_descripteur/base_descripteur_audio";
    config = Lire_CONFIG(&erreur);
    int erreurImage = 0, erreurAudio = 0, erreurTexte = 0, erreurIndex = 0;

    if (strcmp(etat_courant.fonction, "indexationGeneraleFerme") == 0)
    {
        //Afficher_CONFIG(config);
        indexation_generale_ferme(config, &erreurImage, &erreurAudio, &erreurTexte, &erreurIndex);
    }
    else if (strcmp(etat_courant.fonction, "systemTexte") == 0)
    {
        
        tabResultat[0].id = -1;
        tabResultat[0].pourcentage = 20;
        tabResultat[1].id = -12;
        tabResultat[1].pourcentage = 12;
        ecrireCJava(tabResultat, 2);
        system("chmod a-w ../base_descripteur/base_descripteur_texte");
        system("gedit ../base_descripteur/base_descripteur_texte");
        system("chmod 777 ../base_descripteur/base_descripteur_texte");
    }
    else if (strcmp(etat_courant.fonction, "systemImage") == 0)
    {

        system("chmod a-w ../base_descripteur/base_descripteur_image");
        system("gedit ../base_descripteur/base_descripteur_image");
        system("chmod 777 ../base_descripteur/base_descripteur_image");
    }
    else if (strcmp(etat_courant.fonction, "systemAudio") == 0)
    {
        printf("la");
        system("chmod a-w ../base_descripteur/base_descripteur_audio");
        system("gedit ../base_descripteur/base_descripteur_audio");
        system("chmod 777 ../base_descripteur/base_descripteur_audio");
    }
    //"rechercheMot("voiture")"
    else if (strcmp(etat_courant.fonction, "rechercheMot") == 0)
    {
        char motCle[27];
        sscanf(etat_courant.entiere, "%s(\"%s\")", etat_courant.fonction, motCle);
        char *tabFileNameMOT[700];
        erreur = 0;
        tab_similaire *tabResultatMot = malloc(100 * sizeof(tab_similaire));
        rechercheMot(motCle, cheminDescripteurTxt, tabResultatMot, config.Nb_Mots_Cle, &nombreElemetTab, &erreur);
        ecrireCJava(tabResultatMot, nombreElemetTab);
        // ecrire tabResultatMot
        free(tabResultatMot);
    }
    //"comparaisonTexte()"
    else if (strcmp(etat_courant.fonction, "comparaisonTexte") == 0)
    {
        sscanf(etat_courant.entiere, "%s(\"%s\")", etat_courant.fonction, chemin);
        erreur = 0, nombreElemetTab = 0;
        tab_similaire *tabResultatTexte = malloc(100 * sizeof(tab_similaire));
        char *tabFileNameTEXTE[700];
        tabResultatTexte = comparaison_texte(config.Nb_Mots_Cle, chemin, cheminDescripteurTxt, &erreur, &nombreElemetTab);
        // ecrireCJava(tabResultatTexte, nombreElemetTab);
        //  ecrire tabResultatTexte erreur
        free(tabResultatTexte);
    }
    else if (strcmp(etat_courant.fonction, "ComparaisonDescripteurImage") == 0)
    {
        sscanf(etat_courant.entiere, "%s(\"%s\")", etat_courant.fonction, chemin);
        erreur = 0, nombreElemetTab = 0;
        tab_similaire *tabResultatIMG;
        char *tabFileNameIMG[700];
        tabResultatIMG = Comparaison_descripteur_image(&erreur, cheminDescripteurIMG, chemin, config.Nb_Bit_Fort, &nombreElemetTab);
        // ecrireCJava(tabResultatIMG, nombreElemetTab);

        // ecrire tabResultatIMG
        free(tabResultatIMG);
    }

    else if (strcmp(etat_courant.fonction, "comparaisonAudio") == 0)
    {
        sscanf(etat_courant.entiere, "%s(\"%s\")", etat_courant.fonction, chemin);
        erreur = 0;
        nombreElemetTab = 0;
        tab_similaire *tabResultatAudio = malloc(100 * sizeof(tab_similaire));
        char *tabFileNameAUDIO[700];
        tabResultatAudio = comparaison_audio(config.Nb_Fenetre, config.Intervale, chemin, cheminDescripteurAudio, &erreur, &nombreElemetTab);
        // ecrireCJava(tabResultatAudio, nombreElemetTab);
        //  ecrire tabResultatIMG
        free(tabResultatAudio);
    }

    // else if (strcmp(etat_courant.fonction, "Lire_mot_cle") == 0)
    // {

    //     *config = Lire_CONFIG(&Erreur);
    //     *config = Lire_mot_cle(*config, &Erreur);

    //     Ecrire_CONFIG(*config, &Erreur);
    // }
    // else if (strcmp(etat_courant.fonction, "Lire_similariter") == 0)
    // {
    //     // pour changer similarité
    //     *config = Lire_similariter(*config, &Erreur);
    //     Ecrire_CONFIG(*config, &Erreur);
    // }
    // else if (strcmp(etat_courant.fonction, "Lire_nb_bit_fort") == 0)
    // {
    //     // pour changer niveau
    //     *config = Lire_nb_bit_fort(*config, &Erreur);
    //     Ecrire_CONFIG(*config, &Erreur);
    // }
    // else if (strcmp(etat_courant.fonction, "Lire_nb_fenetre") == 0)
    // {
    //     // pour changer nb_fenetre
    //     *config = Lire_nb_fenetre(*config, &Erreur);
    //     Ecrire_CONFIG(*config, &Erreur);
    // }
    // else if (strcmp(etat_courant.fonction, "Lire_intervale") == 0)
    // {
    //     // pour changer intervale
    //     *config = Lire_intervale(*config, &Erreur);
    //     Ecrire_CONFIG(*config, &Erreur);
    // }
}
