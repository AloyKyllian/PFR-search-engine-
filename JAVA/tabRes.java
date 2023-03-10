import com.sun.jna.Structure;

public class tabRes extends Structure {
    public int id;
    public int pourcentage;

    public tabRes() {
        super();
    }

    public tabRes(int id, int pourcentage) {
        super();
        this.id = id;
        this.pourcentage = pourcentage;
    }

    public static class ByReference extends tabRes implements Structure.ByReference {}
}