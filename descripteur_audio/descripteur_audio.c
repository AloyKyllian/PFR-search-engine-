#include "descripteur_audio.h"

descri_audio Descripteur_audio(int fenetre,int intervalle,char *chemin_fichier,descri_audio desci,int * erreur){//demander comment recuperer le chemin et nom du fichier
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

    desci.ligne=k;//donne le nombre de ligne du descripteur 
    desci.colonne=intervalle;//donne le nombre de colonne du descripteur 
    desci.tab = malloc(k * sizeof(*desci.tab));//creation des lignes du tableau
    if(desci.tab==NULL)
    {
        *erreur=1;//erreur malloc
        printf("INDEXATION AUDIO");
        fflush(stdout);
    }
    
    for (int i = 0; i <= k; i++)//creation des colonne du tableau
    {
        desci.tab[i] = malloc(intervalle * sizeof(**desci.tab));
        if(desci.tab[i]==NULL)
        {
            *erreur=1;//erreur malloc
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
