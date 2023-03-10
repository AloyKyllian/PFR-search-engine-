/**
 * Fait par Loic Maignan
 * 
 * Le 23/01/2023
 * 
*/
#ifndef CONFIG_H
#define CONFIG_H


#include "Global.h"
#include <math.h>

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
CONFIG Lire_CONFIG(int*);

//Affiche toute les valeur des parametres de configration
void Afficher_CONFIG(CONFIG);

//Lis et verifie la validiter de la valeur du nombre de mots cle
CONFIG Lire_mot_cle(CONFIG , int*);

//Lis et verifie la validiter de la valeur de la similarite
CONFIG Lire_similariter(CONFIG , int*);

//Lis et verifie la validiter de la valeur du niveau
CONFIG Lire_nb_bit_fort(CONFIG , int*);

//Lis et verifie la validiter de la valeur du nombre de fenetre
CONFIG Lire_nb_fenetre(CONFIG , int*);

//Lis et verifie la validiter de la valeur de l'intervale
CONFIG Lire_intervale(CONFIG , int*);

//Ecrit dans Config.txt les valeur stocker dans la structure CONFIG
void Ecrire_CONFIG(CONFIG , int*);

#endif