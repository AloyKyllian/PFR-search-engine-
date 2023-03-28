import java.util.ArrayList;

public class BoundaryMenuTexte {
	ControlLancerExecutable controlLancerExecutable;
	BDHistorique bdHistorique = BDHistorique.getInstance();

	public BoundaryMenuTexte(ControlLancerExecutable controlLancerExecutable) {
		this.controlLancerExecutable = controlLancerExecutable ;
	}

	public Etat menuTexte() {
		int choix;
		String motCleRecherche = "";
		String cheminFichierRecherche = "";
		int testExtensionFichier;
		int erreur = 0;
		Etat etat_courant = Etat.Menu_texte;

		System.out.println("\n__________________________Recherche fichier texte__________________________\n");
		System.out.println("\nVeuillez faire votre choix  : \n");
		System.out.println(
				"\n[1] Recherche par mot-clé\n[2] Recherche par comparaison de textes\n[R] Retour\n[Q] Quitter\n");
		choix = Clavier.entrerClavierChar();
		switch (choix) {
		case '1': {

			erreur = 0;
			System.out.println("\nVoulez vous faire\n[1] Une requete complexe\n[2] Une requete simple\n");

			char choixRequete = Clavier.entrerClavierChar();
			switch (choixRequete) {
			case '2': {
				System.out.println("\nEntrez votre mot-clé\n");
				 motCleRecherche = Clavier.entrerClavierString();
				 bdHistorique.enregistrerHistorique(  TypeFichier.TEXTE, "Recherche", "Requete simple", motCleRecherche);

				ReadWriteFichier.writeOn(ListCheminFichier.cheminPontJC, "rechercheMot(" + motCleRecherche + ")");
				controlLancerExecutable.lancerOut();
				// this.stringLue = READ_WRITE_FICHIER.read(ListCheminFichier.cheminPontCJ);
				// System.out.println(this.stringLue);
				if (erreur == 7) {
					BoundaryErreur.afficherErreur(erreur);
				} else {
					// this.nombreElementTabFIN = LireResultat(tabResultatMot, this.nombreElemetTab,
					// "rechercheMot", this.motCleRecherche, tabFileNameMOT, config.Nb_Mots_Cle,
					// config.Similariter); A gerer en JAVA
					LireResultat.setRequete(motCleRecherche);
					choix = LireResultat.lireResultatFinale("rechercheMot", null, null);
					// this.choix = visualiser_fichier(tabFileNameMOT, this.nombreElementTabFIN,
					// "texte"); A gerer en JAVA
					if (choix == 'Q') {
						System.out.println("\n\t\033[0;31mVous avez quitte le programme\033[0m\n\n\n\n");
						System.exit(1);
					}
				}
				break;
			}
			case '1': {
				int repere = 0;
				int nombreMot;
				ArrayList<String> pont = new ArrayList<>();
				ArrayList<String> recup = new ArrayList<>();

				System.out.println("Combien de mots clés voulez vous entrer pour votre requete complexe\n");
				nombreMot = Clavier.entrerClavierInt();
				ArrayList<String> motsPlusAuMoins = new ArrayList<>();
				System.out.println(
						"Veuillez ecrire les mots clés que vous voulez rechercher sous cette forme :\nFootball Mondial Argentine Equivaut à \n+football\n+fondial\n+argentine");
				System.out.println();
				for (int i = 0; i < nombreMot; i++) {
					motsPlusAuMoins.add(Clavier.entrerClavierString());
					// motsCles.add(motsPlusAuMoins.get(i).replace("+", "").replace("-", ""));
				}
				bdHistorique.enregistrerHistorique(  TypeFichier.TEXTE, "Recherche", "Requete complexe", motsPlusAuMoins.toString());
				for (int i = 0; i < nombreMot; i++) {
					if (motsPlusAuMoins.get(i).contains("+")) {
						ReadWriteFichier.writeOn(ListCheminFichier.cheminPontJC,"rechercheMot(" + motsPlusAuMoins.get(i).replace("+", "") + ")");
						controlLancerExecutable.lancerOut();
						if (erreur == 7) {
							BoundaryErreur.afficherErreur(erreur);
						}
						if (pont.size() == 0 && repere == 0) {
							pont = LireResultat.lirePontComplexe();
							repere = 1;
							//System.out.println("pont debut" + pont.toString());

						} else {

							recup = LireResultat.lirePontComplexe();
							//System.out.println("recup +" + recup.toString());
							pont.retainAll(recup);
							//System.out.println("pont intersection" + pont.toString());
						}
					}
				}

				for (int k = 0; k < nombreMot; k++) {
					if (motsPlusAuMoins.get(k).contains("-")) {
						ReadWriteFichier.writeOn(ListCheminFichier.cheminPontJC,"rechercheMot(" + motsPlusAuMoins.get(k).replace("-", "") + ")");
						controlLancerExecutable.lancerOut();
						if (erreur == 7) {
							BoundaryErreur.afficherErreur(erreur);
						}
						recup = LireResultat.lirePontComplexe();
						//System.out.println("recup -" + recup.toString());

						pont.removeAll(recup);
						//System.out.println("pont -" + pont.toString());
					}
				}

				LireResultat.setRequete(motCleRecherche) ;
				choix = LireResultat.lireResultatFinale("requeteComplexe", pont, null);
				// this.choix = visualiser_fichier(tabFileNameMOT, this.nombreElementTabFIN,
				// "texte"); A gerer en JAVA
				if (choix == 'Q') {
					System.out.println("\n\t\033[0;31mVous avez quitte le programme\033[0m\n\n\n\n");
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
			testExtensionFichier = -1;
			while (testExtensionFichier == -1) {
				System.out.println("\nEntrez le chemin de votre fichier\n");
				cheminFichierRecherche = Clavier.entrerClavierString();
				boolean isfichierExist = TraitementChemin.fichierExist(cheminFichierRecherche);
																						
				if (isfichierExist == false) {
					System.out.println("\nLe fichier n'existe pas\n");
					System.out.println("\nVeuillez faire un choix pour continuer\n[1] Entrer un autre fichier\n[2] Retour \"Menu General\"\n");
					choix = Clavier.entrerClavierChar();
					switch (choix) {
					case '1':
						testExtensionFichier = -1;
						break;
					case '2':
						testExtensionFichier = 0;
						etat_courant = Etat.Menu_Utilisateur;
						break;
					default:
						etat_courant = Etat.Menu_Utilisateur;
						break;
					}
				} else {
					testExtensionFichier = 0;
				}
			}
			
			if (etat_courant != Etat.Menu_Utilisateur) {
				bdHistorique.enregistrerHistorique(  TypeFichier.TEXTE, "Comparaison", "", cheminFichierRecherche);
				// verification si le fichier passer est un fichier texte
				boolean isverifext = TraitementChemin.verifExtension(cheminFichierRecherche, "xml");
				if (isverifext == false) {
					System.out.println("\nCe fichier n'est pas de type texte\nVeuiller mettre un fichier texte\n");
					etat_courant = Etat.Menu_texte;
				} else {
					erreur = 0;
					ReadWriteFichier.writeOn(ListCheminFichier.cheminPontJC,"comparaisonTexte(" + cheminFichierRecherche + ")");
					controlLancerExecutable.lancerOut();
					String stringLue = ReadWriteFichier.read(ListCheminFichier.cheminPontCJ);
					//System.out.println(stringLue);

					if (erreur == 7 || erreur == 1) {
						BoundaryErreur.afficherErreur(erreur);

					}
					// this.nombreElementTabFIN = LireResultat(tabResultatTexte,
					// this.nombreElemetTab, "texte", this.cheminFichierRecherche, tabFileNameTEXTE,
					// config.Nb_Mots_Cle, config.Similariter); A GERER en JAVA
					// READ_WRITE_FICHIER.writeOn(ListCheminFichier.cheminPontJC,"freeTabResultatTexte)");
					controlLancerExecutable.lancerOut();
					LireResultat.setRequete(cheminFichierRecherche);
					// this.stringLue = READ_WRITE_FICHIER.read(ListCheminFichier.cheminPontCJ);
					// System.out.println(this.stringLue);
					choix = LireResultat.lireResultatFinale("texte", null, null);
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
			etat_courant = Etat.Menu_Utilisateur;
		}
			break;
		case 'Q': {
			System.out.println("\n\tVous avez quitté le programme\n\n\n\n");
			System.exit(1);
		}
			break;
		default: {
			BoundaryErreur.afficherErreur(11);
			etat_courant = Etat.Menu_texte;
		}
			break;
		}
		return etat_courant;
	}

}
