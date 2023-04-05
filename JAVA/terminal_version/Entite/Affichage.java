package Entite;

import java.util.ArrayList;
import java.util.List;

public class Affichage {

	/**
	 * @param type
	 * @param requeteComplexe
	 * @param typeImage
	 * @return
	 */
	static String requete;
	public static void setRequete(String str) {
		LireResultat.setRequete(str);
		requete= str;
	}
	public static ArrayList<String> affichageFinale(String type, List<String> requeteComplexe, String typeImage) {
		ArrayList<Element> listeElement = new ArrayList<>();
		List<String[]> pont = new ArrayList<>();
		pont = LireResultat.lirePont();
		String fileName;
		String cheminFileName;
		ArrayList resultatFinale = new ArrayList<String>();
		// affichage des resultat de recherche par mot cle :
		if (type.contains("requeteComplexe")) {
			if (requeteComplexe.size() == 0) {
				return null;
			} else {
				// Appel de la fonction lire_chemin pour afficher les résultats de recherche par
				// mot clé
				listeElement = LireResultat.lireChemin("texte");
				for (String premiereCase : requeteComplexe) {
					String id = premiereCase;
					for (Element element : listeElement) {
						if (element.ID.equals(id)) {
							cheminFileName = element.chemin;
							resultatFinale.add(cheminFileName);
						}
					}
				}
			}
		}
		if (type.contains("rechercheMot")) {
			if (pont.size() == 0) {
				return null;
			} else {
				// Appel de la fonction lire_chemin pour afficher les résultats de recherche par
				// mot clé
				listeElement = LireResultat.lireChemin("texte");
				for (String[] premiereCase : pont) {
					String id = premiereCase[0];
					String nombreOccurence = premiereCase[1];
					for (Element element : listeElement) {
						// System.out.println(element.toString());
						if (element.ID.equals(id)) {
							fileName = TraitementChemin.extension(TypeFichier.TEXTE, element.chemin);
							cheminFileName = element.chemin;

							if (Integer.parseInt(nombreOccurence) > 0  && Integer.parseInt(nombreOccurence) < 100) {
								resultatFinale.add(cheminFileName);
							}
						}
					}
				}
			}
		}

		else if (type.contains("texte")) {

			if (pont.size() == 0) {
				return null;
			} else {
				// Appel de la fonction lire_chemin pour afficher les résultats de comparaison
				// de texte
				listeElement = LireResultat.lireChemin("texte");
				for (String[] premiereCase : pont) {
					String id = premiereCase[0];
					String nombreOccurence = premiereCase[1];
					for (Element element : listeElement) {
						if (element.ID.equals(id)) {
							fileName = TraitementChemin.extension(TypeFichier.TEXTE, element.chemin);
							cheminFileName = element.chemin;
							if (Integer.parseInt(nombreOccurence) > 0 && Integer.parseInt(nombreOccurence) < 100) {
								resultatFinale.add(cheminFileName);
							}
						}
					}
				}

			}
		}

		// affichage des resultat de comparaison Image :
		else if (type.contains("image")) {
			if (pont.size() == 0) {
				return null;
			} else {
				// Appel de la fonction lire_chemin pour afficher les résultats de comparaison
				// d'image
				if (typeImage.contains("bmp")) {

					listeElement = LireResultat.lireChemin("nb");

					for (String[] premiereCase : pont) {
						String id = premiereCase[0];
						String nombreOccurence = premiereCase[1];
						for (Element element : listeElement) {
							if (element.ID.equals(id)) {
								fileName = TraitementChemin.extension(TypeFichier.NB, element.chemin);
								cheminFileName = element.chemin.replace("txt", "bmp");
								System.out.println("dans affichage  bmp"+cheminFileName);
								if (Integer.parseInt(nombreOccurence) > 0 && Integer.parseInt(nombreOccurence) < 100) {
									resultatFinale.add(cheminFileName);

								}
							}
						}
					}
				}

				if (typeImage.contains("jpg")) {
					listeElement = LireResultat.lireChemin("rgb");

					for (String[] premiereCase : pont) {
						String id = premiereCase[0];
						String nombreOccurence = premiereCase[1];
						for (Element element : listeElement) {
							if (element.ID.equals(id)) {
								fileName = TraitementChemin.extension(TypeFichier.RGB, element.chemin);
								cheminFileName = element.chemin.replace("txt", "jpg");
								System.out.println("dans affichage  jpg"+cheminFileName);
								if (Integer.parseInt(nombreOccurence) > 0 && Integer.parseInt(nombreOccurence) < 100) {
									resultatFinale.add(cheminFileName);
								}
							}
						}
					}
				}
			}
		}
		return resultatFinale;
	}
}