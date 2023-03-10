package JAVA;
import com.sun.jna.Pointer;
import com.sun.jna.Structure;



public static class LesLogins extends Structure {
    public LOGIN[] lesLogins = new LOGIN[5];

    public LesLogins() {
        super();
    }

    public LesLogins(Pointer pointer) {
        super(pointer);
        read();
    }

    protected List<String> getFieldOrder() {
        return Arrays.asList("lesLogins");
    }

    public static class ByReference extends LesLogins implements Structure.ByReference {
        public ByReference() {
        }

        public ByReference(Pointer pointer) {
            super(pointer);
        }
    }

    public static class ByValue extends LesLogins implements Structure.ByValue {
        public ByValue() {
        }

        public ByValue(Pointer pointer) {
            super(pointer);
        }
    }
}