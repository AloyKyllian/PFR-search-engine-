

public class LireResultatTest {
    

        public static void main(String[] args) {
           LireResultat test=new LireResultat();
           test.nbElement=3;
           test.type="texte";
           test.requete="texte";
           test.similarite=50;
           test.pontJavaC="pontJavaC.txt";

           test.lireResultatFinale(test.type);
        }
}
