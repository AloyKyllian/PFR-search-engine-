

#include "comparaison_audio.h"


float comparaison(int val_lu,descri_audio descripteur_comparé,int ligne,int intervalle,descri_audio descri,float fenetre){


    float pourcentage,max=0;
    descripteur_comparé.ligne=ligne;
    descripteur_comparé.colonne=intervalle;
    descri_audio descripteur_intervale;
    descripteur_intervale.tab = malloc(descri.ligne * sizeof(*descripteur_intervale.tab));//creation du tableau
    for (int i = 0; i <= descri.ligne; i++)
    {
        descripteur_intervale.tab[i] = malloc(descri.colonne * sizeof(**descripteur_intervale.tab));
    }
    
    for(int intnbr=0;intnbr<=descripteur_comparé.ligne-descri.ligne;intnbr++)
    {int comparateur=0;
        for (unsigned i = 0; i < descri.ligne; ++i)
        {
            for (unsigned j = 0; j < descri.colonne; ++j)
                {
                    if(descripteur_comparé.tab[i+intnbr][j]-descri.tab[i][j]>0)
                        comparateur+=descripteur_comparé.tab[i+intnbr][j]-descri.tab[i][j];
                    else
                        comparateur+=descri.tab[i][j]-descripteur_comparé.tab[i+intnbr][j];
                }
        }
        pourcentage=comparateur/(fenetre*4.)*100;
        pourcentage=100-pourcentage;
        if(pourcentage>max){
            max=pourcentage;
        }
    }
    printf("max : %f \n",max);


    return max;

}




tab_similaire* comparaison_audio(int seuil,int fenetre,int intervalle,char* chemin_descripteur_compare,char* chemin_descripteur_audio){

    int erreur;
    int id;
    descri_audio descri;
    int ligne=2048;

    //getligne ici


    descri = Descripteur_audio(fenetre,intervalle,chemin_descripteur_compare,&erreur,ligne);

    float verif_seuil;
    float max=0;
    tab_similaire *tab = malloc(ligne * sizeof(tab_similaire));
    if (tab == NULL)
    {
        return NULL;
    }
    int nbr_val;
    int val_lu;
    FILE* fichier = NULL;
    fichier = fopen("../descrripteur_texte_type.txt", "r");
    if(fichier==NULL){
        erreur=7;

    }

    int nbr_ligne;


    int i=0;

    descri_audio descripteur_compare;

    while(fscanf(fichier,"%d %d",&tab[i].id,&nbr_ligne)!=EOF)
    {
        i++;
        descripteur_compare.tab = malloc(nbr_ligne*sizeof(*descripteur_compare.tab));//creation du tableau
        for (int i = 0; i < nbr_ligne; i++)
        {
            descripteur_compare.tab[i] = malloc( intervalle * sizeof(descripteur_compare.tab));
        }

        for(int lig=0;lig<nbr_ligne;lig++)
        {
            for(int col=0;col<intervalle;col++)
            {
                fscanf(fichier,"%d",&descripteur_compare.tab[lig][col]);
            }
        }

        verif_seuil=comparaison( val_lu, descripteur_compare, nbr_ligne, intervalle, descri, fenetre);
        if(verif_seuil>seuil)
            tab[i].pourcentage=verif_seuil;
    }
    fclose(fichier);


        
    tab_similaire *tab_finale = malloc(i * sizeof(tab_similaire));

    for(int y=0;y<i;y++){
        tab_finale[y].id=0;
        tab_finale[y].pourcentage=0;
    }


/* trie a voir !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    int idx;

    printf(" i = %d   \n",i);

    for(int y=0;y<i;y++)
    {
        max=0;
        for(int l=0;l<i;l++)
        {
            if(tab[l].pourcentage>max)
            {
                max=tab[l].pourcentage;
                id=tab[l].id;
                idx=l;
            }
        }

        tab[idx].pourcentage=0;
        tab[idx].id=0;

        tab_finale[y].pourcentage=max;
        tab_finale[y].id=id;
    }
*/



    return tab_finale;
}