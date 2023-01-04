#include "../descripteur_texte/descripteur_texte.h"


// Récupérer chemin en entré

// Descripteur texte nouveau fichier

//Je regard les mots du premeir tableau


//Je regarde s'il existe dans le deuxième et je soustrais


// 



DESCRIPTEUR_TEXTE descripteur_texte_nv(DESCRIPTEUR_TEXTE tab_renv)
{
    bool passe;
    char mot_lu[100];
    int nbr_mot;
    FILE* fichier = NULL;
    fichier = fopen(chemin_fichier, "r");                           //Ouverture du texte à traiter
    if(fichier==NULL){
        printf("Erreur lors de l'ouverture d'un fichier");
        exit(1);
    }

    while(mot_lu[0]!='<' || mot_lu[1]!='t' || mot_lu[2]!='e')//permet de sauter le début du fichier
    {
        fscanf(fichier,"%s",mot_lu);
    }

    while(fscanf(fichier,"%s",mot_lu)!=EOF)
    {
        nbr_mot++;
    }
    
    rewind(fichier);

    DESCRIPTEUR_TEXTE tab;
    tab.index=0;
    tab.tab_mot = malloc(nbr_mot * sizeof(*tab.tab_mot));//creation du tableau
    tab.tab_app = malloc(nbr_mot * sizeof(*tab.tab_app));//creation du tableau

    for(int i=0;i<nbr_mot;i++)
    {
        strcpy(tab.tab_mot[i],"");
    }

    char *mot;
 
    while(mot_lu[0]!='<' || mot_lu[1]!='t' || mot_lu[2]!='e')//permet de sauter le début du fichier
    {
        fscanf(fichier,"%s",mot_lu);
    }

    while(fscanf(fichier,"%s",mot_lu)!=EOF)
    {
        mot = nettoyage(mot_lu);
        passe=filtrage(mot);
        if(passe==true)
        {
            tab=descripteur_texte(nbr_mot,mot,tab);

        }
        return tab;
    }



}


DESCRIPTEUR_TEXTE recup_descripteur(DESCRIPTEUR_TEXTE tab1, chemin)
{
    bool passe;
    char mot_lu[100];
    int nbr_mot;
    FILE* fichier = NULL;
    fichier = fopen(chemin_fichier, "r");                           //Ouverture du texte à traiter
    if(fichier==NULL){
        printf("Erreur lors de l'ouverture d'un fichier");
        exit(1);
    }

    while(mot_lu[0]!='<' || mot_lu[1]!='t' || mot_lu[2]!='e')//permet de sauter le début du fichier
    {
        fscanf(fichier,"%s",mot_lu);
    }

    while(fscanf(fichier,"%s",mot_lu)!=EOF)
    {
        nbr_mot++;
    }


    return tab1;
}


void comparaison(DESCRIPTEUR_TEXTE tab1,DESCRIPTEUR_TEXTE tab2)
{
    int comp=0;
    int cpt=0;
    int pourc=0;
    for(int i =0;i<nbr_mot; i++)
    {
        for(int j=0;j<nbr_mot;j++)
        {
            if(strcmp(tab1.tab_mot[i],tab2.tab_mot[j]))
            {
                comp = abs(tab1.tab_app[i]-tab2.tab_app[j]);
                if(0<comp<3)
                {
                    cpt++;
                }
            }
        }
    } 
    pourc= cpt/nbr_mot *100;
    printf("Similarité : %d %", pourc);

}