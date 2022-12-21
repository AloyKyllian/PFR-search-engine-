#include "../head/Config.h"

CONFIG Lire_CONFIG(String *Erreur)
{
    // Variables
    CONFIG config;
    FILE *fichier = NULL;

    // Lie le fichier .txt et enregistre les valuer dans la structure CONFIG
    fichier = fopen("../Config.txt", "r");
    if (fichier != NULL)
    {
        strcpy(*Erreur,"Erreur : NULL");
        fscanf(fichier, "[1] Nombre de mots clé : %d\n[2] Similarité : %d\n[3] Nombre de bits : %d\n[4] Nombre de fenetre : %d\n[5] Intervale de temps : %d", &config.Nb_Mots_Cle, &config.Similariter, &config.Nb_Bit_Fort, &config.Nb_Fenetre, &config.Intervale);
    }
    else
    {
        strcpy(*Erreur,"Erreur : Fichier introuvable");
    }
    fclose(fichier);
    return config;
}

void Afficher_CONFIG(CONFIG config)
{
    printf("Nombre de mots cle = %d\n", config.Nb_Mots_Cle);
    printf("Similariter = %d\n", config.Similariter);
    printf("Niveau = %d\n", config.Nb_Bit_Fort);
    printf("Nombre de fenetre = %d\n", config.Nb_Fenetre);
    printf("Intervale = %d\n", config.Intervale);
}

CONFIG Lire_mot_cle( String *Erreur, CONFIG config)
{
    // Variable
    int tmp;

    // Verifie si la valeur entrer est valide
    if (!scanf("%d", &tmp))
    {
        strcpy(*Erreur,"Erreur : Pas un nombre");
        viderBuffer();
    }
    else if (tmp <= 0)
    {
        strcpy(*Erreur,"Erreur : Nombre inferieur a 0");
    }
    else
    {
        strcpy(*Erreur,"Erreur : NULL");
        config.Nb_Mots_Cle = tmp;
    }
    
    return config;
}

CONFIG Lire_similariter( String *Erreur, CONFIG config)
{
    // Variable
    int tmp;

    // Verifie si la valeur entrer est valide
    if (!scanf("%d", &tmp))
    {
       strcpy(*Erreur,"Erreur : Pas un nombre");
        viderBuffer();
    }
    else if (tmp <= 0)
    {
       strcpy(*Erreur,"Erreur : Nombre inferieur a 0");
    }
    else if (tmp >= 100)
    {
       strcpy(*Erreur,"Erreur : Nombre superieur a 0");
    }
    else
    {
        strcpy(*Erreur,"Erreur : NULL");
        config.Similariter = tmp;
    }
    return config;
}

CONFIG Lire_nb_bit_fort(String *Erreur, CONFIG config)
{
    // Variable
    int tmp;

    // Verifie si la valeur entrer est valide
    if (!scanf("%d", &tmp))
    {
        strcpy(*Erreur,"Erreur : Pas un nombre");
        viderBuffer();
    }
    else if (tmp <= 0)
    {
        strcpy(*Erreur,"Erreur : Nombre inferieur a 0");
    }
    else if (tmp >= 8)
    {
        strcpy(*Erreur,"Erreur : Nombre superieur a 8");
    }
    return config;
}

CONFIG Lire_nb_fenetre(String *Erreur, CONFIG config)
{
    // Varaible
    int tmp;
    double tmp2;

    // Verifie si la valeur entrer est valide
    if (!scanf("%d", &tmp))
    {
        strcpy(*Erreur,"Erreur : Pas un nombre");
        viderBuffer();
    }
    else if (tmp <= 256)
    {
        strcpy(*Erreur,"Erreur : Nombre inferieur a 256");
    }
    else
    {
        tmp2 = log2((double)tmp);
        if (tmp2 == (int)tmp2)
        {
            strcpy(*Erreur,"Erreur : NULL");
            config.Nb_Bit_Fort = tmp;
        }
        else
        {
           strcpy(*Erreur,"Erreur : Pas une puissance de 2");
        }
    }
    return config;
}

CONFIG Lire_intervale(String *Erreur,CONFIG config)
{
    // Variable
    int tmp;

    // Verifie si la valeur entrer est valide
    if (!scanf("%d", &tmp))
    {
        strcpy(*Erreur,"Erreur : Pas un nombre");
        viderBuffer();
    }
    else if (tmp <= 0)
    {
       strcpy(*Erreur,"Erreur : Nombre inferieur a 0");
    }
    else
    {
       strcpy(*Erreur,"Erreur : NULL");
        config.Intervale = tmp;
    }
    return config;
}

void Ecrire_CONFIG( String *Erreur, CONFIG config)
{
    // Variable
    FILE *fichier = NULL;

    fichier = fopen("../Config.txt", "w");
    if (fichier != NULL)
    {
        strcpy(*Erreur,"Erreur : NULL");
        fprintf(fichier, "[1] Nombre de mots clé : %d\n[2] Similarité : %d\n[3] Nombre de bits : %d\n[4] Nombre de fenetre : %d\n[5] Intervale de temps : %d", config.Nb_Mots_Cle, config.Similariter, config.Nb_Bit_Fort, config.Nb_Fenetre, config.Intervale);
    }
    else
    {
        strcpy(*Erreur,"Erreur : Fichier introuvable");
    }
    fclose(fichier);
}
