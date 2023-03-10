package JAVA;
import com.sun.jna.Structure;
import com.sun.jna.ptr.ByReference;

public class CONFIG extends Structure {
    public int Nb_Mots_Cle;
    public int Similariter;
    public int Nb_Bit_Fort;
    public int Nb_Fenetre;
    public int Intervale;

    public CONFIG() {
        super();
    }

    public CONFIG(int Nb_Mots_Cle, int Similariter, int Nb_Bit_Fort, int Nb_Fenetre, int Intervale) {
        super();
        this.Nb_Mots_Cle = Nb_Mots_Cle;
        this.Similariter = Similariter;
        this.Nb_Bit_Fort = Nb_Bit_Fort;
        this.Nb_Fenetre = Nb_Fenetre;
        this.Intervale = Intervale;
    }

    public static class ByReference extends CONFIG implements Structure.ByReference {}
}