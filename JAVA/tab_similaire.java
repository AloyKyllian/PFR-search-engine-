
public static class tab_similaire extends Structure {
    public int id;
    public float pourcentage;

    public tab_similaire() {
        super();
    }

    public tab_similaire(Pointer pointer) {
        super(pointer);
    }

    protected List<String> getFieldOrder() {
        return Arrays.asList("id", "pourcentage");
    }

    public static class ByReference extends tab_similaire implements Structure.ByReference {
        public ByReference() {
        }

        public ByReference(Pointer pointer) {
            super(pointer);
        }
    }

    public static class ByValue extends tab_similaire implements Structure.ByValue {
        public ByValue() {
        }

        public ByValue(Pointer pointer) {
            super(pointer);
        }
    }
}