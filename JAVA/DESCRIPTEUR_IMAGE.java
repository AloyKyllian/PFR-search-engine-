package JAVA;
import com.sun.jna.Structure;
import java.util.List;
import java.util.Arrays;
import com.sun.jna.ptr.ByReference;

public static class DESCRIPTEUR_IMAGE extends Structure {
    public int Nb_Ligne;
    public int Nb_Colonne;
    public PointerByReference Bilan;

    public DESCRIPTEUR_IMAGE() {
        super();
    }

    public DESCRIPTEUR_IMAGE(Pointer pointer) {
        super(pointer);
    }

    protected List<String> getFieldOrder() {
        return Arrays.asList("Nb_Ligne", "Nb_Colonne", "Bilan");
    }

    public static class ByReference extends DESCRIPTEUR_IMAGE implements Structure.ByReference {
        public ByReference() {
        }

        public ByReference(Pointer pointer) {
            super(pointer);
        }
    }

    public static class ByValue extends DESCRIPTEUR_IMAGE implements Structure.ByValue {
        public ByValue() {
        }

        public ByValue(Pointer pointer) {
            super(pointer);
        }
    }
}