import javax.security.auth.x500.X500Principal;

public class MAE 
{

    private String nomFichierWrite ;
    private String nomfichierRead ;

    private String strERREUR;
    private Etat etat_courant = Etat.Menu_general;

    // variables a utiliser au cours du programme
    private char choix;
    private Config config;

    private String cheminFichierRecherche;
    private String typeRequete;
    private int erreur = 0;
    private int Erreur = 0;
    private int nbTentativeConnexion = 1;
    private String motCleRecherche;
    private int nombreElemetTab = 0;
    private int nombreElementTabFIN = 0;
    private boolean result = false;
    private LOGIN testlogin;
    private int testExtensionFichier, testExtensionFichierBMP;
    private final String cheminDescripteurTxt = "../base_descripteur/base_descripteur_texte";
    private final String cheminDescripteurIMG = "../base_descripteur/base_descripteur_image";
    private final String cheminDescripteurAudio = "../base_descripteur/base_descripteur_audio";

    public MAE(String nomFichierWrite , String nomfichierRead)
    {
        this.nomFichierWrite= nomFichierWrite;
        this.nomfichierRead=nomfichierRead;
        config = new Config( "10","50","4","300","2048");
    }

    public void lancerMAE() 
    {
        while(1)
        {
            switch (this.etat_courant)
            {
            case Etat.Menu_general:
            {
                System.out.println("\n__________________________Menu General__________________________\n");
                System.out.println("\nVeuillez faire votre choix : \n");
                System.out.println("\n[1] Administrateur \n[2] Utilisateur \n[Q] Quitter\n");

                this.choix = Clavier.entrerClavierChar();
                switch (this.choix)
                {
                // case Administrateur:
                    case '1':
                    {
                        // Connexion
                        this.result = false;
                        do
                        {
                            // recuperer le boolean depuis le fichier texte
                            
                                System.out.println("\nConnexion ");
                                this.result = LOGIN.connexion();
                                if(this.result) 
                                {
                                    System.out.println("Réussie\n\n") ; 
                                    System.out.println("\nDirection \"Menu Administrateur\"\n");
                                    this.etat_courant = Etat.Menu_Admin;
                                } 
                                else
                                {
                                    System.out.println("Échouée\n\n");
                                    this.nbTentativeConnexion++;
                                }
                                if (this.nbTentativeConnexion == 3 && this.result == false)
                                {
                                    System.out.println("\nSouhaitez vous basculer en \"Mode Utilisateur\" ou essayer de se connecter une nouvelle fois ?\n");
                                    System.out.println("\n[1] Mode Utilisateur\n[2] nouvelle tentative de connexion\n");
                                    this.choix = Clavier.entrerClavierChar();
                                    switch(this.choix){
                                    case '1' :
                                    {
                                        this.etat_courant = Etat.Menu_Utilisateur;
                                    }break;
                                    case '2' :
                                    {
                                        System.out.println("\nVous devez attendre 30 secondes pour réessayer\n");
                                        Thread.sleep(30000);
                                        READ_WRITE_FICHIER.write(this.nomFichierWrite,"viderBuffer()");
                                        System.out.println("\nFin des 30 secondes, Vous pouvez réessayer maintenant\n");
                                        this.nbTentativeConnexion = 0;      
                                    }break;
                                    default :
                                        {
                                            System.out.println("Erreur de choix");
                                        }break;
                                    }
                                }
                        } while ((this.nbTentativeConnexion < 4) && (this.result == false));

                    }break;
                    //case Utilisateur:
                    case '2':
                    {
                        this.etat_courant = Etat.Menu_Utilisateur;
                    }break;
                    case 'Q':
                    {
                        System.out.println("\n\t\033[0;31mVous avez quitté le programme\033[0m\n\n\n\n");
                        READ_WRITE_FICHIER.write(this.nomFichierWrite,"exit(EXIT_SUCCESS)");
                    }break;
                    default:
                    {
                        this.erreur = 11;
                        Erreur.afficherErreur(this.erreur);
                         
                        this.etat_courant = Etat.Menu_general;
                    }break;
            }break;
            }

            case Etat.Menu_Admin:
            {
                System.out.println("\n__________________________Menu Administrateur__________________________\n");
                System.out.println("\nVeuillez faire votre choix  : \n");
                System.out.println("\n[1] Indexation\n[2] Configuration\n[3] Visualisation des recueils des descripteurs\n[4] Retour \"Mode Utilisateur\"\n");

                this.choix = Clavier.entrerClavierChar();

                switch (this.choix)
                {
                    case '1':
                    {
                        READ_WRITE_FICHIER.write(this.nomFichierWrite,"indexation_generale_ferme(" + config.get_Nb_Mots_Cle() +"," + config.getSimilariter() + "," + config.getNb_Bit_Fort() + "," + config.getNb_Fenetre() + "," + config.getIntervale() + ", erreurImage, erreurAudio, erreurTexte, erreurIndex)");
                        // si ya une erreur j'arrete tt
                    }break;
                    case '2':
                    {
                        this.etat_courant = Etat.Menu_Configuration;
                    }break;
                    case '3':
                    {
                        // visualisation des descripteurs
                        this.etat_courant = Etat.Menu_Visualisation;
                    }break;
                    case '4':
                    {
                        this.etat_courant = Etat.Menu_Utilisateur;
                    }break;
                    default:
                    {
                        this.erreur = 11;
                        Erreur.afficherErreur(this.erreur);
                         
                        this.etat_courant = Etat.Menu_Admin;
                    }break;
                }
            }break;

            case Etat.Menu_Configuration:
            {
                System.out.println("\n__________________________Configuration__________________________\n");
                int  erreur = 0;
                String configstr="";
                config.Lire_config();
                configstr= config.afficher_config();
                System.out.println(configstr);

                System.out.println("\nSi vous voulez changer une valeur, veuillez faire votre choix  : \n");
                System.out.println("\n[1] Nombre de mots-clé \t supérieur à 0\n[2] Similarité         \t entre 1 et 100\n[3] Nombre de bits     \t entre 1 et 8 \n[4] Nombre de fenetre  \t supeieur a 256 et une puissance de 2\n[5] Intervalle de temps\t superieur a 0 \n[R] Retour\n[Q] Déconnexion\n");
                this.choix = Clavier.entrerClavierChar();
                switch (this.choix)
                {
                case '1':
                {
                    System.out.println("Entrez le nombre de mot-clé voulu :\n");
                    config.setNb_Mots_Cle();
                    config.Ecrire_CONFIG();
                    if (this.erreur != 0)
                    {
                        Erreur.afficherErreur(this.erreur);
                         
                        this.erreur = 0;
                    }
                    if (this.erreur != 0)
                    {
                        Erreur.afficherErreur( this.erreur);                      
                        this.erreur = 0;
                    }
                    System.out.println("\nSi vous avez changé votre configuration veuillez lancer l'indexation pour appliquer vos modifications\n");
                }break;
                case '2':
                {
                    // pour changer similarité
                    System.out.println("Entrez la valeur de similarité voulu :\n");
                    config.setSimilariter();
                    config.Ecrire_CONFIG();
                    if ( this.erreur != 0)
                    {
                        Erreur.afficherErreur( this.erreur);
                         this.erreur = 0;
                    }

                    if ( this.erreur != 0)
                    {
                        Erreur.afficherErreur( this.erreur);
                         
                         this.erreur = 0;
                    }
                    System.out.println("\nSi vous avez changé votre configuration veuillez lancer l'indexation pour appliquer vos modifications\n");
                }break;
                case '3':
                {
                    // pour changer niveau
                    System.out.println("Entrez le nombre de bits voulu :\n");
                    config.setNb_Bit_Fort();
                    config.Ecrire_CONFIG();
                    if ( this.erreur != 0)
                    {
                        Erreur.afficherErreur( this.erreur);
                         
                         this.erreur = 0;
                    }
                    if ( this.erreur != 0)
                    {
                        Erreur.afficherErreur( this.erreur);
                         
                         this.erreur = 0;
                    }
                    System.out.println("\nSi vous avez changé votre configuration veuillez lancer l'indexation pour appliquer vos modifications\n");
                }break;
                case '4':
                {
                    System.out.println("Entrez le nombre de fenetres voulu :\n");
                    config.setNb_Fenetre();
                    config.Ecrire_CONFIG();
                    if ( this.erreur != 0)
                    {
                        Erreur.afficherErreur( this.erreur);
                         
                         this.erreur = 0;
                    }
                    if ( this.erreur != 0)
                    {
                        Erreur.afficherErreur( this.erreur);
                         
                         this.erreur = 0;
                    }
                    System.out.println("\nSi vous avez changé votre configuration veuillez lancer l'indexation pour appliquer vos modifications\n");
                }break;
                case '5':
                {
                    // fct pour changer l'intervalle de temps
                    System.out.println("Entrez l'intervalle de temps voulue :\n");
                    config.setIntervale();
                    config.Ecrire_CONFIG();
                    if ( this.erreur != 0)
                    {
                        Erreur.afficherErreur( this.erreur);
                         
                         this.erreur = 0;
                    }
                    if ( this.erreur != 0)
                    {
                        Erreur.afficherErreur( this.erreur);
                         
                         this.erreur = 0;
                    }
                    System.out.println("\nSi vous avez changé votre configuration veuillez lancer l'indexation pour appliquer vos modifications\n");
                }break;
                case 'R':
                {
                    this.etat_courant = Etat.Menu_Admin;
                }break;
                case 'Q':
                {
                    while (this.choix == '1')
                    {
                        System.out.println("\nVous vous êtes deconnecté, voulez vous retourner en \"Mode Utilisateur\" ?\n[1] Oui\n[2] Non\n");
                        this.choix = Clavier.entrerClavierChar();
                        switch (this.choix)
                        {
                        case 1:
                            this.etat_courant = Etat.Menu_Utilisateur;
                            break;
                        case 2:
                            System.out.println("\n\t\033[0;31mVous avez quitté le programme\033[0m\n\n\n\n");
                            READ_WRITE_FICHIER.write(this.nomFichierWrite,"exit(EXIT_SUCCESS)");
                            break;
                        default:
                            this.erreur = 11;
                            Erreur.afficherErreur(this.erreur);
                             
                            this.etat_courant = Etat.Menu_Configuration;
                            break;
                        }
                    }
                }break;
                default:
                {
                    this.erreur = 11;
                    Erreur.afficherErreur(this.erreur);
                     
                    this.etat_courant = Etat.Menu_Configuration;
                }break;
                }
            }break;

            case Etat.Menu_Visualisation:
            {
                System.out.println("\n__________________________Visualisation des recueils des descripteurs__________________________\n");
                System.out.println("\nVeuillez faire votre choix  : \n");
                System.out.println("\n[1] Texte\n[2] Image\n[3] Audio \n[R] Retour\n[Q] Déconnexion\n");
                this.choix = Clavier.entrerClavierChar();
                switch (this.choix)
                {
                case '1':
                {
                    READ_WRITE_FICHIER.write(this.nomfichier,"system(\"chmod a-w ../base_descripteur/base_descripteur_texte\");");
                    
                    System.out.println("\nPenser a fermé la fenetre apres l'avoir consulter pour poursuivre votre activité\n");
                    READ_WRITE_FICHIER.write(this.nomfichier,"system(\"gedit ../base_descripteur/base_descripteur_texte\"");
                    READ_WRITE_FICHIER.write(this.nomfichier,"system(\"chmod 777 ../base_descripteur/base_descripteur_texte\"");
                }break;
                case '2':
                {
                    READ_WRITE_FICHIER.write(this.nomfichier,"system(\"chmod a-w ../base_descripteur/base_descripteur_image\"");
                    System.out.println("\nPenser a fermé la fenetre apres l'avoir consulter pour poursuivre votre activité\n");
                    READ_WRITE_FICHIER.write(this.nomfichier,"system(\"gedit ../base_descripteur/base_descripteur_image\"");
                    READ_WRITE_FICHIER.write(this.nomfichier,"system(\"chmod 777 ../base_descripteur/base_descripteur_image\"");
                }break;
                case '3':
                {
                    READ_WRITE_FICHIER.write(this.nomfichier,"system(\"chmod a-w ../base_descripteur/base_descripteur_audio\"");
                    System.out.println("\nPenser a fermé la fenetre apres l'avoir consulter pour poursuivre votre activité\n");
                    READ_WRITE_FICHIER.write(this.nomfichier,"system(\"gedit ../base_descripteur/base_descripteur_audio\"");
                    READ_WRITE_FICHIER.write(this.nomfichier,"system(\"chmod 777 ../base_descripteur/base_descripteur_audio\"");
                }break;
                case 'R':
                {
                    this.etat_courant = Etat.Menu_Admin;
                }break;
                case 'Q':
                {
                    while (this.choix == '1')
                    {
                        System.out.println("\nVous vous êtes deconnecté, voulez vous retourner en \"Mode Utilisateur\" ?\n[1] Oui\n[2] Non\n");
                        this.choix = Clavier.entrerClavierChar();
                        switch (this.choix)
                        {
                        case 1:
                            this.etat_courant = Etat.Menu_Utilisateur;
                            break;
                        case 2:
                            System.out.println("\n\t\033[0;31mVous avez quitté le programme\033[0m\n\n\n\n");
                            READ_WRITE_FICHIER.write(this.nomFichierWrite,"exit(EXIT_SUCCESS)");
                            break;
                        default:
                            System.out.println("\nMauvais choix, vous allez etre redirigé vers \"Menu visualisation\"\n");
                            this.etat_courant = Etat.Menu_Visualisation;
                            break;
                        }
                    }
                }break;
                default:
                {
                    this.erreur = 11;
                    Erreur.afficherErreur(this.erreur);
                     
                    this.etat_courant = Etat.Menu_Visualisation;
                }break;
                }
            }break;

            case Etat.Menu_Utilisateur:
            {
                System.out.println("\n__________________________Menu utilisateur__________________________\n");
                System.out.println("\nVeuillez faire votre choix  : \n");
                System.out.println("\n[1] Recherche fichier texte\n[2] Recherche fichier image\n[3] Recherche fichier audio \n[R] Retour\n[Q] Déconnexion\n");
                this.choix = Clavier.entrerClavierChar();
                switch (this.choix)
                {
                case '1':
                {
                    this.etat_courant = Etat.Menu_texte;
                }break;
                case '2':
                {
                    this.etat_courant = Etat.Menu_image;
                }break;
                case '3':
                {
                    this.etat_courant = Etat.Menu_audio;
                }break;
                case 'R':
                {
                    this.etat_courant = Etat.Menu_general;
                }break;
                case 'Q':
                {
                    System.out.println("\n\t\033[0;31mVous avez quitté le programme\033[0m\n\n\n\n");
                    READ_WRITE_FICHIER.write(this.nomFichierWrite,"exit(EXIT_SUCCESS)");
                }break;
                default:
                {
                    this.erreur = 11;
                    Erreur.afficherErreur(this.erreur);
                     
                    this.etat_courant = Etat.Menu_Utilisateur;
                }break;
                }
            }break;

            case Etat.Menu_texte:
            {

                System.out.println("\n__________________________Recherche fichier texte__________________________\n");
                System.out.println("\nVeuillez faire votre choix  : \n");
                System.out.println("\n[1] Recherche par mot-clé\n[2] Recherche par comparaison de textes\n[R] Retour\n[Q] Quitter\n");
                this.choix = Clavier.entrerClavierChar();
                switch (this.choix)
                {
                case '1':
                {

                    this.erreur = 0;
                    System.out.println("\nEntrez votre mot-clé\n");
                    this.motCleRecherche=Clavier.entrerClavierString();
                    READ_WRITE_FICHIER.write(this.nomFichierWrite,"rechercheMot(motCleRecherche, cheminDescripteurTxt, tabResultatMot, config->Nb_Mots_Cle, &nombreElemetTab, &erreur)");
                    if (this.erreur == 7)
                    {
                        Erreur.afficherErreur(this.erreur);
                         
                    }
                    else
                    {
                        //this.nombreElementTabFIN = LireResultat(tabResultatMot, this.nombreElemetTab, "rechercheMot", this.motCleRecherche, tabFileNameMOT, config.Nb_Mots_Cle, config.Similariter); A gerer en JAVA
                        if (this.nombreElementTabFIN > 0)
                        {

                            System.out.println("[R] Retour\n\nPensez à fermer l'editeur de texte apres l'avoir consulté pour poursuivre votre activite\n");
                            //this.choix = visualiser_fichier(tabFileNameMOT, this.nombreElementTabFIN, "texte"); A gerer en JAVA
                        }
                        if (choix== 'Q')
                        {
                            System.out.println("\n\t\033[0;31mVous avez quitte le programme\033[0m\n\n\n\n");
                            READ_WRITE_FICHIER.write(this.nomFichierWrite,"exit(EXIT_SUCCESS)");
                        }
                    }
                }break;

                case '2':
                {
                    // verification si le fichier existe
                    this.testExtensionFichier = -1;
                    while (this.testExtensionFichier == -1)
                    {
                        System.out.println("\nEntrez le chemin de votre fichier\n");
                        this.cheminFichierRecherche = Clavier.entrerClavierString();
                        //this.testExtensionFichier = FichierExist(this.cheminFichierRecherche); A gerer en JAVA
                        if (this.testExtensionFichier == -1)
                        {
                            System.out.println("\nLe fichier n'existe pas\n");
                            System.out.println("\nVeuillez faire un choix pour continuer\n[1] Entrer un autre fichier\n[2] Retour \"Menu General\"\n");
                            this.choix = Clavier.entrerClavierChar();
                            switch (this.choix)
                            {
                            case '1':
                                this.testExtensionFichier = 0;
                                this.etat_courant = Etat.Menu_Utilisateur;
                                break;
                            case '2':
                                this.testExtensionFichier = -1;
                                break;
                            default:
                                this.etat_courant = Etat.Menu_Utilisateur;
                                break;
                            }
                        }
                    }
                    // verification si le fichier passer est un fichier texte
                    //this.testExtensionFichier = VerifExtension(this.cheminFichierRecherche, "xml"); A gerer en JAVA
                    if (this.testExtensionFichier == -1)
                    {
                        System.out.println("\nCe fichier n'est pas de type texte\nVeuiller mettre un fichier texte\n");
                        this.etat_courant = Etat.Menu_texte;
                    }
                    else
                    {
                        this.erreur = 0; this.nombreElemetTab = 0;
                        READ_WRITE_FICHIER.write(this.nomFichierWrite,"comparaison_texte(config.Nb_Mots_Cle, this.cheminFichierRecherche, this.cheminDescripteurTxt, &erreur, &nombreElemetTab)");
                        String recuperationResultat = READ_WRITE_FICHIER.read(this.nomfichierRead);
                        
                        if (this.erreur == 7 || this.erreur == 1)
                        {
                            Erreur.afficherErreur(this.erreur);
                             
                        }
                        //this.nombreElementTabFIN = LireResultat(tabResultatTexte, this.nombreElemetTab, "texte", this.cheminFichierRecherche, tabFileNameTEXTE, config.Nb_Mots_Cle, config.Similariter); A GERER en JAVA
                        READ_WRITE_FICHIER.write(nomFichierWrite,"free(tabResultatTexte)");
                        if (this.nombreElementTabFIN > 0)
                        {
                            System.out.println("[R] Retour\n\nPensez à fermer l'editeur de texte apres l'avoir consulté pour poursuivre votre activité\n");
                            //this.choix= visualiser_fichier(tabFileNameTEXTE, this.nombreElementTabFIN, "texte"); // A gerer en JAVA
                        }
                        if (choix=='Q')
                        {
                            System.out.println("\n\t\033[0;31mVous avez quitté le programme\033[0m\n\n\n\n");
                            READ_WRITE_FICHIER.write(this.nomFichierWrite,"exit(EXIT_SUCCESS)");
                        }
                    }
                }break;
                case 'R':
                {
                    this.etat_courant = Etat.Menu_Utilisateur;
                }break;
                case 'Q':
                {
                    System.out.println("\n\t\033[0;31mVous avez quitté le programme\033[0m\n\n\n\n");
                    READ_WRITE_FICHIER.write(this.nomFichierWrite,"exit(EXIT_SUCCESS)");
                }break;
                default:
                {
                    this.erreur = 11;
                    Erreur.afficherErreur(this.erreur);
                     
                    this.etat_courant = Etat.Menu_texte;
                }break;
                }
            }break;

            case Etat.Menu_image:
            {

                System.out.println("\n__________________________Recherche fichier image__________________________\n");
                System.out.println("\nVeuillez faire votre choix  : \n");
                System.out.println("\n[1] Recherche par comparaison d'images\n[R] Retour\n[Q] Quitter\n");
                this.choix = Clavier.entrerClavierChar();
                switch (choix)
                {
                case '1':
                {
                    // verification si le fichier existe
                    this.testExtensionFichier = -1;
                    while (this.testExtensionFichier == -1)
                    {
                        System.out.println("\nEntrez le chemin de votre fichier\n");
                        this.cheminFichierRecherche=Clavier.entrerClavierString();
                        this.testExtensionFichier = FichierExist(this.cheminFichierRecherche);
                        if (this.testExtensionFichier == -1)
                        {
                            System.out.println("\nLe fichier n'existe pas\n");
                            System.out.println("\nVeuillez faire un choix pour continuer\n[1] Entrez un autre fichier\n[2] Retour \"Menu Général\"\n");
                            this.choix = Clavier.entrerClavierChar();
                            switch (this.choix)
                            {
                            case '1':
                            {
                                this.testExtensionFichier = 0;
                                this.etat_courant = Etat.Menu_Utilisateur;
                            }break;
                            case '2':
                            {
                                this.testExtensionFichier = -1;
                            }break;
                            default:
                            {
                                this.etat_courant = Etat.Menu_Utilisateur;
                            }break;
                            }
                        }
                    }
                    // verification si le fichier passer est un fichier texte
                    this.testExtensionFichier = VerifExtension(this.cheminFichierRecherche, "jpg");
                    this.testExtensionFichierBMP = VerifExtension(this.cheminFichierRecherche, "bmp");
                    if (this.testExtensionFichier == -1 && this.testExtensionFichierBMP == -1)
                    {
                        System.out.println("\nCe fichier n'est pas de type image\nVeuillez mettre un fichier .jpg ou .bmp\n");
                        this.etat_courant = Etat.Menu_image;
                    }
                    else
                    {
                        this.typeRequete=this.cheminFichierRecherche;
                        this.erreur = 0; this.nombreElemetTab = 0;
                        READ_WRITE_FICHIER.write(this.nomFichierWrite,"recup_CheminPour_Affichage(\"texte\", &cheminFichierRecherche)");
                        //tabResultatIMG = Comparaison_descripteur_image(this.erreur, this.cheminDescripteurIMG, this.cheminFichierRecherche, config.Nb_Bit_Fort, &nombreElemetTab); A VOIR
                        if (this.erreur != 0)
                        {
                            Erreur.afficherErreur(this.erreur);
                             
                        }
                        else
                        {
                            this.nombreElementTabFIN = LireResultat(tabResultatIMG, this.nombreElemetTab, "image", this.typeRequete, tabFileNameIMG, config->Nb_Mots_Cle, config->Similariter);
                            if (this.nombreElementTabFIN > 0)
                            {
                                System.out.println("[R] Retour\n\nPensez à fermer la fenetre apres l'avoir consulté pour poursuivre votre activité\n");
                                this.choix = visualiser_fichier(tabFileNameIMG, this.nombreElementTabFIN, "image");
                            }
                            if (this.choix == "Q")
                            {
                                System.out.println("\n\t\033[0;31mVous avez quitté le programme\033[0m\n\n\n\n");
                                READ_WRITE_FICHIER.write(this.nomFichierWrite,"exit(EXIT_SUCCESS)");
                            }
                        }
                        free(tabResultatIMG);
                    }
                }break;
                case 'R':
                {
                    this.etat_courant = Etat.Menu_Utilisateur;
                }break;
                case 'Q':
                {
                    System.out.println("\n\t\033[0;31mVous avez quitté le programme\033[0m\n\n\n\n");
                    READ_WRITE_FICHIER.write(this.nomFichierWrite,"exit(EXIT_SUCCESS)");
                }break;
                default:
                {
                    this.erreur = 11;
                    Erreur.afficherErreur(this.erreur);
                     
                    this.etat_courant = Etat.Menu_image;
                }break;
                }
            }break;

            case Etat.Menu_audio:
            {
                System.out.println("\n__________________________Recherche fichier audio__________________________\n");
                System.out.println("\nVeuillez faire votre choix  : \n");
                System.out.println("\n[1] Recherche par comparaison d'audio\n[R] Retour\n[Q] Quitter\n");
                this.choix = Clavier.entrerClavierChar();
                switch (this.choix)
                {
                case '1':
                {
                    // verification si le fichier existe
                    this.testExtensionFichier = -1;
                    while (this.testExtensionFichier == -1)
                    {
                        System.out.println("\nEntrez le chemin de votre fichier\n");
                        this.cheminFichierRecherche = Clavier.entrerClavierChar();
                        this.testExtensionFichier = FichierExist(cheminFichierRecherche);
                        if (this.testExtensionFichier == -1)
                        {
                            System.out.println("\nLe fichier n'existe pas\n");
                            System.out.println("\nVeuillez faire un choix pour continuer\n[1] Entrez un autre fichier\n[2] Retour \"Menu Général\"\n");
                            this.choix = Clavier.entrerClavierChar();
                            switch (this.choix)
                            {
                            case 2:
                            {
                                this.testExtensionFichier = 0;
                                this.etat_courant = Etat.Menu_Utilisateur;
                            }break;
                            case 1:
                            {
                                this.testExtensionFichier = -1;
                            }break;
                            default:
                            {
                                this.etat_courant = Etat.Menu_Utilisateur;
                            }break;
                            }
                        }
                    }
                    // verification si le fichier passer est un fichier texte
                    this.testExtensionFichier = VerifExtension(this.cheminFichierRecherche, "wav");
                    if (this.testExtensionFichier == -1)
                    {
                        System.out.println("\nCe fichier n'est pas de type audio\nVeuillez faire le choix de recherche qui vous correspond\n");
                        this.etat_courant = Etat.Menu_Utilisateur;
                    }
                    else
                    {
                        this.erreur = 0;
                        if (this.erreur != 0)
                        {
                            Erreur.afficherErreur(this.erreur);
                             
                        }
                        else
                        {
                            READ_WRITE_FICHIER.write(this.nomFichierWrite,"recup_CheminPour_Affichage(\"texte\", &cheminFichierRecherche)");
                            READ_WRITE_FICHIER.write(this.nomfichier,"comparaison_audio(config->Nb_Fenetre, config->Intervale, cheminFichierRecherche, cheminDescripteurAudio, &erreur, &nombreElemetTab)");
                            this.nombreElementTabFIN = LireResultat(tabResultatAudio, this.nombreElemetTab, "audio", this.cheminFichierRecherche, tabFileNameAUDIO, config->Nb_Mots_Cle, config->Similariter);

                            if (this.nombreElementTabFIN > 0)
                            {
                                System.out.println("[R] Retour\n\nPensez à fermer la fenetre apres l'avoir consulté pour poursuivre votre activité\n");
                                READ_WRITE_FICHIER.write(this.nomfichier,"visualiser_fichier(tabFileNameAUDIO, nombreElementTabFIN, \"audio\")");
                                this.choix = ; // A voir
                            }
                            if (this.choix == "Q")
                            {
                                System.out.println("\n\t\033[0;31mVous avez quitté le programme\033[0m\n\n\n\n");
                                READ_WRITE_FICHIER.write(this.nomFichierWrite,"exit(EXIT_SUCCESS)");
                            }
                            READ_WRITE_FICHIER.write(this.nomFichierWrite,"free(tabResultatAudio)");
                        }
                    }
                }break;
                case 'R':
                {
                    this.etat_courant = Etat.Menu_Utilisateur;
                }break;
                case 'Q':
                {
                    System.out.println("\n\tVous avez quitté le programme\n\n\n\n");
                    READ_WRITE_FICHIER.write(this.nomFichierWrite,"exit(EXIT_SUCCESS)");
                }break;
                default:
                {
                    this.erreur = 11;
                    Erreur.afficherErreur(this.erreur);
                     
                    this.etat_courant = Etat.Menu_audio;
                }break;
                }
            }break;

            default:
            {
                System.out.println("il y a une erreur, vous allez etre redirigez vers le \"Menu General\"\n");
                this.erreur = 14;
                if (this.erreur != 0)
                {
                    Erreur.afficherErreur(this.erreur);
                    
                     
                }
                this.etat_courant = Etat.Menu_general;
            }break;
        } 
    }
}