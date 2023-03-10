import com.sun.jna.Pointer;
import com.sun.jna.Structure;
import com.sun.jna.ptr.ByReference;
import com.sun.jna.ptr.ByValue;

public static class eCellule extends Structure {
    public ELEMENT element;
    public Pointer suiv;

    public eCellule() {
        super();
    }

    public eCellule(Pointer pointer) {
        super(pointer);
    }

    protected List<String> getFieldOrder() {
        return Arrays.asList("element", "suiv");
    }


    //nom de structure aka CELLULE ?? pas sure
    public static class ByReference extends eCellule implements Structure.ByReference {
        public ByReference() {
        }

        public ByReference(Pointer pointer) {
            super(pointer);
        }
    }

    //pointeur sur structure aka PILE ?? pas sure
    public static class ByValue extends eCellule implements Structure.ByValue {
        public ByValue() {
        }

        public ByValue(Pointer pointer) {
            super(pointer);
        }
    }
}


