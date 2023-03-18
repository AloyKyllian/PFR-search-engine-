public class Erreur{

    public static void afficherErreur(int erreur)
    {
        String[]tmp= READ_WRITE_FICHIER.read(ListCheminFichier.cheminErreur).split("\n");
        System.out.println(tmp[erreur]);
    }
}