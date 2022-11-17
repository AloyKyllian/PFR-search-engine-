#include <stdlib.h>
#include <stdio.h>
#include "../head/Config.h"

CONFIG Lire_CONFIG()
{
    CONFIG config;
    FILE* fichier = NULL;
    int nb_utilisateur = 0;
    int nb_administrateur = 0;

    char chaine[20];
    fichier = fopen("../Config.txt","r");
    if(fichier != NULL)
    {
        fscanf(fichier, "[1] Nombre de mots clé : %d\n[2] Similarité : %d\n[3] Niveau : %d\n[4] Informations Utilisateur :\n\t- Nom1 : %s MDP1 : %s Nom2 : %s MDP2 : %s Nom3 : %s MDP3 : %s Nom4 : %s MDP4 : %s Nom5 : %s MDP5 : %s\n[5] Informations Administrateur :\n\t- Nom1 : %s MDP1 : %s Nom2 : %s MDP2 : %s Nom3 : %s MDP3 : %s Nom4 : %s MDP4 : %s Nom5 : %s MDP5 : %s",&config.nb_mots_cle,&config.similariter,&config.niveau,&config.nom_utilisateur[0].chaine,&config.mdp_utilisateur[0].chaine,&config.nom_utilisateur[1].chaine,&config.mdp_utilisateur[1].chaine,&config.nom_utilisateur[2].chaine,&config.mdp_utilisateur[2].chaine,&config.nom_utilisateur[3].chaine,&config.mdp_utilisateur[3].chaine,&config.nom_utilisateur[4].chaine,&config.mdp_utilisateur[4].chaine,&config.nom_admin[0].chaine,&config.mdp_admin[0].chaine,&config.nom_admin[1].chaine,&config.mdp_admin[1].chaine,&config.nom_admin[2].chaine,&config.mdp_admin[2].chaine,&config.nom_admin[3].chaine,&config.mdp_admin[3].chaine,&config.nom_admin[4].chaine,&config.mdp_admin[4].chaine);
    }
    else
    {
        printf("Impossible d'ouvrir le fichier Config.txt");
    }

    return config;

}

void afficher_CONFIG(CONFIG config)
{
    printf("nb_mots_cle = %d\n",config.nb_mots_cle);
    printf("similariter = %d\n",config.similariter);
    printf("niveau = %d\n",config.niveau);

    printf("Informations Utilisateur :\n");
    printf("Nom1 = %s\tMDP1 = %s\n",config.nom_utilisateur[0].chaine,config.mdp_utilisateur[0].chaine);
    printf("Nom2 = %s\tMDP2 = %s\n",config.nom_utilisateur[1].chaine,config.mdp_utilisateur[1].chaine);
    printf("Nom3 = %s\tMDP3 = %s\n",config.nom_utilisateur[2].chaine,config.mdp_utilisateur[2].chaine);
    printf("Nom4 = %s\tMDP4 = %s\n",config.nom_utilisateur[3].chaine,config.mdp_utilisateur[3].chaine);
    printf("Nom5 = %s\tMDP5 = %s\n",config.nom_utilisateur[4].chaine,config.mdp_utilisateur[4].chaine);

    printf("Informations Administrateur :\n");
    printf("Nom1 = %s\tMDP1 = %s\n",config.nom_admin[0].chaine,config.mdp_admin[0].chaine);
    printf("Nom2 = %s\tMDP2 = %s\n",config.nom_admin[1].chaine,config.mdp_admin[1].chaine);
    printf("Nom3 = %s\tMDP3 = %s\n",config.nom_admin[2].chaine,config.mdp_admin[2].chaine);
    printf("Nom4 = %s\tMDP4 = %s\n",config.nom_admin[3].chaine,config.mdp_admin[3].chaine);
    printf("Nom5 = %s\tMDP5 = %s\n",config.nom_admin[4].chaine,config.mdp_admin[4].chaine);
}

void main()
{
    CONFIG config;
    config = Lire_CONFIG();
    afficher_CONFIG(config);
}