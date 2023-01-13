#include "../Login/Login.h"

int main()
{
    String erreur;
    LOGIN test;
    lesLogins tablogin;

    printf("\nlire_fichier_login\n");
    lire_fichier_login(tablogin,&erreur);
    printf("%s\n",erreur);

    afficher_les_login(tablogin);

     printf("Test saisir login\n");
    test=saisir_login();
    printf("%s\n",erreur);
    return 0;
}