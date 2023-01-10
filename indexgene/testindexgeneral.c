#include "indexation_gene.h"

int main()
{
    char path[100];
    int Erreurtexte = 0, Erreuraudio = 0;
    int Erreurimage = 0;
    int Erreur = 0;
    CONFIG config;
    config = Lire_CONFIG(&Erreurimage);
    indexation_generale_ferme(config, &Erreurimage, &Erreuraudio, &Erreurtexte, &Erreur);

    return 0;
}