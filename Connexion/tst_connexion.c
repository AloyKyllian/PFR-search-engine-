#include "../Connexion/Connexion.h"

int main()
{
    int erreur;
    LOGIN test;
    lesLogins tablogin;
    bool result;
    result=seconnecter(tablogin, test,&erreur);
    printf("\nConnexion ");
    (result)? printf("Réussi\n\n") : printf("Échoué\n\n");
    return 0;
}