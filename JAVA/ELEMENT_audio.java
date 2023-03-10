import com.sun.jna.Structure;

public class ELEMENT_audio extends Structure {
    public descri_audio descripteur;
    public int id;

    public ELEMENT_audio() {
        super();
    }

    public ELEMENT_audio(descri_audio descripteur, int id) {
        super();
        this.descripteur = descripteur;
        this.id = id;
    }

    public static class ByReference extends ELEMENT_image implements Structure.ByReference {}
}