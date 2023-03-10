import com.sun.jna.Structure;

public class ELEMENT_texte extends Structure {
    public DESCRIPTEUR_TEXTE descripteur_texte ;
    public int id;

    public ELEMENT_texte() {
        super();
    }

    public ELEMENT_texte(DESCRIPTEUR_TEXTE descripteur_texte, int id) {
        super();
        this.descripteur_texte = descripteur_texte;
        this.id = id;
    }

    public static class ByReference extends ELEMENT_image implements Structure.ByReference {}
}