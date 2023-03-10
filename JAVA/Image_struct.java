import com.sun.jna.Pointer;
import com.sun.jna.Structure;
import com.sun.jna.ptr.IntByReference;

public class IMAGE extends Structure {
    public int Nb_Ligne;
    public int Nb_Colonne;
    public int Nb_composante;
    public Pointer adr_Matrice;

    public IMAGE() {
        super();
    }

    public IMAGE(int nbLigne, int nbColonne, int nbComposante, int[][] matrice) {
        super();
        Nb_Ligne = nbLigne;
        Nb_Colonne = nbColonne;
        Nb_composante = nbComposante;
        int[] flatMatrice = flattenMatrice(matrice);
        adr_Matrice = new Memory(flatMatrice.length * Native.getNativeSize(Integer.TYPE));
        adr_Matrice.write(0, flatMatrice, 0, flatMatrice.length);
    }

    public int[][] getMatrice() {
        int[] flatMatrice = new int[Nb_Ligne * Nb_Colonne * Nb_composante];
        adr_Matrice.read(0, flatMatrice, 0, flatMatrice.length);
        return unflattenMatrice(flatMatrice);
    }

    private int[] flattenMatrice(int[][] matrice) {
        int[] flatMatrice = new int[matrice.length * matrice[0].length];
        int index = 0;
        for (int i = 0; i < matrice.length; i++) {
            for (int j = 0; j < matrice[i].length; j++) {
                flatMatrice[index++] = matrice[i][j];
            }
        }
        return flatMatrice;
    }

    private int[][] unflattenMatrice(int[] flatMatrice) {
        int[][] matrice = new int[Nb_Ligne][Nb_Colonne];
        int index = 0;
        for (int i = 0; i < Nb_Ligne; i++) {
            for (int j = 0; j < Nb_Colonne; j++) {
                matrice[i][j] = flatMatrice[index++];
            }
        }
        return matrice;
    }

    public static class ByReference extends IMAGE implements Structure.ByReference {}
}