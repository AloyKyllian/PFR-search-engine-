#ifndef CONNEXION_H
#define CONNEXION_H

#include "../Login/Login.h"
#include "../Gestion-Config/Global.h"

/**
 * @brief
 * La fonction "seconnecter" permet à un utilisateur de se connecter en saisissant son nom d'utilisateur et son mot de passe. 
Elle utilise la fonction "saisir_login" pour récupérer les informations de connexion saisies par l'utilisateur et la fonction "lire_fichier_login" pour lire les informations de connexion stockées dans un fichier. 
Ensuite, elle parcourt un tableau de 5 logins pour vérifier si les informations saisies correspondent à un login existant. 
Si c'est le cas, la fonction renvoie "true", sinon elle renvoie "false". 
En cas d'erreur de lecture de fichier, elle retourne un code d'erreur.
 * 
 * 
 * @param tablogin
 * @param newlogin
 * @param erreur
 
 */

bool seconnecter (lesLogins tablogin, LOGIN newlogin, int *erreur);



#endif