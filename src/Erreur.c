#include <stdlib.h>
#include <stdio.h>

typedef char String[100];

void Afficher_Erreur(int Erreur,char Path[])
{
    String chaine = "";
    FILE *fichier = NULL;
    int cpt;
    fichier = fopen(Path,"r");
    if(fichier == NULL)
    {
        printf("Erreur : Ouverture fuchier");
    }
    else
    {
        for (int i = 0; i < Erreur; i++)
        {
           fgets(chaine,100,fichier);
        }
        fgets(chaine,100,fichier);
        printf("%s",chaine);
        
        

    }
}

void main()
{
    Afficher_Erreur(2,"../Erreur.txt");
}