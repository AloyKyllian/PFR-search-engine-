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
	public static Map<String,Integer> affichageFinale(String type, List<String> requeteComplexe, String typeImage) {
		ArrayList<Element> listeElement = new ArrayList<>();
		List<String[]> pont = new ArrayList<>();
		List<String> nomFichier = new ArrayList<>();
		pont = LireResultat.lirePont();
		String fileName;
		String cheminFileName;
		int numero;
		char choix = 'R';
        Map<String,Integer> resultatFinale=new HashMap<>();
		// affichage des resultat de recherche par mot cle :
		if (type.contains("requeteComplexe")) {
			if (requeteComplexe.size() == 0) {
				return null;
			} else {
				// Appel de la fonction lire_chemin pour afficher les résultats de recherche par
				// mot clé
				listeElement = LireResultat.lireChemin("texte");
				numero = 1;
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
				numero = 1;
				for (String[] premiereCase : pont) {
					String id = premiereCase[0];
					String nombreOccurence = premiereCase[1];
					for (Element element : listeElement) {
						// System.out.println(element.toString());
						if (element.ID.equals(id)) {
							fileName = TraitementChemin.extension(TypeFichier.TEXTE, element.chemin);
							cheminFileName = element.chemin;
							if (Integer.parseInt(nombreOccurence) > 0 && Integer.parseInt(nombreOccurence) < 100) {
								resultatFinale.put(cheminFileName, Integer.parseInt(nombreOccurence) );
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
				numero = 1;
				for (String[] premiereCase : pont) {
					String id = premiereCase[0];
					String nombreOccurence = premiereCase[1];
					for (Element element : listeElement) {
						if (element.ID.equals(id)) {
							fileName = TraitementChemin.extension(TypeFichier.TEXTE, element.chemin);
							cheminFileName = element.chemin;
							if (Integer.parseInt(nombreOccurence) > 0 && Integer.parseInt(nombreOccurence) < 100) {
								resultatFinale.put(cheminFileName, Integer.parseInt(nombreOccurence) );
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
					numero = 1;
					for (String[] premiereCase : pont) {
						String id = premiereCase[0];
						String nombreOccurence = premiereCase[1];
						for (Element element : listeElement) {
							if (element.ID.equals(id)) {
								fileName = TraitementChemin.extension(TypeFichier.NB, element.chemin);
								cheminFileName = element.chemin.replace("txt", "bmp");
								if (Integer.parseInt(nombreOccurence) > 0 && Integer.parseInt(nombreOccurence) < 100) {
									resultatFinale.put(cheminFileName, Integer.parseInt(nombreOccurence) );
								}
							}
						}
					}
				}

				if (typeImage.contains("jpg")) {
					listeElement = LireResultat.lireChemin("rgb");
					numero = 1;
					for (String[] premiereCase : pont) {
						String id = premiereCase[0];
						String nombreOccurence = premiereCase[1];
						for (Element element : listeElement) {
							if (element.ID.equals(id)) {
								fileName = TraitementChemin.extension(TypeFichier.RGB, element.chemin);
								cheminFileName = element.chemin.replace("txt", "jpg");
								if (Integer.parseInt(nombreOccurence) > 0 && Integer.parseInt(nombreOccurence) < 100) {
									resultatFinale.put(cheminFileName, Integer.parseInt(nombreOccurence) );
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
				// d'audio
				listeElement = LireResultat.lireChemin(type);

				// separer le nom du fichier du chemin
				numero = 1;
				for (String[] premiereCase : pont) {
					String id = premiereCase[0];
					String nombreOccurence = premiereCase[1];
					for (Element element : listeElement) {
						if (element.ID.equals(id)) {
							fileName = TraitementChemin.extension(TypeFichier.AUDIO, element.chemin);
							cheminFileName = element.chemin.replace("txt", "wav");
							if (Integer.parseInt(nombreOccurence) > 0 && Integer.parseInt(nombreOccurence) < 100) {
								resultatFinale.put(cheminFileName,Integer.parseInt(nombreOccurence) );
							}
						}
					}
				}
			}
		}
		return resultatFinale ;
	}
}