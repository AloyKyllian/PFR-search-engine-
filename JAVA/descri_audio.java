package JAVA;
import com.sun.jna.Pointer;
import com.sun.jna.Structure;

public class descri_audio extends Structure {
    public int ligne;
    public int colonne;
    public Pointer tab;

    public descri_audio() {
        super();
    }

    public descri_audio(int ligne, int colonne, Pointer tab) {
        super();
        this.ligne = ligne;
        this.colonne = colonne;
        this.tab = tab;
    }

    public static class ByReference extends descri_audio implements Structure.ByReference {}
}