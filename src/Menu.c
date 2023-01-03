#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "../head/Menu.h"
#include "../head/Connexion.h"
#include "../head/Config.h"
#include "../head/FichierExist.h"
void MAE()
{

    char etat_courant = Menu_general;
    int test,test1;
    char choix;
    char choixImage;
    char chemin[100];
    char *mot;
    char *extension;
    int i;
    switch (etat_courant)
    {
    case Menu_general:
        printf("Menu général\n");
        printf("Veuillez faire votre choix : \n");
        printf("[1] Administrateur \n[2] Utilisateur \n[Q] Quitter\n");
        scanf("%c", &choix);

        switch (choix)
        {

        case Administrateur:
            // Connexion();
            do
            {
                String erreur;
                LOGIN test;
                lesLogins tablogin;
                bool result;
                result = seconnecter(tablogin, test, &erreur);
                printf("\nConnexion ");
                (result) ? printf("Réussi\n\n") : printf("Échoué\n\n");
                if (result)
                    etat_courant = Menu_Admin;
                if (i == 3 && result == 0)
                {
                    printf("Souhaitez vous basculer en mode utilisateur ou essayer de se connecter une nouvelle fois ?\n");
                    printf("[1] Mode utilisateur\n[2] nouvelle tentative de connexion\n");
                    scanf("%c", &choix);
                    if (choix == '1')
                        etat_courant = Menu_Utilisateur;
                    if (choix == '2')
                    {
                        int nbr_microsec = 0;
                        printf("Vous devez attendre 30 seconde pour réessayer\n");
                        usleep(nbr_microsec);
                        sleep(30);
                        printf("fin 30 sec, Vous pouvez réessayer maintenant\n");
                        i = 0;
                    }
                }
                i++;
            } while (i < 4);

            break;
        case Utilisateur:
            // utilisateur
            etat_courant = Menu_Utilisateur;
            break;
        case Quitter:
            printf("vous avez quitté le programme\n");
            return 0;
            break;
        default:
            printf("erreur de choix\n");
            etat_courant = Menu_general;
            break;
        }

        break;

    case Menu_Admin:
        printf("Menu général de l'administrateur\nFonctionnalité :\n");
        printf("Veuillez faire votre choix  : \n");
        printf("[1] Indexation\n [2] Configuration\n [3] Visualisation des recueils des descripteurs\n[4] Retour en mode utilisateur\n");
        scanf("%c", &choix);

        switch (choix)
        {
        case Indexation:
            // Indexation generale avec config.txt a voir avec yasmine

            break;
        case Configuration:
            // Configuration
            etat_courant = Menu_Configuration;
            break;
        case Visualisation:
            // visualisation
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
        printf("Configuration :\n");
        CONFIG Lire_CONFIG(String * Erreur);
        Afficher_CONFIG(CONFIG config);
        printf("Si vous voulez changer une valeur, veuillez faire votre choix  : \n");
        printf("[1] Nombre de mots clé\n [2] Similarité\n [3] Niveau \n[4] Nombre de fenetre\n");
        printf("[5] Intervalle de temps\n [R] Retour\n[Q] Déconnexion\n");
        scanf("%c", &choix);
        switch (choix)
        {
        case Nombre_de_mot_cle:
            CONFIG Lire_mot_cle(CONFIG config, String * Erreur);
            void Ecrire_CONFIG(CONFIG config, String * Erreur);
            break;
        case Similarité:
            // pour changer similarité
            CONFIG Lire_similariter(CONFIG config, String * Erreur);
            void Ecrire_CONFIG(CONFIG config, String * Erreur);
            break;
        case Niveau:
            // pour changer niveau
            CONFIG Lire_niveau(CONFIG config, String * Erreur);
            void Ecrire_CONFIG(CONFIG config, String * Erreur);
            break;
        case Nombre_de_fenetre:
            // fct pour changer le nombre de fenetre
            CONFIG Lire_nb_fenetre(CONFIG config, String * Erreur);
            void Ecrire_CONFIG(CONFIG config, String * Erreur);
            break;
        case Intervalle_de_temps:
            // fct pour changer l'intervalle de temps
            CONFIG Lire_intervale(CONFIG config, String * Erreur);
            void Ecrire_CONFIG(CONFIG config, String * Erreur);
            break;
        case Retour:
            etat_courant = Menu_Admin;
            break;
        case Deconnexion:
            choix = '3';
            while (choix != '1' || choix != '2')
            {
                printf("vous vous etes deconnecter, voulez vous retourner en mode utilisateur ?\n[1] Oui\n [2] Non ");
                scanf("%c", &choix);
                switch (choix)
                {
                case '1':
                    etat_courant = Menu_Utilisateur;
                    break;
                case '2':
                    printf("vous avez quitté le programme\n");
                    return 0;
                    break;
                default:
                printf("mauvais choix\n");
                break;
                }
            }
            break;
        default:
            printf("erreur de choix\n");
            etat_courant = Menu_Configuration;
            break;
        }
        break;

    case Menu_Visualisation:
        printf("Visualisation des recueils des descripteurs :\n");
        printf("Veuillez faire votre choix  : \n");
        printf("[1] Texte\n [2] Image\n [3] Audio \n[R] Retour\n[Q] Déconnexion\n");
        scanf("%c", &choix);
        switch (choix)
        {
        case texte:
            //

            break;
        case image:
            //
            break;
        case audio:
            //
            break;
        case Retour:
            etat_courant = Menu_Admin;
        case Quitter://DECONNEXION 
            printf("vous avez quitté le programme\n");
            return 0;
            break;
        default:
            printf("erreur de choix\n");
            etat_courant = Menu_Visualisation;
            break;
        }
        break;

    case Menu_Utilisateur:
        printf("Menu utilisateur :\n");
        printf("Veuillez faire votre choix  : \n");
        printf("[1] Recherche fichier texte\n [2] Recherche fichier image\n [3] Recherche fichier audio \n[Q] Déconnexion\n");
        scanf("%c", &choix);
        switch (choix)
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
            printf("vous avez quitté le programme\n");
            return 0;
            break;
        default:
            printf("erreur de choix\n");
            etat_courant = Menu_Utilisateur;
            break;
        }
        break;

    case Menu_texte:
        printf("Recherche fichier texte :\n");
        printf("Veuillez faire votre choix  : \n");
        printf("[1] Recherche par mot clé\n [2] Recherche par comparaison de textes\n[R] Retour\n[Q] Quitter\n");
        scanf("%c", &choix);
        switch (choix)
        {
        case Recherche_mots_cle:
            printf("Veuillez saisir le mot que vous voulez chercher\n");
            scanf("%s",mot);
            rechercheMot(mot,);//chemin descripteur texte
            break;
        case Recherche_par_comparaison:
            // verification si le fichier existe
            test=-1;
            while(test==-1){
                printf("entrez le chemin de votre fichier\n");
                scanf("%s", chemin);
                test=FichierExist(chemin);
                if(test==-1)
                     printf("Le fichier n'existe pas");
                     printf("Veuillez faire un choix pour continuer\n[1] Entrer un autre fichier\n [2] Retour menu principale\n");
                     scanf("%c",&choix);
                     switch (choix)
                     {
                     case '2':
                        etat_courant=Menu_Utilisateur;
                        break;
                     case '1':
                        test=-1;
                        break;
                     default:
                        etat_courant=Menu_Utilisateur;
                        break;
                     }}
            //verification si le fichier passer est un fichier texte
            test=VerifExtension(chemin,"xml");
            if (test==-1){
                   printf("Ce fichier n'est pas de type texte\nVeuiller mettre un fichier texte\n");
                   etat_courant=Menu_texte;}
            else 
                //recherche 
            break;
        case Retour:
            etat_courant = Menu_Utilisateur;
            break;
        case Quitter:
            return 0; 
            break;
        default:
            printf("erreur de choix\n");
            etat_courant = Menu_texte;
            break;
        }
        break;

    case Menu_image:
        printf("Recherche fichier image :\n");
        printf("Veuillez faire votre choix  : \n");
        printf("[1] Recherche par comparaison d'images\n[R] Retour\n[Q] Quitter\n");
        scanf("%c", &choix);
        switch (choix)
        {
        case Recherche_par_comparaison:
            printf("Votres image est une :\n[1] Image couleur\n[2] Image noir et blanc\n");
            scanf("%c",&choixImage);
            printf("entrez le chemin de votre fichier\n");
            scanf("%s", chemin);
            // verification si le fichier existe
            test=-1;
            while(test==-1){
                printf("entrez le chemin de votre fichier\n");
                scanf("%s", chemin);
                test=FichierExist(chemin);
                if(test==-1)
                     printf("Le fichier n'existe pas");
                     printf("Veuillez faire un choix pour continuer\n[1] Entrer un autre fichier\n [2] Retour menu principale\n");
                     scanf("%c",&choix);
                     switch (choix)
                     {
                     case '2':
                        etat_courant=Menu_Utilisateur;
                        break;
                     case '1':
                        test=-1;
                        break;
                     default:
                        etat_courant=Menu_Utilisateur;
                        break;
                     }}
            //verification si le fichier passer est un fichier texte
            
            switch (choixImage)
            {
            case '1' ://Image couleur
                test=VerifExtension(chemin,"txt");
                 if (test==-1){
                   printf("Ce fichier n'est pas de type texte\nVeuiller faire le choix de recherche qui vous correspond\n");
                   etat_courant=Menu_Utilisateur;}
            else 
                //recherche 
                break;
            case '2'://Image noir et blanc
                test=VerifExtension(chemin,"txt");
                 if (test==-1){
                   printf("Ce fichier n'est pas de type texte\nVeuiller faire le choix de recherche qui vous correspond\n");
                   etat_courant=Menu_Utilisateur;}
            else 
                //recherche 
            default:
                printf("erreur de choix\n");
                etat_courant = Menu_image;
                break;
            }
            break;
        case Retour:
            etat_courant = Menu_Utilisateur;
            break;
        case Quitter:
            printf("vous avez quitté le programme\n");
            return 0;
            break;
        default:
            printf("erreur de choix\n");
            etat_courant = Menu_image;
            break;
        }
        break;

    case Menu_audio:
        printf("Recherche fichier audio :\n");
        printf("Veuillez faire votre choix  : \n");
        printf("[1] Recherche par comparaison d'audio\n[R] Retour\n[Q] Quitter\n");
        scanf("%c", &choix);
        switch (choix)
        {
        case Recherche_par_comparaison:
            printf("entrez le chemin de votre fichier\n");
            scanf("%s", chemin);
            // verification si le fichier existe
            test=-1;
            while(test==-1){
                printf("entrez le chemin de votre fichier\n");
                scanf("%s", chemin);
                test=FichierExist(chemin);
                if(test==-1)
                     printf("Le fichier n'existe pas");
                     printf("Veuillez faire un choix pour continuer\n[1] Entrer un autre fichier\n [2] Retour menu principale\n");
                     scanf("%c",&choix);
                     switch (choix)
                     {
                     case '2':
                        etat_courant=Menu_Utilisateur;
                        break;
                     case '1':
                        test=-1;
                        break;
                     default:
                        etat_courant=Menu_Utilisateur;
                        break;
                     }}
            //verification si le fichier passer est un fichier texte
            test=VerifExtension(chemin,"txt");
            if (test==-1){
                   printf("Ce fichier n'est pas de type texte\nVeuiller faire le choix de recherche qui vous correspond\n");
                   etat_courant=Menu_Utilisateur;}
            else 
                //recherche comparaison

            break;
        case Retour:
            etat_courant = Menu_Utilisateur;
            break;
        case Quitter:
            printf("vous avez quitté le programme\n");
            return 0;
            break;
        default:
            printf("erreur de choix\n");
            etat_courant = Menu_audio;
            break;
        }
        break;
        default:
        printf("il y a une erreur, vous allez etre redirigez vers le menu general\n");
        etat_courant=Menu_general;
        break;
    }
}

