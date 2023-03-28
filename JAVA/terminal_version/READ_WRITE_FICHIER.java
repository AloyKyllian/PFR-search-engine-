import java.io.FileWriter;
import java.io.FileReader;
import java.io.IOException;
import java.awt.Desktop;
import java.io.File;

public class READ_WRITE_FICHIER {

    //rajoute les partie
    public  static void write(String nomFichier, String texte) {
    	  try {
              FileWriter writer = new FileWriter(nomFichier, true);
              writer.write(texte);   // write new line
              writer.close();
          } catch (IOException e) {
        	  System.out.println("An error occurred.");
              e.printStackTrace();
          }
    }
    // ecrase le texte existant
    public  static void writeOn(String nomFichier, String texte) {    
          try {

            FileWriter writer1 = new FileWriter(nomFichier, false);
            writer1.write("");
            writer1.close();

              FileWriter writer = new FileWriter(nomFichier, true);
              writer.write(texte);   // write new line
              writer.close();
          } catch (IOException e) {
        	  System.out.println("An error occurred.");
              e.printStackTrace();
          }
    }

     public  static String read(String nomFichier) {
            String texte="";
            try {
                
                FileReader myReader = new FileReader(nomFichier);
                int character;
                while ((character = myReader.read()) != -1) {
                    texte = texte+ (char)character;
                }
                myReader.close();

                /*FileWriter writer1 = new FileWriter(nomFichier, false);
                writer1.write("");
                writer1.close();*/

            } catch (IOException e) {
                System.out.println("An error occurred.");
                e.printStackTrace();
            }

            return texte;
}

    public static void ouvertureFichier(String cheminFichier) {


        try {
            // Créer un objet File avec le chemin du fichier
            File fichier = new File(cheminFichier);

            // Vérifier si le bureau est supporté
            if (Desktop.isDesktopSupported()) {
                Desktop desktop = Desktop.getDesktop();

                // Vérifier si l'ouverture de fichiers est supportée
                if (desktop.isSupported(Desktop.Action.OPEN)) {
                    desktop.open(fichier); // Ouvrir le fichier avec l'application par défaut
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}



