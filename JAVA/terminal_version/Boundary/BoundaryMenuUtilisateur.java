package Boundary;

import Entite.Clavier;
import Entite.Etat;

public class BoundaryMenuUtilisateur {


	public Etat menuUtilisateur() {
		int choix;
		Etat etat_courant = Etat.Menu_Utilisateur;
		System.out.println("\n__________________________Menu utilisateur__________________________\n");
		System.out.println("\nVeuillez faire votre choix  : \n");
		System.out.println("\n[1] Recherche fichier texte\n[2] Recherche fichier image\n[3] Recherche fichier audio \n[R] Retour\n[Q] Déconnexion\n");
		choix = Clavier.entrerClavierChar();
		switch (choix) {
		case '1': {
			etat_courant = Etat.Menu_texte;
		}
			break;
		case '2': {
			etat_courant = Etat.Menu_image;
		}
			break;
		case '3': {
			etat_courant = Etat.Menu_audio;
		}
			break;
		case 'R': {
			etat_courant = Etat.Menu_general;
		}
			break;
		case 'Q': {
			System.out.println("\n\tVous avez quitté le programme\n\n\n\n");
			System.exit(1);
		}
			break;
		default: {
			BoundaryErreur.afficherErreur(11);
			etat_courant = Etat.Menu_Utilisateur;
		}break;
		}
		return etat_courant;
	}
}
