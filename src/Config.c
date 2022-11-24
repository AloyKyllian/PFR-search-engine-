#include "../head/Config.h"
#include "../head/Config.h"

//Work
CONFIG Lire_CONFIG()
{
    CONFIG config;
    FILE* fichier = NULL;

    fichier = fopen("../Config.txt","r");
    if(fichier != NULL)
    {
        fscanf(fichier, "[1] Nombre de mots clé : %d\n[2] Similarité : %d\n[3] Niveau : %d\n[4] Nombre de fenetre : %d\n[5] Intervale de temps : %f",&config.nb_mots_cle,&config.similariter,&config.niveau,&config.nb_fenetre,&config.intervale);
    }
    else
    {
        printf("Erreur !\nImpossible d'ouvrir le fichier Config.txt");
    }

    return config;

}

//Work
void Afficher_CONFIG(CONFIG config)
{
    printf("Nombre de mots cle = %d\n",config.nb_mots_cle);
    printf("Similariter = %d\n",config.similariter);
    printf("Niveau = %d\n",config.niveau);
    printf("Nombre de fenetre = %d\n",config.nb_fenetre);
    printf("Intervale = %f\n",config.intervale);
}

//Work
CONFIG Lire_mot_cle(CONFIG config)
{
    int tmp;
    printf("\nEntrer le nouveau nombre de mots cle (superieur a 0)\n");
    while (1)
    {
        if(!scanf("%d",&tmp))
        {
            printf("Erreur !\nIl faut rentrer un nombre\n");
            viderBuffer();
        }
        else if(tmp <= 0)
        {
            printf("Erreur !\nIl faut un nombre superieur a 0\n");
        }
        else
        {
            config.nb_mots_cle = tmp;
            return config;
        } 
    }
}

//Work
CONFIG Lire_similariter(CONFIG config)
{
    int tmp;
    printf("\nEntrer le pourcentage de similarite (entre 0 et 100)\n");
    while (1)
    {
        if(!scanf("%d",&tmp))
        {
            printf("Erreur !\nIl faut rentrer un nombre\n");
            viderBuffer();
        }
        else if(tmp <= 0 || tmp >= 100)
        {
            printf("Erreur !\nIl faut un nombre entre 0 et 100\n");
        }
        else
        {
            config.similariter = tmp;
            return config;
        } 
    }
}

//Work
CONFIG Lire_niveau(CONFIG config)
{
    int tmp;
    double tmp2;
    printf("\nEntrer le nouveau nombre de niveau (doit etre une puissance de deux entre 0 et 256)\n");
    while (1)
    {
        if(!scanf("%d",&tmp))
        {
            printf("Erreur !\nIl faut rentrer un nombre\n");
            viderBuffer();
        }
        else if(tmp >= 256 || tmp <=0)
        {
            printf("Erreur !\nIl faut un nombre entre 0 et 256\n");
        }
        else 
        {
            tmp2 = log2((double)tmp);
		    if(tmp2 == (int)tmp2)
            {
                config.niveau = tmp;
                return config;
            }
            else
            {
                printf("Erreur !\nIl faut une puissance de 2\n");
            }
        } 
    }
}

//Work
CONFIG Lire_nb_fenetre(CONFIG config)
{
    int tmp;
    printf("\nEntrer le nouveau nombre fenetre (superieur a 0)\n");
    while (1)
    {
        if(!scanf("%d",&tmp))
        {
            printf("Erreur !\nIl faut rentrer un nombre\n");
            viderBuffer();
        }
        else if(tmp <= 0)
        {
            printf("Erreur !\nIl faut un nombre superieur a 0\n");
        }
        else
        {
            config.nb_fenetre = tmp;
            return config;
        } 
    }
}

//Work
CONFIG Lire_intervale(CONFIG config)
{
    float tmp;
    printf("\nEntrer l'intevale\n");
    while (1)
    {
        if(!scanf("%f",&tmp))
        {
            printf("Erreur !\nIl faut rentrer un nombre\n");
            viderBuffer();
        }
        else if(tmp <= 0)
        {
            printf("Erreur !\nIl faut un nombre superieur a 0\n");
        }
        else
        {
            printf("%f",tmp);
            config.intervale = tmp;
            return config;
        } 
    }
}

//Work
void Ecrire_CONFIG(CONFIG config)
{
    FILE* fichier = NULL;

    fichier = fopen("../Config.txt","w");
    if(fichier != NULL)
    {
        fprintf(fichier, "[1] Nombre de mots clé : %d\n[2] Similarité : %d\n[3] Niveau : %d\n[4] Nombre de fenetre : %d\n[5] Intervale de temps : %f",config.nb_mots_cle,config.similariter,config.niveau,config.nb_fenetre,config.intervale);
    }
    else
    {
        printf("Erreur !\nImpossible d'ouvrir le fichier Config.txt");
    }
}

