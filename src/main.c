//premier fichier main
#include<stdint.h>
#include <stdio.h>

void main(){
    int val;
    val=6;
    printf("hello world %d",val);
    //test du merge
    



    
    
}

void Menu_general(){
    char choix='0';
    printf("Menu général\n");
    printf("Veuillez faire votre choix : \n");
    printf("[1] Administrateur \n[2] Utilissateur \n[Q] Quitter\n");
    scanf("%c",&choix);

    switch (choix)
    {
    case '1' :
        //admin
        //Connexion();
        Menu_Admin();
        break;
    case '2' :
        // utilisatuer 
        break;  
    case 'Q' :
        return ;//???
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