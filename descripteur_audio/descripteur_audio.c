#include "descripteur_audio.h"

descri_audio Descripteur_audio(int fenetre,int intervalle,char *chemin_fichier,int * erreur){//demander comment recuperer le chemin et nom du fichier
    double pas;//difference entre 2 intervalles
    int nbr_val=0;//nombre de valeur dans un fichier texte
    int k;//(nbr_val_fenetre)
    int m;//nombre d'intervalle
    double val;//valeur lu dans le fichier
    FILE* fichier = NULL;//pointeur de fichier pour utiliser les fonction associé

    //chemin_fichier="../son/jingle_fi.txt";//example de chemin possible
    fichier = fopen(chemin_fichier, "r");//ouvre le fichier ne mode read
    if(fichier==NULL){    
        *erreur=7;//regarder ouverture fichier
        //printf("Erreur lors de l'ouverture d'un fichier");
        //exit(1);
    }

    while(fscanf(fichier,"%lf",&val)!=EOF){//compte le nombre de valeur présente dans le fichier txt
        nbr_val++;
    }
    
    k=(nbr_val/fenetre);//calcul du nombre de fenetre
    descri_audio desci;
    printf(" |%3d| ",k);
    printf(" |%3d| ",intervalle);
    desci.ligne=k+1;//donne le nombre de ligne du descripteur 
    desci.colonne=intervalle;//donne le nombre de colonne du descripteur 


    desci.tab = malloc(desci.ligne * sizeof(*desci.tab));
    for (int i = 0; i < desci.ligne; i++)
    {
        desci.tab[i] = malloc(desci.colonne * sizeof(**desci.tab));
    }

    for (int i = 0; i < desci.ligne-17; ++i)
    {
        for (int j = 0; j < desci.colonne; ++j)
        {
            //printf(" |%3d| ",desci.tab[i][j]);
        }
        printf("\r\n");
    }

    /*desci.tab = (int**) malloc((k+1) * sizeof(*desci.tab));//creation des lignes du tableau
    if(desci.tab!=NULL)
    {
        *erreur=1;//erreur malloc
    }
    
    for (int i = 0; i < (k+1); i++)//creation des colonne du tableau
    {
        desci.tab[i] = (int*) malloc(intervalle * sizeof(**desci.tab));
        if(desci.tab[i]!=NULL)
        {
            *erreur=1;//erreur malloc
        }
    }*/

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

        for(m=0;m<intervalle;m++)//change d'intervalle
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
