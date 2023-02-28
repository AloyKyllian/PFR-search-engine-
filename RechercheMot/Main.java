public class Main {
    public static void main(String[] args) {
        String fichier = "monfichier.txt";
        String mot = "mot_a_rechercher";
        int resultat = RechercheMot.INSTANCE.Cherche_Mot(fichier, mot);
        System.out.println("Le mot a été trouvé " + resultat + " fois dans le fichier.");
    }
}
