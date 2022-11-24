#include "../head/Config.h"
#include "../head/Config.h"

CONFIG Lire_CONFIG(String *Erreur)
{
    CONFIG config;
    FILE *fichier = NULL;

    fichier = fopen("../Config.txt", "r");
    if (fichier != NULL)
    {
        strcpy(Erreur->chaine,"Erreur : NULL");
        fscanf(fichier, "[1] Nombre de mots clé : %d\n[2] Similarité : %d\n[3] Niveau : %d\n[4] Nombre de fenetre : %d\n[5] Intervale de temps : %f", &config.nb_mots_cle, &config.similariter, &config.niveau, &config.nb_fenetre, &config.intervale);
    }
    else
    {
        strcpy(Erreur->chaine,"Erreur : Fichier introuvable");
    }

    return config;
}

void Afficher_CONFIG(CONFIG config)
{
    printf("Nombre de mots cle = %d\n", config.nb_mots_cle);
    printf("Similariter = %d\n", config.similariter);
    printf("Niveau = %d\n", config.niveau);
    printf("Nombre de fenetre = %d\n", config.nb_fenetre);
    printf("Intervale = %f\n", config.intervale);
}

CONFIG Lire_mot_cle(CONFIG config, String *Erreur)
{
    int tmp;
    if (!scanf("%d", &tmp))
    {
        strcpy(Erreur->chaine,"Erreur : Pas un nombre");
        viderBuffer();
    }
    else if (tmp <= 0)
    {
        strcpy(Erreur->chaine,"Erreur : Nombre inferieur a 0");
    }
    else
    {
        strcpy(Erreur->chaine,"Erreur : NULL");
        config.nb_mots_cle = tmp;
    }
    return config;
}

CONFIG Lire_similariter(CONFIG config, String *Erreur)
{
    int tmp;
    if (!scanf("%d", &tmp))
    {
       strcpy(Erreur->chaine,"Erreur : Pas un nombre");
        viderBuffer();
    }
    else if (tmp <= 0)
    {
       strcpy(Erreur->chaine,"Erreur : Nombre inferieur a 0");
    }
    else if (tmp >= 100)
    {
       strcpy(Erreur->chaine,"Erreur : Nombre superieur a 0");
    }
    else
    {
        strcpy(Erreur->chaine,"Erreur : NULL");
        config.similariter = tmp;
    }
    return config;
}

CONFIG Lire_niveau(CONFIG config, String *Erreur)
{
    int tmp;
    double tmp2;
    if (!scanf("%d", &tmp))
    {
        strcpy(Erreur->chaine,"Erreur : Pas un nombre");
        viderBuffer();
    }
    else if (tmp <= 0)
    {
        strcpy(Erreur->chaine,"Erreur : Nombre inferieur a 0");
    }
    else if (tmp >= 256)
    {
        strcpy(Erreur->chaine,"Erreur : Nombre superieur a 256");
    }
    else
    {
        tmp2 = log2((double)tmp);
        if (tmp2 == (int)tmp2)
        {
            strcpy(Erreur->chaine,"Erreur : NULL");
            config.niveau = tmp;
        }
        else
        {
           strcpy(Erreur->chaine,"Erreur : Pas une puissance de 2");
        }
    }
    return config;
}

CONFIG Lire_nb_fenetre(CONFIG config, String *Erreur)
{
    int tmp;
    if (!scanf("%d", &tmp))
    {
        strcpy(Erreur->chaine,"Erreur : Pas un nombre");
        viderBuffer();
    }
    else if (tmp <= 0)
    {
        strcpy(Erreur->chaine,"Erreur : Nombre inferieur a 0");
    }
    else
    {
       strcpy(Erreur->chaine,"Erreur : NULL");
        config.nb_fenetre = tmp;
    }
    return config;
}

CONFIG Lire_intervale(CONFIG config, String *Erreur)
{
    float tmp;
    if (!scanf("%f", &tmp))
    {
        strcpy(Erreur->chaine,"Erreur : Pas un nombre");
        viderBuffer();
    }
    else if (tmp <= 0)
    {
       strcpy(Erreur->chaine,"Erreur : Nombre inferieur a 0");
    }
    else
    {
       strcpy(Erreur->chaine,"Erreur : NULL");
        config.intervale = tmp;
    }
    return config;
}

void Ecrire_CONFIG(CONFIG config, String *Erreur)
{
    FILE *fichier = NULL;

    fichier = fopen("../Config.txt", "w");
    if (fichier != NULL)
    {
        strcpy(Erreur->chaine,"Erreur : NULL");
        fprintf(fichier, "[1] Nombre de mots clé : %d\n[2] Similarité : %d\n[3] Niveau : %d\n[4] Nombre de fenetre : %d\n[5] Intervale de temps : %f", config.nb_mots_cle, config.similariter, config.niveau, config.nb_fenetre, config.intervale);
    }
    else
    {
        strcpy(Erreur->chaine,"Erreur : Fichier introuvable");
    }
}
