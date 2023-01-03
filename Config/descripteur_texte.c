#include "../head/descripteur_texte.h"


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
        printf("Erreur fichier");               //Vérification ouverture du fichier
        exit(1);
    }

    while(fscanf(fichierBanni,"%s",mot_Banni)!=EOF)                       //Ouverture MotBanni pour enlever les mots indésirables comme "le" "un" etc
    {       
        strcpy(tab_p[cpt],mot_Banni);
        cpt++;
    }
    
    bool verif=true;

    for(int i=0;i<100;i++)
    {
    if(strcmp(mot,tab_p[i])==0)                                 // Si le mot en entrée est présent dans les mots bannis on ne le garde pas
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

tab_total tab_occ(int nbr_occ,tab_total tab,tab_total tab_occ_finale)
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

    for(int x=0;x<nbr_occ;x++)
    {
        printf("%s    |    %d\n",tab_occ_finale.tab_mot[x],tab_occ_finale.tab_app[x]);          //On affiche le tableau final
    }

    return tab_occ_finale;

}

tab_total descripteur_texte_finale(char* chemin_fichier,int nbr_occ,tab_total tab_renvoyer) {

    bool passe;
    char mot_lu[100];
    int nbr_mot;
    FILE* fichier = NULL;
    fichier = fopen(chemin_fichier, "r");                           //Ouverture du texte à traiter
    if(fichier==NULL){
        printf("Erreur lors de l'ouverture d'un fichier");
        exit(1);
    }

    while(mot_lu[0]!='<' || mot_lu[1]!='t' || mot_lu[2]!='e')//permet de sauter le début du fichier
    {
        fscanf(fichier,"%s",mot_lu);
    }

    while(fscanf(fichier,"%s",mot_lu)!=EOF)
    {
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

    tab_total tab_occ_finale;
    tab_renvoyer.index=0;
    tab_renvoyer.tab_mot = malloc(nbr_occ * sizeof(*tab_renvoyer.tab_mot));//creation du tableau
    tab_renvoyer.tab_app = malloc(nbr_occ * sizeof(*tab_renvoyer.tab_app));//creation du tableau

    for(int i=0;i<nbr_occ;i++)
    {
        strcpy(tab_renvoyer.tab_mot[i],"");                     // Initialise le tableau
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