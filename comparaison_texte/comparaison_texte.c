#include "../descripteur_texte/descripteur_texte.h"

typedef struct
{
    int id;
    float pourcentage;
} tab_similaire;

void comparaison(int nbr_mot,char* chemin_fichier_a_compare,char* chemin_descripteur,int * Erreur)
{
char * mot_lu;
int id_lu;    
int comp=0;
float cpt=0;
int pourc=0;
int j=0;
DESCRIPTEUR_TEXTE tab1;
DESCRIPTEUR_TEXTE tab2;
String temp;
tab2.tab_mot = malloc(nbr_mot * sizeof(*tab2.tab_mot));//creation du tableau
tab2.tab_app = malloc(nbr_mot * sizeof(*tab2.tab_app));//creation du tableau
tab1=descripteur_texte_finale(chemin_fichier_a_compare,nbr_mot,tab1);

    if(tab2.tab_mot !=NULL && tab2.tab_app != NULL)
    {
        FILE* fichierD = NULL;
        tab_similaire tab[nbr_mot];
        fichierD = fopen(chemin_descripteur, "r");                           //Ouverture du texte à traiter
        if(fichierD==NULL)
        {
            *Erreur = 7;                                                //Erreur lors de l'ouverture d'un fichier
            exit(1);
        }
        while(fscanf(fichierD,"%d",&id_lu)!=EOF)
        {
            tab[j].id=id_lu;                                        //Récupération de l'ID
            for(int i=0;i<nbr_mot;i++)
            {
                fscanf(fichierD,"%s    |    %d",tab2.tab_mot[i],&tab2.tab_app[i]);      //Remplir un tableau avec les mots et leur nombre d'apparition présent dans les descripteurs
                printf("%s    |    ",tab2.tab_mot[i]);
                printf("%d\n",tab2.tab_app[i]);
        
            }
            j++;
            for(int v =0;v<nbr_mot; v++)
            {
                for(int y=0;y<nbr_mot;y++)
                {   
                    if(strcmp(tab1.tab_mot[v],tab2.tab_mot[y])==0)                      //Comparaison des deux tableaux pour trouver les mots en commun
                    {
                        comp = abs(tab1.tab_app[v]-tab2.tab_app[y]);                    //Valeur absolue entre le nombre d'apparition de chaque tableau pour le meme mot
                        if(0<comp<3)
                        {
                            cpt++;                                                      //Si le mot apparaît à 3 près pour les deux textes on augmente un compteur
                        }
                    }
                 }
            }     
            tab->pourcentage= cpt/nbr_mot *100;                                     // Calcul pourcentage nombre de mot correspondant / nombre de mot total *100
            printf("Similarite : %f pourcent", tab->pourcentage);
        }
        fclose(fichierD);
    }
    else
    {
        *Erreur=1;                      //Erreur Allocation
        exit(1);
    }
}

int main()
{
    int* Erreur;
    comparaison(10,"../texte/Textes_UTF8/03-Mimer_un_signal_nerveux_pour_utf8.xml","michel.txt",Erreur);
}