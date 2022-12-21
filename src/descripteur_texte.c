#include "Descripteur_texte.h"

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
    char mot_Banni[100];
    String tab_p[100];
    int cpt=0;
    FILE* fichierBanni = NULL;
    fichierBanni = fopen("../MotBanni.txt", "r");
    if(fichierBanni==NULL){
        printf("Erreur fichier");
        exit(1);
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

    while(cpt<nbr_occ && case_occ<tab.index)
    {
        //printf("index : %d", tab.index);
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
        tab.tab_app[nbr]=0;
        cpt++;
        case_occ++;
        max=1;
    }

    for(int x=0;x<nbr_occ;x++)
    {
        printf("%s    |    %d\n",tab_occ_finale.tab_mot[x],tab_occ_finale.tab_app[x]);
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
    /*for(int i=0;i<tab.index;i++)
    {
        printf("%s \n" , tab.tab_mot[i]);
    }*/
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
    int nbr_occ=20;

//tab=descripteur_texte_finale("../texte/Textes_UTF8/03-Mimer_un_signal_nerveux_pour_utf8.xml",nbr_occ,tab);





/* mettre un chemin vers un rpertoire qui ne contient que des fichiers */
char CHEMIN [100] =  "../texte/Textes_UTF8/";

char commande[1000] ;
FILE * ptr_fic;  

char nom_fic[100];


/* cr?ation de la commande ? ex?cuter ==> doit ^etre une cha^ine de carcat?re */

/*------------------------------------------------------*/
/* RECUPERATION DU CONTENU DU REPERTOIRE  CHEMIN        */
/*------------------------------------------------------*/
strcpy(commande, "ls -l ");
strcat(commande, CHEMIN);
strcat(commande, " > fic_temp"); 

//printf("execution de %s\n", commande); 
fflush(stdout);

/*---------------------------------------------------------------------*/
/* AFFICHAGE DU CONTENU DU FICHIER CREE LORS DE LA PRECEDENTE COMMANDE */
/*---------------------------------------------------------------------*/
system(commande);
system("cat fic_temp");
//printf("---------------------------------\n");


/* ouverture du fichier temporaire fic_temp*/

ptr_fic = fopen("fic_temp", "r");

if( ptr_fic != NULL)
{   
    /*-- POUR CHAQUE LIGNE CONTENUE DANS LE FICHIER, ON RECUPERE LE NOM DU FICHIER */ 
    /*-- FORMAT DE LA LIGNE :  -rw-r--r--   1 ferrane  minfg       4834 Sep 23  2008 28-Danse___Robyn_Orlin_et.xml */

    fscanf( ptr_fic, "%*s %*s");      /* SAUTER LA PREMIERE LIGNE CONSTITUEE DE 2 CHAINES total xxxx */
    
    fscanf(ptr_fic, "%*s %*s %*s %*s %*s %*s %*s %*s %s", nom_fic);  /* %*s INGNORE LA CHAINE LUE */
    while ( !feof(ptr_fic) )
    {   
          printf( "nom fichier = %s \n", nom_fic);
	  
	   /* nouvelle commande appliqu?e ? chaque fichier de la liste */
      strcpy(commande, "");
	  strcat(commande, CHEMIN); 
      //printf("nom fic : %s\n",nom_fic);
	  strcat(commande, nom_fic);
      printf("commande : %s\n",commande);
      tab=descripteur_texte_finale(commande,nbr_occ,tab);
	  printf("\n==================================\n");
	 
	 /* nom de fichier suivant */
	fscanf( ptr_fic, "%*s %*s %*s %*s %*s %*s %*s %*s %s", nom_fic);
     }
      fclose(ptr_fic);
    }
else
{
   fprintf(stderr, "ERREUR :  PB avec liste_rep\n");
}



}