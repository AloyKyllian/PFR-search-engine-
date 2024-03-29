/**
 * Fait par Hugo Lestrade
 * 
 * Le 23/01/2023
 * 
*/
#include "descripteur_texte.h"


char *nettoyage(char mot_lu[100])
{

    char* mot_envoyer;
    char* ptr;                                          //L'Objectif est de nettoyer les caracteres indesirable
    for(int i=0;mot_lu[i]!='\0';i++)
    {
        if(mot_lu[i]>='A' && mot_lu[i]<='Z')            // Ici on tranforme les majuscule en minuscule pour que les mots ne soient pas traiter differemment
        mot_lu[i]=mot_lu[i]+32;
    } 
    if(mot_lu[0]=='<')
    {
        ptr=strchr(mot_lu,'>');                         //Ici on nettoie les balises
        strcpy(mot_lu,ptr+1);
    }
    if(strchr(mot_lu,'.')!=0)
    {
        ptr=strchr(mot_lu,'.');
        char Chaine[]={'\0'};
        strcpy(&mot_lu[strlen(mot_lu)-strlen(ptr)],Chaine);     //Ici on nettoie les .

    }
    if(strchr(mot_lu,',')!=0)
    {
        ptr=strchr(mot_lu,',');
        char Chaine[]={'\0'};
        strcpy(&mot_lu[strlen(mot_lu)-strlen(ptr)],Chaine);         //Ici on nettoie les ,
    }
    if(strchr(mot_lu,';')!=0)
    {
        ptr=strchr(mot_lu,';');
        char Chaine[]={'\0'};                                           //Ici on nettoie les ;
        strcpy(&mot_lu[strlen(mot_lu)-strlen(ptr)],Chaine);
    }
    if(strchr(mot_lu,'\'')!=0 && (*(strchr(mot_lu,'\'')-2)==0 || *(strchr(mot_lu,'\'')-2)!='>' ))
    {
        ptr=strchr(mot_lu,'\'');                                                                            //Ici on nettoie les ' comme pour l'
        strcpy(mot_lu,ptr+1);

    } 
    if(mot_lu[0]=='-')
    {
        strcpy(mot_lu,&mot_lu[1]);                                                                      //Ici on nettoie les -
    }
    if(mot_lu[strlen(mot_lu)-1]=='-')
    {
        char Chaine[]={'\0'};
        strcpy(&mot_lu[strlen(mot_lu)-1],Chaine);
    }
    if(strchr(mot_lu,'(')!=0)
    {
        strcpy(mot_lu,&mot_lu[1]);                                                                  //Ici on nettoie les ()

    }
    if(strchr(mot_lu,')')!=0)
    {
        ptr=strchr(mot_lu,')');
        char Chaine[]={'\0'};
        strcpy(&mot_lu[strlen(ptr)],Chaine);
    }
    
    mot_envoyer= strdup(mot_lu);
        
    /*if(strlen(mot_envoyer)==0)
        strcpy(mot_envoyer,"NO_DATA");*/
    return mot_envoyer;
    free( mot_envoyer );

}

bool filtrage(char* mot)
{
    char mot_Banni[10000];
    String tab_p[10000];
    int cpt=0;
    FILE* fichierBanni = NULL;
    fichierBanni = fopen("../descripteur_texte/MotBanni.txt", "r");
    if(fichierBanni==NULL){
        exit(1);
    }

    while(fscanf(fichierBanni,"%s",mot_Banni)!=EOF)                       //Ouverture MotBanni pour enlever les mots indésirables comme "le" "un" etc
    {       
        strcpy(tab_p[cpt],mot_Banni);
        cpt++;

    }
    
    bool verif=true;

    for(int i=0;i<cpt;i++)
    {
    if(strcmp(mot,tab_p[i])==0 || strlen(mot)<2)                                 // Si le mot en entrée est présent dans les mots bannis on ne le garde pas
        verif=false;
    }

fclose(fichierBanni);
return verif;
}


