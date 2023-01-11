#include "indexation_gene.h"

int main()
{
    char path[100];
    int Erreurtexte = 0, Erreuraudio = 0;
    int Erreurimage = 0;
    int Erreur = 0;
    CONFIG config;
    config = Lire_CONFIG(&Erreurimage);

    // recuperer_path_tous_fichiers(&Erreurtexte, &Erreuraudio, &Erreurimage);
    indexation_generale_ferme(config, &Erreurimage, &Erreuraudio, &Erreurtexte, &Erreur);
   // indexation_generale_ouverte(config, &Erreurimage, &Erreuraudio, &Erreurtexte, &Erreur);

    return 0;
}