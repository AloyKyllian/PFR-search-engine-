

#include "comparaison_audio.h"


float comparaison(int val_lu,descri_audio descripteur_comparé,int *ligne,int *colonne,int intervalle,descri_audio descri,float fenetre){


    float pourcentage,max=0;
    descripteur_comparé.ligne=*ligne;
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
                    //printf("%d   ",comparateur);
                }
                //printf("\r\n");
        }
        pourcentage=comparateur/(fenetre*4.)*100;
        pourcentage=100-pourcentage;
        if(pourcentage>max){
            max=pourcentage;
        }
        //printf("\n pourcentage : %f   \n",pourcentage);
    }
    printf("\n max : %f   \n",max);
    *ligne=0;
    *colonne=0;

    return max;

}




tab_similaire* comparaison_audio(int seuil,int fenetre,int intervalle,char* chemin_descripteur_compare,char* chemin_descripteur_audio){

    int erreur;

    descri_audio descri;

    descri = Descripteur_audio(fenetre,intervalle,chemin_descripteur_compare,descri,&erreur);
    float verif_seuil;
    tab_similaire *tab = malloc(100 * sizeof(tab_similaire));
    if (tab == NULL)
    {
        return NULL;
    }
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


    int ligne=0;
    int colonne=0;

    int fin;
    descri_audio descripteur_compare;
    descripteur_compare.tab = malloc(10000 * sizeof(*descripteur_compare.tab));//creation du tableau
    for (int i = 0; i <= 10000; i++)
    {
        descripteur_compare.tab[i] = malloc(intervalle * sizeof(**descripteur_compare.tab));
    }


    int i=0;


    while(fin!=EOF)
    {
        fin=fscanf(fichier,"%d",&val_lu);
        if(val_lu<0 && val_lu!=-1)
        {
        tab[i].id=val_lu+1;
        verif_seuil=comparaison( val_lu, descripteur_compare, &ligne, &colonne, intervalle, descri, fenetre);
        if(verif_seuil>seuil)
            tab[i].pourcentage=verif_seuil;
        i++;
        }
        

        if(val_lu>=0)
        {
            descripteur_compare.tab[ligne][colonne]=val_lu;
            colonne++;
            if(colonne==intervalle)
            {
                colonne=0;
                ligne++;
            }
        }
    }
    fclose(fichier);
    descripteur_compare.ligne=ligne;
    descripteur_compare.colonne=intervalle;
        tab[i].id=tab[i-1].id-1;
        verif_seuil=comparaison( val_lu, descripteur_compare, &ligne, &colonne, intervalle, descri, fenetre);
        if(verif_seuil>seuil)
            tab[i].pourcentage=verif_seuil;
        
    return tab;
}