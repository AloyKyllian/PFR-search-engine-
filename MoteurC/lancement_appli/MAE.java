
import java.util.ArrayList;
import java.util.Arrays;

import javax.security.auth.x500.X500Principal;

public class MAE {
    private String strERREUR;
    private Etat etat_courant = Etat.Menu_general;

    // variables a utiliser au cours du programme
    private char choixRequete;
    private char choix;
    private Config config;
    LireResultat lireResultat;
    private String cheminFichierRecherche;
    private String typeRequete;
    private int erreur = 0;
    private int nbTentativeConnexion = 1;
    private String motCleRecherche;
    private int nombreElemetTab = 0;
    private int nombreElementTabFIN = 0;
    private boolean result = false;
    private LOGIN testlogin;
    private int testExtensionFichier, testExtensionFichierBMP;
    private boolean bmp;
    private boolean isfichierExist;
    private boolean isverifext;
    private final String cheminDescripteurTxt = ListCheminFichier.cheminDescripteurTexte;
    private final String cheminDescripteurIMG = ListCheminFichier.cheminDescripteurImage;
    private final String cheminDescripteurAudio = ListCheminFichier.cheminDescripteurAudio;
    private final LancerExecutable LancerExe;
    private String stringLue;

    public MAE() {
        this.config = new Config();
        this.config.Lire_config();
        LancerExe = new LancerExecutable();
        lireResultat = new LireResultat();
    }

    public static void main(String[] args) {
        MAE mae = new MAE();
        mae.lancerMAE();
    }

