import com.sun.jna.Pointer;
import java.util.List;
import java.util.Arrays;
import com.sun.jna.Structure;
import com.sun.jna.ptr.ByReference;
import com.sun.jna.ptr.ByValue;

public static class eCellule_audio extends Structure {
    public ELEMENT_audio element;
    public Pointer suiv;

    public eCellule_audio() {
        super();
    }

    public eCellule_audio(Pointer pointer) {
        super(pointer);
    }

    protected List<String> getFieldOrder() {
        return Arrays.asList("element", "suiv");
    }


    //nom de structure aka CELLULE ?? pas sure
    public static class ByReference extends eCellule_image implements Structure.ByReference {
        public ByReference() {
        }

        public ByReference(Pointer pointer) {
            super(pointer);
        }
    }

    //pointeur sur structure aka PILE ?? pas sure
    public static class ByValue extends eCellule_image implements Structure.ByValue {
        public ByValue() {
        }

        public ByValue(Pointer pointer) {
            super(pointer);
        }
    }
}