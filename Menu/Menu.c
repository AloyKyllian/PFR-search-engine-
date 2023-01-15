#include "Menu.h"


void MAE()
{
    static char etat_courant = Menu_general;
    CONFIG config;
    int test1,test;
    char choix[100];
    char chemin[100];
    char cheminDescripteurTxt[200];
    char *extension;
    int nbTentative=1;
    int nbFenetre,intervalle;
    bool result=false;
    //String erreur;
    LOGIN testlogin;
    lesLogins tablogin;
    int erreur;
    int erreurConfig, erreurIndex=0, erreurTexte=0, erreurImage=0, erreurAudio=0;
    char motCle[25];
    tab_Res *tabResultatTexte=malloc(100*sizeof(tab_Res));
    int nombreElemetTab;
    //lire config si ya une erreur
    config=Lire_CONFIG(&erreurConfig);
    if(erreurConfig==0){
    //voir si un nv fichier
    //indexation
    //4 erreurs index gene, image,audio,texte
    //indexation(config, &erreurImage, &erreurAudio, &erreurTexte, &erreurIndex);
    //verifier les erreurs de tt les phases
    switch (etat_courant)
    {
            case Menu_general:
                printf("Menu général\n");
                printf("Veuillez faire votre choix : \n");
                printf("[1] Administrateur \n[2] Utilisateur \n[Q] Quitter\n");
                scanf("%s", choix);
                switch (choix[0])
                {
                    
                    case Administrateur:
                        // Connexion();
                         result=false;  
                         do
                        {   
                            result = seconnecter(tablogin, testlogin, &erreur);
                            printf("\nConnexion ");
                            (result) ? printf("Réussi\n\n") : printf("Échoué\n\n");
                            if (result){
                                printf("direction menu admin\n");
                                etat_courant = Menu_Admin;}
                            if (nbTentative == 3 && result == false)
                            {
                                printf("Souhaitez vous basculer en mode utilisateur ou essayer de se connecter une nouvelle fois ?\n");
                                printf("[1] Mode utilisateur\n[2] nouvelle tentative de connexion\n");
                                scanf("%s",choix);
                                if (strcmp(&choix[0],"1")==0)
                                    etat_courant = Menu_Utilisateur;
                                if (strcmp(&choix[0],"2")==0)
                                {
                                    int nbr_microsec = 0;
                                    printf("Vous devez attendre 30 seconde pour réessayer\n");
                                    usleep(nbr_microsec);
                                    sleep(30);
                                    printf("fin 30 sec, Vous pouvez réessayer maintenant\n");
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
                        printf("vous avez quitté le programme\n");
                        exit( EXIT_SUCCESS ); 
                        break;
                default:
                        printf("erreur de choix\n");
                        etat_courant = Menu_general;
                        break;
                }

                
            break;

            case Menu_Admin:
                printf("Menu général de l'administrateur\nFonctionnalité :\n");
                printf("Veuillez faire votre choix  : \n");
                printf("[1] Indexation\n [2] Configuration\n [3] Visualisation des recueils des descripteurs\n[4] Retour en mode utilisateur\n");
                
                scanf("%s",choix);

                switch (choix[0])
                {
                case Indexation:
                    indexation_generale_ferme(config, erreurImage, erreurAudio, erreurTexte, erreurIndex);
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
                printf("Configuration :\n");
                int Erreur;
                config=Lire_CONFIG(&Erreur);
                Afficher_CONFIG(config);
                printf("Si vous voulez changer une valeur, veuillez faire votre choix  : \n");
                printf("[1] Nombre de mots clé\n [2] Similarité\n [3] Niveau \n[4] Nombre de fenetre\n");
                printf("[5] Intervalle de temps\n [R] Retour\n[Q] Déconnexion\n");
                scanf("%s", choix);
                switch (choix[0])
                {
                case Nombre_de_mot_cle:
                    printf("entrez le nombre de mot clé voulue :\n");
                    Lire_mot_cle(config,&Erreur);
                    Ecrire_CONFIG(config,&Erreur);
                    break;
                case Similarité:
                    // pour changer similarité
                    printf("entrez la valeur de similarité voulue :\n");
                    config=Lire_similariter(config, &Erreur);
                    Ecrire_CONFIG(config, &Erreur);
                    break;
                case Niveau:
                    // pour changer niveau
                    printf("entrez le niveau voulue :\n");
                    config=Lire_nb_bit_fort(config, &Erreur);
                    Ecrire_CONFIG(config, &Erreur);
                    break;
                case Nombre_de_fenetre:
                    printf("entrez le nombre de fenetre voulue :\n");
                    config=Lire_nb_fenetre(config, &Erreur);
                    Ecrire_CONFIG(config, &Erreur);
                    break;
                case Intervalle_de_temps:
                    // fct pour changer l'intervalle de temps
                    printf("entrez l'intervalle de temps voulue' :\n");
                    config=Lire_intervale(config, &Erreur);
                    Ecrire_CONFIG( config, &Erreur);
                    break;
                case Retour:
                    etat_courant = Menu_Admin;
                    break;
                case Deconnexion:
                    while (strcmp(&choix[0],"1")!=0)
                    {
                        printf("vous vous etes deconnecter, voulez vous retourner en mode utilisateur ?\n[1] Oui\n [2] Non\n");
                        scanf("%s",choix);
                        switch (choix[0])
                        {
                        case oui:
                            strcpy(choix,"1");
                            etat_courant = Menu_Utilisateur;
                            break;
                        case non:
                            printf("Vous avez quitté le programme\n");
                            exit( EXIT_SUCCESS ); 
                            break;
                        default:
                        printf("Mauvais choix, vous allez etre rediriger au menu configuration\n");
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
                printf("Visualisation des recueils des descripteurs :\n");
                printf("Veuillez faire votre choix  : \n");
                printf("[1] Texte\n [2] Image\n [3] Audio \n[R] Retour\n[Q] Déconnexion\n");
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
                        printf("Vous vous etes deconnecter, voulez vous retourner en mode utilisateur ?\n[1] Oui\n [2] Non\n");
                        scanf("%s",choix);
                        switch (choix[0])
                        {
                        case oui:
                            strcpy(choix,"1");
                            etat_courant = Menu_Utilisateur;
                            break;
                        case non:
                            printf("Vous avez quitté le programme\n");
                            exit( EXIT_SUCCESS ); 
                            break;
                        default:
                        printf("Mauvais choix, vous allez etre rediriger vers le menu visualisation\n");
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
                printf("Menu utilisateur :\n");
                printf("Veuillez faire votre choix  : \n");
                printf("[1] Recherche fichier texte\n [2] Recherche fichier image\n [3] Recherche fichier audio \n[Q] Déconnexion\n");
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
                    printf("Vous avez quitté le programme\n");
                    exit( EXIT_SUCCESS ); 
                    break;
                default:
                    printf("erreur de choix menu utilisateur\n");
                    etat_courant = Menu_Utilisateur;
                    break;
                }
            break;

            case Menu_texte:
                printf("Recherche fichier texte :\n");
                printf("Veuillez faire votre choix  : \n");
                printf("[1] Recherche par mot clé\n [2] Recherche par comparaison de textes\n[R] Retour\n[Q] Quitter\n");
                scanf("%s",choix);
                switch (choix[0])
                {
                case Recherche_mots_cle:
                    printf("Entrer votre mot clé\n");
                    scanf("%s",motCle);
                    rechercheMot(motCle,cheminDescripteurTxt,tabResultatTexte,&nombreElemetTab,&erreur);
                    free(tabResultatTexte);
                    //LireResultat(tabResultatTexte,nombreElemetTab);
                    break;
                case Recherche_par_comparaison_Texte:
                    // verification si le fichier existe
                    test=-1;
                    while(test==-1){
                        printf("Entrez le chemin de votre fichier\n");
                        scanf("%s", chemin);
                        test=FichierExist(chemin);
                        if(test==-1){
                            printf("Le fichier n'existe pas");
                            printf("Veuillez faire un choix pour continuer\n[1] Entrer un autre fichier\n [2] Retour menu principale\n");
                            scanf("%s",choix);
                            switch (choix[0])
                            {
                            case Utilisateur:
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
                        printf("Ce fichier n'est pas de type texte\nVeuiller mettre un fichier texte\n");
                        etat_courant=Menu_texte;}
                    else 
                        
                    break;
                case Retour:
                    etat_courant = Menu_Utilisateur;
                    break;
                case Quitter:
                    printf("vous avez quitté le programme\n");
                    exit( EXIT_SUCCESS ); 
                    break;
                default:
                    printf("erreur de choix\n");
                    etat_courant = Menu_texte;
                    break;
                }
            break;

            case Menu_image:
                printf("Recherche fichier image :\n");
                printf("Veuillez faire votre choix  : \n");
                printf("[1] Recherche par comparaison d'images\n[R] Retour\n[Q] Quitter\n");
                scanf("%s", choix);
                switch (choix[0]){
                    case Recherche_comparaison_Image:
                        printf("Entrez le chemin de votre fichier\n");
                        scanf("%s", chemin);
                        // verification si le fichier existe
                        test=-1;
                        while(test==-1){
                            printf("entrez le chemin de votre fichier\n");
                            scanf("%s", chemin);
                            test=FichierExist(chemin);
                            if(test==-1){
                                printf("Le fichier n'existe pas");
                                printf("Veuillez faire un choix pour continuer\n[1] Entrer un autre fichier\n [2] Retour menu principale\n");
                                scanf("%s",choix);
                                switch (choix[0])
                                {
                                case Utilisateur:
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
                            printf("Ce fichier n'est pas de type texte\nVeuiller mettre un fichier texte\n");
                            etat_courant=Menu_texte;}
                        else 
                            //recherche 
                        break;
                        case Retour:
                            etat_courant = Menu_Utilisateur;
                        break;
                        case Quitter:
                            printf("vous avez quitté le programme\n");
                            exit( EXIT_SUCCESS ); 
                        break;
                        default:
                            printf("erreur de choix\n");
                            etat_courant = Menu_image;
                        break;}
            break;

            case Menu_audio:
                printf("Recherche fichier audio :\n");
                printf("Veuillez faire votre choix  : \n");
                printf("[1] Recherche par comparaison d'audio\n[R] Retour\n[Q] Quitter\n");
                scanf("%s", choix);
                switch (choix[0])
                {
                case Recherche_comparaison_Audio:
                    printf("entrez le chemin de votre fichier\n");
                    scanf("%s", chemin);
                    // verification si le fichier existe
                    test=-1;
                    while(test==-1){
                        printf("entrez le chemin de votre fichier\n");
                        scanf("%s", chemin);
                        test=FichierExist(chemin);
                        if(test==-1){
                            printf("Le fichier n'existe pas");
                            printf("Veuillez faire un choix pour continuer\n[1] Entrer un autre fichier\n [2] Retour menu principale\n");
                            scanf("%s",choix);
                            switch (choix[0])
                            {
                            case Utilisateur:
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
                        printf("Ce fichier n'est pas de type audio\nVeuiller faire le choix de recherche qui vous correspond\n");
                        etat_courant=Menu_Utilisateur;}
                    else 
                        
                        //recherche comparaison
                        //je prend le nb de fenetre et d'intervalle
                        // fopen(chemin,"r");
                        // scanf("%d",&nbFenetre);
                        // scanf("%d",&intervalle);
                        // fclose(chemin);
                        //appel indexation audio pour creer un descripteur pour le fichier donner par l'utilisateur


                    break;
                case Retour:
                    etat_courant = Menu_Utilisateur;
                break;
                case Quitter:
                    printf("vous avez quitté le programme\n");
                    exit( EXIT_SUCCESS ); 
                break;
                default:
                    printf("erreur de choix\n");
                    etat_courant = Menu_audio;
                break;
                }
            break;

            default:
                printf("il y a une erreur, vous allez etre redirigez vers le menu general\n");
                etat_courant=Menu_general;
            break;
            }
            
}}