/**
 * Fait par Loic Maignan
 * 
 * Le 23/01/2023
 * 
*/
#include "Config.h"

void main()
{
    int Erreur;
    CONFIG config;

    printf("\nTest Lire_Config\n");
    config = Lire_CONFIG(&Erreur);
    printf("Erreur = %d\n\n",Erreur);

    Afficher_CONFIG(config);

    printf("\nTest Lire_mot_cle\nEntrer un nb de mots cle\n");
    config = Lire_mot_cle(config,&Erreur);
    printf("Erreur = %d\n\n",Erreur);

    printf("Test Lire_similariter\nEntrer un pourcentage de similariter\n");
    config = Lire_similariter(config,&Erreur);
    printf("Erreur = %d\n\n",Erreur);

    printf("Test Lire_nb_bit_fort\nEntrer un nombre de bits\n");
    config = Lire_nb_bit_fort(config,&Erreur);
    printf("Erreur = %d\n\n",Erreur);

    printf("Test Lire_nb_fenetre\nEntrer un nb de fenetre\n");
    config = Lire_nb_fenetre(config,&Erreur);
    printf("Erreur = %d\n\n",Erreur);

    printf("Test Lire_intervale\nEntrer un intervale\n");
    config = Lire_intervale(config,&Erreur);
    printf("Erreur = %d\n",Erreur);

    printf("Test Ecrire_CONFIG\n");
    Ecrire_CONFIG(config,&Erreur);
    printf("Erreur = %d\n",Erreur);

    Afficher_CONFIG(config);
}