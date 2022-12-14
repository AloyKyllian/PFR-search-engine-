#include<stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"
#include "../head/Connexion.h"
#include "../head/Login.h"

int i;
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
                    for( i=0:i<3;i++){
                        String erreur;
                        LOGIN test;
                        lesLogins tablogin;
                        bool result;
                        result=seconnecter(tablogin, test,&erreur);
                        printf("\nConnexion ");
                        (result)? printf("Réussi\n\n") : printf("Échoué\n\n");}
                    if(result)
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
                 case  Configuration :
                        // Configuration
                        etat_courant=Menu_Configuration;
                        break;  
                 case Visualisation :
                        //visualisation
                        etat_courant=Menu_Visualisation;
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
             scanf("%c",&choix);
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
             scanf("%c",&choix);
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
             scanf("%c",&choix);
             switch (choix) {
                    case texte :
                         etat_courant= Menu_texte;                
                         break;
                    case image :
                         etat_courant= Menu_image; 
                         break;  
                    case audio :
                         etat_courant= Menu_audio; 
                         break;
                    case Retour :
                        etat_courant=Menu_general;
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

        case Menu_texte :
             printf("Recherche fichier texte :\n");
             printf("Veuillez faire votre choix  : \n");
             printf("[1] Recherche par mot clé\n [2] Recherche par comparaison de textes\n[R] Retour\n[Q] Quitter\n");
             scanf("%c",&choix);
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

        case Menu_image :
             printf("Recherche fichier image :\n");
             printf("Veuillez faire votre choix  : \n");
             printf("[1] Recherche par nom de couleur\n [2] Recherche par comparaison d'images\n[R] Retour\n[Q] Quitter\n");
             scanf("%c",&choix);
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
        
        case Menu_audio :
             printf("Recherche fichier audio :\n");
             printf("Veuillez faire votre choix  : \n");
             printf("[1] Recherche par comparaison d'audio\n[R] Retour\n[Q] Quitter\n");
             scanf("%c",&choix);
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
        default:
        break;
      }
    }

