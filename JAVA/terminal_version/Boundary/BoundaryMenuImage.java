package Boundary;

import Controle.ControlLancerExecutable;
import Entite.*;

public class BoundaryMenuImage {
	ControlLancerExecutable controlLancerExecutable;

	public BoundaryMenuImage(ControlLancerExecutable controlLancerExecutable) {
		this.controlLancerExecutable = controlLancerExecutable ;
	}

	public Etat menuImage() {
		int choix;
		int testExtensionFichier = -1;
		int erreur = 0;
		String cheminFichierRecherche = "";
		Etat etat_courant = Etat.Menu_image;
		BDHistorique bdHistorique = BDHistorique.getInstance();

		System.out.println("\n__________________________Recherche fichier image__________________________\n");
		System.out.println("\nVeuillez faire votre choix  : \n");
		System.out.println(
				"\n[1] Recherche par comparaison d'images\n[2] Rechercher par couleur\n[R] Retour\n[Q] Quitter\n");
		choix = Clavier.entrerClavierChar();
		switch (choix) {
		case '1': {

			testExtensionFichier = -1;
			while (testExtensionFichier == -1) {

				System.out.println("\nEntrez le chemin de votre fichier\n");
				cheminFichierRecherche = Clavier.entrerClavierString();
				boolean isfichierExist = TraitementChemin.fichierExist(cheminFichierRecherche);
				if (isfichierExist == false) {
					System.out.println("\nLe fichier n'existe pas\n");
					System.out.println(
							"\nVeuillez faire un choix pour continuer\n[1] Entrez un autre fichier\n[2] Retour \"Menu Général\"\n");
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
						break;
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
				bdHistorique.enregistrerHistorique(  TypeFichier.IMAGE, "Comparaison", "", cheminFichierRecherche);
				boolean isverifext = TraitementChemin.verifExtension(cheminFichierRecherche, "jpg");
				boolean bmp = TraitementChemin.verifExtension(cheminFichierRecherche, "bmp");

				if (isverifext == false && bmp == false) {
					System.out.println("\nCe fichier n'est pas de type image\nVeuillez mettre un fichier .jpg ou .bmp\n");
					etat_courant = Etat.Menu_image;
				} else {
					String cheminImageTXT = cheminFichierRecherche.replace("bmp", "txt").replace("jpg", "txt");
					ReadWriteFichier.writeOn(ListCheminFichier.cheminPontJC,"comparaisonDescripteurImage(" + cheminImageTXT + ")");
					controlLancerExecutable.lancerOut();
					// this.stringLue = READ_WRITE_FICHIER.read(ListCheminFichier.cheminPontCJ);
					// System.out.println(this.stringLue);
					// read + traitement retour
					if (erreur != 0) {
						BoundaryErreur.afficherErreur(erreur);
					} else {

						String BmpJpg;
						if (cheminFichierRecherche.contains("bmp")) {
							System.out.print("bmp");
							BmpJpg = "bmp";
						} else {
							System.out.print("jpg");
							BmpJpg = "jpg";
						}
						LireResultat.setRequete(cheminImageTXT) ;
						choix = LireResultat.lireResultatFinale("image", null, BmpJpg);
						// this.choix = visualiser_fichier(tabFileNameIMG, this.nombreElementTabFIN,
						// "image");
						if (choix == 'Q') {
							System.out.println("\n\tVous avez quitté le programme\n\n\n\n");
							System.exit(1);
						}
					}
					etat_courant = Etat.Menu_Utilisateur;
				}
			}
		}
			break;
		case '2': {
			System.out.println("\nEntrer la couleur voulue");
			String couleur = Clavier.entrerClavierString();
			System.out.println("\nEntrer le seuil de couleur voulue");
			int seuil = Clavier.entrerClavierInt();
			bdHistorique.enregistrerHistorique(  TypeFichier.IMAGE, "Recherche couleur", "", couleur);
			BoundarySimuRechercheCouleur simu = new BoundarySimuRechercheCouleur();
			simu.recherche(couleur, seuil);
			etat_courant = Etat.Menu_Utilisateur;

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
		}
			break;
		}
		return etat_courant;
	}
}
