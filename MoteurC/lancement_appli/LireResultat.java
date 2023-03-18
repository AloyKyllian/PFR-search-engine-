//
// AUTEUR :
//          YOUSSERA ACHACHERA
// DERNIERE VERSION :
//    23/01/2023
//

import java.io.*;
import java.util.*;
import java.awt.Desktop;

public class LireResultat {

  int nbElement;
  String type;
  String requete;
  int nombre_mot_cle;
  int similarite;
  String pontJavaC;

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
        String[] ligne = scanner.nextLine().split(" ");
        pont.add(ligne);
      }

      scanner.close();
    } catch (FileNotFoundException e) {
      e.printStackTrace();
    }

    return pont;
  }

  public static ArrayList<ELLEMENT> lireChemin(String type) {
    ArrayList<ELLEMENT> listeElement = new ArrayList<>();

    String chaine = "";
    if (type.equals("nb")) {
      chaine =
        READ_WRITE_FICHIER.read("../liste_base/liste_base_image/NB");
    }
    if (type.equals("rgb")) {
      chaine =
        READ_WRITE_FICHIER.read("../liste_base/liste_base_image/RGB");
    }
    if (type.equals("audio")) {
      chaine =
        READ_WRITE_FICHIER.read("../liste_base/liste_base_audio");
    }
    if (type.equals("texte")) {
      chaine =
        READ_WRITE_FICHIER.read("../liste_base/liste_base_texte");
    }
    String[] ligne = chaine.split("\n");
    for (String lig : ligne) {
      String[] cases = lig.split(" ");
      listeElement.add(new ELLEMENT(cases[0], cases[1]));
    }

    return listeElement;
  }


  public void lireResultatFinale(String type) {
    ArrayList<ELLEMENT> listeElement = new ArrayList<>();
    List<String[]> pont = new ArrayList<>();
    List<String> nomFichier = new ArrayList<>();
    pont=LireResultat.lirePont(this.pontJavaC);
    String fileName;

    // affichage des resultat de recherche par mot cle :
    System.out.println("\nLes resultats pour votre recherche :");
    if (this.type.contains("rechercheMot")) {
      System.out.println("Requete mot-clé : " + this.requete);
      System.out.println("Résultats (fichier -> occurrences) :");
      if (pont.size()==0) {
        System.out.println("Ce mot ne figure pas dans notre base de données");
      } else {
        // Appel de la fonction lire_chemin pour afficher les résultats de recherche par
        // mot clé
        listeElement = LireResultat.lireChemin(type);
        for (String[] premiereCase : pont) {
          String id = premiereCase[0];
          String nombreOccurence = premiereCase[1];
          for (ELLEMENT element : listeElement) {
            if (element.ID.equals(id)) {
              fileName=traitementChemin.recupCheminPourAffichage(TypeFichier.TEXTE, element.chemin);
              System.out.println( fileName+ " : " + nombreOccurence + "%");
              nomFichier.add(element.chemin);
            }
          }
        }
         
      }
    }

    // affichage des resultat de comparaison texte :
    if (type.contains("texte")) {
      System.out.println("Requete texte : " + this.requete);
      System.out.println("Résultats (fichier -> nombre de mots-clés communs) :");
      if (pont.size()==0) {
        System.out.println("Aucun texte en communs n'a été trouvé dans notre base de données");
      } else {
        // Appel de la fonction lire_chemin pour afficher les résultats de comparaison
        // de texte
         listeElement =  LireResultat.lireChemin("texte");
        for (String[] premiereCase : pont) {
          String id = premiereCase[0];
          String nombreOccurence = premiereCase[1];
          for (ELLEMENT element : listeElement) {
            if (element.ID.equals(id)) {
              fileName=traitementChemin.recupCheminPourAffichage(TypeFichier.TEXTE, element.chemin);
              System.out.println( fileName+ " : " + nombreOccurence + "%");
              nomFichier.add(element.chemin);

            }
          }
        }
      }
    }

    // affichage des resultat de comparaison Image :
    if (type.contains("image")) {
      System.out.println("Requete image : " + this.requete);
      System.out.println("Résultats :");
      if (pont.size()==0) {
        System.out.println("Aucune image similaire n'a été trouvé dans notre base de données");
      } else {
        // Appel de la fonction lire_chemin pour afficher les résultats de comparaison
        // d'image
        listeElement =  LireResultat.lireChemin("image");
        for (String[] premiereCase : pont) {
          String id = premiereCase[0];
          String nombreOccurence = premiereCase[1];
          for (ELLEMENT element : listeElement) {
            if (element.ID.equals(id)) {
              fileName=traitementChemin.recupCheminPourAffichage(TypeFichier.RGB, element.chemin);
              System.out.println( fileName+ " : " + nombreOccurence + "%");
              nomFichier.add(element.chemin);
            }
          }
        }
      }
    }
    // affichage des resultat de comparaison Audio :
    if (type.contains("audio")) {
      System.out.println("Requete audio : " + this.requete);
      System.out.println("Résultats :");
      if (pont.size()==0) {
        System.out.println("Aucun audio en communs n'a été trouvé dans notre base de données");
      } else {
        
        // Appel de la fonction lire_chemin pour afficher les résultats de comparaison
        // d'audio
        listeElement =  LireResultat.lireChemin(type);

        //separer le nom du fichier du chemin 
        

        for (String[] premiereCase : pont) {
          String id = premiereCase[0];
          String nombreOccurence = premiereCase[1];
          for (ELLEMENT element : listeElement) {
            if (element.ID.equals(id)) {
              fileName=traitementChemin.recupCheminPourAffichage(TypeFichier.AUDIO, element.chemin);
              System.out.println( fileName+ " : " + nombreOccurence + "%");
              nomFichier.add(element.chemin);
            }
          }
        }
        LireResultat.visualiserFichier(nomFichier.get(0));
      }
    }
    
     
  }

  public static void visualiserFichier(String chemin) {
      File file = new File(chemin+".geddit");
        if (Desktop.isDesktopSupported()) {
            Desktop desktop = Desktop.getDesktop();
            if (file.exists()) {
                try {
                    desktop.open(file);
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }

  }

}
