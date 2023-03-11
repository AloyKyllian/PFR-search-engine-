//
// AUTEUR :
//          YOUSSERA ACHACHERA
// DERNIERE VERSION :
//    22/01/2023
//
#include <stdint.h>
#include <stdio.h>
#include "Menu.h"

int main()
{
    char choix[100];  // variable pour stocker le choix de l'utilisateur
    CONFIG config;    // variable pour stocker les informations de configuration
    char ERREUR[100]; // variable pour stocker le message d'erreur
    printf("\nDebut de la Phase d'initialisation\n");
    int erreurConfig = 0, erreurIndex = 0, erreurTexte = 0, erreurImage = 0, erreurAudio = 0; // variables pour stocker les codes d'erreur
    config = Lire_CONFIG(&erreurConfig);                                                      // lire les informations de configuration
    if (erreurConfig != 0)
    {
        Afficher_Erreur(erreurConfig, "../Gestion-Erreur/Erreur.txt", ERREUR);
        printf("%s", ERREUR); // afficher le message d'erreur si une se produit lors de l'ouverture du fichier qui stocke les valeurs de configuration
    }
    else
    {
        indexation(config, &erreurImage, &erreurAudio, &erreurTexte, &erreurIndex); // lancement de l'indexation
        // afficher le message d'erreur si une se produit lors de l'ouverture d'un fichier
        if (erreurImage != 0)
        {
            Afficher_Erreur(erreurImage, "../Gestion-Erreur/Erreur.txt", ERREUR);
            printf("%s", ERREUR);
        }
        if (erreurAudio != 0)
        {
            Afficher_Erreur(erreurAudio, "../Gestion-Erreur/Erreur.txt", ERREUR);
            printf("%s", ERREUR);
        }
        if (erreurTexte != 0)
        {
            Afficher_Erreur(erreurTexte, "../Gestion-Erreur/Erreur.txt", ERREUR);
            printf("%s", ERREUR);
        }
        if (erreurIndex != 0)
        {
            Afficher_Erreur(erreurIndex, "../Gestion-Erreur/Erreur.txt", ERREUR);
            printf("%s", ERREUR);
        }

        else
        {
            printf("\nFin de la Phase d'initialisation\n");
            do
            {
                MAE(&config, choix, &erreurImage, &erreurAudio, &erreurTexte, &erreurIndex); // appeler la fonction pour afficher le menu principal et traiter les choix de l'utilisateur ainsi que l'administrateur
            } while (1);
        }
    }
}