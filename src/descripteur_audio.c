#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "../head/Global.h"
//#include "Global.h"
#include "../head/descripteur_audio.h"

void Descripteur_audio(int fenetre,int intervalle,char *chemin_fichier,int* tableau){//demander comment recuperer le chemin et nom du fichier
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


    k=(nbr_val/fenetre)+1;

    printf("k=%d",k);

    int tab[k][intervalle];

    if((nbr_val%fenetre)!=0)
    {
        
        printf("la\r\n");
        derrnier_fenetre=nbr_val-fenetre;

    for (unsigned i = 0; i < k; ++i)
    {
        //printf("%d",i);//afficher le numero de fenetre
        for (unsigned j = 0; j < intervalle; ++j)
        {
           tab[i][j]=0;
           printf(" |%3d| ",tab[i][j]);
        }
        printf("\r\n");
    }

    printf("\r\n");
    printf("\r\n");
    printf("\r\n");
    printf("\r\n");

       
    }
    else
    {
    int tab[k][intervalle];
    for (unsigned i = 0; i < k; ++i)
    {
        //printf("%d",i);//afficher le numero de fenetre
        for (unsigned j = 0; j < intervalle; ++j)
        {
           tab[i][j]=0;
        }
        printf("\r\n");
    }

        //init_tableau(tab,k,intervalle);
    }
    

    k=0;
    
    pas=2./intervalle;

    rewind(fichier);
 

    while(fscanf(fichier,"%lf",&val)!=EOF){

        if(i==fenetre)
        {
            i=0;
            k++;
        }

        if(nbr_val<=fenetre)
        {
            for(m=0;-1+m*pas<1;m++)
            {

                if(val>=pas*m-1 && val<pas*(m+1)-1)
                {

                    if(val<1&&val>-1&&m<intervalle)
                        tab[k][m]++;
                }
                
            }
        }
          
        for(m=0;m<intervalle;m++)
        {
            if((val>=(pas*m-1)) && (val<(pas*(m+1)-1)))
            {
             
                if(val<1&&val>-1&&m<intervalle)
                    tab[k][m]++;
            }
               
        }
        i++;
        nbr_val--;
    }
    fclose(fichier);

printf("teste");

printf("%d\t",m);
printf("%d\n",k);

    for (unsigned i = 0; i < k; ++i)
    {
        for (unsigned j = 0; j < m; ++j)
        {
            printf(" |%3d| ",tab[i][j]);
        }
        printf("\r\n");
    }


    //tableau=tab;
}




void main(){
    int* tab;
    Descripteur_audio(2048,32,"../son/jingle_fi.txt",tab);
    //printf("%d",*tab);

   // printf("%ls",(int * )tab);S

    //affiche_tableau((int *)tab,10,10);
}
