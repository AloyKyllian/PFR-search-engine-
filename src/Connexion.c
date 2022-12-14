#include "../head/Connexion.h"
#include "../head/Login.h"

bool seconnecter (lesLogins tablogin, LOGIN newlogin, String *erreur  )
{   int i ;
    newlogin=saisir_login();
    lire_fichier_login(tablogin,erreur);
    for(i=0; i<5;i++)
    {

        if (!strcmp(tablogin[i].id,newlogin.id) & !strcmp(tablogin[i].mdp,newlogin.mdp) )
          { 
            return true;
          }
    }
    return false;
}