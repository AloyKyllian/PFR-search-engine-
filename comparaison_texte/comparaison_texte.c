#include "../descripteur_texte/descripteur_texte.h"


// Récupérer chemin en entré

// Descripteur texte nouveau fichier

//Je regard les mots du premeir tableau


//Je regarde s'il existe dans le deuxième et je soustrais


// 



void comparaison(int seuil,int nbr_mot,char* chemin_fichier_a_compare,char* chemin_descripteur)
{
char * mot_lu;
int id_lu;
DESCRIPTEUR_TEXTE tab1;
DESCRIPTEUR_TEXTE tab2;

tab1=descripteur_texte_finale(chemin_fichier_a_compare,nbr_mot,tab1);


    FILE* fichier = NULL;
    fichier = fopen(chemin_descripteur, "r");                           //Ouverture du texte à traiter
    if(fichier==NULL){
        printf("Erreur lors de l'ouverture d'un fichier");
        exit(1);
    }

    while(scanf("%d",id_lu)!=EOF)
    {
            tab[j].id=id_lu;
            for(int i=0;i<nbr_mot;i++)
            {
                scanf("%s    |    %d\n",tab2.tab_mot[i], tab2.tab_app[i]);
            }


            verif_seuil=comparaison
            if(verif_seuil>seuil)
           tab[j].pourcentage = verif_seuil;
            j++;




    }





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