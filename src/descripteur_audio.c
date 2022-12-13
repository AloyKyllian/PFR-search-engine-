#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
//#include "Global.h"

void Descripteur_audio(int fenetre,int intervalle,char *chemin_fichier,void* tableau){//demander comment recuperer le chemin et nom du fichier
    double pas;
    int fe=0;//(nombre de fenetre)
    int nbr_val=0;
    int k;//(nbr_val_fenetre)
    int m;
    int i=0;
    double val;
    FILE* fichier = NULL;
    char c;
    int derrnier_fenetre;


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

    int tab[k][intervalle+1];
        if((nbr_val%fenetre)!=0)
    {
        printf("");
        derrnier_fenetre=nbr_val-fenetre;
        init_tableau(tab,k,intervalle+1);
    }
    else
    {
        init_tableau(tab,k,intervalle);
    }
    
    printf("k=%d",k);
    k=0;
    pas=2./intervalle;

    affiche_tableau(tab,k,intervalle);

    printf("k=%d\n%d\n%d\n%d\n%f\n",k,nbr_val,fenetre,intervalle,pas);

    rewind(fichier);
 
 

    while(fscanf(fichier,"%lf",&val)!=EOF){

        if(i==fenetre)
        {
            i=0;
            k++;
        }

        if(nbr_val<=fenetre)
        {
            for(m=0;-1+m*pas<=1;m++)
            {
                    //printf("%d\r\n",m);
                if(val>-1+pas*m && val<=-1+pas*(m+1))
                {
                
                    if(val<1&&val>-1&&m<intervalle)
                        tab[k+1][m]++;
                }
                
            }
        }
          
        for(m=0;-1+m*pas<=1;m++)
        {
                //printf("%d\r\n",m);
            if(val>-1+pas*m && val<=-1+pas*(m+1))
            {
             
                if(val<1&&val>-1&&m<intervalle)
                    tab[k][m]++;
            }
               
        }
        i++;
        nbr_val--;
    }
    fclose(fichier);

    tableau=tab;

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


void init_tableau(int (*tab)[2], int n, int m)
{
    for (unsigned i = 0; i < n; ++i)
    {
        //printf("%d",i);//afficher le numero de fenetre
        for (unsigned j = 0; j < m; ++j)
        {
            tab[i][j]=0;
            printf(" |%3d| ",tab[i][j]);
        }
        printf("\r\n");
    }
}



void main(){
    void* tab;
    Descripteur_audio(1024,30,"../son/jingle_fi.txt",tab);
    printf("\n\n\n\n\n");

   // printf("%ls",(int * )tab);

    //affiche_tableau((int *)tab,10,10);
}
