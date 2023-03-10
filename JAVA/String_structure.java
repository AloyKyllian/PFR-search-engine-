import com.sun.jna.Structure;
import com.sun.jna.ptr.ByReference;

public class StringStruct extends Structure {
    public byte[] str = new byte[700];

    public StringStruct() {
        super();
    }

    public StringStruct(String s) {
        super();
        byte[] bytes = s.getBytes();
        for (int i = 0; i < bytes.length && i < 700; i++) {
            str[i] = bytes[i];
        }
    }

    public static class ByReference extends StringStruct implements Structure.ByReference {}
}