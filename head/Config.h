#ifndef CONFIG_H
#define CONFIG_H

#include "../head/Global.h"

//Tout les parametres necessaires aux configurations .
typedef struct
{ 
    int Nb_Mots_Cle;
    int Similariter;
    int Nb_Bit_Fort;
    int Nb_Fenetre;
    int Intervale;
}CONFIG;

//Lis Config.txt et renvoie les parametre dans la structure CONFIG
CONFIG Lire_CONFIG(String*);

//Affiche toute les valeur des parametres de configration
void Afficher_CONFIG(CONFIG);

//Lis et verifie la validiter de la valeur du nombre de mots cle
CONFIG Lire_mot_cle(String*, CONFIG);

//Lis et verifie la validiter de la valeur de la similarite
CONFIG Lire_similariter(String*, CONFIG);

//Lis et verifie la validiter de la valeur du niveau
CONFIG Lire_nb_bit_fort(String*, CONFIG);

//Lis et verifie la validiter de la valeur du nombre de fenetre
CONFIG Lire_nb_fenetre(String*, CONFIG);

//Lis et verifie la validiter de la valeur de l'intervale
CONFIG Lire_intervale(String*, CONFIG);

//Ecrit dans Config.txt les valeur stocker dans la structure CONFIG
void Ecrire_CONFIG(String*, CONFIG);

#endif