DESCRIPTEUR_TEXTE descripteur_texte( int nbr_mot, char* mot,DESCRIPTEUR_TEXTE tab)
{

    bool verif=false;

    for(int i=0;i<tab.index;i++)
    {

         if(strcmp(mot,tab.tab_mot[i])==0)   //Verification si le mot existe deja dans le tableau
        {
            tab.tab_app[i]++;
            verif =true;
        }
    }

    if(verif==false)
    {
        strcpy(tab.tab_mot[tab.index],mot);         // Si ce n'est pas le cas on l'ajoute et on dit qu'il est apparu 1 fois
        tab.tab_app[tab.index]=1;
        tab.index++;
    }

    return tab;
}

DESCRIPTEUR_TEXTE tab_occ(int nbr_occ,DESCRIPTEUR_TEXTE tab,DESCRIPTEUR_TEXTE tab_occ_finale)
{

    int max=1;
    int nbr=0;
    int case_occ=0;
    int cpt=0;

    while(cpt<nbr_occ && case_occ<tab.index)
    {
        for(int y=0;y<tab.index;y++)
        {
            if(tab.tab_app[y] >= max && tab.tab_app[y]!=0)                       // On balaye mon tableau d'apparition de mot pour déterminer celui qui apparait le plus
            {
            max=tab.tab_app[y];
            nbr=y;
            }
        }
        strcpy(tab_occ_finale.tab_mot[case_occ],tab.tab_mot[nbr]);
        tab_occ_finale.tab_app[case_occ]=max;
        tab.tab_app[nbr]=0;                                             //On copie le mot le plus cité ainsi que son nombre de fois dans le tableau d'occurence à renvoyer
        cpt++;                                                          // On met le nombre d'apparition des mots déjà traiter à 0 pour éviter qu'il ne perturbe la fonction
        case_occ++;
        max=1;
    }


    return tab_occ_finale;

}

DESCRIPTEUR_TEXTE descripteur_texte_finale(char* chemin_fichier,int nbr_occ,DESCRIPTEUR_TEXTE tab_renvoyer) {

    bool passe;
    char mot_lu[100];
    int nbr_mot=0;
    FILE* fichier = NULL;
    fichier = fopen(chemin_fichier, "r");                           //Ouverture du texte à traiter
    if(fichier==NULL){
        exit(1);
    }

 do
    {
        fscanf(fichier,"%s",mot_lu);
    }
       while(mot_lu[0]=='<' && mot_lu[1]=='t' && mot_lu[2]=='e');//permet de sauter le début du fichier

    while(fscanf(fichier,"%s",mot_lu)!=EOF)
    {
        nbr_mot++;
    }

    rewind(fichier);

    DESCRIPTEUR_TEXTE tab;
    tab.index=0;
    tab.tab_mot = malloc(nbr_mot * sizeof(*tab.tab_mot));//creation du tableau
    tab.tab_app = malloc(nbr_mot * sizeof(*tab.tab_app));//creation du tableau


    for(int i=0;i<nbr_mot;i++)
    {

        strcpy(tab.tab_mot[i],"");
        tab.tab_app[i]=0;
    }

    char *mot;



    while(mot_lu[0]!='<' || mot_lu[1]!='t' || mot_lu[2]!='e')//permet de sauter le début du fichier
    {
        fscanf(fichier,"%s",mot_lu);
    }

    while(fscanf(fichier,"%s",mot_lu)!=EOF)
    {
        mot = nettoyage(mot_lu);
        passe=filtrage(mot);
        if(passe==true)
        {
            tab=descripteur_texte(nbr_mot,mot,tab);

        }
    }

    tab_renvoyer.index=0;
    tab_renvoyer.tab_mot = malloc(nbr_occ * sizeof(*tab_renvoyer.tab_mot));//creation du tableau
    tab_renvoyer.tab_app = malloc(nbr_occ * sizeof(*tab_renvoyer.tab_app));//creation du tableau

    for(int i=0;i<nbr_occ;i++)
    {
        strcpy(tab_renvoyer.tab_mot[i],"");                     // Initialise le tableau
        tab_renvoyer.tab_app[i]=0;
    }

    tab_renvoyer=tab_occ(nbr_occ,tab,tab_renvoyer);

    String nodata;

    for(int x=0;x<nbr_occ;x++)
    {
        if(strlen(tab_renvoyer.tab_mot[x])==0)
    {
        sprintf(nodata,"NO_DATA%d",x);
        strcpy(tab_renvoyer.tab_mot[x],nodata);
    }
    }

    return tab_renvoyer;
}