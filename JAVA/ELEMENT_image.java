import com.sun.jna.Structure;

public class ELEMENT_image extends Structure {
    public DESCRIPTEUR_IMAGE descripteur_image ;
    public int id;

    public ELEMENT_image() {
        super();
    }

    public ELEMENT_image(DESCRIPTEUR_IMAGE descripteur_image, int id) {
        super();
        this.descripteur_image = descripteur_image;
        this.id = id;
    }

    public static class ByReference extends ELEMENT_image implements Structure.ByReference {}
}