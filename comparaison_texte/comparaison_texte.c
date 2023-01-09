#include "../descripteur_texte/descripteur_texte.h"


// Récupérer chemin en entré

// Descripteur texte nouveau fichier

//Je regard les mots du premeir tableau


//Je regarde s'il existe dans le deuxième et je soustrais


// 

typedef struct
{
    int id;
    float pourcentage;
} tab_similaire;

void comparaison(int seuil,int nbr_mot,char* chemin_fichier_a_compare,char* chemin_descripteur)
{
char * mot_lu;
int id_lu;
DESCRIPTEUR_TEXTE tab1;
DESCRIPTEUR_TEXTE tab2;



tab1=descripteur_texte_finale(chemin_fichier_a_compare,nbr_mot,tab1);

    int comp=0;
    int cpt=0;
    int pourc=0;
    int j=0;
    FILE* fichier = NULL;
    tab_similaire tab[100];
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
        j++;
    }
    for(int v =0;v<nbr_mot; v++)
    {
        for(int y=0;y<nbr_mot;y++)
        {
            if(strcmp(tab1.tab_mot[v],tab2.tab_mot[y]))
            {
                comp = abs(tab1.tab_app[v]-tab2.tab_app[y]);
                if(0<comp<3)
                {
                    cpt++;
                }
            }
        }
    } 
    tab->pourcentage= cpt/nbr_mot *100;
    printf("Similarité : %d pourcent", pourc);



           /* verif_seuil=comparaison
            if(verif_seuil>seuil)
           tab[j].pourcentage = verif_seuil;
            j++;*/

}

int main()
{
    comparaison()
}