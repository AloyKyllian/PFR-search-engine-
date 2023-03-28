public class BoundaryMenuGeneral {
	private BoundaryConnexion boundaryConnexion;

	public BoundaryMenuGeneral(BoundaryConnexion bc) {
		this.boundaryConnexion = bc;
	}

	public Etat menuGeneral() {
		Etat etat_courant = Etat.Menu_general;
		int nbTentativeConnexion = 0;

		System.out.println("\n__________________________Menu General__________________________\n");
		System.out.println("\nVeuillez faire votre choix : \n");
		System.out.println("\n[1] Administrateur \n[2] Utilisateur \n[Q] Quitter\n");

		char choix = Clavier.entrerClavierChar();
		switch (choix) {
		// case Administrateur:
		case '1': {
			// Connexion
			boolean result = false;
			do {
				// recuperer le boolean depuis le fichier texte
				result = this.boundaryConnexion.seConnecter();
				if (result) {
					System.out.println("Réussie\n\n");
					System.out.println("\nDirection \"Menu Administrateur\"\n");
					etat_courant = Etat.Menu_Admin;
				} else {
					System.out.println("Échouée\n\n");
					nbTentativeConnexion++;
				}
				if (nbTentativeConnexion == 3 && result == false) {
					System.out.println(
							"\nSouhaitez vous basculer en \"Mode Utilisateur\" ou essayer de se connecter une nouvelle fois ?\n");
					System.out.println("\n[1] Mode Utilisateur\n[2] nouvelle tentative de connexion\n");
					choix = Clavier.entrerClavierChar();
					switch (choix) {
					case '1': {
						etat_courant = Etat.Menu_Utilisateur;
					}
						break;
					case '2': {
						System.out.println("\nVous devez attendre 10 secondes pour réessayer\n");
						try {
							Thread.sleep(10000);
						} catch (InterruptedException e) {
							e.printStackTrace();
						}

						System.out.println("\nFin des 30 secondes, Vous pouvez réessayer maintenant\n");
						nbTentativeConnexion = 0;
					}
						break;
					default: {
						System.out.println("Erreur de choix");
					}
						break;
					}
				}
			} while ((nbTentativeConnexion < 4) && (result == false));

		}
			break;
		// case Utilisateur:
		case '2': {
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
			etat_courant = Etat.Menu_general;
		}break;
		}
		return etat_courant;
	}
}