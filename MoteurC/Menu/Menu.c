//
// AUTEUR :
//          YOUSSERA ACHACHERA
// DERNIERE VERSION :
//    22/01/2023
//
#include "Menu.h"

typedef struct
{
    char entiere[100];
    char fonction[100];
} chaine_typ;

chaine_typ lire_fichier()
{
    char *ptr;
    chaine_typ chaine;
    do
    {
        FILE *fichier = NULL;
        fichier = fopen("../MoteurC/fichierJavaC.txt", "r");
        if (fichier != NULL)
        {
            fscanf(fichier, "%s", chaine.entiere);
            if (chaine.entiere != NULL)
            {
                ptr = strchr(chaine.entiere, '(');
                strcpy(chaine.fonction, chaine.entiere[0, strlen(ptr)]);
            }
        }
    } while (chaine.entiere[0] != 0);
    return (chaine);
}

void MAE(CONFIG *config, char choix[100], int *erreurImage, int *erreurAudio, int *erreurTexte, int *erreurIndex)
{
    FILE *cheminfichier;
    char ERREUR[100];
    chaine_typ etat_courant = lire_fichier();
    // variables a utiliser au cours du programme
    char chemin[100];
    char requete[100];
    int erreur = 0;
    int nbTentative = 1;
    char motCle[27];
    int nombreElemetTab = 0;
    int nombreElementTabFIN = 0;
    bool result = false;
    LOGIN testlogin;
    lesLogins tablogin;
    int test, test2;
    char cheminDescripteurTxt[200] = "../base_descripteur/base_descripteur_texte";
    char cheminDescripteurIMG[100] = "../base_descripteur/base_descripteur_image";
    char cheminDescripteurAudio[100] = "../base_descripteur/base_descripteur_audio";

    if (strcmp(etat_courant.fonction, "indexation_generale_ferme"))
    {
        indexation_generale_ferme(*config, erreurImage, erreurAudio, erreurTexte, erreurIndex);
    }

    else if (strcmp(etat_courant.fonction, "Lire_mot_cle") == 0)
    {

        *config = Lire_CONFIG(&Erreur);
        fprintf("Entrez le nombre de mot-clé voulu :\n");
        *config = Lire_mot_cle(*config, &Erreur);
        // if (Erreur != 0)
        // {
        //     Afficher_Erreur(Erreur, "../Gestion-Erreur/Erreur.txt", ERREUR);
        //     fprintf("%s", ERREUR);
        //     Erreur = 0;
        // } A ECRIRE EN FICHIER TXT

        Ecrire_CONFIG(*config, &Erreur);
        // if (Erreur != 0)
        // {
        //     Afficher_Erreur(Erreur, "../Gestion-Erreur/Erreur.txt", ERREUR);
        //     fprintf("%s", ERREUR);
        //     Erreur = 0;
        // }
        // fprintf("\nSi vous avez changé votre configuration veuillez lancer l'indexation pour appliquer vos modifications\n");
    }
    else if (strcmp(etat_courant.fonction, "Lire_similariter") == 0)
    {
        // pour changer similarité
        *config = Lire_similariter(*config, &Erreur);
        // if (Erreur != 0)
        // {
        //     Afficher_Erreur(Erreur, "../Gestion-Erreur/Erreur.txt", ERREUR);
        //     fprintf("%s", ERREUR);
        //     Erreur = 0;
        // }

        Ecrire_CONFIG(*config, &Erreur);
        // if (Erreur != 0)
        // {
        //     Afficher_Erreur(Erreur, "../Gestion-Erreur/Erreur.txt", ERREUR);
        //     fprintf("%s", ERREUR);
        //     Erreur = 0;
        // }
    }
    else if (strcmp(etat_courant.fonction, "Lire_nb_bit_fort") == 0)
    {
        // pour changer niveau
        *config = Lire_nb_bit_fort(*config, &Erreur);
        // if (Erreur != 0)
        // {
        //     Afficher_Erreur(Erreur, "../Gestion-Erreur/Erreur.txt", ERREUR);
        //     fprintf("%s", ERREUR);
        //     Erreur = 0;
        // }

        Ecrire_CONFIG(*config, &Erreur);
        // if (Erreur != 0)
        // {
        //     Afficher_Erreur(Erreur, "../Gestion-Erreur/Erreur.txt", ERREUR);
        //     fprintf("%s", ERREUR);
        //     Erreur = 0;
        // }
    }
    else if (strcmp(etat_courant.fonction, "Lire_nb_fenetre") == 0)
    {
        // pour changer nb_fenetre
        *config = Lire_nb_fenetre(*config, &Erreur);
        // if (Erreur != 0)
        // {
        //     Afficher_Erreur(Erreur, "../Gestion-Erreur/Erreur.txt", ERREUR);
        //     fprintf("%s", ERREUR);
        //     Erreur = 0;
        // }

        Ecrire_CONFIG(*config, &Erreur);
        // if (Erreur != 0)
        // {
        //     Afficher_Erreur(Erreur, "../Gestion-Erreur/Erreur.txt", ERREUR);
        //     fprintf("%s", ERREUR);
        //     Erreur = 0;
        // }
    }
    else if (strcmp(etat_courant.fonction, "Lire_intervale") == 0)
    {
        // pour changer intervale
        *config = Lire_intervale(*config, &Erreur);
        // if (Erreur != 0)
        // {
        //     Afficher_Erreur(Erreur, "../Gestion-Erreur/Erreur.txt", ERREUR);
        //     fprintf("%s", ERREUR);
        //     Erreur = 0;
        // }

        Ecrire_CONFIG(*config, &Erreur);
        // if (Erreur != 0)
        // {
        //     Afficher_Erreur(Erreur, "../Gestion-Erreur/Erreur.txt", ERREUR);
        //     fprintf("%s", ERREUR);
        //     Erreur = 0;
        // }
    }
    else if (strcmp(etat_courant.fonction, "system(texte)") == 0)
    {
        system("chmod a-w ../base_descripteur/base_descripteur_texte");
        fprintf("\nPenser a fermé la fenetre apres l'avoir consulter pour poursuivre votre activité\n");
        system("gedit ../base_descripteur/base_descripteur_texte");
        system("chmod 777 ../base_descripteur/base_descripteur_texte");
    }
    else if (strcmp(etat_courant.fonction, "system(image)") == 0)
    {
        system("chmod a-w ../base_descripteur/base_descripteur_image");
        fprintf("\nPenser a fermé la fenetre apres l'avoir consulter pour poursuivre votre activité\n");
        system("gedit ../base_descripteur/base_descripteur_image");
        system("chmod 777 ../base_descripteur/base_descripteur_image");
    }
    else if (strcmp(etat_courant.fonction, "system(audio)") == 0)
    {
        system("chmod a-w ../base_descripteur/base_descripteur_audio");
        fprintf("\nPenser a fermé la fenetre apres l'avoir consulter pour poursuivre votre activité\n");
        system("gedit ../base_descripteur/base_descripteur_audio");
        system("chmod 777 ../base_descripteur/base_descripteur_audio");
    }
    else if (strcmp(etat_courant.fonction, "rechercheMot") == 0)
    {
        char *tabFileNameMOT[700];
        erreur = 0;
        tab_similaire *tabResultatMot = malloc(100 * sizeof(tab_similaire));
        rechercheMot(motCle, cheminDescripteurTxt, tabResultatMot, config->Nb_Mots_Cle, &nombreElemetTab, &erreur);
        
    //     if (erreur != 7)
    //     {

    //         nombreElementTabFIN = LireResultat(tabResultatMot, nombreElemetTab, "rechercheMot", motCle, tabFileNameMOT, config->Nb_Mots_Cle, config->Similariter);
    //         // RENVOIE NOMBRE_ELEMENT_TAB_FIN a JAVA
    //         free(tabResultatMot);
    //     }
    // }

    // else if (strcmp(etat_courant.fonction, "visualiser_fichier") == 0)
    // {
    //     choix[0] = visualiser_fichier(tabFileNameMOT, nombreElementTabFIN, "texte");
    //     // RENVOIE CHOIX DANS LE FICHIER
    // }
    // if (strcmp(choix, "Q") == 0)
    // {
    //     fprintf("\n\t\033[0;31mVous avez quitté le programme\033[0m\n\n\n\n");
    //     exit(EXIT_SUCCESS);
    // } RENVOYER VALEUR CHOIX A JAVA
    }
    else if(2==2)
    {
        // ON RENVOIE ERREUR DANS FICHIER
    }

    else if (strcmp(etat_courant.fonction, "comparaison_texte") == 0)
    {

        // verification si le fichier existe
        test = -1;
        while (test == -1)
        {
            fprintf("\nEntrez le chemin de votre fichier\n");
            fscanf("%s", chemin);
            test = FichierExist(chemin);
            if (test == -1)
            {
                fprintf("\nLe fichier n'existe pas\n");
                fprintf("\nVeuillez faire un choix pour continuer\n[1] Entrer un autre fichier\n[2] Retour \"Menu Général\"\n");
                fscanf("%s", choix);

                // Switch choix menu supprimé
            }
        }
        // verification si le fichier passer est un fichier texte
        test = VerifExtension(chemin, "xml");
        if (test == -1)
        {
            fprintf("\nCe fichier n'est pas de type texte\nVeuiller mettre un fichier texte\n");
            etat_courant = Menu_texte;
        }
        else
        {
            erreur = 0, nombreElemetTab = 0;
            tab_similaire *tabResultatTexte = malloc(100 * sizeof(tab_similaire));
            char *tabFileNameTEXTE[700];
            tabResultatTexte = comparaison_texte(config->Nb_Mots_Cle, chemin, cheminDescripteurTxt, &erreur, &nombreElemetTab);
            // if (erreur == 7 || erreur == 1)
            // {
            //     Afficher_Erreur(erreur, "../Gestion-Erreur/Erreur.txt", ERREUR);
            //     fprintf("%s", ERREUR);
            // } ECRIRE VALEUR ERREUR DANS FICHIER POUR RENOYER A JAVA
            nombreElementTabFIN = LireResultat(tabResultatTexte, nombreElemetTab, "texte", chemin, tabFileNameTEXTE, config->Nb_Mots_Cle, config->Similariter);
            free(tabResultatTexte);
            if (nombreElementTabFIN > 0)
            {
                fprintf("[R] Retour\n\nPensez à fermer l'editeur de texte apres l'avoir consulté pour poursuivre votre activité\n");
                choix[0] = visualiser_fichier(tabFileNameTEXTE, nombreElementTabFIN, "texte");
            }
            // if (strcmp(choix, "Q") == 0)
            // {
            //     fprintf("\n\t\033[0;31mVous avez quitté le programme\033[0m\n\n\n\n");
            //     exit(EXIT_SUCCESS);
            // } RENVOYER CHOIX A JAVA
        }
    }

    else if (strcmp(etat_courant.fonction, "Comparaison_descripteur_image") == 0)
    {

        fprintf("\n__________________________Recherche fichier image__________________________\n");
        fprintf("\nVeuillez faire votre choix  : \n");
        fprintf("\n[1] Recherche par comparaison d'images\n[R] Retour\n[Q] Quitter\n");
        fscanf("%s", choix);
        // switch (choix[0])
        // {
        //     case Recherche_comparaison_Image:
        //         // verification si le fichier existe
        //         test = -1;
        //         while (test == -1)
        //         {
        //             fprintf("\nEntrez le chemin de votre fichier\n");
        //             fscanf("%s", chemin);
        //             test = FichierExist(chemin);
        //             if (test == -1)
        //             {
        //                 fprintf("\nLe fichier n'existe pas\n");
        //                 fprintf("\nVeuillez faire un choix pour continuer\n[1] Entrez un autre fichier\n[2] Retour \"Menu Général\"\n");
        //                 fscanf("%s", choix);
        //                 switch (choix[0])
        //                 {
        //                 case Utilisateur:
        //                     test = 0;
        //                     etat_courant = Menu_Utilisateur;
        //                     break;
        //                 case AutreFichier:
        //                     test = -1;
        //                     break;
        //                 default:
        //                     etat_courant = Menu_Utilisateur;
        //                     break;
        //                 }
        //             }
        //         }
        //         // verification si le fichier passer est un fichier texte
        //         test = VerifExtension(chemin, "jpg");
        //         test2 = VerifExtension(chemin, "bmp");
        //         if (test == -1 && test2 == -1)
        //         {
        //             fprintf("\nCe fichier n'est pas de type image\nVeuillez mettre un fichier .jpg ou .bmp\n");
        //             etat_courant = Menu_image;
        //         }
        //         else
        //         {
        //             strcpy(requete, chemin);
        //             erreur = 0, nombreElemetTab = 0;
        //             tab_similaire *tabResultatIMG;
        //             char *tabFileNameIMG[700];
        //             recup_CheminPour_Affichage("texte", &chemin);
        //             tabResultatIMG = Comparaison_descripteur_image(&erreur, cheminDescripteurIMG, chemin, config->Nb_Bit_Fort, &nombreElemetTab);
        //             // if (erreur != 0)
        //             // {
        //             //     Afficher_Erreur(erreur, "../Gestion-Erreur/Erreur.txt", ERREUR);
        //             //     fprintf("%s", ERREUR);
        //             // } ERREUR A RENVOYER EN JAVA
        //             else
        //             {
        //                 nombreElementTabFIN = LireResultat(tabResultatIMG, nombreElemetTab, "image", requete, tabFileNameIMG, config->Nb_Mots_Cle, config->Similariter);
        //                 if (nombreElementTabFIN > 0)
        //                 {
        //                     fprintf("[R] Retour\n\nPensez à fermer la fenetre apres l'avoir consulté pour poursuivre votre activité\n");
        //                     choix[0] = visualiser_fichier(tabFileNameIMG, nombreElementTabFIN, "image");
        //                 }
        //                 // if (strcmp(choix, "Q") == 0)
        //                 // {
        //                 //     fprintf("\n\t\033[0;31mVous avez quitté le programme\033[0m\n\n\n\n");
        //                 //     exit(EXIT_SUCCESS);
        //                 // } CHOIX A RENVOYER
        //             }
        //             free(tabResultatIMG);
        //         }
        // break
        //     case Retour:
        //         etat_courant = Menu_Utilisateur;
        //         break;
        //     case Quitter:
        //         fprintf("\n\t\033[0;31mVous avez quitté le programme\033[0m\n\n\n\n");
        //         exit(EXIT_SUCCESS);
        //         break;
        //     default:
        //         erreur = 11;
        //         Afficher_Erreur(erreur, "../Gestion-Erreur/Erreur.txt", ERREUR);
        //         fprintf("%s", ERREUR);
        //         etat_courant = Menu_image;
        //         break;
        //     }
        //     break;
    }
    else if (strcmp(etat_courant.fonction, "comparaison_audio") == 0)
    {
        
                erreur = 0;
                nombreElemetTab = 0;
                tab_similaire *tabResultatAudio = malloc(100 * sizeof(tab_similaire));
                char *tabFileNameAUDIO[700];
        //         // if (erreur != 0)
        //         // {
        //         //     Afficher_Erreur(erreur, "../Gestion-Erreur/Erreur.txt", ERREUR);
        //         //     fprintf("%s", ERREUR);
        //         // } ERREUR A RENVOYER
        //         else
        //         {
                    recup_CheminPour_Affichage("texte", &chemin);
                    tabResultatAudio = comparaison_audio(config->Nb_Fenetre, config->Intervale, chemin, cheminDescripteurAudio, &erreur, &nombreElemetTab);
                    nombreElementTabFIN = LireResultat(tabResultatAudio, nombreElemetTab, "audio", chemin, tabFileNameAUDIO, config->Nb_Mots_Cle, config->Similariter);

        //             if (nombreElementTabFIN > 0)
        //             {
        //                 fprintf("[R] Retour\n\nPensez à fermer la fenetre apres l'avoir consulté pour poursuivre votre activité\n");
        //                 choix[0] = visualiser_fichier(tabFileNameAUDIO, nombreElementTabFIN, "audio");
        //             }
        //             // if (strcmp(choix, "Q") == 0)
        //             // {
        //             //     fprintf("\n\t\033[0;31mVous avez quitté le programme\033[0m\n\n\n\n");
        //             //     exit(EXIT_SUCCESS);
        //             // } CHOIX A RENVOYER
        //             free(tabResultatAudio);
        //         }
        //     }
        //     break;
        // case Retour:
        //     etat_courant = Menu_Utilisateur;
        //     break;
        // case Quitter:
        //     fprintf("\n\t\033[0;31mVous avez quitté le programme\033[0m\n\n\n\n");
        //     exit(EXIT_SUCCESS);
        //     break;
        // default:
        //     erreur = 11;
        //     Afficher_Erreur(erreur, "../Gestion-Erreur/Erreur.txt", ERREUR);
        //     fprintf("%s", ERREUR);
        //     etat_courant = Menu_audio;
        //     break;
        // }
        // break;
    }
}
