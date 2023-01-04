#include "descript_audio.h"

descri_audio Descripteur_audio(int fenetre,int intervalle,char *chemin_fichier,descri_audio desci,int * erreur){//demander comment recuperer le chemin et nom du fichier
    double pas;
    int nbr_val=0;
    int k;//(nbr_val_fenetre)
    int m;//nombre d'intervalle
    double val;//valeur lu dans le fichier
    FILE* fichier = NULL;//pointeur de fichier pour utiliser les fonction associé

    //chemin_fichier="../son/jingle_fi.txt";//example de chemin possible
    fichier = fopen(chemin_fichier, "r");//ouvre le fichier ne mode read
    if(fichier==NULL){    
        *erreur=1;//regarder ouverture fichier
        //printf("Erreur lors de l'ouverture d'un fichier");
        //exit(1);
    }
    while(fscanf(fichier,"%lf",&val)!=EOF){
        nbr_val++;
    }
    
 


    k=(nbr_val/fenetre);//calcul du nombre de fenetre

    desci.size_x=k;
    desci.size_y=intervalle;


    desci.tab = malloc(k * sizeof(*desci.tab));//creation du tableau
    if(desci.tab!=NULL)
    {
        *erreur=2;//erreur malloc
    }
    for (int i = 0; i <= k; i++)
    {
        desci.tab[i] = malloc(intervalle * sizeof(**desci.tab));
        if(desci.tab[i]!=NULL)
        {
            *erreur=2;//erreur malloc
        }
    }


    for (unsigned i = 0; i < k; ++i)//initialisation du tableau(possibilité de fonction)
    {
        for (unsigned j = 0; j < intervalle; ++j)
        {
            desci.tab[i][j]=0;
        }
    }
    k=0;
    pas=2./intervalle;
    rewind(fichier);//permet de revenir au debut du fichier




    for(int cpt=0;fscanf(fichier,"%lf",&val)!=EOF;cpt++)
    {
        if(cpt==fenetre)//passer de fenetre en fenetre
        {
            cpt=0;
            k++;
        }

        for(m=0;m<intervalle;m++)
        {
               
            if((val>=(pas*m-1)) && (val<(pas*(m+1)-1)))
            {
                if(val<1&&val>-1&&m<intervalle)
                    desci.tab[k][m]++;
            }
               
        }
    }
    fclose(fichier);//fermeture du fichier

 
return desci;//retour de la structure du descripteur
}



/*
void main(){//exemple d'utilisation
  descri_audio mabite;

    mabite=Descripteur_audio(2048,32,"../son/jingle_fi.txt",mabite);
    
    for (unsigned i = 0; i < mabite.size_x; ++i)
    {
        for (unsigned j = 0; j < mabite.size_y; ++j)
        {
            printf(" |%3d| ",mabite.tab[i][j]);
        }
        printf("\r\n");
    }

}
*/