#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
//#include "Global.h"

char Descripteur_audio(int fenetre,int intervalle,char *chemin_fichier){//demander comment recuperer le chemin et nom du fichier
    double pas;
    int fe=0;//(nombre de fenetre)
    int nbr_val=0;
    int k;//(nbr_val_fenetre)
    int m;
    int i=0;

    double val;
    FILE* fichier = NULL;
    char c;


    //chemin_fichier="../son/jingle_fi.txt";

    fichier = fopen(chemin_fichier, "r");
    if(fichier==NULL){                           
        printf("Erreur lors de l'ouverture d'un fichier");
        exit(1);
    }


    while(fscanf(fichier,"%lf",&val)!=EOF){
        nbr_val++;
    }


    k=nbr_val/fenetre;
    int tab[k][intervalle];
    k=0;
    pas=2./intervalle;

    rewind(fichier);
 

    while(fscanf(fichier,"%lf",&val)!=EOF){

        if(i==fenetre)
        {
            i=0;
            k++;
        }
          
        for(m=0;-1+m*pas<=1;m++)
        {
             
            if(val>-1+pas*m && val<=-1+pas*(m+1))
            {
                 tab[k][m]++;
            }
               
        }
        i++;
    }

    fclose(fichier);

   affiche_tableau(tab,k,m);

}


void affiche_tableau(int (*tab)[2], int n, int m)
{
    for (unsigned i = 0; i < n; ++i)
    {
        //printf("%d",i);//afficher le numero de fenetre
        for (unsigned j = 0; j < m; ++j)
        {
            printf(" |%3d| ",tab[i][j]);
        }
        printf("\r\n");
    }
}


/*

void main(){
    Descripteur_test(1024,30,"../son/jingle_fi.txt");
}
*/