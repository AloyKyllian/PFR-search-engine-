#include<stdint.h>
#include <stdio.h>
#include <stdlib.h>


//Etat :
//MENUS PRINCIPAUX
#define Menu_general 1
#define Menu_Admin 2
#define Menu_Utilisateur 3


//Menu General
#define Administrateur 1
#define Utilisateur 2
#define Quitter 'Q'
#define Deconnexion 'Q'


//Menu Admin
#define Indexation 1
#define Menu_Configuration 2
#define Menu_Visualisation 3
#define Retour_Utilisateur 4

//Menu configuration 
#define Nombre_de_mot_cle 1
#define Similarité 2
#define Niveau 3
#define Nombre_de_fenetre 4
#define Intervalle_de_temps 5

//Visualisation descripeteur
//Menu Utilisateur
#define texte 1
#define image 2
#define audio 3

//Menu recherche texte
#define Recherche_mots_cle 1
#define Recherche_par_comparaison 2
#define Retour 'R'

//Menu recherche image
#define Recherche_nom_couleur 1

//Menu recherche audio
#define Recherche_comparaison_audio 1
char choix;




void MAE(){

    char etat_courant=Menu_general;

    switch (etat_courant)
    {
        case Menu_general :
             printf("Menu général\n");
             printf("Veuillez faire votre choix : \n");
             printf("[1] Administrateur \n[2] Utilisateur \n[Q] Quitter\n");
             scanf("%c",&choix);
          
            switch (choix){

                 case Administrateur :
                    //Connexion();
                    etat_courant=Menu_Admin;
                    break;
                 case Utilisateur :
                    // utilisateur 
                    etat_courant=Menu_Utilisateur;
                    break;  
                 case Quitter :
                    printf("vous avez quitté le programme\n");
                    //etat_courant=??????
                    break;
                 default:
                 printf("erreur de choix\n");
                 etat_courant=Menu_general;
                 break;
                 }
        break;

        case Menu_Admin:
             printf("Menu général de l'administrateur\nFonctionnalité :\n");
             printf("Veuillez faire votre choix  : \n");
             printf("[1] Indexation\n [2] Configuration\n [3] Visualisation des recueils des descripteurs\n[4] Retour en mode utilisateur\n");
             scanf("%c",&choix);

            switch (choix){
                 case Indexation :
                        //Indexation
                        break;
                 case  Menu_Configuration :
                        // Configuration
                        etat_courant=Menu_Configuration;
                        break;  
                 case Menu_Visualisation :
                        //visualisation
                        break;
                 case Retour_Utilisateur :
                        etat_courant=Menu_Utilisateur;
                        break;
                 case Quitter :
                        return ;//????
                        break;
                 default:
                        printf("erreur de choix\n");
                        etat_courant=Menu_Admin;
                        break;
                        }
        break;
        
        case Menu_Configuration :
             printf("Configuration :\n");
             printf("Veuillez faire votre choix  : \n");
             printf("[1] Nombre de mots clé\n [2] Similarité\n [3] Niveau \n[4] Nombre de fenetre\n");
             printf("[5] Intervalle de temps\n [R] Retour\n[Q] Déconnexion\n");
             scanf("%c",choix);
             switch (choix) {
                    case Nombre_de_mot_cle :
                         //fct pour changer le nombre de mot cle                   
                         break;
                    case Similarité :
                         // pour changer similarité
                         
                         break;  
                    case Niveau :
                         // pour changer niveau
                         break;
                    case Nombre_de_fenetre :
                        //fct pour changer le nombre de fenetre
                    case Intervalle_de_temps :
                        //fct pour changer l'intervalle de temps
                    case Retour :
                        etat_courant=Menu_Admin;
                    case Quitter :
                        return ;//????
                        break;
                    default:
                        printf("erreur de choix\n");
                        etat_courant=Menu_Configuration;
                        break;
                        }  
        break;

        case Menu_Visualisation :
             printf("Visualisation des recueils des descripteurs :\n");
             printf("Veuillez faire votre choix  : \n");
             printf("[1] Texte\n [2] Image\n [3] Audio \n[R] Retour\n[Q] Déconnexion\n");
             scanf("%c",choix);
             switch (choix) {
                    case texte :
                         //                  
                         break;
                    case image :
                         // 
                         break;  
                    case audio :
                         //
                         break;
                    case Retour :
                        etat_courant=Menu_Admin;
                    case Quitter :
                        return ;//????
                        break;
                    default:
                        printf("erreur de choix\n");
                        etat_courant=Menu_Visualisation;
                        break;
                        }  
        break;

        case Menu_Utilisateur :
             printf("Menu utilisateur :\n");
             printf("Veuillez faire votre choix  : \n");
             printf("[1] Recherche fichier texte\n [2] Recherche fichier image\n [3] Recherche fichier audio \n[Q] Déconnexion\n");
             scanf("%c",choix);
             switch (choix) {
                    case texte :
                         //                  
                         break;
                    case image :
                         // 
                         break;  
                    case audio :
                         //
                         break;
                    case Retour :
                        etat_courant=Menu_Utilisateur;
                        break;
                    case Quitter :
                        return ;//????
                        break;
                    default:
                        printf("erreur de choix\n");
                        etat_courant=Menu_Utilisateur;
                        break;
                        }  
        break;

        case texte :
             printf("Recherche fichier texte :\n");
             printf("Veuillez faire votre choix  : \n");
             printf("[1] Recherche par mot clé\n [2] Recherche par comparaison de textes\n[R] Retour\n[Q] Quitter\n");
             scanf("%c",choix);
             switch (choix) {
                    case Recherche_mots_cle :
                        //                  
                        break;
                    case Recherche_par_comparaison :
                        // 
                        break;  
                    case Retour :
                        etat_courant=Menu_Utilisateur;
                        break;
                    case Quitter :
                        return ;//????
                        break;
                    default:
                        printf("erreur de choix\n");
                        etat_courant=texte;
                        break;
                        }  
        break;

        case image :
             printf("Recherche fichier image :\n");
             printf("Veuillez faire votre choix  : \n");
             printf("[1] Recherche par nom de couleur\n [2] Recherche par comparaison d'images\n[R] Retour\n[Q] Quitter\n");
             scanf("%c",choix);
             switch (choix) {
                    case Recherche_nom_couleur :
                        //                  
                        break;
                    case Recherche_par_comparaison :
                        // 
                        break;  
                    case Retour :
                        etat_courant=Menu_Utilisateur;
                        break;
                    case Quitter :
                        return ;//????
                        break;
                    default:
                        printf("erreur de choix\n");
                        etat_courant=image;
                        break;
                        }  
        break;
        
        case audio :
             printf("Recherche fichier audio :\n");
             printf("Veuillez faire votre choix  : \n");
             printf("[1] Recherche par comparaison d'audio\n[R] Retour\n[Q] Quitter\n");
             scanf("%c",choix);
             switch (choix) {
                    case Recherche_par_comparaison :
                        // 
                        break;  
                    case Retour :
                        etat_courant=Menu_Utilisateur;
                        break;
                    case Quitter :
                        return ;//????
                        break;
                    default:
                        printf("erreur de choix\n");
                        etat_courant=audio;
                        break;
                        }  
        break;




          

                                        
    break;
    default:
    break;
      }
    }

