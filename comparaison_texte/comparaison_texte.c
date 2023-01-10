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

void comparaison(int nbr_mot,char* chemin_fichier_a_compare,char* chemin_descripteur)
{
char * mot_lu;
int id_lu;
DESCRIPTEUR_TEXTE tab1;
DESCRIPTEUR_TEXTE tab2;
String temp;
tab2.tab_mot = malloc(nbr_mot * sizeof(*tab2.tab_mot));//creation du tableau
tab2.tab_app = malloc(nbr_mot * sizeof(*tab2.tab_app));//creation du tableau
tab1=descripteur_texte_finale(chemin_fichier_a_compare,nbr_mot,tab1);

    int comp=0;
    float cpt=0;
    int pourc=0;
    int j=0;
    FILE* fichierD = NULL;
    tab_similaire tab[nbr_mot];
    fichierD = fopen(chemin_descripteur, "r");                           //Ouverture du texte à traiter
    if(fichierD==NULL){
        printf("Erreur lors de l'ouverture d'un fichier test");
        exit(1);
    }
    /*fscanf(fichierD,"%d",&id_lu);
    printf("id : %d\n",id_lu);
    fscanf(fichierD,"%s",mot_lu);
    printf("id : %s\n",mot_lu);
    fscanf(fichierD,"%s",mot_lu);
    printf("id : %s\n",mot_lu);
    fscanf(fichierD,"%s",mot_lu);
    printf("id : %s\n",mot_lu);*/
    
   while(fscanf(fichierD,"%d",&id_lu)!=EOF)
    {
        tab[j].id=id_lu;
        for(int i=0;i<nbr_mot;i++)
        {
            fscanf(fichierD,"%s    |    %d",tab2.tab_mot[i],&tab2.tab_app[i]);
        printf("%s    |    ",tab2.tab_mot[i]);
        printf("%d\n",tab2.tab_app[i]);
        
        }
        j++;
    for(int v =0;v<nbr_mot; v++)
    {
        for(int y=0;y<nbr_mot;y++)
        {
            
            if(strcmp(tab1.tab_mot[v],tab2.tab_mot[y])==0)
            {
                printf("premier mot :%s",tab1.tab_mot[v]);
            printf("deux mot :%s\n",tab2.tab_mot[y]);
                comp = abs(tab1.tab_app[v]-tab2.tab_app[y]);
                if(0<comp<3)
                {
                    cpt++;
                }
            }
        }
    }     
    printf("cpt : %f",cpt);
    printf("cpt : %d",nbr_mot);
    tab->pourcentage= cpt/nbr_mot *100;
    printf("Similarite : %f pourcent", tab->pourcentage);
    }
    fclose(fichierD);
    




           /* verif_seuil=comparaison
            if(verif_seuil>seuil)
           tab[j].pourcentage = verif_seuil;
            j++;*/

}

int main()
{
    comparaison(10,"../texte/Textes_UTF8/03-Mimer_un_signal_nerveux_pour_utf8.xml","michel.txt");
}