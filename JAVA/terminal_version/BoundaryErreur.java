public class BoundaryErreur {
	 public static void afficherErreur(int erreur)
	    {
	        String[]tmp= ReadWriteFichier.readOn(ListCheminFichier.cheminErreur).split("\n");
	        System.out.println(tmp[erreur]);
	    }

}
