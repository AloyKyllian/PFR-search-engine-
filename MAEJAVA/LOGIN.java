import java.util.Map;
import java.util.HashMap;

public class LOGIN{

    //attributs
    private String username;
    private String motDePasse;
    // cle username , valeur mot de passe 
    static Map<String, String> logins;

    //constructeur
    private LOGIN(String username, String motDePasse)
    {
        this.username= username;
        this.motDePasse = motDePasse;
        logins = new HashMap<>();
        logins.put("kyllian","aloy");
        logins.put("achachera","youssera");
        logins.put("m","l");
        logins.put("allal","yasmine");
        logins.put("lestrade","hugo");
    }

    //methodes
    private static boolean verifierLogin(LOGIN login)
    {
        boolean connexion=false;
        for (Map.Entry mapentry : logins.entrySet()) 
        {
            if(login.username.equals(mapentry.getKey()) && login.motDePasse.equals(mapentry.getValue()))
            {
                connexion=true;
            }
        }
        return connexion;
    }
    public static LOGIN SetLogin()
    {
        String id;
        String mdp;
        System.out.println("Entrer votre id: ");
        id= Clavier.entrerClavierString();
        System.out.println("Entrer votre mot de passe: ");
        mdp= Clavier.entrerClavierString();
        LOGIN login = new LOGIN(id,mdp);
        return login;
    }
    public static boolean connexion()
    {
        LOGIN login =LOGIN.SetLogin();
        return verifierLogin(login);
    }
    public String getUsername()
    {
        return username;
    }
    public String getmotDePasse()
    {
        return motDePasse;
    }

}