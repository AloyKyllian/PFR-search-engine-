#ifndef CONFIG_H
#define CONFIG_H

#include "../head/Global.h"

//Tout les parametre necessaire son donner dans cette structure.
typedef struct
{ 
    int nb_mots_cle;
    int similariter;
    int niveau;
    int nb_fenetre;
    int intervale;
}CONFIG;

//Lis Config.txt et renvoie les parametre dans la structure CONFIG
CONFIG Lire_CONFIG(String*);
//Affiche toute les valeur des parametres de configration
void Afficher_CONFIG(CONFIG);
//Lis et verifie la validiter de la valeur du nombre de mots cle
CONFIG Lire_mot_cle(CONFIG,String*);
//Lis et verifie la validiter de la valeur de la similarite
CONFIG Lire_similariter(CONFIG,String*);
//Lis et verifie la validiter de la valeur du niveau
CONFIG Lire_niveau(CONFIG,String*);
//Lis et verifie la validiter de la valeur du nombre de fenetre
CONFIG Lire_nb_fenetre(CONFIG,String*);
//Lis et verifie la validiter de la valeur de l'intervale
CONFIG Lire_intervale(CONFIG,String*);
//Ecrit dans Config.txt les valeur stocker dans la structure CONFIG
void Ecrire_CONFIG(CONFIG,String*);

#endif