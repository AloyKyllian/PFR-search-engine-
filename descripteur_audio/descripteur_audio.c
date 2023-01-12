#include "descripteur_audio.h"

descri_audio Descripteur_audio(int nb_val_fenetre, int intervalle, char *chemin_fichier,int * erreur, int ligne){//demander comment recuperer le chemin et nom du fichier
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
    }
    
    k=(ligne/nb_val_fenetre);//calcul du nombre de fenetre
    descri_audio descipteur_audio;
    descipteur_audio.ligne=k;//donne le nombre de ligne du descripteur 
    descipteur_audio.colonne=intervalle;//donne le nombre de colonne du descripteur 

    descipteur_audio.tab = malloc(descipteur_audio.ligne * sizeof(*descipteur_audio.tab));
    if (descipteur_audio.tab == NULL)
    {
        *erreur = 1;
    }
    for (int i = 0; i < descipteur_audio.ligne; i++)
    {
        descipteur_audio.tab[i] = malloc(descipteur_audio.colonne * sizeof(**descipteur_audio.tab));
        if (descipteur_audio.tab[i] == NULL)
        {
            *erreur = 1;
        }
    }

    for (int i = 0; i < descipteur_audio.ligne; ++i)
    {
        for (int j = 0; j < descipteur_audio.colonne; ++j)
        {
            descipteur_audio.tab[i][j]=0;
        }
    }

    k=0;
    pas=2./intervalle;

    for(int cpt=0;fscanf(fichier,"%lf",&val)!=EOF;cpt++)
    {
        if(cpt==nb_val_fenetre && k<descipteur_audio.ligne-1)//passer de fenetre en fenetre
        {
            cpt=0;
            k++;
        }

        for(m=0;m<intervalle;m++)//change d'intervalle
        {
            if((val>=(pas*m-1)) && (val<(pas*(m+1)-1)))
            {
                if(val<1&&val>-1&&m<intervalle)
                    descipteur_audio.tab[k][m]++;
            }
        }
    }
    fclose(fichier);//fermeture du fichier

return descipteur_audio;//retour de la structure du descripteur
}
