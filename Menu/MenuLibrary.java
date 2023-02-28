import com.sun.jna.Library;
import com.sun.jna.Native;
import com.sun.jna.ptr.PointerByReference;

public interface MenuLibrary extends Library {

    MenuLibrary INSTANCE = (MenuLibrary) Native.loadLibrary("Menu", MenuLibrary.class);

    void Afficher_Menu(PointerByReference cfg);

    void Lire_CHOIX(char[] choix);

    void indexation(CONFIG cfg, int[] err_img, int[] err_aud, int[] err_txt, int[] err_idx);

    CONFIG Lire_CONFIG(int[] erreurConfig);

    void Afficher_Erreur(int erreur, String nom_fichier, char[] msg_erreur);

    void MAE(PointerByReference cfg, char[] choix, int[] err_img, int[] err_aud, int[] err_txt, int[] err_idx);

}
