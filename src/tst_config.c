#include "../head/Config.h"
#include "../head/Config.h"

void main()
{
    CONFIG config;
    config = Lire_CONFIG();
    Afficher_CONFIG(config);
    config = Lire_mot_cle(config);
    config = Lire_similariter(config);
    config = Lire_niveau(config);
    config = Lire_nb_fenetre(config);
    config = Lire_intervale(config);
    Ecrire_CONFIG(config);
    Afficher_CONFIG(config);
}