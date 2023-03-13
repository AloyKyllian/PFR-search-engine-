//
// AUTEUR :
//          YOUSSERA ACHACHERA
// DERNIERE VERSION :
//    23/01/2023
//

import java.io.*;
import java.util.*;

public class LireResultat {
    int nbElement;
    String type;
    String requete;
    int nombre_mot_cle;
    int similarite;
    String pontJavaC = "../pontJavaC.txt";

    public LireResultat() {
        super();
    }

    public static List<String[]> lirePont(String filename) {

        List<String[]> pont = new ArrayList<>();

        try {
            File file = new File(filename);
            Scanner scanner = new Scanner(file);

            // Lit chaque ligne du fichier et stocke les données dans le tableau
            while (scanner.hasNextLine()) {
                String[] line = scanner.nextLine().split(" ");
                pont.add(line);
            }

            scanner.close();

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

        return pont;
    }

    public ArrayList<ELLEMENT> lireChemin(List<String[]> pont, String type) {
        ArrayList<ELLEMENT> listeElement = new ArrayList<>();

        String chaine = "";
        if (type.equals("nb")) {
            chaine = READ_WRITE_FICHIER.read("../MoteurC/liste_base/liste_base_image/NB");
        }
        if (type.equals("rgb")) {
            chaine = READ_WRITE_FICHIER.read("../MoteurC/liste_base/liste_base_image/RGB");
        }
        if (type.equals("audio")) {
            chaine = READ_WRITE_FICHIER.read("../MoteurC/liste_base/liste_base_audio");
        }
        if (type.equals("texte")) {
            chaine = READ_WRITE_FICHIER.read("../MoteurC/liste_base/liste_base_texte");
        }
        String[] ligne = chaine.split("\n");
        for (String lig : ligne) {
            String[] cases = lig.split(" ");
            listeElement.add(new ELLEMENT(cases[0], cases[1]));
        }

        for (String[] premiereCase : pont) {
            String id = premiereCase[0];
            String nombreOccurence = premiereCase[1];
            for (ELLEMENT element : listeElement) {
                if (element.ID.equals(id)) {
                    System.out.println(element.chemin + " : " + nombreOccurence + "%");
                }
            }
        }
        return listeElement;
    }
    /*
     * public LireResultat(TreeSet tableauResultat, int nombreElement, String
     * typeRequete, ArrayList fileName,
     * int nbMotCle, int similaritee) {
     * this.tabResultat = tableauResultat;
     * this.nbElement = nombreElement;
     * this.type = typeRequete;
     * this.tabFileName = fileName;
     * this.nombre_mot_cle = nbMotCle;
     * this.similarite = similaritee;
     * }
     */

    public int lireResultatFinale() {
        int element_tableauRes = 0;
        // affichage des resultat de recherche par mot cle :
        System.out.println("\nLes resultats pour votre recherche :");
        if (this.type.contains("rechercheMot")) {
            System.out.printf("\nRequete mot-clé :" + this.requete + "\n");
            System.out.println("\nRésultats (fichier -> occurrences) :");
            if (this.nbElement == 0) {
                System.out.println("\nCe mot ne figure pas dans notre base de données\n");
            } else {
                // Appel de la fonction lire_chemin pour afficher les résultats de recherche par
                // mot clé
                lireChemin(lirePont(this.pontJavaC), "texte");
            }
        }

        // affichage des resultat de comparaison texte :
        if (type.contains("texte")) {
            System.out.printf("\nRequete texte :" + this.requete + "\n");
            System.out.println("\nRésultats (fichier -> nombre de mots-clés communs) :");
            if (nbElement == 0) {
                System.out.println("\nAucun mot en communs n'a été trouvé dans notre base de données\n");
            } else {
                // Appel de la fonction lire_chemin pour afficher les résultats de comparaison
                // de texte
                lireChemin(lirePont(this.pontJavaC), "texte");
            }
        }

        // affichage des resultat de comparaison Image :
        if (type.contains("image")) {
            System.out.printf("\nRequete image :" + this.requete + "\n");
            System.out.println("\nRésultats :");
            if (nbElement == 0) {
                System.out.println("\nAucune image similaire n'a été trouvé dans notre base de données\n");
            } else {
                // Appel de la fonction lire_chemin pour afficher les résultats de comparaison
                // d'image
                lireChemin(lirePont(this.pontJavaC), "image");
            }
        }
        // affichage des resultat de comparaison Audio :
        if (type.contains("audio")) {
            System.out.printf("\nRequete audio :" + this.requete + "\n");
            System.out.println("\nRésultats :");
            if (nbElement == 0) {
                System.out.println("\nAucun mot en communs n'a été trouvé dans notre base de données\n");
            } else {
                // Appel de la fonction lire_chemin pour afficher les résultats de comparaison
                // d'audio
                lireChemin(lirePont(this.pontJavaC), "audio");
            }
        }
        return element_tableauRes;
    }

}
