import java.io.File;

public class traitementChemin {
    public static String extension(TypeFichier type, String chemin) {
        String[] tmp1;
        if (chemin.charAt(0) == '.') {
            tmp1 = chemin.split("/");
            chemin = tmp1[4];
        }
        String[] chemins = chemin.split("\\.");
        switch (type) {
            case TEXTE:
                chemins[0] = chemins[0] + ".xml";
                break;
            case AUDIO:
                chemins[0] = chemins[0] + ".wav";
                break;
            case NB:
                chemins[0] = chemins[0] + ".bmp";
                break;
            case RGB:
                chemins[0] = chemins[0] + ".jpg";
                break;
        }
        chemins[0] = "../" + chemins[0];

        return chemins[0];

    }

    public static String recupCheminPourAffichage(String chemin) {
        String[] tmp1;
        if (chemin.charAt(0) == '.') {
            tmp1 = chemin.split("\\.\\./");
            chemin = tmp1[1];
        }
        String[] chemins = chemin.split("\\.");
        chemins[0] = chemins[0] + ".txt";
        chemins[0] = "../" + chemins[0];
        return chemins[0];

    }

    public static boolean fichierExist(String chemin) {
        File fichier = new File(chemin);
        return fichier.exists();
    }

    public static boolean verifExtension(String chemin, String extension) {
        String[] tmp1;
        if (chemin.charAt(0) == '.') {
            tmp1 = chemin.split("\\.\\./");
            chemin = tmp1[1];
        }
        String[] chemins = chemin.split("\\.");
        return chemins[1].equals(extension);
    }

}
