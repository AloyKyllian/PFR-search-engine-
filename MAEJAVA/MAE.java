
public class MAE {

	public static void lancerMAE() 
    {
        private String nomfichier = "tst.txt";
        private String nomfichierRead = "tst.txt";
        
        private String ERREUR;
        private Etat etat_courant = Etat.Menu_general;

        // variables a utiliser au cours du programme
        private char choix;

        private String chemin;
        private String requete;
        private int erreur = 0;
        private int nbTentative = 1;
        private String motCle;
        private int nombreElemetTab = 0;
        private int nombreElementTabFIN = 0;
        private boolean result = false;
        private LOGIN testlogin;
        private int test, test2;
        private String cheminDescripteurTxt= "../base_descripteur/base_descripteur_texte";
        private String cheminDescripteurIMG = "../base_descripteur/base_descripteur_image";
        private String cheminDescripteurAudio = "../base_descripteur/base_descripteur_audio";
        
        while(1)
        {
            switch (etat_courant)
            {
            case Etat.Menu_general:
            {
                System.out.println("\n__________________________Menu Général__________________________\n");
                System.out.println("\nVeuillez faire votre choix : \n");
                System.out.println("\n[1] Administrateur \n[2] Utilisateur \n[Q] Quitter\n");

                choix = Clavier.entrerClavierChar();
                switch (choix)
                {
                // case Administrateur:
                case '1':
                {
                    // Connexion
                    result = false;
                    do
                    {
                        // recuperer le boolean depuis le fichier texte
                        
                            System.out.println("\nConnexion ");
                            result = LOGIN.connexion();
                            if(result) 
                            {
                                System.out.println("Réussie\n\n") ; 
                                System.out.println("\nDirection \"Menu Administrateur\"\n");
                                etat_courant = Etat.Menu_Admin;
                            } 
                            else
                            {
                                System.out.println("Échouée\n\n");
                                nbTentative++;
                            }
                            if (nbTentative == 3 && result == false)
                            {
                                System.out.println("\nSouhaitez vous basculer en \"Mode Utilisateur\" ou essayer de se connecter une nouvelle fois ?\n");
                                System.out.println("\n[1] Mode Utilisateur\n[2] nouvelle tentative de connexion\n");
                                choix = Clavier.entrerClavierInt();
                                switch(choix)
                                case 1 :
                                {
                                    etat_courant = Etat.Menu_Utilisateur;
                                }break;
                                case 2 :
                                {
                                    System.out.println("\nVous devez attendre 30 secondes pour réessayer\n");
                                    Thread.sleep(30000);
                                    READ_WRITE_FICHIER.write(nomFichier,"viderBuffer()");
                                    System.out.println("\nFin des 30 secondes, Vous pouvez réessayer maintenant\n");
                                    nbTentative = 0;      
                                }break;
                                default :
                                     {
                                        System.out.println("Erreur de choix");
                                     }break;
                            
                            
                             }
                    } while (nbTentative < 4 && result == false);

                }break;
                //case Utilisateur:
                case '2':
                {
                    etat_courant = Etat.Menu_Utilisateur;
                }break;
                case 'Q':
                {
                    System.out.println("\n\t\033[0;31mVous avez quitté le programme\033[0m\n\n\n\n");
                    READ_WRITE_FICHIER.write(nomFichier",exit(EXIT_SUCCESS)");
                }break;
                default:
                {
                    erreur = 11;
                    READ_WRITE_FICHIER.write(nomFichier,"Afficher_Erreur(erreur, \"../Gestion-Erreur/Erreur.txt\", ERREUR)");
                    System.out.println(ERREUR);
                    etat_courant = Etat.Menu_general;
                }break;
            }break;

            case Etat.Menu_Admin:
            {
                System.out.println("\n__________________________Menu Administrateur__________________________\n");
                System.out.println("\nVeuillez faire votre choix  : \n");
                System.out.println("\n[1] Indexation\n[2] Configuration\n[3] Visualisation des recueils des descripteurs\n[4] Retour \"Mode Utilisateur\"\n");

                choix = Clavier.entrerClavierChar();

                switch (choix)
                {
                    case '1':
                    {
                        READ_WRITE_FICHIER.write(nomFichier,"indexation_generale_ferme(" + Config.get_Nb_Mots_Cle +"," + Config.getSimilariter + "," + Config.getNb_Bit_Fort + "," + Config.getNb_Fenetre + "," + Config.getIntervale + ", erreurImage, erreurAudio, erreurTexte, erreurIndex)");
                        // si ya une erreur j'arrete tt
                    }break;
                    case '2':
                    {
                        etat_courant = Etat.Menu_Configuration;
                    }break;
                    case '3':
                    {
                        // visualisation des descripteurs
                        etat_courant = Etat.Menu_Visualisation;
                    }break;
                    case '4':
                    {
                        etat_courant = Etat.Menu_Utilisateur;
                    }break;
                    default:
                    {
                        erreur = 11;
                        READ_WRITE_FICHIER.write(nomFichier,"Afficher_Erreur(erreur, \"../Gestion-Erreur/Erreur.txt\", ERREUR)");
                        System.out.println(ERREUR);
                        etat_courant = Etat.Menu_Admin;
                    }break;
                }
            }break;

            case Etat.Menu_Configuration:
            {
                System.out.println("\n__________________________Configuration__________________________\n");
                int Erreur = 0;
                READ_WRITE_FICHIER.write(nomfichier,"Lire_CONFIG(&Erreur)");
                //// A voir
                *config = READ_WRITE_FICHIER.read(nomfichier);
                READ_WRITE_FICHIER.write(nomFichier,"Afficher_CONFIG(" + Config.get_Nb_Mots_Cle +"," + Config.getSimilariter + "," + Config.getNb_Bit_Fort + "," + Config.getNb_Fenetre + "," + Config.getIntervale + ")");

                System.out.println("\nSi vous voulez changer une valeur, veuillez faire votre choix  : \n");
                System.out.println("\n[1] Nombre de mots-clé \t supérieur à 0\n[2] Similarité         \t entre 1 et 100\n[3] Nombre de bits     \t entre 1 et 8 \n[4] Nombre de fenetre  \t supeieur a 256 et une puissance de 2\n[5] Intervalle de temps\t superieur a 0 \n[R] Retour\n[Q] Déconnexion\n");
                choix = Clavier.entrerClavierChar();
                switch (choix)
                {
                case '1':
                {
                    System.out.println("Entrez le nombre de mot-clé voulu :\n");
                    *config = Lire_mot_cle(*config, &Erreur);
                    if (Erreur != 0)
                    {
                        READ_WRITE_FICHIER.write(nomFichier,"Afficher_Erreur(Erreur, \"../Gestion-Erreur/Erreur.txt\", ERREUR)");
                        System.out.println(ERREUR);
                        Erreur = 0;
                    }

                    READ_WRITE_FICHIER.write(nomFichier,"Ecrire_CONFIG(" + Config.get_Nb_Mots_Cle +"," + Config.getSimilariter + "," + Config.getNb_Bit_Fort + "," + Config.getNb_Fenetre + "," + Config.getIntervale + ", &Erreur)");
                    if (Erreur != 0)
                    {
                        READ_WRITE_FICHIER.write(nomFichier,"Afficher_Erreur(Erreur, \"../Gestion-Erreur/Erreur.txt\", ERREUR)");
                        System.out.println(ERREUR);
                        Erreur = 0;
                    }
                    System.out.println("\nSi vous avez changé votre configuration veuillez lancer l'indexation pour appliquer vos modifications\n");
                }break;
                case '2':
                {
                    // pour changer similarité
                    System.out.println("Entrez la valeur de similarité voulu :\n");
                    READ_WRITE_FICHIER.write(nomfichier,"Lire_similariter(" + Config.get_Nb_Mots_Cle +"," + Config.getSimilariter + "," + Config.getNb_Bit_Fort + "," + Config.getNb_Fenetre + "," + Config.getIntervale + ", &Erreur)");
                    *config = ; /// A voir
                    if (Erreur != 0)
                    {
                        READ_WRITE_FICHIER.write(nomFichier,"Afficher_Erreur(Erreur, \"../Gestion-Erreur/Erreur.txt\", ERREUR)");
                        System.out.println(ERREUR);
                        Erreur = 0;
                    }

                    READ_WRITE_FICHIER.write(nomFichier,"Ecrire_CONFIG(" + Config.get_Nb_Mots_Cle +"," + Config.getSimilariter + "," + Config.getNb_Bit_Fort + "," + Config.getNb_Fenetre + "," + Config.getIntervale + ", &Erreur)");
                    if (Erreur != 0)
                    {
                        READ_WRITE_FICHIER.write(nomFichier,"Afficher_Erreur(Erreur, \"../Gestion-Erreur/Erreur.txt\", ERREUR)");
                        System.out.println(ERREUR);
                        Erreur = 0;
                    }
                    System.out.println("\nSi vous avez changé votre configuration veuillez lancer l'indexation pour appliquer vos modifications\n");
                }break;
                case '3':
                {
                    // pour changer niveau
                    System.out.println("Entrez le nombre de bits voulu :\n");
                    *config = Lire_nb_bit_fort(*config, &Erreur);
                    if (Erreur != 0)
                    {
                        READ_WRITE_FICHIER.write(nomFichier,"Afficher_Erreur(Erreur, \"../Gestion-Erreur/Erreur.txt\", ERREUR)");
                        System.out.println( ERREUR);
                        Erreur = 0;
                    }

                    READ_WRITE_FICHIER.write(nomFichier,"Ecrire_CONFIG(" + Config.get_Nb_Mots_Cle +"," + Config.getSimilariter + "," + Config.getNb_Bit_Fort + "," + Config.getNb_Fenetre + "," + Config.getIntervale + ", &Erreur)");
                    if (Erreur != 0)
                    {
                        READ_WRITE_FICHIER.write(nomFichier,"Afficher_Erreur(Erreur, \"../Gestion-Erreur/Erreur.txt\", ERREUR)");
                        System.out.println( ERREUR);
                        Erreur = 0;
                    }
                    System.out.println("\nSi vous avez changé votre configuration veuillez lancer l'indexation pour appliquer vos modifications\n");
                }break;
                case '4':
                {
                    System.out.println("Entrez le nombre de fenetres voulu :\n");
                    " + Config.get_Nb_Mots_Cle +"," + Config.getSimilariter + "," + Config.getNb_Bit_Fort + "," + Config.getNb_Fenetre + "," + Config.getIntervale + " = Lire_nb_fenetre(*config, &Erreur);
                    if (Erreur != 0)
                    {
                        READ_WRITE_FICHIER.write(nomFichier,"Afficher_Erreur(Erreur, \"../Gestion-Erreur/Erreur.txt\", ERREUR)");
                        System.out.println(ERREUR);
                        Erreur = 0;
                    }
                    READ_WRITE_FICHIER.write(nomFichier,"Ecrire_CONFIG(" + Config.get_Nb_Mots_Cle +"," + Config.getSimilariter + "," + Config.getNb_Bit_Fort + "," + Config.getNb_Fenetre + "," + Config.getIntervale + ", &Erreur)");
                    if (Erreur != 0)
                    {
                        READ_WRITE_FICHIER.write(nomFichier,"Afficher_Erreur(Erreur, \"../Gestion-Erreur/Erreur.txt\", ERREUR)");
                        System.out.println(ERREUR);
                        Erreur = 0;
                    }
                    System.out.println("\nSi vous avez changé votre configuration veuillez lancer l'indexation pour appliquer vos modifications\n");
                }break;
                case '5':
                {
                    // fct pour changer l'intervalle de temps
                    System.out.println("Entrez l'intervalle de temps voulue :\n");
                    *config = Lire_intervale(*config, &Erreur);
                    if (Erreur != 0)
                    {
                        READ_WRITE_FICHIER.write(nomFichier,"Afficher_Erreur(Erreur, \"../Gestion-Erreur/Erreur.txt\", ERREUR)");
                        System.out.println(ERREUR);
                        Erreur = 0;
                    }
                    READ_WRITE_FICHIER.write(nomFichier,"Ecrire_CONFIG(" + Config.get_Nb_Mots_Cle +"," + Config.getSimilariter + "," + Config.getNb_Bit_Fort + "," + Config.getNb_Fenetre + "," + Config.getIntervale + ", &Erreur)");
                    if (Erreur != 0)
                    {
                        READ_WRITE_FICHIER.write(nomFichier,"Afficher_Erreur(Erreur, \"../Gestion-Erreur/Erreur.txt\", ERREUR)");
                        System.out.println(ERREUR);
                        Erreur = 0;
                    }
                    System.out.println("\nSi vous avez changé votre configuration veuillez lancer l'indexation pour appliquer vos modifications\n");
                }break;
                case 'R':
                {
                    etat_courant = Menu_Admin;
                }break;
                case 'Q':
                {
                    while (strcmp(&choix[0], "1") != 0)
                    {
                        System.out.println("\nVous vous êtes deconnecté, voulez vous retourner en \"Mode Utilisateur\" ?\n[1] Oui\n[2] Non\n");
                        choix = Clavier.entrerClavierChar();
                        switch (choix[0])
                        {
                        case oui:
                            strcpy(choix, "1");
                            etat_courant = Menu_Utilisateur;
                            break;
                        case non:
                            System.out.println("\n\t\033[0;31mVous avez quitté le programme\033[0m\n\n\n\n");
                            READ_WRITE_FICHIER.write(nomFichier,"exit(EXIT_SUCCESS)");
                            break;
                        default:
                            erreur = 11;
                            READ_WRITE_FICHIER.write(nomFichier,"Afficher_Erreur(erreur, \"../Gestion-Erreur/Erreur.txt\", ERREUR)");
                            System.out.println(ERREUR);
                            etat_courant = Etat.Menu_Configuration;
                            break;
                        }
                    }
                }break;
                default:
                {
                    erreur = 11;
                    READ_WRITE_FICHIER.write(nomFichier,"Afficher_Erreur(erreur, \"../Gestion-Erreur/Erreur.txt\", ERREUR)");
                    System.out.println(ERREUR);
                    etat_courant = Menu_Configuration;
                }break;
                }
            }break;

            case Etat.Menu_Visualisation:
            {
                System.out.println("\n__________________________Visualisation des recueils des descripteurs__________________________\n");
                System.out.println("\nVeuillez faire votre choix  : \n");
                System.out.println("\n[1] Texte\n[2] Image\n[3] Audio \n[R] Retour\n[Q] Déconnexion\n");
                choix = Clavier.entrerClavierChar();
                switch (choix)
                {
                case '1':
                {
                    READ_WRITE_FICHIER.write(nomfichier,"system(\"chmod a-w ../base_descripteur/base_descripteur_texte\");");
                    
                    System.out.println("\nPenser a fermé la fenetre apres l'avoir consulter pour poursuivre votre activité\n");
                    READ_WRITE_FICHIER.write(nomfichier,"system(\"gedit ../base_descripteur/base_descripteur_texte\"");
                    READ_WRITE_FICHIER.write(nomfichier,"system(\"chmod 777 ../base_descripteur/base_descripteur_texte\"");
                }break;
                case '2':
                {
                    READ_WRITE_FICHIER.write(nomfichier,"system(\"chmod a-w ../base_descripteur/base_descripteur_image\"");
                    System.out.println("\nPenser a fermé la fenetre apres l'avoir consulter pour poursuivre votre activité\n");
                    READ_WRITE_FICHIER.write(nomfichier,"system(\"gedit ../base_descripteur/base_descripteur_image\"");
                    READ_WRITE_FICHIER.write(nomfichier,"system(\"chmod 777 ../base_descripteur/base_descripteur_image\"");
                }break;
                case '3':
                {
                    READ_WRITE_FICHIER.write(nomfichier,"system(\"chmod a-w ../base_descripteur/base_descripteur_audio\"");
                    System.out.println("\nPenser a fermé la fenetre apres l'avoir consulter pour poursuivre votre activité\n");
                    READ_WRITE_FICHIER.write(nomfichier,"system(\"gedit ../base_descripteur/base_descripteur_audio\"");
                    READ_WRITE_FICHIER.write(nomfichier,"system(\"chmod 777 ../base_descripteur/base_descripteur_audio\"");
                }break;
                case 'R':
                {
                    etat_courant = Etat.Menu_Admin;
                }break;
                case 'Q':
                {
                    while (choix == '1')
                    {
                        System.out.println("\nVous vous êtes deconnecté, voulez vous retourner en \"Mode Utilisateur\" ?\n[1] Oui\n[2] Non\n");
                        choix = Clavier.entrerClavierChar();
                        switch (choix)
                        {
                        case 1:
                            etat_courant = Etat.Menu_Utilisateur;
                            break;
                        case 2:
                            System.out.println("\n\t\033[0;31mVous avez quitté le programme\033[0m\n\n\n\n");
                            READ_WRITE_FICHIER.write(nomFichier,"exit(EXIT_SUCCESS)");
                            break;
                        default:
                            System.out.println("\nMauvais choix, vous allez etre redirigé vers \"Menu visualisation\"\n");
                            etat_courant = Etat.Menu_Visualisation;
                            break;
                        }
                    }
                }break;
                default:
                {
                    erreur = 11;
                    READ_WRITE_FICHIER.write(nomFichier,"Afficher_Erreur(erreur, \"../Gestion-Erreur/Erreur.txt\", ERREUR)");
                    System.out.println(ERREUR);
                    etat_courant = Etat.Menu_Visualisation;
                }break;
                }
            }break;

            case Etat.Menu_Utilisateur:
            {
                System.out.println("\n__________________________Menu utilisateur__________________________\n");
                System.out.println("\nVeuillez faire votre choix  : \n");
                System.out.println("\n[1] Recherche fichier texte\n[2] Recherche fichier image\n[3] Recherche fichier audio \n[R] Retour\n[Q] Déconnexion\n");
                choix = Clavier.entrerClavierChar();
                switch (choix)
                {
                case '1':
                {
                    etat_courant = Etat.Menu_texte;
                }break;
                case '2':
                {
                    etat_courant = Etat.Menu_image;
                }break;
                case '3':
                {
                    etat_courant = Etat.Menu_audio;
                }break;
                case 'R':
                {
                    etat_courant = Etat.Menu_general;
                }break;
                case 'Q':
                {
                    System.out.println("\n\t\033[0;31mVous avez quitté le programme\033[0m\n\n\n\n");
                    READ_WRITE_FICHIER.write(nomFichier,"exit(EXIT_SUCCESS)");
                }break;
                default:
                {
                    erreur = 11;
                    READ_WRITE_FICHIER.write(nomFichier,"Afficher_Erreur(erreur, \"../Gestion-Erreur/Erreur.txt\", ERREUR)");
                    System.out.println(ERREUR);
                    etat_courant = Etat.Menu_Utilisateur;
                }break;
                }
            }break;

            case Etat.Menu_texte:
            {

                System.out.println("\n__________________________Recherche fichier texte__________________________\n");
                System.out.println("\nVeuillez faire votre choix  : \n");
                System.out.println("\n[1] Recherche par mot-clé\n[2] Recherche par comparaison de textes\n[R] Retour\n[Q] Quitter\n");
                choix = Clavier.entrerClavierChar();
                switch (choix)
                {
                case '1':
                {
                    char *tabFileNameMOT[700];

                    erreur = 0;
                    System.out.println("\nEntrez votre mot-clé\n");
                    motCle=Clavier.entrerClavierString();
                    tab_similaire *tabResultatMot = malloc(100 * sizeof(tab_similaire));
                    READ_WRITE_FICHIER.write(nomFichier,"rechercheMot(motCle, cheminDescripteurTxt, tabResultatMot, config->Nb_Mots_Cle, &nombreElemetTab, &erreur)");
                    if (erreur == 7)
                    {
                        READ_WRITE_FICHIER.write(nomFichier,"Afficher_Erreur(erreur, \"../Gestion-Erreur/Erreur.txt\", ERREUR)");
                        System.out.println(ERREUR);
                    }
                    else
                    {
                        nombreElementTabFIN = LireResultat(tabResultatMot, nombreElemetTab, "rechercheMot", motCle, tabFileNameMOT, config->Nb_Mots_Cle, config->Similariter);
                        READ_WRITE_FICHIER.write(nomFichier,"free(tabResultatMot)");
                        if (nombreElementTabFIN > 0)
                        {

                            System.out.println("[R] Retour\n\nPensez à fermer l'editeur de texte apres l'avoir consulté pour poursuivre votre activité\n");
                            choix[0] = visualiser_fichier(tabFileNameMOT, nombreElementTabFIN, "texte");
                        }
                        if (choix== 'Q')
                        {
                            System.out.println("\n\t\033[0;31mVous avez quitté le programme\033[0m\n\n\n\n");
                            READ_WRITE_FICHIER.write(nomFichier,"exit(EXIT_SUCCESS)");
                        }
                    }
                }break;

                case '2':
                {
                    // verification si le fichier existe
                    test = -1;
                    while (test == -1)
                    {
                        System.out.println("\nEntrez le chemin de votre fichier\n");
                        chemin = Clavier.entrerClavierString();
                        test = FichierExist(chemin);
                        if (test == -1)
                        {
                            System.out.println("\nLe fichier n'existe pas\n");
                            System.out.println("\nVeuillez faire un choix pour continuer\n[1] Entrer un autre fichier\n[2] Retour \"Menu Général\"\n");
                            choix = Clavier.entrerClavierChar();
                            switch (choix)
                            {
                            case '1':
                                test = 0;
                                etat_courant = Etat.Menu_Utilisateur;
                                break;
                            case '2':
                                test = -1;
                                break;
                            default:
                                etat_courant = Etat.Menu_Utilisateur;
                                break;
                            }
                        }
                    }
                    // verification si le fichier passer est un fichier texte
                    test = VerifExtension(chemin, "xml");
                    if (test == -1)
                    {
                        System.out.println("\nCe fichier n'est pas de type texte\nVeuiller mettre un fichier texte\n");
                        etat_courant = Menu_texte;
                    }
                    else
                    {
                        erreur = 0, nombreElemetTab = 0;
                        tab_similaire *tabResultatTexte = malloc(100 * sizeof(tab_similaire));
                        char *tabFileNameTEXTE[700];
                        tabResultatTexte = comparaison_texte(config->Nb_Mots_Cle, chemin, cheminDescripteurTxt, &erreur, &nombreElemetTab);
                        if (erreur == 7 || erreur == 1)
                        {
                            READ_WRITE_FICHIER.write(nomFichier,"Afficher_Erreur(erreur, \"../Gestion-Erreur/Erreur.txt\", ERREUR)");
                            System.out.println(ERREUR);
                        }
                        nombreElementTabFIN = LireResultat(tabResultatTexte, nombreElemetTab, "texte", chemin, tabFileNameTEXTE, config->Nb_Mots_Cle, config->Similariter);
                        READ_WRITE_FICHIER.write(nomFichier,"free(tabResultatTexte)");
                        if (nombreElementTabFIN > 0)
                        {
                            System.out.println("[R] Retour\n\nPensez à fermer l'editeur de texte apres l'avoir consulté pour poursuivre votre activité\n");
                            choix[0] = visualiser_fichier(tabFileNameTEXTE, nombreElementTabFIN, "texte");
                        }
                        if (strcmp(choix, "Q") == 0)
                        {
                            System.out.println("\n\t\033[0;31mVous avez quitté le programme\033[0m\n\n\n\n");
                            READ_WRITE_FICHIER.write(nomFichier,exit(EXIT_SUCCESS));
                        }
                    }
                }break;
                case 'R':
                {
                    etat_courant = Etat.Menu_Utilisateur;
                }break;
                case 'Q':
                {
                    System.out.println("\n\t\033[0;31mVous avez quitté le programme\033[0m\n\n\n\n");
                    READ_WRITE_FICHIER.write(nomFichier,"exit(EXIT_SUCCESS)");
                }break;
                default:
                {
                    erreur = 11;
                    READ_WRITE_FICHIER.write(nomFichier,"Afficher_Erreur(erreur, "../Gestion-Erreur/Erreur.txt", ERREUR)");
                    System.out.println(ERREUR);
                    etat_courant = Etat.Menu_texte;
                }break;
                }
            }break;

            case Etat.Menu_image:
            {

                System.out.println("\n__________________________Recherche fichier image__________________________\n");
                System.out.println("\nVeuillez faire votre choix  : \n");
                System.out.println("\n[1] Recherche par comparaison d'images\n[R] Retour\n[Q] Quitter\n");
                choix = Clavier.entrerClavierChar();
                switch (choix)
                {
                case '1':
                    // verification si le fichier existe
                    test = -1;
                    while (test == -1)
                    {
                        System.out.println("\nEntrez le chemin de votre fichier\n");
                        scanf("%s", chemin);
                        test = FichierExist(chemin);
                        if (test == -1)
                        {
                            System.out.println("\nLe fichier n'existe pas\n");
                            System.out.println("\nVeuillez faire un choix pour continuer\n[1] Entrez un autre fichier\n[2] Retour \"Menu Général\"\n");
                            choix = Clavier.entrerClavierChar();
                            switch (choix)
                            {
                            case '1':
                            {
                                test = 0;
                                etat_courant = Etat.Menu_Utilisateur;
                            }break;
                            case '2':
                            {
                                test = -1;
                            }break;
                            default:
                            {
                                etat_courant = Etat.Menu_Utilisateur;
                            }break;
                            }
                        }
                    }
                    // verification si le fichier passer est un fichier texte
                    test = VerifExtension(chemin, "jpg");
                    test2 = VerifExtension(chemin, "bmp");
                    if (test == -1 && test2 == -1)
                    {
                        System.out.println("\nCe fichier n'est pas de type image\nVeuillez mettre un fichier .jpg ou .bmp\n");
                        etat_courant = Etat.Menu_image;
                    }
                    else
                    {
                        strcpy(requete, chemin);
                        erreur = 0, nombreElemetTab = 0;
                        tab_similaire *tabResultatIMG;
                        char *tabFileNameIMG[700];
                        READ_WRITE_FICHIER.write(nomFichier,"recup_CheminPour_Affichage(\"texte\", &chemin)");
                        tabResultatIMG = Comparaison_descripteur_image(&erreur, cheminDescripteurIMG, chemin, config->Nb_Bit_Fort, &nombreElemetTab);
                        if (erreur != 0)
                        {
                            READ_WRITE_FICHIER.write(nomFichier,"Afficher_Erreur(erreur, \"../Gestion-Erreur/Erreur.txt\", ERREUR)");
                            System.out.println(ERREUR);
                        }
                        else
                        {
                            nombreElementTabFIN = LireResultat(tabResultatIMG, nombreElemetTab, "image", requete, tabFileNameIMG, config->Nb_Mots_Cle, config->Similariter);
                            if (nombreElementTabFIN > 0)
                            {
                                System.out.println("[R] Retour\n\nPensez à fermer la fenetre apres l'avoir consulté pour poursuivre votre activité\n");
                                choix[0] = visualiser_fichier(tabFileNameIMG, nombreElementTabFIN, "image");
                            }
                            if (choix == "Q")
                            {
                                System.out.println("\n\t\033[0;31mVous avez quitté le programme\033[0m\n\n\n\n");
                                READ_WRITE_FICHIER.write(nomFichier,"exit(EXIT_SUCCESS)");
                            }
                        }
                        free(tabResultatIMG);
                    }
                }break;
                case 'R':
                {
                    etat_courant = Etat.Menu_Utilisateur;
                }break;
                case 'Q':
                {
                    System.out.println("\n\t\033[0;31mVous avez quitté le programme\033[0m\n\n\n\n");
                    READ_WRITE_FICHIER.write(nomFichier,"exit(EXIT_SUCCESS)");
                }break;
                default:
                {
                    erreur = 11;
                    READ_WRITE_FICHIER.write(nomFichier,"Afficher_Erreur(erreur, \"../Gestion-Erreur/Erreur.txt\", ERREUR)");
                    System.out.println(ERREUR);
                    etat_courant = Etat.Menu_image;
                }break;
                }
            }break;

            case Etat.Menu_audio:
            {
                System.out.println("\n__________________________Recherche fichier audio__________________________\n");
                System.out.println("\nVeuillez faire votre choix  : \n");
                System.out.println("\n[1] Recherche par comparaison d'audio\n[R] Retour\n[Q] Quitter\n");
                choix = Clavier.entrerClavierChar();
                switch (choix)
                {
                case '1':
                {
                    // verification si le fichier existe
                    test = -1;
                    while (test == -1)
                    {
                        System.out.println("\nEntrez le chemin de votre fichier\n");
                        scanf("%s", chemin);
                        test = FichierExist(chemin);
                        if (test == -1)
                        {
                            System.out.println("\nLe fichier n'existe pas\n");
                            System.out.println("\nVeuillez faire un choix pour continuer\n[1] Entrez un autre fichier\n[2] Retour \"Menu Général\"\n");
                            choix = Clavier.entrerClavierChar();
                            switch (choix)
                            {
                            case 2:
                            {
                                test = 0;
                                etat_courant = Etat.Menu_Utilisateur;
                            }break;
                            case 1:
                            {
                                test = -1;
                            }break;
                            default:
                            {
                                etat_courant = Etat.Menu_Utilisateur;
                            }break;
                            }
                        }
                    }
                    // verification si le fichier passer est un fichier texte
                    test = VerifExtension(chemin, "wav");
                    if (test == -1)
                    {
                        System.out.println("\nCe fichier n'est pas de type audio\nVeuillez faire le choix de recherche qui vous correspond\n");
                        etat_courant = Etat.Menu_Utilisateur;
                    }
                    else
                    {
                        erreur = 0;
                        if (erreur != 0)
                        {
                            READ_WRITE_FICHIER.write(nomFichier,"Afficher_Erreur(erreur, \"../Gestion-Erreur/Erreur.txt\", ERREUR)");
                            System.out.println(ERREUR);
                        }
                        else
                        {
                            READ_WRITE_FICHIER.write(nomFichier,"recup_CheminPour_Affichage(\"texte\", &chemin)");
                            READ_WRITE_FICHIER.write(nomfichier,"comparaison_audio(config->Nb_Fenetre, config->Intervale, chemin, cheminDescripteurAudio, &erreur, &nombreElemetTab)");
                            nombreElementTabFIN = LireResultat(tabResultatAudio, nombreElemetTab, "audio", chemin, tabFileNameAUDIO, config->Nb_Mots_Cle, config->Similariter);

                            if (nombreElementTabFIN > 0)
                            {
                                System.out.println("[R] Retour\n\nPensez à fermer la fenetre apres l'avoir consulté pour poursuivre votre activité\n");
                                READ_WRITE_FICHIER.write(nomfichier,"visualiser_fichier(tabFileNameAUDIO, nombreElementTabFIN, \"audio\")");
                                choix = ; // A voir
                            }
                            if (choix == "Q")
                            {
                                System.out.println("\n\t\033[0;31mVous avez quitté le programme\033[0m\n\n\n\n");
                                READ_WRITE_FICHIER.write(nomFichier,"exit(EXIT_SUCCESS)");
                            }
                            READ_WRITE_FICHIER.write(nomFichier,"free(tabResultatAudio)");
                        }
                    }
                }break;
                case 'R':
                {
                    etat_courant = Etat.Menu_Utilisateur;
                }break;
                case 'Q':
                {
                    System.out.println("\n\tVous avez quitté le programme\n\n\n\n");
                    READ_WRITE_FICHIER.write(nomFichier,"exit(EXIT_SUCCESS)");
                }break;
                default:
                {
                    erreur = 11;
                    READ_WRITE_FICHIER.write(nomFichier,"Afficher_Erreur(erreur, \"../Gestion-Erreur/Erreur.txt\", ERREUR)");
                    System.out.println(ERREUR);
                    etat_courant = Etat.Menu_audio;
                }break;
                }
            }break;

            default:
            {
                System.out.println("il y a une erreur, vous allez etre redirigez vers le \"Menu General\"\n");
                erreur = 14;
                if (erreur != 0)
                {
                    READ_WRITE_FICHIER.write(nomFichier,"Afficher_Erreur(erreur, \"../Gestion-Erreur/Erreur.txt\", ERREUR)");
                    
                    System.out.println(ERREUR);
                }
                etat_courant = Etat.Menu_general;
            }break;
        }   
    }
}