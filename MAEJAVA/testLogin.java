public class testLogin {
    public static void main(String[] args) {
        boolean result;
        result= LOGIN.connexion();
        if(result) 
                            {
                                System.out.println("Réussie\n\n") ;                    
                            } 
                            else
                            {
                                System.out.println("Échouée\n\n");
                            }
    }
}