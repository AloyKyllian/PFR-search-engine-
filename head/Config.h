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

CONFIG Lire_CONFIG(String*);
void Afficher_CONFIG(CONFIG);
CONFIG Lire_mot_cle(CONFIG,String*);
CONFIG Lire_similariter(CONFIG,String*);
CONFIG Lire_niveau(CONFIG,String*);
CONFIG Lire_nb_fenetre(CONFIG,String*);
CONFIG Lire_intervale(CONFIG,String*);
void Ecrire_CONFIG(CONFIG,String*);

#endif