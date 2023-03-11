import com.sun.jna.Library;
import com.sun.jna.Native;

public interface RechercheMot extends Library {
    RechercheMot INSTANCE = (RechercheMot) Native.loadLibrary("libRechercheMot", RechercheMot.class);
    
    int Cherche_Mot(String fichier, String mot);
}
