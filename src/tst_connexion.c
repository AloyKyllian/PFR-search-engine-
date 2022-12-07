#include "../head/Connexion.h"
#include "../head/Login.h"

int main()
{
    String erreur;
    LOGIN test;
    lesLogins tablogin;
    bool result;

    printf("\nlire_fichier_login\n");
    lire_fichier_login(tablogin,&erreur);
    printf("%s\n",erreur);
    result=seconnecter(tablogin, test);
    printf("\nConnexion ");
    (result)? printf("Réussi\n\n") : printf("Failed\n\n");
    return 0;
}