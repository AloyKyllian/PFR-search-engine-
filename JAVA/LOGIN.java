package JAVA;
import com.sun.jna.Structure;

public class LOGIN extends Structure {
    public String id;
    public String mdp;

    public LOGIN() {
        super();
    }

    public LOGIN(String id, String mdp) {
        super();
        this.id = id;
        this.mdp = mdp;
    }

    public static class ByReference extends LOGIN implements Structure.ByReference {}
}
