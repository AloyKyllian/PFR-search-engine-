#include "Menu.h"

void MAE(CONFIG *config, char choix[100], int *erreurImage, int *erreurAudio, int *erreurTexte, int *erreurIndex)
{
    char ERREUR[100];
    static char etat_courant = Menu_general;

    // variables a utiliser au cours du programme
    char chemin[100];
    int erreur = 0;
    int nbTentative = 1;
    char motCle[27];
    int nombreElemetTab = 0;
    int nombreElementTabFIN = 0;
    bool result = false;
    LOGIN testlogin;
    lesLogins tablogin;
    int test;
    char cheminDescripteurTxt[200] = "../base_descripteur/base_descripteur_texte";
    char cheminDescripteurIMG[100] = "../base_descripteur/base_descripteur_image";
    char cheminDescripteurAudio[100] = "../base_descripteur/base_descripteur_audio";

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
                if (erreur == 7)
                {
                    Afficher_Erreur(erreur, "../Gestion-Erreur/Erreur.txt", ERREUR);
                    printf("%s", ERREUR);
                }
                else
                {
                    printf("\nConnexion ");
                    (result) ? printf("Réussie\n\n") : printf("Échoué\n\n");
                    if (result)
                    {
                        printf("\nDirection menu administrateur\n");
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
                }
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
            erreur = 11;
            Afficher_Erreur(erreur, "../Gestion-Erreur/Erreur.txt", ERREUR);
            printf("%s", ERREUR);
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
            erreur = 11;
            Afficher_Erreur(erreur, "../Gestion-Erreur/Erreur.txt", ERREUR);
            printf("%s", ERREUR);
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
        printf("\n[1] Nombre de mots clé\n[2] Similarité\n[3] Nombre de bits \n[4] Nombre de fenetre\n");
        printf("[5] Intervalle de temps\n[R] Retour\n[Q] Déconnexion\n");
        scanf("%s", choix);
        switch (choix[0])
        {
        case Nombre_de_mot_cle:
            printf("Entrez le nombre de mot clé voulue :\n");
            *config = Lire_mot_cle(*config, &Erreur);
            if (Erreur != 0)
            {
                Afficher_Erreur(Erreur, "../Gestion-Erreur/Erreur.txt", ERREUR);
                printf("%s", ERREUR);
                Erreur = 0;
            }

            Ecrire_CONFIG(*config, &Erreur);
            if (Erreur != 0)
            {
                Afficher_Erreur(Erreur, "../Gestion-Erreur/Erreur.txt", ERREUR);
                printf("%s", ERREUR);
                Erreur = 0;
            }
            printf("\nSi vous avez changer votre configuration veuillez lancer l'indexation pour appliquer vos modification\n");
            break;
        case Similarité:
            // pour changer similarité
            printf("Entrez la valeur de similarité voulue :\n");
            *config = Lire_similariter(*config, &Erreur);
            if (Erreur != 0)
            {
                Afficher_Erreur(Erreur, "../Gestion-Erreur/Erreur.txt", ERREUR);
                printf("%s", ERREUR);
                Erreur = 0;
            }

            Ecrire_CONFIG(*config, &Erreur);
            if (Erreur != 0)
            {
                Afficher_Erreur(Erreur, "../Gestion-Erreur/Erreur.txt", ERREUR);
                printf("%s", ERREUR);
                Erreur = 0;
            }
            printf("\nSi vous avez changer votre configuration veuillez lancer l'indexation pour appliquer vos modification\n");
            break;
        case Nombre_de_bits:
            // pour changer niveau
            printf("Entrez le nombre de bits voulue :\n");
            *config = Lire_nb_bit_fort(*config, &Erreur);
            if (Erreur != 0)
            {
                Afficher_Erreur(Erreur, "../Gestion-Erreur/Erreur.txt", ERREUR);
                printf("%s", ERREUR);
                Erreur = 0;
            }

            Ecrire_CONFIG(*config, &Erreur);
            if (Erreur != 0)
            {
                Afficher_Erreur(Erreur, "../Gestion-Erreur/Erreur.txt", ERREUR);
                printf("%s", ERREUR);
                Erreur = 0;
            }
            printf("\nSi vous avez changer votre configuration veuillez lancer l'indexation pour appliquer vos modification\n");
            break;
        case Nombre_de_fenetre:
            printf("Entrez le nombre de fenetre voulue :\n");
            *config = Lire_nb_fenetre(*config, &Erreur);
            if (Erreur != 0)
            {
                Afficher_Erreur(Erreur, "../Gestion-Erreur/Erreur.txt", ERREUR);
                printf("%s", ERREUR);
                Erreur = 0;
            }
            Ecrire_CONFIG(*config, &Erreur);
            if (Erreur != 0)
            {
                Afficher_Erreur(Erreur, "../Gestion-Erreur/Erreur.txt", ERREUR);
                printf("%s", ERREUR);
                Erreur = 0;
            }
            printf("\nSi vous avez changer votre configuration veuillez lancer l'indexation pour appliquer vos modification\n");
            break;
        case Intervalle_de_temps:
            // fct pour changer l'intervalle de temps
            printf("Entrez l'intervalle de temps voulue' :\n");
            *config = Lire_intervale(*config, &Erreur);
            if (Erreur != 0)
            {
                Afficher_Erreur(Erreur, "../Gestion-Erreur/Erreur.txt", ERREUR);
                printf("%s", ERREUR);
                Erreur = 0;
            }
            Ecrire_CONFIG(*config, &Erreur);
            if (Erreur != 0)
            {
                Afficher_Erreur(Erreur, "../Gestion-Erreur/Erreur.txt", ERREUR);
                printf("%s", ERREUR);
                Erreur = 0;
            }
            printf("\nSi vous avez changer votre configuration veuillez lancer l'indexation pour appliquer vos modification\n");
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
                    printf("\n\t\033[0;31mVous avez quitté le programme\033[0m\n\n\n\n");
                    exit(EXIT_SUCCESS);
                    break;
                default:
                    erreur = 11;
                    Afficher_Erreur(erreur, "../Gestion-Erreur/Erreur.txt", ERREUR);
                    printf("%s", ERREUR);
                    etat_courant = Menu_Configuration;
                    break;
                }
            }
            break;
        default:
            erreur = 11;
            Afficher_Erreur(erreur, "../Gestion-Erreur/Erreur.txt", ERREUR);
            printf("%s", ERREUR);
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
            system("chmod 777 ../base_descripteur/base_descripteur_texte");
            break;
        case image:
            system("chmod a-w ../base_descripteur/base_descripteur_image");
            system("gedit ../base_descripteur/base_descripteur_image");
            system("chmod 777 ../base_descripteur/base_descripteur_image");
            break;
        case audio:
            system("chmod a-w ../base_descripteur/base_descripteur_audio");
            system("gedit ../base_descripteur/base_descripteur_audio");
            system("chmod 777 ../base_descripteur/base_descripteur_audio");
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
                    printf("\n\t\033[0;31mVous avez quitté le programme\033[0m\n\n\n\n");
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
            erreur = 11;
            Afficher_Erreur(erreur, "../Gestion-Erreur/Erreur.txt", ERREUR);
            printf("%s", ERREUR);
            etat_courant = Menu_Visualisation;
            break;
        }
        break;

    case Menu_Utilisateur:
        printf("\n__________________________Menu utilisateur__________________________\n");
        printf("\nVeuillez faire votre choix  : \n");
        printf("\n[1] Recherche fichier texte\n[2] Recherche fichier image\n[3] Recherche fichier audio \n[R] Retour\n[Q] Déconnexion\n");
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
            printf("\n\t\033[0;31mVous avez quitté le programme\033[0m\n\n\n\n");
            exit(EXIT_SUCCESS);
            break;
        default:
            erreur = 11;
            Afficher_Erreur(erreur, "../Gestion-Erreur/Erreur.txt", ERREUR);
            printf("%s", ERREUR);
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
        {
            char *tabFileName[700];
            erreur = 0;
            printf("\nEntrer votre mot clé\n");
            scanf("%s", motCle);
            tab_similaire *tabResultatMot = malloc(100 * sizeof(tab_similaire));
            rechercheMot(motCle, cheminDescripteurTxt, tabResultatMot, config->Nb_Mots_Cle, &nombreElemetTab, &erreur);
            if (erreur == 7)
            {
                Afficher_Erreur(erreur, "../Gestion-Erreur/Erreur.txt", ERREUR);
                printf("%s", ERREUR);
            }
            else
            {
                nombreElementTabFIN = LireResultat(tabResultatMot, nombreElemetTab, "rechercheMot", motCle, tabFileName, config->Nb_Mots_Cle, config->Similariter);

                if (nombreElementTabFIN > 0)
                {
                    printf("\n[R] Retour\nPenser a fermé l'editeur de texte apres l'avoir consulter pour poursuivre votre activité\n");
                    choix[0] = visualiser_fichier(tabFileName, nombreElementTabFIN, "texte");
                }
                if (strcmp(choix, "Q") == 0)
                {
                    printf("\n\t\033[0;31mVous avez quitté le programme\033[0m\n\n\n\n");
                    exit(EXIT_SUCCESS);
                }
            }
            free(tabResultatMot);
        }

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
                char *tabFileName[700];
                tabResultatTexte = comparaison_texte(config->Nb_Mots_Cle, chemin, cheminDescripteurTxt, &erreur, &nombreElemetTab);
                if (erreur == 7 || erreur == 1)
                {
                    Afficher_Erreur(erreur, "../Gestion-Erreur/Erreur.txt", ERREUR);
                    printf("%s", ERREUR);
                }
                nombreElementTabFIN = LireResultat(tabResultatTexte, nombreElemetTab, "texte", chemin, tabFileName, config->Nb_Mots_Cle, config->Similariter);

                if (nombreElementTabFIN > 0)
                {
                    printf("\n[R] Retour\nPenser a fermé l'editeur de texte apres l'avoir consulter pour poursuivre votre activité\n");
                    choix[0] = visualiser_fichier(tabFileName, nombreElementTabFIN, "texte");
                }
                if (strcmp(choix, "Q") == 0)
                {
                    printf("\n\t\033[0;31mVous avez quitté le programme\033[0m\n\n\n\n");
                    exit(EXIT_SUCCESS);
                }
                free(tabResultatTexte);
            }
            break;
        case Retour:
            etat_courant = Menu_Utilisateur;
            break;
        case Quitter:
            printf("\n\t\033[0;31mVous avez quitté le programme\033[0m\n\n\n\n");
            exit(EXIT_SUCCESS);
            break;
        default:
            erreur = 11;
            Afficher_Erreur(erreur, "../Gestion-Erreur/Erreur.txt", ERREUR);
            printf("%s", ERREUR);
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
                printf("\nCe fichier n'est pas de type image\nVeuiller mettre un fichier .txt\n");
                etat_courant = Menu_image;
            }
            else
            {
                erreur = 0, nombreElemetTab = 0;
                tab_similaire *tabResultatIMG;
                char *tabFileName[700];
                tabResultatIMG = Comparaison_descripteur_image(&erreur, cheminDescripteurIMG, chemin, config->Nb_Bit_Fort, &nombreElemetTab);
                if (erreur != 0)
                {
                    Afficher_Erreur(erreur, "../Gestion-Erreur/Erreur.txt", ERREUR);
                    printf("%s", ERREUR);
                }
                else
                {
                    nombreElementTabFIN = LireResultat(tabResultatIMG, nombreElemetTab, "image", chemin, tabFileName, config->Nb_Mots_Cle, config->Similariter);
                    if (nombreElementTabFIN > 0)
                    {
                        printf("\n[R] Retour\nPenser a fermé la fenetre apres l'avoir consulter pour poursuivre votre activité\n");
                        choix[0] = visualiser_fichier(tabFileName, nombreElementTabFIN, "image");
                    }
                    if (strcmp(choix, "Q") == 0)
                    {
                        printf("\n\t\033[0;31mVous avez quitté le programme\033[0m\n\n\n\n");
                        exit(EXIT_SUCCESS);
                    }
                }
                free(tabResultatIMG);
            }
            break;
        case Retour:
            etat_courant = Menu_Utilisateur;
            break;
        case Quitter:
            printf("\n\t\033[0;31mVous avez quitté le programme\033[0m\n\n\n\n");
            exit(EXIT_SUCCESS);
            break;
        default:
            erreur = 11;
            Afficher_Erreur(erreur, "../Gestion-Erreur/Erreur.txt", ERREUR);
            printf("%s", ERREUR);
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
                char *tabFileName[700];
                if (erreur != 0)
                {
                    Afficher_Erreur(erreur, "../Gestion-Erreur/Erreur.txt", ERREUR);
                    printf("%s", ERREUR);
                }
                else
                {
                    tabResultatAudio = comparaison_audio(config->Nb_Fenetre, config->Intervale, chemin, cheminDescripteurAudio, &erreur, &nombreElemetTab);
                    printf("debut de l'affichage\n");
                    nombreElementTabFIN = LireResultat(tabResultatAudio, nombreElemetTab, "audio", chemin, tabFileName, config->Nb_Mots_Cle, config->Similariter);

                    if (nombreElementTabFIN > 0)
                    {
                        printf("\n[R] Retour\nPenser a fermé la fenetre apres l'avoir consulter pour poursuivre votre activité\n");
                        choix[0] = visualiser_fichier(tabFileName, nombreElementTabFIN, "audio");
                    }
                    if (strcmp(choix, "Q") == 0)
                    {
                        printf("\n\t\033[0;31mVous avez quitté le programme\033[0m\n\n\n\n");
                        exit(EXIT_SUCCESS);
                    }
                    free(tabResultatAudio);
                }
            }
            break;
        case Retour:
            etat_courant = Menu_Utilisateur;
            break;
        case Quitter:
            printf("\n\t\033[0;31mVous avez quitté le programme\033[0m\n\n\n\n");
            exit(EXIT_SUCCESS);
            break;
        default:
            erreur = 11;
            Afficher_Erreur(erreur, "../Gestion-Erreur/Erreur.txt", ERREUR);
            printf("%s", ERREUR);
            etat_courant = Menu_audio;
            break;
        }
        break;

    default:
        printf("il y a une erreur, vous allez etre redirigez vers le menu general\n");
        erreur = 14;
        if (erreur != 0)
        {
            Afficher_Erreur(erreur, "../Gestion-Erreur/Erreur.txt", ERREUR);
            printf("%s", ERREUR);
        }
        etat_courant = Menu_general;
        break;
    }
}
