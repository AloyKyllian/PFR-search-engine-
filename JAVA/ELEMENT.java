import com.sun.jna.Structure;

public class ELEMENT extends Structure {
    public int id;
    public String CHEMIN;

    public ELEMENT() {
        super();
    }

    public ELEMENT(int id, String chemin) {
        super();
        this.id = id;
        this.CHEMIN = chemin;
    }

    public static class ByReference extends ELEMENT implements Structure.ByReference {}
}