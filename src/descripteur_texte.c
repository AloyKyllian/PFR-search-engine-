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
char mot_lu[100]="moncul,";
char* ptr;
//fscanf("%s",mot_lu);
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
if(strchr(mot_lu,'\'')!=0 && *(strchr(mot_lu,'\'')-2)==0)//pb quand il y 4 lettres apres l'apostrophe (surement pb de la fonction strcpy)
{
    ptr=strchr(mot_lu,'\'');
    //printf("mot lu avant : %s \n",mot_lu);
    //printf("ptr avant : %s \n",ptr+1);
    strcpy(mot_lu,ptr+1);
    //printf("mot lu apres : %s \n",mot_lu);
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

printf("mot finale : %s \n\r",mot_lu);
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
    /*
    char mabite[100]="laaile";
    char test[100];
    strcpy(test,&mabite[1]);
    printf("mot finale : %s \n\r",test);
*/
    nettoyage();

}

