#include <stdint.h>
#include <stdio.h>
#include "../head/Global.h"
#include <string.h>
#include <ctype.h>



int comptemot(char* mot_lu)
{
    int nbr_mot=0;
    char* mot;
    /*while(mot_lu!="<texte>")
    {
        
    }*/
    while(mot_lu!="les")
    {
        printf("Nombre de mot : %d   ", nbr_mot);
      nbr_mot++;  
    }
    
return nbr_mot;    
}



char *nettoyage(char mot_lu[100])
{
    /*FILE* fichier = NULL;
    fichier = fopen("../texte/Textes_UTF8/03-Mimer_un_signal_nerveux_pour_utf8.xml", "r");
    if(fichier==NULL){
        printf("Erreur lors de l'ouverture d'un fichier");
        exit(1);
    }
    char mot_lu[100];//.</texte>*/
    char* mot_envoyer;
    char* ptr;
    /*fseek(fichier,340,SEEK_SET);
    while(fscanf(fichier,"%s",mot_lu)!=EOF){*/
        //printf(" ||||||%s ",mot_lu);
    //fscanf("%s",mot_lu);
    //  Maj
    for(int i=0;mot_lu[i]!='\0';i++)
    {
        if(mot_lu[i]>='A' && mot_lu[i]<='Z')
        mot_lu[i]=mot_lu[i]+32;
    }
    if(mot_lu[0]=='<')
    {
        ptr=strchr(mot_lu,'>'); //ptr c un pointeur vers le caractere c l'addresse du carractere *ptr c'est le caractere et non pas sa position dans le tableau
        strcpy(mot_lu,ptr+1);
    }
    if(strchr(mot_lu,'.')!=0)
    {
        ptr=strchr(mot_lu,'.');
        char Chaine[]={'\0'};
        strcpy(&mot_lu[strlen(mot_lu)-strlen(ptr)],Chaine);

    }
    if(strchr(mot_lu,',')!=0)
    {
        ptr=strchr(mot_lu,',');
        char Chaine[]={'\0'};
        strcpy(&mot_lu[strlen(mot_lu)-strlen(ptr)],Chaine);
    }
    if(strchr(mot_lu,';')!=0)
    {
        ptr=strchr(mot_lu,';');
        char Chaine[]={'\0'};
        strcpy(&mot_lu[strlen(mot_lu)-strlen(ptr)],Chaine);
    }
    if(strchr(mot_lu,'\'')!=0 && *(strchr(mot_lu,'\'')-2)==0)
    {
        ptr=strchr(mot_lu,'\'');
       // printf("ptr+1 : %s",ptr+1);
        //return ptr+1;
    }
    //printf("Mot lu : %s    ",mot_lu);
    //}

    mot_envoyer= strdup(mot_lu);
   
    return mot_envoyer;
    free( mot_envoyer );
     //printf("mot finale : %s \n\r",mot_lu);
}

bool filtrage(char* mot)
{
    String test;
    bool verif=true;
 while((mot)!="</texte>")
    { 
        
        //grep motif nomfichier
        //cat nomfichier|grep motif
        //grep "la" ficherPoubelle
        //cat /tmp/test |grep -w vache recherche le mot vache
        // Il existe une fonction find sur windows qui fait pareil (on s'en bat les couille on est pas sur windows)

        /*if(cat /tmp/test |grep -w vache)
        {
            verif=false;            //Concrètement il faut faire ça
        }*/
        /*int TailleMax=100;
        char* motbanni[100];
        FILE* fichierALire = NULL;
        fichierALire = fopen("fichierMotBANNI", "r");               Solution Alternative
        fgets(motbanni,TailleMax, fichierALire);
        for(int i=0; i<TailleMax;i++)
        {
            if(strcmp(motbanni[i],mot))
            {
                verif=false;
            }
        }*/
        if(mot!="la" && mot!="le" && mot!="les" && mot!="ma" && mot!="mon" && mot!="me" && mot!="l'" && mot!="de" && mot!="mes" && mot!="m'" && mot!="à" && mot!="car" && mot!="où" && mot!="donc" && mot!="or" && mot!="ni" && mot!="un" && mot!="une")
        {
           verif=false;
        }
    }

return verif;
}



