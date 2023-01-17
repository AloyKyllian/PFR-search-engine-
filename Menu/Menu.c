#include "Menu.h"


void MAE(CONFIG *config,char choix[100], int *erreurImage, int *erreurAudio, int *erreurTexte, int *erreurIndex)
{
    static char etat_courant = Menu_general;
    char chemin[100];
    char cheminDescripteurTxt[200];
    //lire config si ya une erreur
    //config=Lire_CONFIG(&erreurConfig);
    //voir si un nv fichier
    //indexation
    //4 erreurs index gene, image,audio,texte
    //indexation_generale_ferme(config, &erreurImage, &erreurAudio, &erreurTexte, &erreurIndex);
    //verifier les erreurs de tt les phases
    switch (etat_courant)
    {
            case Menu_general:
                printf("\n__________________________Menu général__________________________\n");
                printf("\nVeuillez faire votre choix : \n");
                printf("\n[1] Administrateur \n[2] Utilisateur \n[Q] Quitter\n");
                scanf("%s", choix);
                switch (choix[0])
                {
                    
                    case Administrateur:
                        // Connexion
                        int erreur=0;
                        int nbTentative=1;
                        bool result=false;
                        LOGIN testlogin;
                        lesLogins tablogin;
                        result=false;  
                         do
                        {   
                            result = seconnecter(tablogin, testlogin, &erreur);
                            printf("\nConnexion ");
                            (result) ? printf("Réussie\n\n") : printf("Échoué\n\n");
                            if (result){
                                printf("\nDirection menu admin\n");
                                etat_courant = Menu_Admin;}
                            if (nbTentative == 3 && result == false)
                            {
                                printf("\nSouhaitez vous basculer en mode utilisateur ou essayer de se connecter une nouvelle fois ?\n");
                                printf("\n[1] Mode utilisateur\n[2] nouvelle tentative de connexion\n");
                                scanf("%s",choix);
                                if (strcmp(&choix[0],"1")==0)
                                    etat_courant = Menu_Utilisateur;
                                if (strcmp(&choix[0],"2")==0)
                                {
                                    int nbr_microsec = 0;
                                    printf("\nVous devez attendre 30 seconde pour réessayer\n");
                                    usleep(nbr_microsec);
                                    sleep(30);
                                    printf("\nFin 30 sec, Vous pouvez réessayer maintenant\n");
                                    nbTentative= 0;
                                }
                            }
                            nbTentative++;
                        } while (nbTentative < 4 && result==false);

                        break;
                case Utilisateur:
                        etat_courant = Menu_Utilisateur;
                        break;
                    case Quitter :
                        printf("\nVous avez quitté le programme\n");
                        exit( EXIT_SUCCESS ); 
                        break;
                default:
                        printf("erreur de choix\n");
                        etat_courant = Menu_general;
                        break;
                }

                
            break;

            case Menu_Admin:
                printf("\n__________________________Menu administrateur__________________________\n");
                printf("\nVeuillez faire votre choix  : \n");
                printf("\n[1] Indexation\n[2] Configuration\n[3] Visualisation des recueils des descripteurs\n[4] Retour en mode utilisateur\n");
                
                scanf("%s",choix);

                switch (choix[0])
                {
                case Indexation:
                    int Erreur=0;
                    indexation_generale_ferme(*config, &erreurImage, &erreurAudio, &erreurTexte, &erreurIndex);
                    
                    //si ya une erreur j'arrete tt
                    break;
                case Configuration :
                    etat_courant = Menu_Configuration;
                    break;
                case Visualisation:
                    // visualisation des descripteurs
                    etat_courant = Menu_Visualisation;
                    break;
                case Retour_Utilisateur:
                    etat_courant = Menu_Utilisateur;
                    break;
                default:
                    printf("erreur de choix\n");
                    etat_courant = Menu_Admin;
                    break;
                }
            break;

            case Menu_Configuration:
                printf("\n__________________________Configuration__________________________\n");
                int Erreur=0;
                *config=Lire_CONFIG(&Erreur);
                Afficher_CONFIG(*config);
                printf("\nSi vous voulez changer une valeur, veuillez faire votre choix  : \n");
                printf("[1] Nombre de mots clé\n[2] Similarité\n[3] Nombre de bits \n[4] Nombre de fenetre\n");
                printf("[5] Intervalle de temps\n[R] Retour\n[Q] Déconnexion\n");
                scanf("%s", choix);
                switch (choix[0])
                {
                case Nombre_de_mot_cle:
                    printf("Entrez le nombre de mot clé voulue :\n");
                    *config=Lire_mot_cle(*config,&Erreur);
                    Ecrire_CONFIG(*config,&Erreur);
                    break;
                case Similarité:
                    // pour changer similarité
                    printf("Entrez la valeur de similarité voulue :\n");
                    *config=Lire_similariter(*config, &Erreur);
                    Ecrire_CONFIG(*config, &Erreur);
                    break;
                case Nombre_de_bits:
                    // pour changer niveau
                    printf("Entrez le nombre de bits voulue :\n");
                    *config=Lire_nb_bit_fort(*config, &Erreur);
                    Ecrire_CONFIG(*config, &Erreur);
                    break;
                case Nombre_de_fenetre:
                    printf("Entrez le nombre de fenetre voulue :\n");
                    *config=Lire_nb_fenetre(*config, &Erreur);
                    Ecrire_CONFIG(*config, &Erreur);
                    break;
                case Intervalle_de_temps:
                    // fct pour changer l'intervalle de temps
                    printf("Entrez l'intervalle de temps voulue' :\n");
                    *config=Lire_intervale(*config, &Erreur);
                    Ecrire_CONFIG( *config, &Erreur);
                    break;
                case Retour:
                    etat_courant = Menu_Admin;
                    break;
                case Deconnexion:
                    while (strcmp(&choix[0],"1")!=0)
                    {
                        printf("\nVous vous etes deconnecter, voulez vous retourner en mode utilisateur ?\n[1] Oui\n[2] Non\n");
                        scanf("%s",choix);
                        switch (choix[0])
                        {
                        case oui:
                            strcpy(choix,"1");
                            etat_courant = Menu_Utilisateur;
                            break;
                        case non:
                            printf("\nVous avez quitté le programme\n");
                            exit( EXIT_SUCCESS ); 
                            break;
                        default:
                        printf("\nMauvais choix, vous allez etre rediriger au menu configuration\n");
                        etat_courant=Menu_Configuration;
                        break;
                        }
                    }
                    break;
                default:
                    printf("Erreur de choix\n");
                    etat_courant = Menu_Configuration;
                    break;
                }
                break;

            case Menu_Visualisation:
                printf("\n__________________________Visualisation des recueils des descripteurs__________________________\n");
                printf("\nVeuillez faire votre choix  : \n");
                printf("\n[1] Texte\n[2] Image\n[3] Audio \n[R] Retour\n[Q] Déconnexion\n");
                scanf("%s", choix);
                //scanf("%c",& choixVisualisation);
                switch (choix[0])
                {
                case texte:
                    //gedit("../DescripteurTexte.txt");
                    break;
                case image:
                    //gedit("../DescripteurImage.txt");
                    break;
                case audio:
                    //gedit("../DescripteurAudio.txt");
                    break;
                case Retour:
                    etat_courant = Menu_Admin;
                case Deconnexion:
                    while (strcmp(&choix[0],"1")!=0)
                    {
                        printf("\nVous vous etes deconnecter, voulez vous retourner en mode utilisateur ?\n[1] Oui\n[2] Non\n");
                        scanf("%s",choix);
                        switch (choix[0])
                        {
                        case oui:
                            strcpy(choix,"1");
                            etat_courant = Menu_Utilisateur;
                            break;
                        case non:
                            printf("\nVous avez quitté le programme\n");
                            exit( EXIT_SUCCESS ); 
                            break;
                        default:
                        printf("\nMauvais choix, vous allez etre rediriger vers le menu visualisation\n");
                        etat_courant=Menu_Visualisation;
                        break;
                        }
                    }
                    break;
                default:
                    printf("erreur de choix\n");
                    etat_courant = Menu_Visualisation;
                    break;
                }
            break;

            case Menu_Utilisateur:
                printf("\n__________________________Menu utilisateur__________________________\n");
                printf("\nVeuillez faire votre choix  : \n");
                printf("\n[1] Recherche fichier texte\n[2] Recherche fichier image\n[3] Recherche fichier audio \n[Q] Déconnexion\n");
                scanf("%s",choix);
                switch (choix[0])
                {
                case texte:
                    etat_courant = Menu_texte;
                    break;
                case image:
                    etat_courant = Menu_image;
                    break;
                case audio:
                    etat_courant = Menu_audio;
                    break;
                case Retour:
                    etat_courant = Menu_general;
                    break;
                case Quitter:
                    printf("\nVous avez quitté le programme\n");
                    exit( EXIT_SUCCESS ); 
                    break;
                default:
                    printf("erreur de choix menu utilisateur\n");
                    etat_courant = Menu_Utilisateur;
                    break;
                }
            break;

            case Menu_texte:
                int nombreElemetTab=0;
                printf("\n__________________________Recherche fichier texte__________________________\n");
                printf("\nVeuillez faire votre choix  : \n");
                printf("\n[1] Recherche par mot clé\n[2] Recherche par comparaison de textes\n[R] Retour\n[Q] Quitter\n");
                scanf("%s",choix);
                switch (choix[0])
                {
                case Recherche_mots_cle:
                    char motCle[27];
                    int erreur=0;
                    char cheminDescripteurTxt[100]="../base_descripteur/base_descripteur_texte";
                    printf("\nEntrer votre mot clé\n");
                    scanf("%s",motCle);
                    tab_Res *tabResultatTexte=malloc(100*sizeof(tab_Res));
                    rechercheMot(motCle,cheminDescripteurTxt,tabResultatTexte,config->Nb_Mots_Cle,&nombreElemetTab,&erreur);
                    LireResultat(tabResultatTexte, nombreElemetTab, "rechercheMot", motCle);
                    free(tabResultatTexte);
                    break;
                case Recherche_par_comparaison_Texte:
                    // verification si le fichier existe
                    char *extension;
                    int test=-1;
                    while(test==-1){
                        printf("\nEntrez le chemin de votre fichier\n");
                        scanf("%s", chemin);
                        test=FichierExist(chemin);
                        if(test==-1){
                            printf("\nLe fichier n'existe pas\n");
                            printf("\nVeuillez faire un choix pour continuer\n[1] Entrer un autre fichier\n [2] Retour menu principale\n");
                            scanf("%s",choix);
                            switch (choix[0])
                            {
                            case Utilisateur:
                                test=0;
                                etat_courant=Menu_Utilisateur;
                                break;
                            case AutreFichier:
                                test=-1;
                                break;
                            default:
                                etat_courant=Menu_Utilisateur;
                                break;
                            }}}
                    //verification si le fichier passer est un fichier texte
                    test=VerifExtension(chemin,"xml");
                    if (test==-1){
                        printf("\nCe fichier n'est pas de type texte\nVeuiller mettre un fichier texte\n");
                        etat_courant=Menu_texte;}
                    else {
                        tab_Res *tabResultatTexte=malloc(100*sizeof(tab_Res));
                    
                        free(tabResultatTexte);}
                    break;
                case Retour:
                    etat_courant = Menu_Utilisateur;
                    break;
                case Quitter:
                    printf("\nVous avez quitté le programme\n");
                    exit( EXIT_SUCCESS ); 
                    break;
                default:
                    printf("erreur de choix\n");
                    etat_courant = Menu_texte;
                    break;
                }
            break;

            case Menu_image:
                
                printf("\n__________________________Recherche fichier image__________________________\n");
                printf("\nVeuillez faire votre choix  : \n");
                printf("\n[1] Recherche par comparaison d'images\n[R] Retour\n[Q] Quitter\n");
                scanf("%s", choix);
                switch (choix[0]){
                    case Recherche_comparaison_Image:
                        char *extension;
                        // verification si le fichier existe
                        int test=-1;
                        while(test==-1){
                            printf("\nEntrez le chemin de votre fichier\n");
                            scanf("%s", chemin);
                            test=FichierExist(chemin);
                            if(test==-1){
                                printf("\nLe fichier n'existe pas\n");
                                printf("\nVeuillez faire un choix pour continuer\n[1] Entrer un autre fichier\n[2] Retour menu principale\n");
                                scanf("%s",choix);
                                switch (choix[0])
                                {
                                    case Utilisateur:
                                        test=0;
                                        etat_courant=Menu_Utilisateur;
                                    break;
                                    case AutreFichier:
                                        test=-1;
                                    break;
                                    default:
                                        etat_courant=Menu_Utilisateur;
                                    break;
                                }}}
                        //verification si le fichier passer est un fichier texte
                        test=VerifExtension(chemin,"txt");
                        if (test==-1){
                            printf("\nCe fichier n'est pas de type image\nVeuiller mettre un fichier texte\n");
                            etat_courant=Menu_image;}
                        else 
                            {tab_Res *tabResultatTexte=malloc(100*sizeof(tab_Res));
                            //recherche 
                            free(tabResultatTexte);}
                        break;
                        case Retour:
                            etat_courant = Menu_Utilisateur;
                        break;
                        case Quitter:
                            printf("\nVous avez quitté le programme\n");
                            exit( EXIT_SUCCESS ); 
                        break;
                        default:
                            printf("erreur de choix\n");
                            etat_courant = Menu_image;
                        break;}
            break;

            case Menu_audio:
                printf("\n__________________________Recherche fichier audio__________________________\n");
                printf("\nVeuillez faire votre choix  : \n");
                printf("\n[1] Recherche par comparaison d'audio\n[R] Retour\n[Q] Quitter\n");
                scanf("%s", choix);
                switch (choix[0])
                {
                case Recherche_comparaison_Audio:
                    char *extension;
                    // verification si le fichier existe
                    int test=-1;
                    while(test==-1){
                        printf("\nEntrez le chemin de votre fichier\n");
                        scanf("%s", chemin);
                        test=FichierExist(chemin);
                        if(test==-1){
                            printf("\nLe fichier n'existe pas\n");
                            printf("\nVeuillez faire un choix pour continuer\n[1] Entrer un autre fichier\n[2] Retour menu principale\n");
                            scanf("%s",choix);
                            switch (choix[0])
                            {
                                case Utilisateur:
                                    test=0;
                                    etat_courant=Menu_Utilisateur;
                                break;
                                case AutreFichier:
                                    test=-1;
                                break;
                                default:
                                    etat_courant=Menu_Utilisateur;
                                break;
                            }}}
                    //verification si le fichier passer est un fichier texte
                    test=VerifExtension(chemin,"txt");
                    if (test==-1){
                        printf("\nCe fichier n'est pas de type audio\nVeuiller faire le choix de recherche qui vous correspond\n");
                        etat_courant=Menu_Utilisateur;}
                    else 
                        {tab_Res *tabResultatTexte=malloc(100*sizeof(tab_Res));
                        //recherche comparaison
                        //je prend le nb de fenetre et d'intervalle
                        /*fopen(chemin,"r");
                        scanf("%d",&nbFenetre);
                        scanf("%d",&intervalle);
                        fclose(chemin);*/
                        //appel indexation audio pour creer un descripteur pour le fichier donner par l'utilisateur
                        free(tabResultatTexte);
                        }
                    break;
                case Retour:
                    etat_courant = Menu_Utilisateur;
                break;
                case Quitter:
                    printf("\nVous avez quitté le programme\n");
                    exit( EXIT_SUCCESS ); 
                break;
                default:
                    printf("Erreur de choix\n");
                    etat_courant = Menu_audio;
                break;
                }
            break;

            default:
                printf("il y a une erreur, vous allez etre redirigez vers le menu general\n");
                etat_courant=Menu_general;
            break;
            }
}