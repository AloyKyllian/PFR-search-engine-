public class BoundaryMenuAudio {
	ControlLancerExecutable controlLancerExecutable;

	public BoundaryMenuAudio(ControlLancerExecutable controlLancerExecutable) {
		this.controlLancerExecutable = controlLancerExecutable ;
	}

	public Etat menuAudio() {
		int testExtensionFichier;
		String cheminFichierRecherche = "";
		char choix;
		int erreur =0;
		BDHistorique bdHistorique = BDHistorique.getInstance();
		Etat etat_courant = Etat.Menu_audio;
		System.out.println("\n__________________________Recherche fichier audio__________________________\n");
		System.out.println("\nVeuillez faire votre choix  : \n");
		System.out.println("\n[1] Recherche par comparaison d'audio\n[R] Retour\n[Q] Quitter\n");
		choix = Clavier.entrerClavierChar();
		switch (choix) {
		case '1': {

			// verification si le fichier existe
			testExtensionFichier = -1;
			while (testExtensionFichier == -1) {
				System.out.println("\nEntrez le chemin de votre fichier\n");

				cheminFichierRecherche = Clavier.entrerClavierString();

				boolean isfichierExist = TraitementChemin.fichierExist(cheminFichierRecherche);
				if (isfichierExist == false) {
					System.out.println("\nLe fichier n'existe pas\n");
					System.out.println("\nVeuillez faire un choix pour continuer\n[1] Entrez un autre fichier\n[2] Retour \"Menu Général\"\n");
					choix = Clavier.entrerClavierChar();
					switch (choix) {
					case '1': {
						testExtensionFichier = -1;
					}
						break;
					case '2': {
						testExtensionFichier = 0;
						etat_courant = Etat.Menu_Utilisateur;
					}
					default: {
						etat_courant = Etat.Menu_Utilisateur;
					}
						break;
					}
				} else {
					testExtensionFichier = 0;
				}
			}
			if (etat_courant != Etat.Menu_Utilisateur) {
				bdHistorique.enregistrerHistorique(  TypeFichier.AUDIO, "Comparaison", null, cheminFichierRecherche);
				// verification si le fichier passer est un fichier texte
				boolean isverifext = TraitementChemin.verifExtension(cheminFichierRecherche, "wav");
				if (isverifext == false) {
					System.out.println(
							"\nCe fichier n'est pas de type audio\nVeuillez faire le choix de recherche qui vous correspond\n");
					etat_courant = Etat.Menu_Utilisateur;
				} else {
					erreur = 0;
					if (erreur != 0) {
						BoundaryErreur.afficherErreur(erreur);

					} else {
						// this.cheminFichierRecherche =
						// traitementChemin.recupCheminPourAffichage(this.cheminFichierRecherche);
						String cheminAudioTXT = cheminFichierRecherche.replace("wav", "txt");
						ReadWriteFichier.writeOn(ListCheminFichier.cheminPontJC,
								"comparaisonAudio(" + cheminAudioTXT + ")");
						controlLancerExecutable.lancerOut();
						LireResultat.setRequete(cheminFichierRecherche) ;
						choix = LireResultat.lireResultatFinale("audio", null, null);
						if (choix == 'Q') {
							System.out.println("\n\tVous avez quitté le programme\n\n\n\n");

							System.exit(1);
						}
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
			erreur = 11;
			BoundaryErreur.afficherErreur(erreur);
			etat_courant = Etat.Menu_audio;
		}
			break;
		}
		return etat_courant;
	}

}
