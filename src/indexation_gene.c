#include "indexation_gene.h"

void recup_path(String *ptr_tableau, char typefichier, String *Erreur)
{
    FILE *fichier = NULL;

    fichier = fopen("../Config.txt", "r");
    if (fichier == NULL)
    {
        strcpy(*Erreur,"Erreur : Fichier introuvable");
    }

}