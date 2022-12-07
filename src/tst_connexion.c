#include "../head/Connexion.h"
#include "../head/Login.h"

int main()
{
    String erreur;
    LOGIN test;
    lesLogins tablogin;
    bool result;
    result=seconnecter(tablogin, test,&erreur);
    printf("\nConnexion ");
    (result)? printf("Réussi\n\n") : printf("Échoué\n\n");
    return 0;
}