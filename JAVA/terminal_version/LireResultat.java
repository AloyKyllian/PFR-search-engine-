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

  public LireResultat() {
  }

  public ArrayList<String[]> lirePont() {
    ArrayList<String[]> pont = new ArrayList<>();

    try {
      File file = new File(ListCheminFichier.cheminPontCJ);
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

  public ArrayList<String> lirePontComplexe() {
    ArrayList<String> pont = new ArrayList<>();

    try {
      File file = new File(ListCheminFichier.cheminPontCJ);
      Scanner scanner = new Scanner(file);

      // Lit chaque ligne du fichier et stocke les données dans le tableau
      while (scanner.hasNextLine()) {
        String[] ligne = scanner.nextLine().split(" ");
        pont.add(ligne[0]);
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
      chaine = READ_WRITE_FICHIER.read(ListCheminFichier.cheminBaseNB);
    }
    if (type.equals("rgb")) {
      chaine = READ_WRITE_FICHIER.read(ListCheminFichier.cheminBaseRGB);
    }
    if (type.equals("audio")) {
      chaine = READ_WRITE_FICHIER.read(ListCheminFichier.cheminBaseAudio);
    }
    if (type.equals("texte")) {
      chaine = READ_WRITE_FICHIER.read(ListCheminFichier.cheminBaseTexte);
    }
    String[] ligne = chaine.split("\n");
    for (String lig : ligne) {
      String[] cases = lig.split(" ");
      String premiereSousChaine = cases[1].replace("|", "");
      listeElement.add(new ELLEMENT(cases[0], premiereSousChaine));
    }

    return listeElement;
  }

  public char lireResultatFinale(String type, List<String> requeteComplexe, String typeImage) {
    ArrayList<ELLEMENT> listeElement = new ArrayList<>();
    ArrayList<ELLEMENT> listeElementRGB = new ArrayList<>();
    ArrayList<ELLEMENT> listeElementNB = new ArrayList<>();
    List<String[]> pont = new ArrayList<>();
    List<String> nomFichier = new ArrayList<>();
    pont = lirePont();
    String fileName;
    String cheminFileName;
    int numero;
    String chaineNB = "";
    String chaineRGB = "";
    char choix = 'R';
    // affichage des resultat de recherche par mot cle :
    System.out.println("\nLes resultats pour votre recherche :");
    if (type.contains("requeteComplexe")) {
      System.out.println("Requete mot-clé : " + this.requete);
      System.out.println("Résultats (fichier) :");
      if (requeteComplexe.size() == 0) {
        System.out.println("Ces mot ne figure pas dans notre base de données");
      } else {
        // Appel de la fonction lire_chemin pour afficher les résultats de recherche par
        // mot clé
        listeElement = LireResultat.lireChemin("texte");
        numero = 1;
        for (String premiereCase : requeteComplexe) {
          String id = premiereCase;
          for (ELLEMENT element : listeElement) {
            if (element.ID.equals(id)) {
              fileName = traitementChemin.extension(TypeFichier.TEXTE, element.chemin);
              cheminFileName = element.chemin;
              System.out.println("[" + numero + "]" + " " + fileName.substring(fileName.lastIndexOf('/') + 1));
              numero++;
              nomFichier.add(cheminFileName);
            }
          }
        }
        LireResultat.visualiserFichier(nomFichier.get(0));
        choix = LireResultat.visualiserToutFichier(nomFichier);
      }
    }
    if (type.contains("rechercheMot")) {
      System.out.println("Requete mot-clé : " + this.requete);
      System.out.println("Résultats (fichier : occurrences) :");
      if (pont.size() == 0) {
        System.out.println("Ce mot ne figure pas dans notre base de données");
      } else {
        // Appel de la fonction lire_chemin pour afficher les résultats de recherche par
        // mot clé
        listeElement = LireResultat.lireChemin("texte");
        numero = 1;
        for (String[] premiereCase : pont) {
          String id = premiereCase[0];
          String nombreOccurence = premiereCase[1];
          for (ELLEMENT element : listeElement) {
            // System.out.println(element.toString());
            if (element.ID.equals(id)) {
              fileName = traitementChemin.extension(TypeFichier.TEXTE, element.chemin);
              cheminFileName = element.chemin;
              if (Integer.parseInt(nombreOccurence) > 0 && Integer.parseInt(nombreOccurence) < 100) {
                System.out.println("[" + numero + "]" + " " + fileName.substring(fileName.lastIndexOf('/') + 1) + " : "
                    + nombreOccurence);
                numero++;
                nomFichier.add(cheminFileName);
              }
            }
          }
        }
        LireResultat.visualiserFichier(nomFichier.get(0));
        choix = LireResultat.visualiserToutFichier(nomFichier);
      }
    }

    // affichage des resultat de comparaison texte :
    else if (type.contains("texte")) {
      System.out.println("Requete texte : " + this.requete);
      System.out.println("Résultats (fichier -> nombre de mots-clés communs) :");
      if (pont.size() == 0) {
        System.out.println("Aucun texte en communs n'a été trouvé dans notre base de données");
      } else {
        // Appel de la fonction lire_chemin pour afficher les résultats de comparaison
        // de texte
        listeElement = LireResultat.lireChemin("texte");
        numero = 1;
        for (String[] premiereCase : pont) {
          String id = premiereCase[0];
          String nombreOccurence = premiereCase[1];
          for (ELLEMENT element : listeElement) {
            if (element.ID.equals(id)) {
              fileName = traitementChemin.extension(TypeFichier.TEXTE, element.chemin);
              cheminFileName = element.chemin;
              if (Integer.parseInt(nombreOccurence) > 0 && Integer.parseInt(nombreOccurence) < 100) {
                System.out.println("[" + numero + "]" + " " + fileName.substring(fileName.lastIndexOf('/') + 1) + " : "
                    + nombreOccurence + "%");
                numero++;
                nomFichier.add(cheminFileName);
              }
            }
          }
        }
        LireResultat.visualiserFichier(nomFichier.get(0));
        choix = LireResultat.visualiserToutFichier(nomFichier);
      }
    }

    // affichage des resultat de comparaison Image :
    else if (type.contains("image")) {
      System.out.println("Requete image : " + this.requete);
      System.out.println("Résultats :");
      if (pont.size() == 0) {
        System.out.println("Aucune image similaire n'a été trouvé dans notre base de données");
      } else {
        // Appel de la fonction lire_chemin pour afficher les résultats de comparaison
        // d'image
        if (typeImage.contains("bmp")) {

          listeElement = LireResultat.lireChemin("nb");
          numero = 1;
          for (String[] premiereCase : pont) {
            String id = premiereCase[0];
            String nombreOccurence = premiereCase[1];
            for (ELLEMENT element : listeElement) {
              if (element.ID.equals(id)) {
                fileName = traitementChemin.extension(TypeFichier.NB, element.chemin);
                cheminFileName = element.chemin.replace("txt", "bmp");
                if (Integer.parseInt(nombreOccurence) > 0 && Integer.parseInt(nombreOccurence) < 100) {
                  System.out
                      .println("[" + numero + "]" + " " + fileName.substring(fileName.lastIndexOf('/') + 1) + " : "
                          + nombreOccurence + "%");
                  numero++;
                  nomFichier.add(cheminFileName);
                }
              }
            }
          }
          LireResultat.visualiserFichier(nomFichier.get(0));
          choix = LireResultat.visualiserToutFichier(nomFichier);
        }

        if (typeImage.contains("jpg")) {
          System.out.println("parrtie jpg");
          listeElement = LireResultat.lireChemin("rgb");
          numero = 1;
          for (String[] premiereCase : pont) {
            String id = premiereCase[0];
            String nombreOccurence = premiereCase[1];
            for (ELLEMENT element : listeElement) {
              if (element.ID.equals(id)) {
                fileName = traitementChemin.extension(TypeFichier.NB, element.chemin);
                cheminFileName = element.chemin.replace("txt", "jpg");
                if (Integer.parseInt(nombreOccurence) > 0 && Integer.parseInt(nombreOccurence) < 100) {
                  System.out
                      .println("[" + numero + "]" + " " + fileName.substring(fileName.lastIndexOf('/') + 1) + " : "
                          + nombreOccurence + "%");
                  numero++;
                  nomFichier.add(cheminFileName);
                }
              }
            }
          }
        }
      }
    }
    // affichage des resultat de comparaison Audio :
    else if (type.contains("audio")) {
      System.out.println("Requete audio : " + this.requete);
      System.out.println("Résultats :");
      if (pont.size() == 0) {
        System.out.println("Aucun audio en communs n'a été trouvé dans notre base de données");
      } else {

        // Appel de la fonction lire_chemin pour afficher les résultats de comparaison
        // d'audio
        listeElement = LireResultat.lireChemin(type);

        // separer le nom du fichier du chemin
        numero = 1;
        for (String[] premiereCase : pont) {
          String id = premiereCase[0];
          String nombreOccurence = premiereCase[1];
          for (ELLEMENT element : listeElement) {
            if (element.ID.equals(id)) {
              fileName = traitementChemin.extension(TypeFichier.AUDIO, element.chemin);
              cheminFileName = element.chemin.replace("txt", "wav");
              if (Integer.parseInt(nombreOccurence) > 0 && Integer.parseInt(nombreOccurence) < 100) {
                System.out.println("[" + numero + "]" + " " + fileName.substring(fileName.lastIndexOf('/') + 1) + " : "
                    + nombreOccurence + "%");
                numero++;
                nomFichier.add(cheminFileName);
              }
            }
          }
        }
        LireResultat.visualiserFichier(nomFichier.get(0));
        choix = LireResultat.visualiserToutFichier(nomFichier);
      }
    }
    return choix;
  }

  public static void visualiserFichier(String chemin) {
    try {
      File file = new File(chemin);
      if (!file.exists()) {
        System.out.println("Le fichier n'existe pas.");
        return;
      }
      String extension = chemin.substring(chemin.lastIndexOf('.') + 1);
      if (extension.equalsIgnoreCase("xml")) {
        ProcessBuilder pb = new ProcessBuilder();
        pb.command("gedit", chemin);
        pb.start();
      } else {
        ProcessBuilder pb = new ProcessBuilder();
        pb.command("xdg-open", chemin);
        pb.start();
      }
    } catch (IOException e) {
      e.printStackTrace();
    }
  }

  public static char visualiserToutFichier(List<String> nomFichier) {
    char choix = '1';
    int numeroFichier;
    while (choix != 'Q' && choix != 'R') {
      switch (choix) {
        case '1':
          System.out.println("Voulez vous revoir un autre fichier ?");
          System.out.println("[1] Oui\n[2] Non");
          choix = Clavier.entrerClavierChar();
          if (choix != '2') {
            System.out.println("Entrer le numero de fichier que vous voulez visualiser");
            numeroFichier = Clavier.entrerClavierInt();
            if (numeroFichier < nomFichier.size() + 1) {
              visualiserFichier(nomFichier.get(numeroFichier - 1));
            } else {
              System.out.println("Ce fichier ne figure pas sur la liste");
              choix = '1';
            }
          } else {
            choix = '2';
          }
          break;

        case '2':
          System.out.println("Voulez vous Quitter ou retourner aux recherches?");
          System.out.println("[Q] Quitter\n[R] Retour");
          choix = Clavier.entrerClavierChar();
          break;
        default:
          break;
      }
    }
    return choix;
  }

}
