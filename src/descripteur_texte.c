#include <stdint.h>
#include <stdio.h>
#include "../head/Global.h"
#include <string.h>
#include <ctype.h>


typedef struct 
{
    String *tab_mot;
    int *tab_app;
    int index;
}tab_total;



int comptemot(char* mot_lu)
{
    int nbr_mot=0;
    char* mot;
    while(mot_lu!="<texte>")
    {
        
    };

    
return nbr_mot;    
}



char *nettoyage(char mot_lu[100])
{

    char* mot_envoyer;
    char* ptr;
    //printf("Mot Lu : %s", mot_lu);
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
    if(strchr(mot_lu,'\'')!=0 && (*(strchr(mot_lu,'\'')-2)==0 || *(strchr(mot_lu,'\'')-2)!='>' ))
    {
        ptr=strchr(mot_lu,'\'');
        strcpy(mot_lu,ptr+1);

    } 
    if(mot_lu[0]=='-')
    {
        strcpy(mot_lu,&mot_lu[1]);
    }
    if(mot_lu[strlen(mot_lu)-1]=='-')
    {
        char Chaine[]={'\0'};
        strcpy(&mot_lu[strlen(mot_lu)-1],Chaine);
    }
    if(strchr(mot_lu,'(')!=0)
    {
        strcpy(mot_lu,&mot_lu[1]);

    }
    if(strchr(mot_lu,')')!=0)
    {
        ptr=strchr(mot_lu,')');
        char Chaine[]={'\0'};
        strcpy(&mot_lu[strlen(ptr)],Chaine);
    }
    


    mot_envoyer= strdup(mot_lu);
   //printf("\tMot Lu apres : %s \n", mot_envoyer);
    return mot_envoyer;
    free( mot_envoyer );

}

bool filtrage(char* mot)
{
<<<<<<< HEAD
    char mot_Banni[100];
    String tab_p[100];
    int cpt=0;
    FILE* fichierBanni = NULL;
    fichierBanni = fopen("../MotBanni.txt", "r");
    if(fichierBanni==NULL){
        printf("Erreur fichier");
        exit(1);
=======
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
>>>>>>> 3559959e65047705aa3338faa714e5c7d073f6d8
    }

     while(fscanf(fichierBanni,"%s",mot_Banni)!=EOF){
        strcpy(tab_p[cpt],mot_Banni);
        cpt++;
     }
    //char *tab_p[100]={"la","le","les","des","ma","mon","me","l'","de","mes","m'","de","des","dans","et","","</texte>"};
   // printf("%s MotBanni", mot_Banni );
    bool verif=true;
    /*for(int j=0;j<100;j++)
    {
    if(strcpy(mot_cmp[j],mot_Banni[j])==0)
        verif=false;
    }*/
    
    for(int i=0;i<100;i++)
    {
       // printf("%s",tab_p[i]);
    if(strcmp(mot,tab_p[i])==0)
        verif=false;
    }

fclose(fichierBanni);
return verif;
}



tab_total descripteur_texte( int nbr_mot, char* mot,tab_total tab)
{


    bool verif=false;

    for(int i=0;i<tab.index;i++)
    {


         if(strcmp(mot,tab.tab_mot[i])==0)
        {
            tab.tab_app[i]++;
            verif =true;
        }
    }

    if(verif==false)
    {
        strcpy(tab.tab_mot[tab.index],mot);
        tab.tab_app[tab.index]=1;
        tab.index++;
    }

    return tab;
}

tab_total tab_occ(int nbr_occ,tab_total tab,tab_total tab_occ_finale)
{

    int max=1;
    int nbr=0;
    int case_occ=0;
    int cpt=0;

    while(cpt<nbr_occ)
    {
        for(int y=0;y<tab.index;y++)
        {
            if(tab.tab_app[y] >= max)                       // On balaye mon tableau d'apparition de mot pour déterminer celui qui apparait le plus
            {
            max=tab.tab_app[y];
            nbr=y;
            }
        }
        strcpy(tab_occ_finale.tab_mot[case_occ],tab.tab_mot[nbr]);
        tab_occ_finale.tab_app[case_occ]=max;
        tab.tab_app[nbr]=0;
        cpt++;
        case_occ++;
        max=1;
    }

    for(int x=0;x<nbr_occ;x++)
    {
        printf("%s:    |    %d\n",tab_occ_finale.tab_mot[x],tab_occ_finale.tab_app[x]);
    }

    return tab_occ_finale;

}

tab_total descripteur_texte_finale(char* chemin_fichier,int nbr_occ,tab_total tab_renvoyer) {

    bool passe;
    char mot_lu[100];
    int nbr_mot;
    FILE* fichier = NULL;
    fichier = fopen(chemin_fichier, "r");
    if(fichier==NULL){
        printf("Erreur lors de l'ouverture d'un fichier");
        exit(1);
    }

    while(mot_lu[0]!='<' || mot_lu[1]!='t' || mot_lu[2]!='e')//permet de sauter l'entet du fichier
    {
        fscanf(fichier,"%s",mot_lu);
    }

    while(fscanf(fichier,"%s",mot_lu)!=EOF){
    nbr_mot++;
    }
    
    rewind(fichier);
    

    tab_total tab;
    tab.index=0;
    tab.tab_mot = malloc(nbr_mot * sizeof(*tab.tab_mot));//creation du tableau
    tab.tab_app = malloc(nbr_mot * sizeof(*tab.tab_app));//creation du tableau

    for(int i=0;i<nbr_mot;i++)
{
    strcpy(tab.tab_mot[i],"");

}

    char *mot;
 
        while(mot_lu[0]!='<' || mot_lu[1]!='t' || mot_lu[2]!='e')//permet de sauter l'entet du fichier
    {
        fscanf(fichier,"%s",mot_lu);
    }

    while(fscanf(fichier,"%s",mot_lu)!=EOF){
    mot = nettoyage(mot_lu);
    passe=filtrage(mot);
    if(passe==true)
    {
        tab=descripteur_texte(nbr_mot,mot,tab);

    }
    }
    for(int i=0;i<tab.index;i++)
    {
        printf("%s \n" , tab.tab_mot[i]);
    }
    tab_total tab_occ_finale;
    tab_renvoyer.index=0;
    tab_renvoyer.tab_mot = malloc(nbr_occ * sizeof(*tab_renvoyer.tab_mot));//creation du tableau
    tab_renvoyer.tab_app = malloc(nbr_occ * sizeof(*tab_renvoyer.tab_app));//creation du tableau


    for(int i=0;i<nbr_occ;i++)
{
    strcpy(tab_renvoyer.tab_mot[i],"");
    tab_renvoyer.tab_app[i]=0;
}


    tab_renvoyer=tab_occ(nbr_occ,tab,tab_renvoyer);




}







































int main()
{
tab_total tab;
    int nbr_occ=6;

tab=descripteur_texte_finale("../texte/Textes_UTF8/05-Photographie___Philip_Blenkinsop_a_utf8.xml",nbr_occ,tab);

}