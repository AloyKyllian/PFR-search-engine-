#include "../head/Config.h"
#include "../head/Config.h"

void main()
{
    String Erreur;
    CONFIG config;

    printf("\nTest Lire_Config\n");
    config = Lire_CONFIG(&Erreur);
    printf("%s\n",Erreur.chaine);

    Afficher_CONFIG(config);

    printf("Test Lire_mot_cle\n");
    config = Lire_mot_cle(config,&Erreur);
    printf("%s\n",Erreur.chaine);

    printf("Test Lire_similariter\n");
    config = Lire_similariter(config,&Erreur);
    printf("%s\n",Erreur.chaine);


    printf("Test Lire_niveau\n");
    config = Lire_niveau(config,&Erreur);
    printf("%s\n",Erreur.chaine);


    printf("Test Lire_nb_fenetre\n");
    config = Lire_nb_fenetre(config,&Erreur);
    printf("%s\n",Erreur.chaine);


    printf("Test Lire_intervale\n");
    config = Lire_intervale(config,&Erreur);
    printf("%s\n",Erreur.chaine);


    printf("Test Ecrire_CONFIG\n");
    Ecrire_CONFIG(config,&Erreur);
    printf("%s\n",Erreur.chaine);

    Afficher_CONFIG(config);
}