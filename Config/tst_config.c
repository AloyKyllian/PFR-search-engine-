#include "Config.h"


void main()
{
    String Erreur;
    CONFIG config;

    printf("\nTest Lire_Config\n");
    config = Lire_CONFIG(&Erreur);
    printf("%s\n",Erreur);

    Afficher_CONFIG(config);

    printf("Test Lire_mot_cle\nEntrer un nb de mots cle\n");
    config = Lire_mot_cle(config,&Erreur);
    printf("%s\n",Erreur);

    printf("Test Lire_similariter\nEntrer un pourcentage de similariter\n");
    config = Lire_similariter(config,&Erreur);
    printf("%s\n",Erreur);


    printf("Test Lire_niveau\nEntrer un niveau\n");
    config = Lire_niveau(config,&Erreur);
    printf("%s\n",Erreur);


    printf("Test Lire_nb_fenetre\nEntrer un nb de fenetre\n");
    config = Lire_nb_fenetre(config,&Erreur);
    printf("%s\n",Erreur);


    printf("Test Lire_intervale\nEntrer un intervale\n");
    config = Lire_intervale(config,&Erreur);
    printf("%s\n",Erreur);


    printf("Test Ecrire_CONFIG\n");
    Ecrire_CONFIG(config,&Erreur);
    printf("%s\n",Erreur);

    Afficher_CONFIG(config);
}