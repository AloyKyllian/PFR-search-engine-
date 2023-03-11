import java.util.ArrayList;
public class testLireResusltat {

    public static void main(String[] args) {
       LireResultat lireresult = new LireResultat();
       ArrayList<ELLEMENT> listeElement = new ArrayList<>();
       listeElement=lireresult.lireChemin("texte");
       for( ELLEMENT lig : listeElement)
       {
           System.out.println(lig);
       }
      
    }
}