import com.sun.jna.Library;
import com.sun.jna.Native;
import com.sun.jna.Pointer;
import com.sun.jna.Memory;

public class Main{

public interface MenuLibrary extends Library {

    MenuLibrary INSTANCE = (MenuLibrary) Native.loadLibrary("Menu.so", MenuLibrary.class);

    void MAE(Pointer config, char [] choix, Pointer erreurImage,Pointer erreurAudio, Pointer erreurTexte, Pointer erreurIndex);
}
public static void main(String[] args) {
    Congif config ;
    Pointer ptrConfig=new Memory(4);
    ptrConfig.setConfig(0,config);

    int erreurImage = -1;
    Pointer ptrErreurImage=new Memory(4);
    ptrErreurImage.setInt(0,erreurImage);

    int erreurAudio = -1;
    Pointer ptrErreurAudio=new Memory(4);
    ptrErreurAudio.setInt(0,erreurAudio);

    int erreurIndex = -1;
    Pointer ptrErreurIndex=new Memory(4);
    ptrErreurIndex.setInt(0,erreurIndex);

    int erreurTexte = -1;
    Pointer ptrErreurTexte=new Memory(4);
    ptrErreurTexte.setInt(0,erreurTexte);

    char[] choix = new char[100];

    MAE(ptrConfig,choix, ptrErreurImage, ptrErreurAudio, ptrErreurTexte, ptrErreurIndex);
   
}
}
