import java.io.FileWriter;
import java.io.FileReader;
import java.io.IOException;


public class READ_WRITE_FICHIER {

    //deux methodes
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

     public  static String read(String nomFichier) {
            String texte="";
            try {
                
                FileReader myReader = new FileReader(nomFichier);
                int character;
                while ((character = myReader.read()) != -1) {
                    texte = texte+ (char)character;
                }
                myReader.close();
            } catch (IOException e) {
                System.out.println("An error occurred.");
                e.printStackTrace();
            }
            return texte;
}
    }

