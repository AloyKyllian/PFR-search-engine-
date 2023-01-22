// premier fichier main
#include <stdint.h>
#include <stdio.h>
#include "Menu.h"

int main()
{
    char choix[100];
    CONFIG config;
    String ERREUR;
    printf("\nDebut de la Phase d'initialisation\n");
    int erreurConfig = 0, erreurIndex = 0, erreurTexte = 0, erreurImage = 0, erreurAudio = 0;
    config = Lire_CONFIG(&erreurConfig);
    if (erreurConfig != 0)
    {
        Afficher_Erreur(erreurConfig, "../Gestion-Erreur/Erreur.txt", &ERREUR);
        printf("%s", ERREUR);
    }
    else
    {
        indexation(config, &erreurImage, &erreurAudio, &erreurTexte, &erreurIndex);
        if (erreurImage != 0)
        {
            Afficher_Erreur(erreurImage, "../Gestion-Erreur/Erreur.txt", &ERREUR);
            printf("%s", ERREUR);
        }
        if (erreurAudio != 0)
        {
            Afficher_Erreur(erreurAudio, "../Gestion-Erreur/Erreur.txt", &ERREUR);
            printf("%s", ERREUR);
        }
        if (erreurTexte != 0)
        {
            Afficher_Erreur(erreurTexte, "../Gestion-Erreur/Erreur.txt", &ERREUR);
            printf("%s", ERREUR);
        }
        if (erreurIndex != 0)
        {
            Afficher_Erreur(erreurIndex, "../Gestion-Erreur/Erreur.txt", &ERREUR);
            printf("%s", ERREUR);
        }

        else
        {
            printf("\n\tFin de la Phase d'initialisation\n");
            do
            {
                MAE(&config, choix, &erreurImage, &erreurAudio, &erreurTexte, &erreurIndex,ERREUR);
            } while (1);
        }
    }
}