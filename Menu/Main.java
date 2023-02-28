import com.sun.jna.ptr.PointerByReference;

public class Main {
    public static void main(String[] args) {
        PointerByReference cfg = new PointerByReference();
        int[] err_img = new int[1];
        int[] err_aud = new int[1];
        int[] err_txt = new int[1];
        int[] err_idx = new int[1];
        int[] erreurConfig = new int[1];
        char[] choix = new char[100];
        MenuLibrary.INSTANCE.Afficher_Menu(cfg);
        MenuLibrary.INSTANCE.Lire_CHOIX(choix);
        CONFIG config = MenuLibrary.INSTANCE.Lire_CONFIG(erreurConfig);
        MenuLibrary.INSTANCE.indexation(config, err_img, err_aud, err_txt, err_idx);
        MenuLibrary.INSTANCE.MAE(cfg, choix, err_img, err_aud, err_txt, err_idx);
    }
}
