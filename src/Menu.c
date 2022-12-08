#include<stdint.h>
#include <stdio.h>
#include <stdlib.h>
#define Quitter Q

//Menus Principaux
enum ETAT {Menugeneral,MenuAdmin,MenuIndexation, MenuUtilisateur};
//Menu General
enum General {Administrateur,Utilisateur,Quitter};
//Menu Admin
enum Admin{Indexation, Configuration,Visualisation, Retour_Utilisateur };


void MAE(){

     int etat_courant=Menu_general;

    switch (etat_courant)
    {
        case Menu_general :
             printf("Menu général\n");
             printf("Veuillez faire votre choix : \n");
             printf("[1] Administrateur \n[2] Utilisateur \n[Q] Quitter\n");
             scanf("%c",&General);
          
            switch (General){

                 case Administrateur :
                 //admin
                 //Connexion();
                 //Menu_Admin();
                 etat_courant=Menu_Admin;
                 break;
                 case Utilisateur :
                 // utilisateur 
                 etat_courant=Menu_Utilisateur;
                 break;  
                 case Quitter :
                 printf("vous avez quitté le programme\n");
                 break;
                 default:
                 printf("erreur de choix\n");
                 etat_courant=Menu_general;
                 break;
                 }
    break;

    default:
    break;
    }

}

void Menu_general(){
    char General='0';
    printf("Menu général\n");
    printf("Veuillez faire votre choix : \n");
    printf("[1] Administrateur \n[2] Utilisateur \n[Q] Quitter\n");
    scanf("%c",&General);
    
    switch (General)
    {
    case Administrateur :
        //admin
        //Connexion();
        Menu_Admin();
        break;
    case '2' :
        // utilisateur 
        break;  
    case 'Q' :
        printf("vous avez quitté le programme\n");
        break;
    default:
        printf("erreur de choix\n");
        Menu_general();
        break;
    }
}


            void Menu_Admin(){
                 printf("Menu général de l'administrateur\nFonctionnalité :\n");
                 char choix;
                 printf("Veuillez faire votre choix  : \n");
                 printf("[1] Indexation\n [2] Comparaison\n [3] Moteur de recherche \n[R] Retour\n[Q] Déconnexion\n");
                 scanf("%c",choix);

                 switch (choix){
                          case '1' :
                             //Indexation
                             break;
                         case '2' :
                             // Comparaison
                             break;  
                         case '3' :
                             // Moteur de recherche 
                             //Utilisateur
                             break;
                         case 'R' :
                             Menu_general();
                             break;
                         case 'Q' :
                             return ;//????
                             break;
                         default:
                             return NULL; 
                             break;
                        }
                } 

                 // 1. Indexation 
                           void Menu_Indexation(){
                                 printf("Indexation :\n");
                                 char choix;
                                 printf("Veuillez faire votre choix  : \n");
                                 printf("[1] Automatique\n [2] ouvrir descripteur\n [3] Configuration \n[R] Retour\n[Q] Déconnexion\n");
                                 scanf("%c",choix);

                                 switch (choix) {
                                         case '1' :
                                             //Lancer l'Indexation automatique
                                             Menu_Indexation();
                                             break;
                                         case '2' :
                                             // ouvrir descripteur
                                             Menu_Indexation();
                                             break;  
                                         case '3' :
                                             // Configuration
                                             Menu_Indexation();
                                             break;
                                         case 'R' :
                                             Menu_Admin();
                                             break;
                                         case 'Q' :
                                         return ;//????
                                         break;
                                         default:
                                         printf("erreur de choix\n");
                                         Menu_Admin();
                                         break;
                                        }
                             }

                 // 2. Comparaison
                           void Menu_Comparaison(){
                                 printf("Comparaison :\n");
                                 char choix;
                                 char choix2;
                                 printf("Veuillez faire votre choix  : ");
                                 printf("[1] Texte\n [2] Image\n [3] Audio\n[R] Retour\n[Q] Déconnexion\n");
                                 scanf("%c",&choix);

                                 if( (choix=='1') || (choix=='2') || (choix='3')){
                                     printf("Veuillez faire votre choix  : ");
                                     printf("[1] Fichiers\n [2] Descripteurs\n[R] Retour\n[Q] Déconnexion\n");
                                     scanf("%c",choix2);
                                 } 
                                 switch (choix) {
                                         case '1' :
                                             //Texte
                                             
                                             break;
                                         case '2' :
                                             // Image

                                             break;  
                                         case '3' :
                                             // Audio

                                             break;
                                         case 'R' :
                                             Menu_Admin();
                                             break;
                                         case 'Q' :
                                         return ;//????
                                         break;
                                         default:
                                         printf("erreur de choix\n");
                                         Menu_Admin();
                                         break;
                                        }
                             }

