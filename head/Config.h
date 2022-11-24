#ifndef CONFIG_H
#define CONFIG_H

#include "../head/Global.h"

typedef struct
{ 
    int nb_mots_cle;
    int similariter;
    int niveau;
    int nb_fenetre;
    float intervale;

}CONFIG;

CONFIG Lire_CONFIG();
void Afficher_CONFIG(CONFIG config);
CONFIG Lire_mot_cle(CONFIG config);
CONFIG Lire_similariter(CONFIG config);
CONFIG Lire_niveau(CONFIG config);
CONFIG Lire_nb_fenetre(CONFIG config);
CONFIG Lire_intervale(CONFIG config);
void Ecrire_CONFIG(CONFIG config);

#endif