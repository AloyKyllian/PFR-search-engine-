#include "Menu.h"

void MAE(CONFIG *config, char choix[100], int *erreurImage, int *erreurAudio, int *erreurTexte, int *erreurIndex)
{
    static char etat_courant = Menu_general;

    // variables a utiliser au cours du programme
    char chemin[100];
    int erreur = 0;
    int nbTentative = 1;
    int Erreur = 0;
    char motCle[27];
    char *choixIMG;
    int nombreElemetTab = 0;
    bool result = false;
    LOGIN testlogin;
    lesLogins tablogin;
    char *extension;
    int test;
    char *lire = "gedit ";
    char *cheminBasetxt = "../DATA_FIL_ROUGE_DEV/Textes";
    char cheminDescripteurTxt[200] = "../base_descripteur/base_descripteur_texte";
    char *cheminBaseImgNB = "../DATA_FIL_ROUGE_DEV/IMG_et_AUDIO/TEST_NB";
    char *cheminBaseImgRGB = "../DATA_FIL_ROUGE_DEV/IMG_et_AUDIO/TEST_RGB";
    char cheminDescripteurIMG[100] = "../base_descripteur/base_descripteur_image";
    char *cheminBaseAudio = "../DATA_FIL_ROUGE_DEV/IMG_et_AUDIO/TEST_SON";
    char cheminDescripteurAudio[100] = "../base_descripteur/base_descripteur_audio";
    // lire config si ya une erreur
    // config=Lire_CONFIG(&erreurConfig);
    // voir si un nv fichier
    // indexation
    // 4 erreurs index gene, image,audio,texte
    // indexation_generale_ferme(config, &erreurImage, &erreurAudio, &erreurTexte, &erreurIndex);
    // verifier les erreurs de tt les phases
    switch (etat_courant)
    {
    case Menu_general:
        printf("\n__________________________Menu général__________________________\n");
        printf("\nVeuillez faire votre choix : \n");
        printf("\n[1] Administrateur \n[2] Utilisateur \n[Q] Quitter\n");
        scanf("%s", choix);
        switch (choix[0])
        {

        case Administrateur:
            // Connexion
            result = false;
            do
            {
                result = seconnecter(tablogin, testlogin, &erreur);
                printf("\nConnexion ");
                (result) ? printf("Réussie\n\n") : printf("Échoué\n\n");
                if (result)
                {
                    printf("\nDirection menu admin\n");
                    etat_courant = Menu_Admin;
                }
                if (nbTentative == 3 && result == false)
                {
                    printf("\nSouhaitez vous basculer en mode utilisateur ou essayer de se connecter une nouvelle fois ?\n");
                    printf("\n[1] Mode utilisateur\n[2] nouvelle tentative de connexion\n");
                    scanf("%s", choix);
                    if (strcmp(&choix[0], "1") == 0)
                        etat_courant = Menu_Utilisateur;
                    if (strcmp(&choix[0], "2") == 0)
                    {
                        int nbr_microsec = 0;
                        printf("\nVous devez attendre 30 seconde pour réessayer\n");
                        usleep(nbr_microsec);
                        sleep(30);
                        printf("\nFin 30 sec, Vous pouvez réessayer maintenant\n");
                        nbTentative = 0;
                    }
                }
                nbTentative++;
            } while (nbTentative < 4 && result == false);

            break;
        case Utilisateur:
            etat_courant = Menu_Utilisateur;
            break;
        case Quitter:
            printf("\n\t\033[0;31mVous avez quitté le programme\033[0m\n\n\n\n");
            exit(EXIT_SUCCESS);
            break;
        default:
            printf("erreur de choix\n");
            etat_courant = Menu_general;
            break;
        }

        break;

    case Menu_Admin:
        printf("\n__________________________Menu administrateur__________________________\n");
        printf("\nVeuillez faire votre choix  : \n");
        printf("\n[1] Indexation\n[2] Configuration\n[3] Visualisation des recueils des descripteurs\n[4] Retour en mode utilisateur\n");

        scanf("%s", choix);

        switch (choix[0])
        {
        case Indexation:

            indexation_generale_ferme(*config, erreurImage, erreurAudio, erreurTexte, erreurIndex);

            // si ya une erreur j'arrete tt
            break;
        case Configuration:
            etat_courant = Menu_Configuration;
            break;
        case Visualisation:
            // visualisation des descripteurs
            etat_courant = Menu_Visualisation;
            break;
        case Retour_Utilisateur:
            etat_courant = Menu_Utilisateur;
            break;
        default:
            printf("erreur de choix\n");
            etat_courant = Menu_Admin;
            break;
        }
        break;

    case Menu_Configuration:
        printf("\n__________________________Configuration__________________________\n");
        int Erreur = 0;
        *config = Lire_CONFIG(&Erreur);
        Afficher_CONFIG(*config);
        printf("\nSi vous voulez changer une valeur, veuillez faire votre choix  : \n");
        printf("[1] Nombre de mots clé\n[2] Similarité\n[3] Nombre de bits \n[4] Nombre de fenetre\n");
        printf("[5] Intervalle de temps\n[R] Retour\n[Q] Déconnexion\n");
        scanf("%s", choix);
        switch (choix[0])
        {
        case Nombre_de_mot_cle:
            printf("Entrez le nombre de mot clé voulue :\n");
            *config = Lire_mot_cle(*config, &Erreur);
            Ecrire_CONFIG(*config, &Erreur);
            //???????????????????????????????
            break;
        case Similarité:
            // pour changer similarité
            printf("Entrez la valeur de similarité voulue :\n");
            *config = Lire_similariter(*config, &Erreur);
            Ecrire_CONFIG(*config, &Erreur);
            break;
        case Nombre_de_bits:
            // pour changer niveau
            printf("Entrez le nombre de bits voulue :\n");
            *config = Lire_nb_bit_fort(*config, &Erreur);
            Ecrire_CONFIG(*config, &Erreur);
            break;
        case Nombre_de_fenetre:
            printf("Entrez le nombre de fenetre voulue :\n");
            *config = Lire_nb_fenetre(*config, &Erreur);
            Ecrire_CONFIG(*config, &Erreur);
            break;
        case Intervalle_de_temps:
            // fct pour changer l'intervalle de temps
            printf("Entrez l'intervalle de temps voulue' :\n");
            *config = Lire_intervale(*config, &Erreur);
            Ecrire_CONFIG(*config, &Erreur);
            break;
        case Retour:
            etat_courant = Menu_Admin;
            break;
        case Deconnexion:
            while (strcmp(&choix[0], "1") != 0)
            {
                printf("\nVous vous etes deconnecter, voulez vous retourner en mode utilisateur ?\n[1] Oui\n[2] Non\n");
                scanf("%s", choix);
                switch (choix[0])
                {
                case oui:
                    strcpy(choix, "1");
                    etat_courant = Menu_Utilisateur;
                    break;
                case non:
                    printf("\n\tVous avez quitté le programme\n\n\n\n");
                    exit(EXIT_SUCCESS);
                    break;
                default:
                    printf("\nMauvais choix, vous allez etre rediriger au menu configuration\n");
                    etat_courant = Menu_Configuration;
                    break;
                }
            }
            break;
        default:
            printf("Erreur de choix\n");
            etat_courant = Menu_Configuration;
            break;
        }
        break;

    case Menu_Visualisation:
        printf("\n__________________________Visualisation des recueils des descripteurs__________________________\n");
        printf("\nVeuillez faire votre choix  : \n");
        printf("\n[1] Texte\n[2] Image\n[3] Audio \n[R] Retour\n[Q] Déconnexion\n");
        scanf("%s", choix);
        switch (choix[0])
        {
        case texte:
            system("chmod a-w ../base_descripteur/base_descripteur_texte");
            system("gedit ../base_descripteur/base_descripteur_texte");
            system("chmod a+w ../base_descripteur/base_descripteur_texte");
            break;
        case image:
            system("chmod a-w ../base_descripteur/base_descripteur_image");
            system("gedit ../base_descripteur/base_descripteur_image");
            system("chmod a+w ../base_descripteur/base_descripteur_image");
            break;
        case audio:
            system("chmod a-w ../base_descripteur/base_descripteur_audio");
            system("gedit ../base_descripteur/base_descripteur_audio");
            system("chmod a+w ../base_descripteur/base_descripteur_audio");
            break;
        case Retour:
            etat_courant = Menu_Admin;
        case Deconnexion:
            while (strcmp(&choix[0], "1") != 0)
            {
                printf("\nVous vous etes deconnecter, voulez vous retourner en mode utilisateur ?\n[1] Oui\n[2] Non\n");
                scanf("%s", choix);
                switch (choix[0])
                {
                case oui:
                    strcpy(choix, "1");
                    etat_courant = Menu_Utilisateur;
                    break;
                case non:
                    printf("\n\tVous avez quitté le programme\n\n\n\n");
                    exit(EXIT_SUCCESS);
                    break;
                default:
                    printf("\nMauvais choix, vous allez etre rediriger vers le menu visualisation\n");
                    etat_courant = Menu_Visualisation;
                    break;
                }
            }
            break;
        default:
            printf("erreur de choix\n");
            etat_courant = Menu_Visualisation;
            break;
        }
        break;

    case Menu_Utilisateur:
        printf("\n__________________________Menu utilisateur__________________________\n");
        printf("\nVeuillez faire votre choix  : \n");
        printf("\n[1] Recherche fichier texte\n[2] Recherche fichier image\n[3] Recherche fichier audio \n[Q] Déconnexion\n");
        scanf("%s", choix);
        switch (choix[0])
        {
        case texte:
            etat_courant = Menu_texte;
            break;
        case image:
            etat_courant = Menu_image;
            break;
        case audio:
            etat_courant = Menu_audio;
            break;
        case Retour:
            etat_courant = Menu_general;
            break;
        case Quitter:
            printf("\n\tVous avez quitté le programme\n\n\n\n");
            exit(EXIT_SUCCESS);
            break;
        default:
            printf("erreur de choix menu utilisateur\n");
            etat_courant = Menu_Utilisateur;
            break;
        }
        break;

    case Menu_texte:

        printf("\n__________________________Recherche fichier texte__________________________\n");
        printf("\nVeuillez faire votre choix  : \n");
        printf("\n[1] Recherche par mot clé\n[2] Recherche par comparaison de textes\n[R] Retour\n[Q] Quitter\n");
        scanf("%s", choix);
        switch (choix[0])
        {
        case Recherche_mots_cle:
            char *tabFileName = (char *)malloc(700);
            char *commande = (char *)malloc(500);
            erreur = 0;
            printf("\nEntrer votre mot clé\n");
            scanf("%s", motCle);
            tab_similaire *tabResultatMot = malloc(100 * sizeof(tab_similaire));
            rechercheMot(motCle, cheminDescripteurTxt, tabResultatMot, config->Nb_Mots_Cle, &nombreElemetTab, &erreur);
            LireResultat(tabResultatMot, nombreElemetTab, "rechercheMot", motCle, tabFileName);
            printf("\n[R] Retour\n");
            strcpy(commande, lire);
            strcat(commande, cheminBasetxt);
            strcat(commande, tabFileName[0]);
            system(commande);
            free(commande);
            // printf("\nVoulez vous visionné un autre fichier ?\n[1] Oui\n[2] Non\n");
            // scanf("%s", choix);
            // switch (choix[0])
            // {
            // case oui:
            //     while (choix[0] != Retour)
            //     {
            //         char *commande = (char *)malloc(500);
            //         printf("\nEntrer le numero de fichier que vous voulez visualiser, ou R pour un retour vers le menu de recherche texte\n");
            //         strcpy(commande, lire);
            //         strcat(commande, cheminBasetxt);
            //         strcat(commande, tabFileName[choix[0] - 1]);
            //         system(commande);
            //         free(commande);
            //     }
            //     etat_courant = Menu_texte;
            //     break;
            // case non:
            //     printf("\nVoulez vous revenir au Menu de recherche principale ou quitter le programme?\n[R] Retour\n[Q] Quitter\n");
            //     scanf("%s", choix);
            //     switch (choix[0])
            //     {
            //     case Retour:
            //         etat_courant = Menu_Utilisateur;
            //         break;
            //     case Quitter:
            //         printf("\n\tVous avez quitté le programme\n\n\n\n");
            //         exit(EXIT_SUCCESS);
            //         break;
            //     default:
            //         printf("erreur de choix, vous allez etre redirigez vers le menu de la recherche texte\n");
            //         etat_courant = Menu_texte;
            //         break;
            //     }
            // break;
            // default:
            //     printf("erreur de choix, vous allez etre redirigez vers le menu recherche texte\n");
            // break;
            // }
            free(tabResultatMot);
            free(tabFileName);
            break;

        case Recherche_par_comparaison_Texte:
            // verification si le fichier existe
            test = -1;
            while (test == -1)
            {
                printf("\nEntrez le chemin de votre fichier\n");
                scanf("%s", chemin);
                test = FichierExist(chemin);
                if (test == -1)
                {
                    printf("\nLe fichier n'existe pas\n");
                    printf("\nVeuillez faire un choix pour continuer\n[1] Entrer un autre fichier\n [2] Retour menu principale\n");
                    scanf("%s", choix);
                    switch (choix[0])
                    {
                    case Utilisateur:
                        test = 0;
                        etat_courant = Menu_Utilisateur;
                        break;
                    case AutreFichier:
                        test = -1;
                        break;
                    default:
                        etat_courant = Menu_Utilisateur;
                        break;
                    }
                }
            }
            // verification si le fichier passer est un fichier texte
            test = VerifExtension(chemin, "xml");
            if (test == -1)
            {
                printf("\nCe fichier n'est pas de type texte\nVeuiller mettre un fichier texte\n");
                etat_courant = Menu_texte;
            }
            else
            {
                erreur = 0, nombreElemetTab = 0;
                tab_similaire *tabResultatTexte = malloc(100 * sizeof(tab_similaire));
                char *tabFileName = (char *)malloc(700);
                tabResultatTexte = comparaison_texte(config->Nb_Mots_Cle, chemin, cheminDescripteurTxt, &erreur, &nombreElemetTab);
                LireResultat(tabResultatTexte, nombreElemetTab, "texte", chemin, tabFileName);
                printf("\n[R] Retour\n");
                free(tabResultatTexte);
                free(tabFileName);
            }
            break;
        case Retour:
            etat_courant = Menu_Utilisateur;
            break;
        case Quitter:
            printf("\n\tVous avez quitté le programme\n\n\n\n");
            exit(EXIT_SUCCESS);
            break;
        default:
            printf("erreur de choix\n");
            etat_courant = Menu_texte;
            break;
        }
        break;

    case Menu_image:

        printf("\n__________________________Recherche fichier image__________________________\n");
        printf("\nVeuillez faire votre choix  : \n");
        printf("\n[1] Recherche par comparaison d'images\n[R] Retour\n[Q] Quitter\n");
        scanf("%s", choix);
        switch (choix[0])
        {
        case Recherche_comparaison_Image:
            // verification si le fichier existe
            test = -1;
            while (test == -1)
            {
                printf("\nEntrez le chemin de votre fichier\n");
                scanf("%s", chemin);
                test = FichierExist(chemin);
                if (test == -1)
                {
                    printf("\nLe fichier n'existe pas\n");
                    printf("\nVeuillez faire un choix pour continuer\n[1] Entrer un autre fichier\n[2] Retour menu principale\n");
                    scanf("%s", choix);
                    switch (choix[0])
                    {
                    case Utilisateur:
                        test = 0;
                        etat_courant = Menu_Utilisateur;
                        break;
                    case AutreFichier:
                        test = -1;
                        break;
                    default:
                        etat_courant = Menu_Utilisateur;
                        break;
                    }
                }
            }
            // verification si le fichier passer est un fichier texte
            test = VerifExtension(chemin, "txt");
            if (test == -1)
            {
                printf("\nCe fichier n'est pas de type image\nVeuiller mettre un fichier texte\n");
                etat_courant = Menu_image;
            }
            else
            {
                erreur = 0, nombreElemetTab = 0;
                tab_similaire *tabResultatIMG = malloc(100 * sizeof(tab_similaire));
                char *tabFileName = (char *)malloc(700);
                tabResultatIMG = Comparaison_descripteur_image(&erreur, cheminDescripteurIMG, chemin, config->Nb_Bit_Fort, &nombreElemetTab);
                printf("debut de l'affichage\n");
                LireResultat(tabResultatIMG, nombreElemetTab, "image", chemin, tabFileName);
                printf("\n[R] Retour\n");
                free(tabResultatIMG);
                free(tabFileName);
            }
            break;
        case Retour:
            etat_courant = Menu_Utilisateur;
            break;
        case Quitter:
            printf("\n\tVous avez quitté le programme\n\n\n\n");
            exit(EXIT_SUCCESS);
            break;
        default:
            printf("erreur de choix\n");
            etat_courant = Menu_image;
            break;
        }
        break;

    case Menu_audio:
        printf("\n__________________________Recherche fichier audio__________________________\n");
        printf("\nVeuillez faire votre choix  : \n");
        printf("\n[1] Recherche par comparaison d'audio\n[R] Retour\n[Q] Quitter\n");
        scanf("%s", choix);
        switch (choix[0])
        {
        case Recherche_comparaison_Audio:
            // verification si le fichier existe
            test = -1;
            while (test == -1)
            {
                printf("\nEntrez le chemin de votre fichier\n");
                scanf("%s", chemin);
                test = FichierExist(chemin);
                if (test == -1)
                {
                    printf("\nLe fichier n'existe pas\n");
                    printf("\nVeuillez faire un choix pour continuer\n[1] Entrer un autre fichier\n[2] Retour menu principale\n");
                    scanf("%s", choix);
                    switch (choix[0])
                    {
                    case Utilisateur:
                        test = 0;
                        etat_courant = Menu_Utilisateur;
                        break;
                    case AutreFichier:
                        test = -1;
                        break;
                    default:
                        etat_courant = Menu_Utilisateur;
                        break;
                    }
                }
            }
            // verification si le fichier passer est un fichier texte
            test = VerifExtension(chemin, "txt");
            if (test == -1)
            {
                printf("\nCe fichier n'est pas de type audio\nVeuiller faire le choix de recherche qui vous correspond\n");
                etat_courant = Menu_Utilisateur;
            }
            else
            {
                erreur = 0;
                nombreElemetTab = 0;
                tab_similaire *tabResultatAudio = malloc(100 * sizeof(tab_similaire));
                char *tabFileName = (char *)malloc(700);
                tabResultatAudio = comparaison_audio(config->Nb_Fenetre, config->Intervale, chemin, cheminDescripteurAudio, &erreur, &nombreElemetTab);
                printf("debut de l'affichage\n");
                LireResultat(tabResultatAudio, nombreElemetTab, "audio", chemin, tabFileName);
                printf("\n[R] Retour\n");
                free(tabResultatAudio);
                free(tabFileName);
            }
            break;
        case Retour:
            etat_courant = Menu_Utilisateur;
            break;
        case Quitter:
            printf("\n\tVous avez quitté le programme\n\n\n\n");
            exit(EXIT_SUCCESS);
            break;
        default:
            printf("Erreur de choix\n");
            etat_courant = Menu_audio;
            break;
        }
        break;

    default:
        printf("il y a une erreur, vous allez etre redirigez vers le menu general\n");
        etat_courant = Menu_general;
        break;
    }
}

void visionnerFichier()
{
}