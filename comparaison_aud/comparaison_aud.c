#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "../head/descript_audio.h"



void comparaison_audio(int fenetre,int intervalle,descri_audio descri,char* chemin_descripteur_audio){

    int nbr_val;
    int val_lu;
    FILE* fichier = NULL;
    fichier = fopen(chemin_descripteur_audio, "r");
    if(fichier==NULL){
        printf("Erreur lors de l'ouverture d'un fichier");
        exit(1);
    }
    int lig=0;
    int col=0;
    int bonneval=0;
    float pourcentage;

int ligne=0;
int colonne=0;
    descri_audio descripteur_comparé;
    descripteur_comparé.tab = malloc(10000 * sizeof(*descripteur_comparé.tab));//creation du tableau
    for (int i = 0; i <= 10000; i++)
    {
        descripteur_comparé.tab[i] = malloc(10000 * sizeof(**descripteur_comparé.tab));
    }



    while(fscanf(fichier,"%d",&val_lu)!=EOF)//permet de sauter l'entet du fichier
    {
        while(val_lu>=0)
        {
            descripteur_comparé.tab[ligne][colonne]=val_lu;
            ligne++;
            colonne++;
        }

    for (unsigned i = 0; i < ligne; ++i)
    {
        for (unsigned j = 0; j < colonne; ++j)
        {
            printf(" |%3d| ",descripteur_comparé.tab[i][j]);
        }
        printf("\r\n");
    }





        /*if(nbr_val%intervalle==0)//renvient a la ligne 
        {
            col=0;
            lig++;
        }
        if(descri.size_x<lig)
        {
            lig=0;
        }
        if(val_lu<0)//nouveau descripteur
        {
           pourcentage = bonneval/nbr_val*100;

            nbr_val=0;
            col=0;
            lig=0;
        }
        if(val_lu==descri.tab[lig][col])//valeur bonne
        {
            bonneval++;
        }
        nbr_val++;*/
    }






}





void main (){


printf("hello world");
    int nbr_val;
    int val_lu;
    FILE* fichier = NULL;
    fichier = fopen("../descrripteur_texte_type.txt", "r");
    if(fichier==NULL){
        printf("Erreur lors de l'ouverture d'un fichier");
        exit(1);
    }
    int lig=0;
    int col=0;
    int bonneval=0;
    float pourcentage;

int ligne=0;
int colonne=0;
    descri_audio descripteur_comparé;
    descripteur_comparé.tab = malloc(10000 * sizeof(*descripteur_comparé.tab));//creation du tableau
    for (int i = 0; i <= 10000; i++)
    {
        descripteur_comparé.tab[i] = malloc(10000 * sizeof(**descripteur_comparé.tab));
    }


    while(fscanf(fichier,"%d",&val_lu)!=EOF)//permet de sauter l'entet du fichier
    {
        printf("%d\n",val_lu);
        
        while(val_lu>=0)
        {
            //descripteur_comparé.tab[ligne][colonne]=val_lu;
            printf("%d\n",val_lu);
            ligne++;
            colonne++;
            fscanf(fichier,"%d",&val_lu);
        }
/*
    for (unsigned i = 0; i < ligne; ++i)
    {
        for (unsigned j = 0; j < colonne; ++j)
        {
            printf(" |%3d| ",descripteur_comparé.tab[i][j]);
        }
        printf("\r\n");
    }


printf("hello world");
*/
}

}