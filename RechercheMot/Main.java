public class Main {
    public static void main(String[] args) {
        String fichier = "../base_descripteur/base_descripteur_texte";
        String mot = "soleil";
        int resultat = RechercheMot.INSTANCE.Cherche_Mot(fichier, mot);
        System.out.println("Le mot a été trouvé " + resultat + " fois dans le fichier.");
    }
}
