package Boundary;

import Controle.ControlMenuAudio;
import Entite.Clavier;
import Entite.Etat;
import Entite.LireResultat;
import Entite.TraitementChemin;

public class BoundaryMenuAudio {

	ControlMenuAudio menuAudio;

	public BoundaryMenuAudio(ControlMenuAudio menuAudio) {
		this.menuAudio=menuAudio;
	}


	public Etat menuAudio() {
		int testExtensionFichier;
		String cheminFichierRecherche = "";
		char choix;
		int erreur =0;
		Etat etat_courant = Etat.Menu_audio;
		System.out.println("\n__________________________Recherche fichier audio__________________________\n");
		System.out.println("\nVeuillez faire votre choix  : \n");
		System.out.println("\n[1] Recherche par comparaison d'audio\n[R] Retour\n[Q] Quitter\n");
		choix = Clavier.entrerClavierChar();
		switch (choix) {
			case '1' -> {

				// verification si le fichier existe
				testExtensionFichier = -1;
				while (testExtensionFichier == -1) {
					System.out.println("\nEntrez le chemin de votre fichier\n");

					cheminFichierRecherche = Clavier.entrerClavierString();

					boolean isfichierExist = TraitementChemin.fichierExist(cheminFichierRecherche);
					if (!isfichierExist) {
						System.out.println("\nLe fichier n'existe pas\n");
						System.out.println("\nVeuillez faire un choix pour continuer\n[1] Entrez un autre fichier\n[2] Retour \"Menu Général\"\n");
						choix = Clavier.entrerClavierChar();
						switch (choix) {
							case '1': {
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

					// verification si le fichier passer est un fichier texte
					boolean isverifext = TraitementChemin.verifExtension(cheminFichierRecherche, "wav");
					if (!isverifext) {
						System.out.println(
								"\nCe fichier n'est pas de type audio\nVeuillez faire le choix de recherche qui vous correspond\n");
						etat_courant = Etat.Menu_Utilisateur;
					} else {
						String cheminAudioTXT = cheminFichierRecherche.replace("wav", "txt");
						menuAudio.comparaisonAudio(cheminAudioTXT, cheminFichierRecherche);
						choix = LireResultat.lireResultatFinale("audio", null, null);
						if (choix == 'Q') {
							System.out.println("\n\tVous avez quitté le programme\n\n\n\n");

							System.exit(1);
						}
					}
				}
			}
			case 'R' -> {
				etat_courant = Etat.Menu_Utilisateur;
			}
			case 'Q' -> {
				System.out.println("\n\tVous avez quitté le programme\n\n\n\n");
				System.exit(1);

			}
			default -> {
				erreur = 11;
				BoundaryErreur.afficherErreur(erreur);
			}
		}
		return etat_courant;
	}

}
