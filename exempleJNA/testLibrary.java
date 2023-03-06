import com.sun.jna.Library;
import com.sun.jna.Native;
import com.sun.jna.ptr.PointerByReference;

public interface testLibrary extends Library {

    testLibrary INSTANCE = (testLibrary) Native.loadLibrary("test", testLibrary.class);

    void test();
}
