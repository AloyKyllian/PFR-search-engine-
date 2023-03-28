public class BoundaryMenuConfig {

	private BoundaryConfig boundaryConfig;

	public BoundaryMenuConfig(BoundaryConfig boundaryConfig) {
		this.boundaryConfig = boundaryConfig;
	}

	public Etat menuConfig() {
		Etat etat_courant = Etat.Menu_Configuration;
		
		System.out.println("\n__________________________Configuration__________________________\n");

		Config config = Config.getInstance();
		config.lire_config();
		System.out.println(config.toString());

		
		System.out.println("\nSi vous voulez changer une valeur, veuillez faire votre choix  : \n");
		System.out.println("\n[1] Nombre de mots-clé \t supérieur à 0\n[2] Similarité         \t entre 1 et 100\n[3] Nombre de bits     \t entre 1 et 8 \n[4] Nombre de fenetre  \t supeieur a 256 et une puissance de 2\n[5] Intervalle de temps\t superieur a 0 \n[R] Retour\n[Q] Déconnexion\n");

		char choix = Clavier.entrerClavierChar();
		switch (choix) {
		case '1': {
			boundaryConfig.ModifierConfig(TypeConfig.NB_MOTS_CLE);
			System.out.println(
					"\nSi vous avez changé votre configuration veuillez lancer l'indexation pour appliquer vos modifications\n");
		}
			break;
		case '2': {
			// pour changer similarité
			boundaryConfig.ModifierConfig(TypeConfig.SIMILARITER);
			System.out.println(
					"\nSi vous avez changé votre configuration veuillez lancer l'indexation pour appliquer vos modifications\n");
		}
			break;
		case '3': {
			// pour changer nb bits
			boundaryConfig.ModifierConfig(TypeConfig.NB_BITS_FORT);
			System.out.println(
					"\nSi vous avez changé votre configuration veuillez lancer l'indexation pour appliquer vos modifications\n");
		}
			break;
		case '4': {
			boundaryConfig.ModifierConfig(TypeConfig.NB_FENETRE);
			System.out.println(
					"\nSi vous avez changé votre configuration veuillez lancer l'indexation pour appliquer vos modifications\n");
		}
			break;
		case '5': {
			// fct pour changer l'intervalle de temps
			boundaryConfig.ModifierConfig(TypeConfig.INTERVALLE);
			System.out.println(
					"\nSi vous avez changé votre configuration veuillez lancer l'indexation pour appliquer vos modifications\n");
		}
			break;
		case 'R': {
			etat_courant = Etat.Menu_Admin;
		}
			break;
		case 'Q': {
			while (choix == '1') {
				System.out.println(
						"\nVous vous êtes deconnecté, voulez vous retourner en \"Mode Utilisateur\" ?\n[1] Oui\n[2] Non\n");
				choix = Clavier.entrerClavierChar();
				switch (choix) {
				case 1: {
					etat_courant = Etat.Menu_Utilisateur;
				}

					break;
				case 2: {
					System.out.println("\n\tVous avez quitté le programme\n\n\n\n");

					System.exit(1);
				}
					break;

				default: {
					BoundaryErreur.afficherErreur(11);
					etat_courant = Etat.Menu_Configuration;
				}
					break;
				}
			}
		}
			break;
		default: {
			BoundaryErreur.afficherErreur(11);
			etat_courant = Etat.Menu_Configuration;
		}
			break;
		}
		return etat_courant;
	}
}