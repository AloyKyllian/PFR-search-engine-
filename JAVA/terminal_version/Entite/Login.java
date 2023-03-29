package Entite;

import java.util.Map;
import java.util.HashMap;

public class Login{

    //attributs
    private String username;
    private String motDePasse;
    // cle username , valeur mot de passe 
    static Map<String, String> logins;

    //constructeur
    public Login(String username, String motDePasse)
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
    public boolean verifierLogin()
    {
        boolean connexion=false;
        for (Map.Entry mapentry : logins.entrySet()) 
        {
            if( username.equals(mapentry.getKey()) && motDePasse.equals(mapentry.getValue()))
            {
                connexion=true;
            }
        }
        return connexion;
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
