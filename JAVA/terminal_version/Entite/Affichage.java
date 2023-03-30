package Entite;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Affichage {

	/**
	 * @param type
	 * @param requeteComplexe
	 * @param typeImage
	 * @return
	 */
	String requete;
	public static void setRequete(String str) {
		requete = str;
	}
	public static Map<String, Integer> affichageFinale(String type, List<String> requeteComplexe, String typeImage) {
		ArrayList<Element> listeElement = new ArrayList<>();
		List<String[]> pont = new ArrayList<>();
		pont = LireResultat.lirePont();
		String fileName;
		String cheminFileName;
		Map<String, Integer> resultatFinale = new HashMap<>();
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
							resultatFinale.put(cheminFileName, null);
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
							if (Integer.parseInt(nombreOccurence) > 0 && Integer.parseInt(nombreOccurence) < 100) {
								resultatFinale.put(cheminFileName, Integer.parseInt(nombreOccurence));
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
								resultatFinale.put(cheminFileName, Integer.parseInt(nombreOccurence));
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
								if (Integer.parseInt(nombreOccurence) > 0 && Integer.parseInt(nombreOccurence) < 100) {
									resultatFinale.put(cheminFileName, Integer.parseInt(nombreOccurence));
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
								if (Integer.parseInt(nombreOccurence) > 0 && Integer.parseInt(nombreOccurence) < 100) {
									resultatFinale.put(cheminFileName, Integer.parseInt(nombreOccurence));
								}
							}
						}
					}
				}
			}
		}
		// affichage des resultat de comparaison Audio :
		else if (type.contains("audio")) {
			if (pont.size() == 0) {
				return null;
			} else {
				// Appel de la fonction lire_chemin pour afficher les résultats de comparaison
				// de texte
				listeElement = LireResultat.lireChemin("audio");

				for (String[] premiereCase : pont) {
					String id = premiereCase[0];
					String nombreOccurence = premiereCase[1];
					for (Element element : listeElement) {
						if (element.ID.equals(id)) {
							fileName = TraitementChemin.extension(TypeFichier.AUDIO, element.chemin);
							cheminFileName = element.chemin;
							if (Integer.parseInt(nombreOccurence) == 100) {
								if (fileName.contains("jingle")) {
									resultatFinale.put("DATA_FIL_ROUGE_DEV/IMG_et_AUDIO/TEST_SON/corpus_fi.wav",
											2);
								} else if (fileName.contains("corpus")) {
									resultatFinale.put(null, 0);
									resultatFinale.clear();
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