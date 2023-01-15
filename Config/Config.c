#include "../Config/Config.h"

//Lis Config.txt et renvoie les parametre dans la structure CONFIG
CONFIG Lire_CONFIG(int *Erreur)
{
    CONFIG config;
    FILE *fichier = NULL;

    fichier = fopen("../Config.txt", "r");
    if (fichier != NULL)
    {
        //strcpy(*Erreur,"Erreur : NULL");
        *Erreur=0;
        fscanf(fichier, "[1] Nombre de mots clé : %d\n[2] Similarité : %d\n[3] Niveau : %d\n[4] Nombre de fenetre : %d\n[5] Intervale de temps : %f", &config.nb_mots_cle, &config.similariter, &config.niveau, &config.nb_fenetre, &config.intervale);
    }
    else
    {
        //strcpy(*Erreur,"Erreur : Fichier introuvable");
        *Erreur=7;
    }
    fclose(fichier);

    return config;
}
//Affiche toute les valeur des parametres de configration
void Afficher_CONFIG(CONFIG config)
{
    printf("Nombre de mots cle = %d\n", config.nb_mots_cle);
    printf("Similariter = %d\n", config.similariter);
    printf("Niveau = %d\n", config.niveau);
    printf("Nombre de fenetre = %d\n", config.nb_fenetre);
    printf("Intervale = %f\n", config.intervale);
}
//Lis et verifie la validiter de la valeur du nombre de mots cle
CONFIG Lire_mot_cle(CONFIG config, int *Erreur)
{
    int tmp;
    
    if (!scanf("%d", &tmp))
    {
        //strcpy(*Erreur,"Erreur : Pas un nombre");
        *Erreur=9;
        viderBuffer();
    }
    else if (tmp <= 0)
    {
        //strcpy(*Erreur,"Erreur : Nombre inferieur a 0");
    }
    else
    {
        //strcpy(*Erreur,"Erreur : NULL");
        *Erreur=0;
        config.nb_mots_cle = tmp;
    }
    
    return config;
}
//Lis et verifie la validiter de la valeur de la similarite
CONFIG Lire_similariter(CONFIG config, int *Erreur)
{
    int tmp;
    if (!scanf("%d", &tmp))
    {
       //strcpy(*Erreur,"Erreur : Pas un nombre");
       *Erreur=9;
        viderBuffer();
    }
    else if (tmp <= 0)
    {
       //strcpy(*Erreur,"Erreur : Nombre inferieur a 0");
       *Erreur=2;
    }
    else if (tmp >= 100)
    {
       //strcpy(*Erreur,"Erreur : Nombre superieur a 0");
       *Erreur=4;
    }
    else
    {
        //strcpy(*Erreur,"Erreur : NULL");
        *Erreur=0;
        config.similariter = tmp;
    }
    return config;
}
//Lis et verifie la validiter de la valeur du niveau
CONFIG Lire_niveau(CONFIG config, int *Erreur)
{
    int tmp;
    double tmp2;
    if (!scanf("%d", &tmp))
    {
        //strcpy(*Erreur,"Erreur : Pas un nombre");
        *Erreur=9;
        viderBuffer();
    }
    else if (tmp <= 0)
    {
        //strcpy(*Erreur,"Erreur : Nombre inferieur a 0");
        *Erreur=2;
    }
    else if (tmp >= 256)
    {
        //strcpy(*Erreur,"Erreur : Nombre superieur a 256");
        *Erreur=3;
    }
    else
    {
        tmp2 = log2((double)tmp);
        if (tmp2 == (int)tmp2)
        {
            //strcpy(*Erreur,"Erreur : NULL");
            *Erreur=0;
            config.niveau = tmp;
        }
        else
        {
           //strcpy(*Erreur,"Erreur : Pas une puissance de 2");
           *Erreur=6;
        }
    }
    return config;
}
//Lis et verifie la validiter de la valeur du nombre de fenetre
CONFIG Lire_nb_fenetre(CONFIG config, int *Erreur)
{
    int tmp;
    if (!scanf("%d", &tmp))
    {
        //strcpy(*Erreur,"Erreur : Pas un nombre");
        *Erreur=9;
        viderBuffer();
    }
    else if (tmp <= 0)
    {
        //strcpy(*Erreur,"Erreur : Nombre inferieur a 0");
        *Erreur=2;
    }
    else
    {
       //strcpy(*Erreur,"Erreur : NULL");
       *Erreur=0;
        config.nb_fenetre = tmp;
    }
    return config;
}
//Lis et verifie la validiter de la valeur de l'intervale
CONFIG Lire_intervale(CONFIG config, int *Erreur)
{
    float tmp;
    if (!scanf("%f", &tmp))
    {
        //strcpy(*Erreur,"Erreur : Pas un nombre");
        *Erreur=9;
        viderBuffer();
    }
    else if (tmp <= 0)
    {
       //strcpy(*Erreur,"Erreur : Nombre inferieur a 0");
       *Erreur=2;
    }
    else
    {
       //strcpy(*Erreur,"Erreur : NULL");
       *Erreur=0;
        config.intervale = tmp;
    }
    return config;
}
//Ecrit dans Config.txt les valeur stocker dans la structure CONFIG
void Ecrire_CONFIG(CONFIG config, int *Erreur)
{
    FILE *fichier = NULL;

    fichier = fopen("../Config.txt", "w");
    if (fichier != NULL)
    {
        //strcpy(*Erreur,"Erreur : NULL");
        *Erreur=0;
        fprintf(fichier, "[1] Nombre de mots clé : %d\n[2] Similarité : %d\n[3] Niveau : %d\n[4] Nombre de fenetre : %d\n[5] Intervale de temps : %f", config.nb_mots_cle, config.similariter, config.niveau, config.nb_fenetre, config.intervale);
    }
    else
    {
        //strcpy(*Erreur,"Erreur : Fichier introuvable");
        *Erreur=7;
    }
    fclose(fichier);
}
