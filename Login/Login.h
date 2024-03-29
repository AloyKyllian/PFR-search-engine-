//
// AUTEUR :
//          YASMINE ALLAL
// DERNIERE VERSION :
//    23/01/2023
//
#ifndef LOGIN_H
#define LOGIN_H

#define MAXPW 32
#include "../Gestion-Config/Global.h"
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

// structure login :
//                    - ID
//                    - MOT DE PASSE
// NB: ID unique

typedef struct eLOGIN
{ 
    String id;
    String mdp;

}LOGIN;

typedef LOGIN lesLogins[5];  


//_________________________________
//Fonctions pour la structure LOGIN
//__________________________________

//affiche id et mdp 
void afficher_un_login (lesLogins tablogin, int i);
// afficher tous les logins
void afficher_les_login (lesLogins tablogin);
// Entrer id et mdp
LOGIN saisir_login();

//___________________________________________
//Fonctions pour le fichier.txt et structure
//___________________________________________

// importe id et mdp du fichier texte a la structure
void lire_fichier_login (lesLogins tablogin, int * erreur);






#endif