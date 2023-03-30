package Boundary;

import Controle.ControlLancerExecutable;
import Controle.ControleVisualiserDescripteur;
import Entite.Clavier;
import Entite.Etat;
import Entite.ListCheminFichier;
import Entite.ReadWriteFichier;

public class BoundaryMenuVisualisation {
	ControlLancerExecutable controlLancerExecutable;
	ControleVisualiserDescripteur controleVisualiserDescripteur = new ControleVisualiserDescripteur();
	public BoundaryMenuVisualisation(ControlLancerExecutable controlLancerExecutable) {
		this.controlLancerExecutable = controlLancerExecutable ;
	}

	public Etat menuVisualisation() {
		String stringLue;
		Etat etat_courant = Etat.Menu_Visualisation;
		char choix;

		System.out.println("\n__________________________Visualisation des recueils des descripteurs__________________________\n");
		System.out.println("\nVeuillez faire votre choix  : \n");
		System.out.println("\n[1] Texte\n[2] Image\n[3] Audio \n[R] Retour\n[Q] Déconnexion\n");
		choix = Clavier.entrerClavierChar();
		switch (choix) {
		case '1': {
			System.out.println("\nPenser a fermé la fenetre apres l'avoir consulter pour poursuivre votre activité\n");
			stringLue=controleVisualiserDescripteur.controleSystemTexte();
			System.out.println(stringLue);
			// recuperer dans le fichier xecutabe
		}
			break;
		case '2': {
			System.out.println("\nPenser a fermé la fenetre apres l'avoir consulter pour poursuivre votre activité\n");
			stringLue=controleVisualiserDescripteur.controleSystemImage();
			System.out.println(stringLue);
		}
			break;
		case '3': {
			System.out.println("\nPenser a fermé la fenetre apres l'avoir consulter pour poursuivre votre activité\n");
			stringLue=controleVisualiserDescripteur.controleSystemAudio();
			System.out.println(stringLue);
		}
			break;
		case 'R': {
			etat_courant = Etat.Menu_Admin;
		}
			break;
		case 'Q': {
			choix = '1';
			while (choix == '1') {
				System.out.println(
						"\nVous vous êtes deconnecté, voulez vous retourner en \"Mode Utilisateur\" ?\n[1] Oui\n[2] Non\n");
				choix = Clavier.entrerClavierChar();
				switch (choix) {
				case '1':
					etat_courant = Etat.Menu_Utilisateur;
				case '2':
					System.out.println("\n\tVous avez quitté le programme\n\n\n\n");
					System.exit(1);
				default:
					System.out.println("\nMauvais choix, vous allez etre redirigé vers \"Menu visualisation\"\n");
					etat_courant = Etat.Menu_Visualisation;
					break;
				}
			}
		}
			break;
		default: {
			BoundaryErreur.afficherErreur(11);
			etat_courant = Etat.Menu_Visualisation;
		}
			break;
		}
		return etat_courant;
	}
}
