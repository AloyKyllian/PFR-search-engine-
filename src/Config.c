#include <stdlib.h>
#include <stdio.h>

#define MAX_UTILISATEUR 5
#define MAX_CHAINE 100

typedef struct
{
    char chaine[MAX_CHAINE];
}String;

typedef struct
{
    
    int nb_mots_cle;
    int similariter;
    int niveau;
    String nom_utilisateur[MAX_UTILISATEUR];
    String nom_admin[MAX_UTILISATEUR];
    String mdp_utilisateur[MAX_UTILISATEUR];
    String mdp_admin[MAX_UTILISATEUR];

}CONFIG;

CONFIG Lire_Config()
{
    CONFIG config;
    FILE* fichier = NULL;
    int nb_utilisateur = 0;
    int nb_administrateur = 0;
    fichier = fopen("../Config.txt","r");
    if(fichier != NULL)
    {
        fscanf(fichier, "[1] Nombre de mots clé : %d",&config.nb_mots_cle);
        fscanf(fichier,"\n[2] Similarité : %d",&config.similariter);
        fscanf(fichier,"\n\n[3] Niveau : %d",&config.niveau);
        fscanf(fichier,"\n\n\n\n - Nom1 : %s MDP1 : %s Nom2 : %s MDP2 : %s Nom3 : %s MDP3 : %s Nom4 : %s MDP4 : %s Nom5 : %s MDP5 : %s",&config.nom_utilisateur[0].chaine,&config.nom_utilisateur[1],&config.nom_utilisateur[2],&config.nom_utilisateur[3],&config.nom_utilisateur[4]);



        fscanf(fichier,"\n\n\n\n\t1- %s %s",&config.nom_utilisateur[0], &config.mdp_utilisateur[0]);
        fscanf(fichier,"\n\n\n\n\n\t[3] Niveau : %d",&config.niveau);

        printf("%d\n%d\n%d",config.nb_mots_cle,config.similariter,config.niveau);
        printf("%s",config.nom_utilisateur[0]);

    }
    else
    {
        printf("Impossible d'ouvrir le fichier Config.txt");
    }

    return config;

}

void main()
{
    Lire_Config();
}