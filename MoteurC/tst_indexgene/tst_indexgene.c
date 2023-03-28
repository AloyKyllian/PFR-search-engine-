//
// AUTEUR :
//          YASMINE ALLAL
// DERNIERE VERSION :
//    23/01/2023
//
#include "../indexgene/indexation_gene.h"

int main()
{
    int Erreurtexte = 0, Erreuraudio = 0;
    int Erreurimage = 0;
    int Erreur = 0;
    CONFIG config;
    config = Lire_CONFIG(&Erreurimage);

    // recuperer_path_tous_fichiers(&Erreurtexte, &Erreuraudio, &Erreurimage);
    // indexation_generale_ferme(config, &Erreurimage, &Erreuraudio, &Erreurtexte, &Erreur);
     indexation(config, &Erreurimage, &Erreuraudio, &Erreurtexte, &Erreur);
    // indexation_ouverte(config,type,Erreurimage,Erreuraudio,Erreurtexte,Erreur);

    return 0;
}