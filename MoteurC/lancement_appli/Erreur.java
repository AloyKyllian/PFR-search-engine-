public class Erreur{

    public static void afficherErreur(int erreur)
    {
        String[]tmp= READ_WRITE_FICHIER.read("../MoteurC/Gestion-Erreur/Erreur.txt").split("\n");
        System.out.println(tmp[erreur]);
    }
}