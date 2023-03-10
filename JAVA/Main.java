package JAVA;
import com.sun.jna.Native;
import com.sun.jna.Library;
import com.sun.jna.Pointer;
import com.sun.jna.Memory;
import com.sun.jna.Structure;

public class Main {
   
    public interface MyLibrary extends Library {
        MyLibrary INSTANCE = (MyLibrary) Native.load("../MoteurC/Login/Login.so", MyLibrary.class);
        
        //affiche id et mdp 
        //void afficher_un_login (LesLogins.ByValue tablogin, int i);
        // afficher tous les logins
        //void afficher_les_login (LesLogins.ByValue tablogin);
        // Entrer id et mdp
        LOGIN saisir_login();
        //void lire_fichier_login (lesLogins tablogin, int * erreur);
    }
    public static void main(String[] args) {

        LOGIN test = new LOGIN();

        test = MyLibrary.INSTANCE.saisir_login();
        
    }
}