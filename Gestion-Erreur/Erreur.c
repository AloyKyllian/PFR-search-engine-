#include <stdlib.h>
#include <stdio.h>
#include "Erreur.h"

void Afficher_Erreur(int Erreur,char Path[], String* Phrase)
{
    // Variable
    FILE *fichier = NULL;
    int cpt;
    
    // Lecture de la ligne corrrecpondant à l'erreur
    fichier = fopen(Path,"r");
    if(fichier == NULL)
    {
        printf("Erreur : Ouverture fuchier");
    }
    else
    {
        for (int i = 0; i < Erreur; i++)
        {
           fgets(*Phrase,100,fichier);
        }
        fgets(*Phrase,100,fichier);
    }
}