#include <stdint.h>
#include <stdio.h>
#include "../head/Global.h"
#include <string.h>


/*int comptemot ()
{
    int cpt=0;
    String mot;
    while(fscanf("%s",&mot)!="<texte>")
    {
        
        return null;
    }
  
return cpt;
}*/

void nettoyage()
{
char mot_lu[100]="Amis,";

printf("%c \n\r 1 :",mot_lu[2]);
char* ptr;
char* test;
//fscanf("%s",mot_lu);
if(mot_lu[0]=='<')
{
    printf("1");
    ptr=strchr(mot_lu,'>');
    printf("2");
    strcpy(mot_lu,&mot_lu);
    printf("3");
}
if(mot_lu[sizeof(mot_lu)-1]=='>')
{
    ptr=strchr(mot_lu,'.');
    strncpy(mot_lu,mot_lu,(*ptr-1));

}
//printf("test %p \n\r  ",strchr(mot_lu,'\''));
if(strchr(mot_lu,'\'')!=0)
{
    //printf("%s \n\r la ",mot_lu);
    strcpy(mot_lu,&mot_lu[2]);
   // printf("%s \n\r la2 ",mot_lu);

}
test=strchr(mot_lu,',');
printf("la la %d ",(*test));
if(strchr(mot_lu,',')!=0 || strchr(mot_lu,';')!=0)
{
    printf("%s \n\r la ",mot_lu);
    ptr=strchr(mot_lu,',');
    strncpy(mot_lu,&mot_lu,*ptr-1);
}
printf("%s \n\r",mot_lu);
}

/*void filtrage()
{
 while(fscanf("%s",&mot)!="</texte>")
    {
        if(mot!="la" && mot!="le" && mot!="les" && mot!="ma" && mot!="mon" && mot!="me" && mot!="l'" && mot!="de" && mot!="mes" && mot!="m'" && mot!="à" && mot!="car" && mot!="où" && mot!="donc" && mot!="or" && mot!="ni" && mot!="un" && mot!="une")
        {
            //Appel Fonction Descripteur
        }
    }

//return ?
}

void descripteur_texte( int nbr_mot, int nbr_occ)
{
    String tab_mot[nbr_mot];
    int tab_app[nbr_mot];
    String mot;
    int case=0;
    bool verif;
    fscanf("%s",&mot);
    for(int j=0;i<nbr_mot;j++)
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
    if(verif==false && case <=nbr_mot)
    {
        tab_mot[case]=mot;
        case++;
    }

    // 2eme partie

    int max=1;
    int nbr=0;
    int case_occ=0;
    int cpt=0;
    String tab_occ_mot[nbr_occ];
    int tab_occ_app[nbr_occ];
    while(cpt<nbr_occ)
    {
    for(int y=0;y<nbr_mot;y++)
    {
        if(tab_occ_app[y]=>max && max!=0)
        {
            max=tab_occ_app[y];
            nbr=y;
        }
    }
    tab_occ_mot[case_occ]=tab[nbr];
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


}*/
int main()
{
    nettoyage();

}

