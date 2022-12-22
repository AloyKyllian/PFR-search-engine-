#include "../head/Config.h"
#include "../head/Config.h"

CONFIG Lire_CONFIG(int *Erreur)
{
    // Variables
    CONFIG config;
    FILE *fichier = NULL;

    // Lie le fichier .txt et enregistre les valuer dans la structure CONFIG
    fichier = fopen("../Config.txt", "r");
    if (fichier != NULL)
    {
        *Erreur = 0;
        fscanf(fichier, "[1] Nombre de mots clé : %d\n[2] Similarité : %d\n[3] Nombre de bits : %d\n[4] Nombre de fenetre : %d\n[5] Intervale de temps : %d", &config.Nb_Mots_Cle, &config.Similariter, &config.Nb_Bit_Fort, &config.Nb_Fenetre, &config.Intervale);
    }
    else
    {
        *Erreur = 7;
    }
    fclose(fichier);
    return config;
}

void Afficher_CONFIG(CONFIG config)
{
    printf("Nombre de mots cle = %d\n", config.Nb_Mots_Cle);
    printf("Similariter = %d\n", config.Similariter);
    printf("Nombre de bits de poids fort = %d\n", config.Nb_Bit_Fort);
    printf("Nombre de fenetre = %d\n", config.Nb_Fenetre);
    printf("Intervale = %d\n", config.Intervale);
}

CONFIG Lire_mot_cle(int *Erreur, CONFIG config)
{
    // Variable
    int tmp;

    // Verifie si la valeur entrer est valide
    if (!scanf("%d", &tmp))
    {
        *Erreur = 9;
        viderBuffer();
    }
    else if (tmp <= 0)
    {
        *Erreur = 2;
    }
    else
    {
        *Erreur = 0;
        config.Nb_Mots_Cle = tmp;
    }
    return config;
}

CONFIG Lire_similariter(int *Erreur, CONFIG config)
{
    // Variable
    int tmp;

    // Verifie si la valeur entrer est valide
    if (!scanf("%d", &tmp))
    {
       *Erreur = 9;
        viderBuffer();
    }
    else if (tmp <= 0)
    {
       *Erreur = 2;
    }
    else if (tmp >= 100)
    {
       *Erreur = 10;
    }
    else
    {
        *Erreur = 0;
        config.Similariter = tmp;
    }
    return config;
}

CONFIG Lire_nb_bit_fort(int *Erreur, CONFIG config)
{
    // Variable
    int tmp;

    // Verifie si la valeur entrer est valide
    if (!scanf("%d", &tmp))
    {
        *Erreur = 9;
        viderBuffer();
    }
    else if (tmp <= 0)
    {
        *Erreur = 2;
    }
    else if (tmp >= 8)
    {
        *Erreur = 5;
    }
    else
    {
        *Erreur = 0;
        config.Nb_Bit_Fort = tmp;
    }
    return config;
}

CONFIG Lire_nb_fenetre(int *Erreur, CONFIG config)
{
    // Varaible
    int tmp;
    double tmp2;

    // Verifie si la valeur entrer est valide
    if (!scanf("%d", &tmp))
    {
        *Erreur = 9;
        viderBuffer();
    }
    else if (tmp <= 256)
    {
        *Erreur = 3;
    }
    else
    {
        tmp2 = log2((double)tmp);
        if (tmp2 == (int)tmp2)
        {
            *Erreur = 0;
            config.Nb_Bit_Fort = tmp;
        }
        else
        {
           *Erreur = 6;
        }
    }
    return config;
}

CONFIG Lire_intervale(int *Erreur,CONFIG config)
{
    // Variable
    int tmp;

    // Verifie si la valeur entrer est valide
    if (!scanf("%d", &tmp))
    {
        *Erreur = 9;
        viderBuffer();
    }
    else if (tmp <= 0)
    {
       *Erreur = 2;
    }
    else
    {
        *Erreur = 0;
        config.Intervale = tmp;
    }
    return config;
}

void Ecrire_CONFIG(int *Erreur, CONFIG config)
{
    // Variable
    FILE *fichier = NULL;

    fichier = fopen("../Config.txt", "w");
    if (fichier != NULL)
    {
        *Erreur = 0;
        fprintf(fichier, "[1] Nombre de mots clé : %d\n[2] Similarité : %d\n[3] Nombre de bits : %d\n[4] Nombre de fenetre : %d\n[5] Intervale de temps : %d", config.Nb_Mots_Cle, config.Similariter, config.Nb_Bit_Fort, config.Nb_Fenetre, config.Intervale);
    }
    else
    {
        *Erreur = 7;
    }
    fclose(fichier);
}