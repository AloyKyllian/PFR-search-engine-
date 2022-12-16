#include <stdint.h>
#include <stdio.h>
#include "../head/Global.h"
#include <string.h>
#include <ctype.h>


typedef struct 
{
    String *tab_mot;
    int *tab_app;
}tab_total;



int comptemot(char* mot_lu)
{
    int nbr_mot=0;
    char* mot;
    while(mot_lu!="<texte>")
    {
        
    };
    /*
    while()
    {
        printf("%d   ", nbr_mot);
      nbr_mot++;  
    }*/
    
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
    int nombre_mot=15;
    char *tab_p[100]={"la","le","les","des","ma","mon","me","l'","de","mes","m'","de","des","dans","et"};

    bool verif=true;



    for(int i=0;i<nombre_mot;i++)
    {
    if(strcmp(mot,tab_p[i])==0)
        verif=false;
    }


/*
    char poubelle[100]="le";
    if(strcmp(mot,poubelle)==0)
        verif=false;
*/
    //strcat(mot,"\0");
    //printf("%s  ", mot);
    //strlen(mot);
    //strlen("le");
 
 //while((mot)!="</texte>")
   // {
      /*  if(mot=="la" || mot=="le" || mot=="les" || mot=="ma" || mot=="mon" || mot=="me" || mot=="l'" || mot=="de" || mot=="mes" || mot=="m'" || mot=="à" || mot=="car" || mot=="où" || mot=="donc" || mot=="or" || mot=="ni" || mot=="un" || mot=="une")
        {
           verif=false;
        }*/
    //}

return verif;
}



tab_total descripteur_texte( int nbr_mot, char* mot,tab_total tab)
{
    printf("%s ",mot);
    //tab->tab_mot[0]="teste0";
    for(int i=0;i<nbr_mot;i++)
{
    printf("%s    ",tab.tab_mot[i]);
    printf("%d\n",tab.tab_app[i]);

}
    //char* tab_mot[nbr_mot];
    //int tab_app[nbr_mot];
    int index=0;
    bool verif;
    //fscanf("%s",&mot);
    printf("la");
    for(int i=0;i<nbr_mot;i++)
    {
        printf(" la ");
        printf("%s",mot);
        printf("%s",tab.tab_mot[i]);
        if(*mot==tab.tab_mot[i])
        {
            
            tab.tab_app[i]++;
            verif =true;
        }
    }
    printf(" salut ");
    if(verif==false && index <=nbr_mot)
    {
        tab.tab_mot[index]=*mot;
        index++;
    }

    return tab;
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

/*
void test_avancer()
{
        int nbr_mot;

        FILE* fichier = NULL;
    fichier = fopen("../texte/Textes_UTF8/03-Mimer_un_signal_nerveux_pour_utf8.xml", "r");
    if(fichier==NULL){
        printf("Erreur lors de l'ouverture d'un fichier");
        exit(1);
    }

    char mot_lu[100];
    while(mot_lu[0]!='<' || mot_lu[1]!='t' || mot_lu[2]!='e')//permet de sauter l'entet du fichier
    {
        fscanf(fichier,"%s",mot_lu);
    }


    
    while(fscanf(fichier,"%s",mot_lu)!=EOF){
        //printf("Bonsoir 2");
        // nbr_mot=comptemot(mot_lu);
        nbr_mot++;
    }    
    printf("%d",nbr_mot);

}*/



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

    while(mot_lu[0]!='<' || mot_lu[1]!='t' || mot_lu[2]!='e')//permet de sauter l'entet du fichier
    {
        fscanf(fichier,"%s",mot_lu);
    }

    while(fscanf(fichier,"%s",mot_lu)!=EOF){
    nbr_mot++;
    }

    printf("%d \n",nbr_mot);
    
    
    rewind(fichier);
    

    tab_total tab;

    tab.tab_mot = malloc(nbr_mot * sizeof(*tab.tab_mot));//creation du tableau
    tab.tab_app = malloc(nbr_mot * sizeof(*tab.tab_app));//creation du tableau

String test;
strcpy(test,"salut");

    for(int i=0;i<nbr_mot;i++)
{
    *(tab.tab_mot+i)="salut";
    tab.tab_app[i]=20;
    printf("%c    ",tab.tab_mot[i]);
    printf("%d\n",tab.tab_app[i]);

}
    
    //char* tab_mot[nbr_mot];
    
    //int tab_app[nbr_mot];
 
    char* tab_occ_mot[nbr_occ];
   
    int tab_occ_app[nbr_occ];

    char *mot;
 
        while(mot_lu[0]!='<' || mot_lu[1]!='t' || mot_lu[2]!='e')//permet de sauter l'entet du fichier
    {
        fscanf(fichier,"%s",mot_lu);
    }


    while(fscanf(fichier,"%s",mot_lu)!=EOF){
    //printf("%s  ", mot_lu);
    mot = nettoyage(mot_lu);
    //printf("%s  ", mot);
    passe=filtrage(mot);
    //printf("%d\n",passe);
    if(passe==true)
    {
        printf("la");
        printf("%s  ", mot);
        tab=descripteur_texte(nbr_mot,mot,tab);
        printf("%s    ",tab.tab_mot[0]);
    }
    }

    for(int i;i<nbr_mot;i++)
{
    printf("%s    ",tab.tab_mot[i]);
    printf("%d\n",tab.tab_app[i]);

}


    //Après le while
    tab_occ(nbr_mot,nbr_occ,&tab.tab_mot,tab.tab_app,tab_occ_mot,tab_occ_app);



/*
    char mabite[100]="laaile";
    char test[100];
    strcpy(test,&mabite[1]);
    printf("mot finale : %s \n\r",test);
*/
  
 

 //printf("mot finale : %s \n\r",mot);

}