    public void lancerMAE() {
        while (true) {
            READ_WRITE_FICHIER.writeOn(ListCheminFichier.cheminPontJC, "indexationOuverte()");
            LancerExe.lancerOut();
            this.stringLue = READ_WRITE_FICHIER.read(ListCheminFichier.cheminPontCJ);
            System.out.println(this.stringLue);
            // System.out.println(ListCheminFichier.cheminAudio);
            switch (this.etat_courant) {
                case Menu_general: {

                    System.out.println("\n__________________________Menu General__________________________\n");
                    System.out.println("\nVeuillez faire votre choix : \n");
                    System.out.println("\n[1] Administrateur \n[2] Utilisateur \n[Q] Quitter\n");

                    this.choix = Clavier.entrerClavierChar();
                    switch (this.choix) {
                        // case Administrateur:
                        case '1': {
                            // Connexion
                            this.result = false;
                            do {
                                // recuperer le boolean depuis le fichier texte

                                System.out.println("\nConnexion ");
                                this.result = LOGIN.connexion();
                                if (this.result) {
                                    System.out.println("Réussie\n\n");
                                    System.out.println("\nDirection \"Menu Administrateur\"\n");
                                    this.etat_courant = Etat.Menu_Admin;
                                } else {
                                    System.out.println("Échouée\n\n");
                                    this.nbTentativeConnexion++;
                                }
                                if (this.nbTentativeConnexion == 3 && this.result == false) {
                                    System.out.println(
                                            "\nSouhaitez vous basculer en \"Mode Utilisateur\" ou essayer de se connecter une nouvelle fois ?\n");
                                    System.out.println("\n[1] Mode Utilisateur\n[2] nouvelle tentative de connexion\n");
                                    this.choix = Clavier.entrerClavierChar();
                                    switch (this.choix) {
                                        case '1': {
                                            this.etat_courant = Etat.Menu_Utilisateur;
                                        }
                                            break;
                                        case '2': {
                                            System.out.println("\nVous devez attendre 30 secondes pour réessayer\n");
                                            try {
                                                Thread.sleep(10000);
                                            } catch (InterruptedException e) {
                                                e.printStackTrace();
                                            }

                                            System.out.println(
                                                    "\nFin des 30 secondes, Vous pouvez réessayer maintenant\n");
                                            this.nbTentativeConnexion = 0;
                                        }
                                            break;
                                        default: {
                                            System.out.println("Erreur de choix");
                                        }
                                            break;
                                    }
                                }
                            } while ((this.nbTentativeConnexion < 4) && (this.result == false));

                        }
                            break;
                        // case Utilisateur:
                        case '2': {
                            this.etat_courant = Etat.Menu_Utilisateur;
                        }
                            break;
                        case 'Q': {
                            System.out.println("\n\tVous avez quitté le programme\n\n\n\n");
                            System.exit(1);
                        }
                            break;
                        default: {
                            this.erreur = 11;
                            Erreur.afficherErreur(this.erreur);
                            this.etat_courant = Etat.Menu_general;
                        }
                            break;
                    }
                    break;
                }

                case Menu_Admin: {
                    System.out.println("\n__________________________Menu Administrateur__________________________\n");
                    System.out.println("\nVeuillez faire votre choix  : \n");
                    System.out.println(
                            "\n[1] Indexation\n[2] Configuration\n[3] Visualisation des recueils des descripteurs\n[4] Retour \"Mode Utilisateur\"\n");

                    this.choix = Clavier.entrerClavierChar();

                    switch (this.choix) {
                        case '1': {
                            READ_WRITE_FICHIER.writeOn(ListCheminFichier.cheminPontJC, "indexationGeneraleFerme()");
                            LancerExe.lancerOut();
                            this.stringLue = READ_WRITE_FICHIER.read(ListCheminFichier.cheminPontCJ);
                            System.out.println(this.stringLue);
                            // si ya une erreur j'arrete tt
                        }
                            break;
                        case '2': {
                            this.etat_courant = Etat.Menu_Configuration;
                        }
                            break;
                        case '3': {
                            // visualisation des descripteurs
                            this.etat_courant = Etat.Menu_Visualisation;
                        }
                            break;
                        case '4': {
                            this.etat_courant = Etat.Menu_Utilisateur;
                        }
                            break;
                        default: {
                            this.erreur = 11;
                            Erreur.afficherErreur(this.erreur);

                            this.etat_courant = Etat.Menu_Admin;
                        }
                            break;
                    }
                }
                    break;

                case Menu_Configuration: {
                    System.out.println("\n__________________________Configuration__________________________\n");
                    int erreur = 0;
                    String configstr = "";
                    config.Lire_config();
                    configstr = config.afficher_config();
                    System.out.println(configstr);

                    System.out.println("\nSi vous voulez changer une valeur, veuillez faire votre choix  : \n");
                    System.out.println(
                            "\n[1] Nombre de mots-clé \t supérieur à 0\n[2] Similarité         \t entre 1 et 100\n[3] Nombre de bits     \t entre 1 et 8 \n[4] Nombre de fenetre  \t supeieur a 256 et une puissance de 2\n[5] Intervalle de temps\t superieur a 0 \n[R] Retour\n[Q] Déconnexion\n");
                    this.choix = Clavier.entrerClavierChar();
                    switch (this.choix) {
                        case '1': {
                            System.out.println("Entrez le nombre de mot-clé voulu :\n");

                            config.setNb_Mots_Cle();
                            config.ecrire_config();
                            if (this.erreur != 0) {
                                Erreur.afficherErreur(this.erreur);

                                this.erreur = 0;
                            }
                            if (this.erreur != 0) {
                                Erreur.afficherErreur(this.erreur);
                                this.erreur = 0;
                            }
                            System.out.println(
                                    "\nSi vous avez changé votre configuration veuillez lancer l'indexation pour appliquer vos modifications\n");
                        }
                            break;
                        case '2': {
                            // pour changer similarité
                            System.out.println("Entrez la valeur de similarité voulu :\n");
                            config.setSimilariter();
                            config.ecrire_config();
                            if (this.erreur != 0) {
                                Erreur.afficherErreur(this.erreur);
                                this.erreur = 0;
                            }

                            if (this.erreur != 0) {
                                Erreur.afficherErreur(this.erreur);

                                this.erreur = 0;
                            }
                            System.out.println(
                                    "\nSi vous avez changé votre configuration veuillez lancer l'indexation pour appliquer vos modifications\n");
                        }
                            break;
                        case '3': {
                            // pour changer niveau
                            System.out.println("Entrez le nombre de bits voulu :\n");
                            config.setNb_Bit_Fort();
                            config.ecrire_config();
                            if (this.erreur != 0) {
                                Erreur.afficherErreur(this.erreur);
                                this.erreur = 0;
                            }
                            if (this.erreur != 0) {
                                Erreur.afficherErreur(this.erreur);
                                this.erreur = 0;
                            }
                            System.out.println(
                                    "\nSi vous avez changé votre configuration veuillez lancer l'indexation pour appliquer vos modifications\n");
                        }
                            break;
                        case '4': {
                            System.out.println("Entrez le nombre de fenetres voulu :\n");
                            config.setNb_Fenetre();
                            config.ecrire_config();
                            if (this.erreur != 0) {
                                Erreur.afficherErreur(this.erreur);

                                this.erreur = 0;
                            }
                            if (this.erreur != 0) {
                                Erreur.afficherErreur(this.erreur);

                                this.erreur = 0;
                            }
                            System.out.println(
                                    "\nSi vous avez changé votre configuration veuillez lancer l'indexation pour appliquer vos modifications\n");
                        }
                            break;
                        case '5': {
                            // fct pour changer l'intervalle de temps
                            System.out.println("Entrez l'intervalle de temps voulue :\n");
                            config.setIntervale();
                            config.ecrire_config();
                            if (this.erreur != 0) {
                                Erreur.afficherErreur(this.erreur);

                                this.erreur = 0;
                            }
                            if (this.erreur != 0) {
                                Erreur.afficherErreur(this.erreur);

                                this.erreur = 0;
                            }
                            System.out.println(
                                    "\nSi vous avez changé votre configuration veuillez lancer l'indexation pour appliquer vos modifications\n");
                        }
                            break;
                        case 'R': {
                            this.etat_courant = Etat.Menu_Admin;
                        }
                            break;
                        case 'Q': {
                            while (this.choix == '1') {
                                System.out.println(
                                        "\nVous vous êtes deconnecté, voulez vous retourner en \"Mode Utilisateur\" ?\n[1] Oui\n[2] Non\n");
                                this.choix = Clavier.entrerClavierChar();
                                switch (this.choix) {
                                    case 1:
                                        this.etat_courant = Etat.Menu_Utilisateur;
                                        break;
                                    case 2:
                                        System.out.println("\n\tVous avez quitté le programme\n\n\n\n");

                                        System.exit(1);
                                    default:
                                        this.erreur = 11;
                                        Erreur.afficherErreur(this.erreur);
                                        this.etat_courant = Etat.Menu_Configuration;
                                        break;
                                }
                            }
                        }
                            break;
                        default: {
                            this.erreur = 11;
                            Erreur.afficherErreur(this.erreur);
                            this.etat_courant = Etat.Menu_Configuration;
                        }
                            break;
                    }
                }
                    break;

                case Menu_Visualisation: {
                    System.out.println(
                            "\n__________________________Visualisation des recueils des descripteurs__________________________\n");
                    System.out.println("\nVeuillez faire votre choix  : \n");
                    System.out.println("\n[1] Texte\n[2] Image\n[3] Audio \n[R] Retour\n[Q] Déconnexion\n");
                    this.choix = Clavier.entrerClavierChar();
                    switch (this.choix) {
                        case '1': {
                            System.out.println(
                                    "\nPenser a fermé la fenetre apres l'avoir consulter pour poursuivre votre activité\n");
                            READ_WRITE_FICHIER.writeOn(ListCheminFichier.cheminPontJC, "systemTexte()");
                            LancerExe.lancerOut();
                            this.stringLue = READ_WRITE_FICHIER.read(ListCheminFichier.cheminPontCJ);
                            System.out.println(this.stringLue);
                            // recuperer dans le fichier xecutabe
                        }
                            break;
                        case '2': {
                            System.out.println(
                                    "\nPenser a fermé la fenetre apres l'avoir consulter pour poursuivre votre activité\n");
                            READ_WRITE_FICHIER.writeOn(ListCheminFichier.cheminPontJC, "systemImage()");
                            LancerExe.lancerOut();
                            this.stringLue = READ_WRITE_FICHIER.read(ListCheminFichier.cheminPontCJ);
                            System.out.println(this.stringLue);
                        }
                            break;
                        case '3': {
                            System.out.println(
                                    "\nPenser a fermé la fenetre apres l'avoir consulter pour poursuivre votre activité\n");
                            READ_WRITE_FICHIER.writeOn(ListCheminFichier.cheminPontJC, "systemAudio()");
                            LancerExe.lancerOut();
                            this.stringLue = READ_WRITE_FICHIER.read(ListCheminFichier.cheminPontCJ);
                            System.out.println(this.stringLue);
                        }
                            break;
                        case 'R': {
                            this.etat_courant = Etat.Menu_Admin;
                        }
                            break;
                        case 'Q': {
                            this.choix = '1';
                            while (this.choix == '1') {
                                System.out.println(
                                        "\nVous vous êtes deconnecté, voulez vous retourner en \"Mode Utilisateur\" ?\n[1] Oui\n[2] Non\n");
                                this.choix = Clavier.entrerClavierChar();
                                switch (this.choix) {
                                    case '1':
                                        this.etat_courant = Etat.Menu_Utilisateur;
                                        this.choix = '0';
                                        break;
                                    case '2':
                                        System.out.println("\n\tVous avez quitté le programme\n\n\n\n");
                                        System.exit(1);
                                        break;
                                    default:
                                        System.out.println(
                                                "\nMauvais choix, vous allez etre redirigé vers \"Menu visualisation\"\n");
                                        this.choix = '0';
                                        this.etat_courant = Etat.Menu_Visualisation;
                                        break;
                                }
                            }
                        }
                            break;
                        default: {
                            this.erreur = 11;
                            Erreur.afficherErreur(this.erreur);

                            this.etat_courant = Etat.Menu_Visualisation;
                        }
                            break;
                    }
                }
                    break;

                case Menu_Utilisateur: {
                    System.out.println("\n__________________________Menu utilisateur__________________________\n");
                    System.out.println("\nVeuillez faire votre choix  : \n");
                    System.out.println(
                            "\n[1] Recherche fichier texte\n[2] Recherche fichier image\n[3] Recherche fichier audio \n[R] Retour\n[Q] Déconnexion\n");
                    this.choix = Clavier.entrerClavierChar();
                    switch (this.choix) {
                        case '1': {
                            this.etat_courant = Etat.Menu_texte;
                        }
                            break;
                        case '2': {
                            this.etat_courant = Etat.Menu_image;
                        }
                            break;
                        case '3': {
                            this.etat_courant = Etat.Menu_audio;
                        }
                            break;
                        case 'R': {
                            this.etat_courant = Etat.Menu_general;
                        }
                            break;
                        case 'Q': {
                            System.out.println("\n\tVous avez quitté le programme\n\n\n\n");
                            System.exit(1);
                        }
                            break;
                        default: {
                            this.erreur = 11;
                            Erreur.afficherErreur(this.erreur);

                            this.etat_courant = Etat.Menu_Utilisateur;
                        }
                            break;
                    }
                }
                    break;

                case Menu_texte: {

                    System.out
                            .println("\n__________________________Recherche fichier texte__________________________\n");
                    System.out.println("\nVeuillez faire votre choix  : \n");
                    System.out.println(
                            "\n[1] Recherche par mot-clé\n[2] Recherche par comparaison de textes\n[R] Retour\n[Q] Quitter\n");
                    this.choix = Clavier.entrerClavierChar();
                    switch (this.choix) {
                        case '1': {

                            this.erreur = 0;
                            System.out
                                    .println("\nVoulez vous faire\n[1] Une requete complexe\n[2] Une requete simple\n");

                            this.choixRequete = Clavier.entrerClavierChar();
                            switch (this.choixRequete) {
                                case '2': {
                                    System.out.println("\nEntrez votre mot-clé\n");
                                    this.motCleRecherche = Clavier.entrerClavierString();
                                    READ_WRITE_FICHIER.writeOn(ListCheminFichier.cheminPontJC,
                                            "rechercheMot(" + this.motCleRecherche + ")");
                                    LancerExe.lancerOut();
                                    // this.stringLue = READ_WRITE_FICHIER.read(ListCheminFichier.cheminPontCJ);
                                    // System.out.println(this.stringLue);
                                    if (this.erreur == 7) {
                                        Erreur.afficherErreur(this.erreur);
                                    } else {
                                        // this.nombreElementTabFIN = LireResultat(tabResultatMot, this.nombreElemetTab,
                                        // "rechercheMot", this.motCleRecherche, tabFileNameMOT, config.Nb_Mots_Cle,
                                        // config.Similariter); A gerer en JAVA
                                        lireResultat.requete = motCleRecherche;
                                        choix = lireResultat.lireResultatFinale("rechercheMot", null);
                                        // this.choix = visualiser_fichier(tabFileNameMOT, this.nombreElementTabFIN,
                                        // "texte"); A gerer en JAVA
                                        if (choix == 'Q') {
                                            System.out.println(
                                                    "\n\t\033[0;31mVous avez quitte le programme\033[0m\n\n\n\n");
                                            System.exit(1);
                                        }
                                    }
                                    break;
                                }
                                case '1': {
                                    int repere=0;
                                    int nombreMot;
                                    ArrayList<String> pont = new ArrayList<>();
                                    ArrayList<String> recup = new ArrayList<>();

                                    ArrayList<String> motsCles = new ArrayList<>();
                                    System.out.println(
                                            "Combien de mots clés voulez vous entrer pour votre requete complexe\n");
                                    nombreMot = Clavier.entrerClavierInt();
                                    ArrayList<String> motsPlusAuMoins = new ArrayList<>();
                                    System.out.println(
                                            "Veuillez ecrire les mots clés que vous voulez rechercher sous cette forme :\nFootball Mondial Argentine Equivaut à \n+football\n+fondial\n+argentine");
                                            System.out.println();
                                    for (int i = 0; i < nombreMot; i++) {
                                        motsPlusAuMoins.add(Clavier.entrerClavierString());
                                        // motsCles.add(motsPlusAuMoins.get(i).replace("+", "").replace("-", ""));
                                    }

                                    for (int i = 0; i < nombreMot; i++) {
                                        if (motsPlusAuMoins.get(i).contains("+")) {
                                            READ_WRITE_FICHIER.writeOn(ListCheminFichier.cheminPontJC,
                                                    "rechercheMot(" + motsPlusAuMoins.get(i).replace("+", "") + ")");
                                            LancerExe.lancerOut();
                                            if (this.erreur == 7) {
                                                Erreur.afficherErreur(this.erreur);
                                            }
                                            if (pont.size() == 0 && repere==0) {
                                                pont = lireResultat.lirePontComplexe();
                                                repere=1;
                                                System.out.println("pont debut" + pont.toString());

                                            } else {

                                                recup = lireResultat.lirePontComplexe();
                                                System.out.println("recup +" + recup.toString());
                                                pont.retainAll(recup);
                                            System.out.println("pont intersection" + pont.toString());
                                            }   
                                        }
                                    }

                                    for (int k = 0; k < nombreMot; k++) {
                                        if (motsPlusAuMoins.get(k).contains("-")) {
                                            READ_WRITE_FICHIER.writeOn(ListCheminFichier.cheminPontJC,
                                                    "rechercheMot(" + motsPlusAuMoins.get(k).replace("-", "") + ")");
                                            LancerExe.lancerOut();
                                            if (this.erreur == 7) {
                                                Erreur.afficherErreur(this.erreur);
                                            }
                                            recup = lireResultat.lirePontComplexe();
                                            System.out.println("recup -" + recup.toString());

                                            pont.removeAll(recup);
                                            System.out.println("pont -" + pont.toString());
                                        }
                                    }
                                    
                                    lireResultat.requete = motCleRecherche;
                                    choix = lireResultat.lireResultatFinale("requeteComplexe", pont);
                                    // this.choix = visualiser_fichier(tabFileNameMOT, this.nombreElementTabFIN,
                                    // "texte"); A gerer en JAVA
                                    if (choix == 'Q') {
                                        System.out.println(
                                                "\n\t\033[0;31mVous avez quitte le programme\033[0m\n\n\n\n");
                                        System.exit(1);
                                    }
                                    break;
                                }
                                default:
                                    break;
                            }

                        }

                            break;

                        case '2': {
                            // verification si le fichier existe
                            this.testExtensionFichier = -1;
                            while (this.testExtensionFichier == -1) {
                                System.out.println("\nEntrez le chemin de votre fichier\n");
                                this.cheminFichierRecherche = Clavier.entrerClavierString();
                                this.isfichierExist = traitementChemin.fichierExist(this.cheminFichierRecherche); // A
                                                                                                                  // gerer
                                                                                                                  // en
                                                                                                                  // JAVA
                                if (this.isfichierExist == false) {
                                    System.out.println("\nLe fichier n'existe pas\n");
                                    System.out.println(
                                            "\nVeuillez faire un choix pour continuer\n[1] Entrer un autre fichier\n[2] Retour \"Menu General\"\n");
                                    this.choix = Clavier.entrerClavierChar();
                                    switch (this.choix) {
                                        case '1':
                                            this.testExtensionFichier = -1;
                                            break;
                                        case '2':
                                            this.testExtensionFichier = 0;
                                            this.etat_courant = Etat.Menu_Utilisateur;
                                            break;
                                        default:
                                            this.etat_courant = Etat.Menu_Utilisateur;
                                            break;
                                    }
                                } else {
                                    this.testExtensionFichier = 0;
                                }
                            }
                            if (this.etat_courant != Etat.Menu_Utilisateur) {

                                // verification si le fichier passer est un fichier texte
                                this.isverifext = traitementChemin.verifExtension(this.cheminFichierRecherche, "xml");
                                if (this.isverifext == false) {
                                    System.out.println(
                                            "\nCe fichier n'est pas de type texte\nVeuiller mettre un fichier texte\n");
                                    this.etat_courant = Etat.Menu_texte;
                                } else {
                                    this.erreur = 0;
                                    this.nombreElemetTab = 0;
                                    READ_WRITE_FICHIER.writeOn(ListCheminFichier.cheminPontJC,
                                            "comparaison_texte(" + this.cheminFichierRecherche + ")");
                                    LancerExe.lancerOut();
                                    this.stringLue = READ_WRITE_FICHIER.read(ListCheminFichier.cheminPontCJ);
                                    System.out.println(this.stringLue);
                                    String recuperationResultat = READ_WRITE_FICHIER
                                            .read(ListCheminFichier.cheminPontCJ);

                                    if (this.erreur == 7 || this.erreur == 1) {
                                        Erreur.afficherErreur(this.erreur);

                                    }
                                    // this.nombreElementTabFIN = LireResultat(tabResultatTexte,
                                    // this.nombreElemetTab, "texte", this.cheminFichierRecherche, tabFileNameTEXTE,
                                    // config.Nb_Mots_Cle, config.Similariter); A GERER en JAVA
                                    // READ_WRITE_FICHIER.writeOn(ListCheminFichier.cheminPontJC,"freeTabResultatTexte)");
                                    LancerExe.lancerOut();
                                    lireResultat.requete = this.cheminFichierRecherche;
                                    // this.stringLue = READ_WRITE_FICHIER.read(ListCheminFichier.cheminPontCJ);
                                    // System.out.println(this.stringLue);
                                    choix = lireResultat.lireResultatFinale("texte", null);
                                    // this.choix= visualiser_fichier(tabFileNameTEXTE, this.nombreElementTabFIN,
                                    // "texte"); // A gerer en JAVA
                                    if (choix == 'Q') {
                                        System.out.println("\n\tVous avez quitté le programme\n\n\n\n");
                                        System.exit(1);
                                    }
                                }
                            }
                        }
                            break;
                        case 'R': {
                            this.etat_courant = Etat.Menu_Utilisateur;
                        }
                            break;
                        case 'Q': {
                            System.out.println("\n\tVous avez quitté le programme\n\n\n\n");
                            System.exit(1);
                        }
                            break;
                        default: {
                            this.erreur = 11;
                            Erreur.afficherErreur(this.erreur);

                            this.etat_courant = Etat.Menu_texte;
                        }
                            break;
                    }
                }
                    break;

                case Menu_image: {

                    System.out
                            .println("\n__________________________Recherche fichier image__________________________\n");
                    System.out.println("\nVeuillez faire votre choix  : \n");
                    System.out.println(
                            "\n[1] Recherche par comparaison d'images\n[2] Rechercher par couleur\n[R] Retour\n[Q] Quitter\n");
                    this.choix = Clavier.entrerClavierChar();
                    switch (choix) {
                        case '1': {

                            this.testExtensionFichier = -1;
                            while (this.testExtensionFichier == -1) {
                                System.out.println("\nEntrez le chemin de votre fichier\n");
                                this.cheminFichierRecherche = Clavier.entrerClavierString();
                                this.isfichierExist = traitementChemin.fichierExist(this.cheminFichierRecherche);
                                if (this.isfichierExist == false) {
                                    System.out.println("\nLe fichier n'existe pas\n");
                                    System.out.println(
                                            "\nVeuillez faire un choix pour continuer\n[1] Entrez un autre fichier\n[2] Retour \"Menu Général\"\n");
                                    this.choix = Clavier.entrerClavierChar();
                                    switch (this.choix) {
                                        case '1': {
                                            this.testExtensionFichier = -1;
                                        }
                                            break;
                                        case '2': {
                                            this.testExtensionFichier = 0;
                                            this.etat_courant = Etat.Menu_Utilisateur;
                                        }
                                            break;
                                        default: {
                                            this.etat_courant = Etat.Menu_Utilisateur;
                                        }
                                            break;
                                    }
                                } else {
                                    this.testExtensionFichier = 0;
                                }
                            }
                            if (this.etat_courant != Etat.Menu_Utilisateur) {
                                // verification si le fichier passer est un fichier texte

                                this.isverifext = traitementChemin.verifExtension(this.cheminFichierRecherche, "jpg");
                                this.bmp = traitementChemin.verifExtension(this.cheminFichierRecherche, "bmp");

                                if (this.isverifext == false && this.bmp == false) {
                                    System.out.println(
                                            "\nCe fichier n'est pas de type image\nVeuillez mettre un fichier .jpg ou .bmp\n");
                                    this.etat_courant = Etat.Menu_image;
                                } else {
                                    this.cheminFichierRecherche = traitementChemin
                                            .recupCheminPourAffichage(this.cheminFichierRecherche);
                                    READ_WRITE_FICHIER.writeOn(ListCheminFichier.cheminPontJC,
                                            "Comparaison_descripteur_image(" + this.cheminFichierRecherche + ")");
                                    LancerExe.lancerOut();
                                    // this.stringLue = READ_WRITE_FICHIER.read(ListCheminFichier.cheminPontCJ);
                                    // System.out.println(this.stringLue);
                                    // read + traitement retour

                                    if (this.erreur != 0) {
                                        Erreur.afficherErreur(this.erreur);
                                    } else {
                                        // this.nombreElementTabFIN = LireResultat(tabResultatIMG, this.nombreElemetTab,
                                        // "image", this.typeRequete, tabFileNameIMG, config->Nb_Mots_Cle,
                                        // config->Similariter);
                                        lireResultat.requete = this.cheminFichierRecherche;
                                        choix = lireResultat.lireResultatFinale("image", null);
                                        System.out.println(
                                                "\n\nPensez à fermer la fenetre apres l'avoir consulté pour poursuivre votre activité\n");
                                        // this.choix = visualiser_fichier(tabFileNameIMG, this.nombreElementTabFIN,
                                        // "image");
                                        if (this.choix == 'Q') {
                                            System.out.println("\n\tVous avez quitté le programme\n\n\n\n");
                                            System.exit(1);
                                        }
                                    }
                                    this.etat_courant = Etat.Menu_Utilisateur;
                                }
                            }
                        }
                            break;
                        case '2': {
                            System.out.println("\nEntrer la couleur voulue");
                            String couleur = Clavier.entrerClavierString();
                            System.out.println("\nEntrer le seuil de couleur voulue");
                            int seuil = Clavier.entrerClavierInt();
                            SimuRechercheCouleur simu = new SimuRechercheCouleur();
                            simu.recherche(couleur, seuil);
                            this.etat_courant = Etat.Menu_Utilisateur;

                        }
                            break;
                        case 'R': {
                            this.etat_courant = Etat.Menu_Utilisateur;
                        }
                            break;
                        case 'Q': {
                            System.out.println("\n\tVous avez quitté le programme\n\n\n\n");
                            System.exit(1);
                        }
                            break;
                        default: {
                            this.erreur = 11;
                            Erreur.afficherErreur(this.erreur);
                            this.etat_courant = Etat.Menu_image;
                        }
                            break;
                    }
                }
                    break;

                case Menu_audio: {
                    System.out
                            .println("\n__________________________Recherche fichier audio__________________________\n");
                    System.out.println("\nVeuillez faire votre choix  : \n");
                    System.out.println("\n[1] Recherche par comparaison d'audio\n[R] Retour\n[Q] Quitter\n");
                    this.choix = Clavier.entrerClavierChar();
                    switch (this.choix) {
                        case '1': {

                            // verification si le fichier existe
                            this.testExtensionFichier = -1;
                            while (this.testExtensionFichier == -1) {
                                System.out.println("\nEntrez le chemin de votre fichier\n");

                                this.cheminFichierRecherche = Clavier.entrerClavierString();
                                this.isfichierExist = traitementChemin.fichierExist(this.cheminFichierRecherche);
                                if (this.isfichierExist == false) {
                                    System.out.println("\nLe fichier n'existe pas\n");
                                    System.out.println(
                                            "\nVeuillez faire un choix pour continuer\n[1] Entrez un autre fichier\n[2] Retour \"Menu Général\"\n");
                                    this.choix = Clavier.entrerClavierChar();
                                    switch (this.choix) {
                                        case '1': {
                                            this.testExtensionFichier = -1;
                                        }
                                            break;
                                        case '2': {
                                            this.testExtensionFichier = 0;
                                            this.etat_courant = Etat.Menu_Utilisateur;
                                        }
                                        default: {
                                            this.etat_courant = Etat.Menu_Utilisateur;
                                        }
                                            break;
                                    }
                                } else {
                                    this.testExtensionFichier = 0;
                                }
                            }
                            if (this.etat_courant != Etat.Menu_Utilisateur) {
                                // verification si le fichier passer est un fichier texte
                                this.isverifext = traitementChemin.verifExtension(this.cheminFichierRecherche, "wav");
                                if (this.isverifext == false) {
                                    System.out.println(
                                            "\nCe fichier n'est pas de type audio\nVeuillez faire le choix de recherche qui vous correspond\n");
                                    this.etat_courant = Etat.Menu_Utilisateur;
                                } else {
                                    this.erreur = 0;
                                    if (this.erreur != 0) {
                                        Erreur.afficherErreur(this.erreur);

                                    } else {
                                        this.cheminFichierRecherche = traitementChemin
                                                .recupCheminPourAffichage(this.cheminFichierRecherche);
                                        READ_WRITE_FICHIER.writeOn(ListCheminFichier.cheminPontJC,
                                                "comparaison_audio(" + this.cheminFichierRecherche + ")");
                                        LancerExe.lancerOut();
                                        // this.stringLue = READ_WRITE_FICHIER.read(ListCheminFichier.cheminPontCJ);
                                        // System.out.println(this.stringLue);
                                        // this.nombreElementTabFIN = LireResultat(tabResultatAudio,
                                        // this.nombreElemetTab, "audio", this.cheminFichierRecherche, tabFileNameAUDIO,
                                        // config->Nb_Mots_Cle, config->Similariter);

                                        if (this.nombreElementTabFIN > 0) {
                                            System.out.println(
                                                    "\n\nPensez à fermer la fenetre apres l'avoir consulté pour poursuivre votre activité\n");
                                            lireResultat.requete = this.cheminFichierRecherche;
                                            choix = lireResultat.lireResultatFinale("audio", null);
                                            // READ_WRITE_FICHIER.writeOn(ListCheminFichier.cheminPontJC,"visualiser_fichier(tabFileNameAUDIO,nombreElementTabFIN,\"audio\")");
                                            // this.choix = ; // A voir
                                        }
                                        if (this.choix == 'Q') {
                                            System.out.println("\n\tVous avez quitté le programme\n\n\n\n");

                                            System.exit(1);
                                        }
                                        // READ_WRITE_FICHIER.writeOn(ListCheminFichier.cheminPontJC,"free(tabResultatAudio)");
                                    }
                                }
                            }
                        }
                            break;
                        case 'R': {
                            this.etat_courant = Etat.Menu_Utilisateur;
                        }
                            break;
                        case 'Q': {
                            System.out.println("\n\tVous avez quitté le programme\n\n\n\n");
                            System.exit(1);

                        }
                            break;
                        default: {
                            this.erreur = 11;
                            Erreur.afficherErreur(this.erreur);

                            this.etat_courant = Etat.Menu_audio;
                        }
                            break;
                    }
                }
                    break;

                default: {
                    System.out.println("Il y a une erreur, vous allez etre redirigez vers le \"Menu General\"\n");
                    this.erreur = 14;
                    if (this.erreur != 0) {
                        Erreur.afficherErreur(this.erreur);
                    }
                    this.etat_courant = Etat.Menu_general;
                }
                    break;
            }
        }
    }
}