void descripteur_texte( int nbr_mot, char* mot, char* tab_mot[nbr_mot],int tab_app[nbr_mot])
{
    //char* tab_mot[nbr_mot];
    //int tab_app[nbr_mot];
    int index=0;
    bool verif;
    //fscanf("%s",&mot);
    for(int j=0;j<nbr_mot;j++)
    {
        tab_app[j]=0;
    }
    for(int i=0;i<nbr_mot;i++)
    {
        if(mot==tab_mot[i])
        {
            tab_app[i]++;
            verif =true;
        }
    }
    if(verif==false && index <=nbr_mot)
    {
        tab_mot[index]=mot;
        index++;
    }
}

void tab_occ(int nbr_mot,int nbr_occ,char* tab_mot[nbr_mot],int tab_app[nbr_mot],char* tab_occ_mot[nbr_occ],int tab_occ_app[nbr_occ])
{
    // 2eme partie

    int max=1;
    int nbr=0;
    int case_occ=0;
    int cpt=0;
    //char* tab_occ_mot[nbr_occ];
    //int tab_occ_app[nbr_occ];
    while(cpt<nbr_occ)
    {
    for(int y=0;y<nbr_mot;y++)
    {
        if(tab_occ_app[y] >= max && max!=0)
        {
            max=tab_occ_app[y];
            nbr=y;
        }
    }
    *tab_occ_mot[case_occ]=*tab_mot[nbr];
    tab_occ_app[case_occ]=max;
    tab_app[nbr]=0;
    cpt++;
    max=1;
    }
    //Affichage

    for(int x=0;x<nbr_occ;x++)
    {
        printf("%s",tab_occ_mot[x],": %d",tab_occ_app[x],"   |   ");
    }


}
int main()
{
    int nbr_occ=3;
    bool passe;
    char mot_lu[100];
    int nbr_mot;
    FILE* fichier = NULL;
    fichier = fopen("../texte/Textes_UTF8/03-Mimer_un_signal_nerveux_pour_utf8.xml", "r");
    if(fichier==NULL){
        printf("Erreur lors de l'ouverture d'un fichier");
        exit(1);
    }
    fseek(fichier,340,SEEK_SET);
    //printf("Bonsoir 1");
    while(fscanf(fichier,"%s",mot_lu)!=EOF){
       // printf("Bonsoir 2");
   // nbr_mot=comptemot(mot_lu);
    nbr_mot++;
    }
    printf("Nombre de mot : %d",nbr_mot);
    char* tab_mot[nbr_mot];
    int tab_app[nbr_mot];
    char* tab_occ_mot[nbr_occ];
    int tab_occ_app[nbr_occ];
    char *mot;
    
   /* FILE* fichier = NULL;
    fichier = fopen("../texte/Textes_UTF8/03-Mimer_un_signal_nerveux_pour_utf8.xml", "r");
    if(fichier==NULL){
        printf("Erreur lors de l'ouverture d'un fichier");
        exit(1);
    }
    fseek(fichier,340,SEEK_SET);*/
    while(fscanf(fichier,"%s",mot_lu)!=EOF){
    mot = nettoyage(mot_lu);
    passe=filtrage(mot);
    if(passe==true)
    {
        descripteur_texte(nbr_mot,mot,tab_mot,tab_app);
    }
    }
    //Après le while
    tab_occ(nbr_mot,nbr_occ,tab_mot,tab_app,tab_occ_mot,tab_occ_app);
/*
    char mabite[100]="laaile";
    char test[100];
    strcpy(test,&mabite[1]);
    printf("mot finale : %s \n\r",test);
*/
  
 

 //printf("mot finale : %s \n\r",mot);

}

