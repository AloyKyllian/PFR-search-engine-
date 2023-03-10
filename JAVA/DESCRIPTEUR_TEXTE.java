import com.sun.jna.Structure;

public class DESCRIPTEUR_TEXTE extends Structure {
    public String tab_mot;
    public int[] tab_app;
    public int index;

    public DESCRIPTEUR_TEXTE() {
        super();
    }

    public DESCRIPTEUR_TEXTE(String tab_mot, int[] tab_app, int index) {
        super();
        this.tab_mot = tab_mot;
        this.tab_app = tab_app;
        this.index = index;
    }

    public static class ByReference extends DESCRIPTEUR_TEXTE implements Structure.ByReference {}
}