#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
//#include "Global.h"
typedef double tab_intervalle[];

char Descripteur_test(int fenetre,int intervalle){
    double pas;
    int fe=0;
    int nbr_val;
    int k;//(nbr_val_fenetre)
    double tab_valeur[1000000];
int y;
int i=0;

    double val;
    FILE* fichier = NULL;
    char c;
    fichier = fopen("../son/corpus_fi.txt", "r");


        if(fichier==NULL){
                                            
        printf("Erreur lors de l'ouverture d'un fichier");
       exit(1);
        }

    nbr_val=0;

    while(fscanf(fichier,"%lf",&val)!=EOF){
        nbr_val++;
        //printf("%.10lf\r\n",val);
    }

    

    printf("%d\r\n",nbr_val);
    k=nbr_val/fenetre;
    int tab[k][intervalle];
    pas=2./intervalle;
    printf("%d\r\n",k);
    printf("%.10lf\r\n",pas);

    rewind(fichier);

    while(fscanf(fichier,"%lf",&val)!=EOF){

        if(i==fenetre)
            fe++;
        for(y=0;y*pas<=1;y++)
        {
             
            if(val>-1+pas*y && val<-1+pas*(y+1))
            {
                 tab[fe][y]++;
            }
               
        }
        i++;
    }

    fclose(fichier);

   affiche_tableau(tab,fe,y);
/*
    for(int i=0;i<=nbr_val;i++)
    {
        if(i==fenetre)
            fe++;
        for(y=0;y*pas<=1;y++)
        {
             
            if(tab_valeur[i]>-1+pas*y && tab_valeur[i]<-1+pas*(y+1))
                a++;
                //tab[fe][y]++;
        }
         
    }

  



  
*/
}


void affiche_tableau(int (*tab)[2], int n, int m)
{
    for (unsigned i = 0; i < n; ++i)
        for (unsigned j = 0; j < m; ++j)
            printf("tab[%u][%u] = %d\n", i, j, tab[i][j]);
}




void main(){
    Descripteur_test(1024,30);
}
