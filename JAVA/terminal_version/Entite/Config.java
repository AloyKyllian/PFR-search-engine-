package Entite;

public class Config {
	
    //attributs
    private  String Nb_Mots_Cle;
    private String Similariter;
    private String Nb_Bit_Fort;
    private String Nb_Fenetre;
    private String Intervale;

    //Constructeur
    public Config()
    {
       this.lire_config();
    }

    //Holder
    private static class ConfigHolder {
        private final static Config instance = new Config();
    }

    //Methodes
    public static Config getInstance() 
    { 
        return ConfigHolder.instance;
    } 
    public String toString()
    {
        String texte="";
        texte= "[1] Nombre de mots-clé :"+Nb_Mots_Cle+"\n[2] Similarité :"+Similariter+"\n[3] Nombre de bits de poids fort :"+Nb_Bit_Fort+"\n[4] Nombre de fenetres :"+Nb_Fenetre+"\n[5] Intervale de temps :"+Intervale;
        return texte;
    }
    public void lire_config()
    {
        String chaine="";
        chaine=ReadWriteFichier.readOn(ListCheminFichier.cheminConfig);
        String[] premier = chaine.split("\n");
        String cle = premier[0].substring(24,premier[0].length());
        this.Nb_Mots_Cle=cle;
        cle = premier[1].substring(16,premier[1].length());
        this.Similariter=cle;
        cle = premier[2].substring(34,premier[2].length());
        this.Nb_Bit_Fort=cle;
        cle = premier[3].substring(24,premier[3].length());
        Nb_Fenetre=cle;
        cle = premier[4].substring(24,premier[4].length());
        this.Intervale=cle;
    }
    public void ecrire_config() 
    {
        ReadWriteFichier.writeOn(ListCheminFichier.cheminConfig,this.toString()); 
    }
    public void setNb_Mots_Cle(String nb)
    {
       this.Nb_Mots_Cle= nb;
    }
    public void setSimilariter(String nb)
    {
        this.Similariter=nb;
    }
    public void setNb_Bit_Fort(String nb)
    {
        this.Nb_Bit_Fort=nb;
    }
    public void setNb_Fenetre(String nb)
    {
        this.Nb_Fenetre=nb;
    }
    public void setIntervale(String nb)
    {
        this.Intervale=nb;
    }

    public String getNb_Mots_Cle() {return this.Nb_Mots_Cle;}
    public int getSimilariter() {return Integer.parseInt(this.Similariter);}
    public int getNb_Bit_Fort() {return Integer.parseInt(this.Nb_Bit_Fort);}
    public int getNb_Fenetre() {return Integer.parseInt(this.Nb_Fenetre);}
    public int getIntervale(){return Integer.parseInt(this.Intervale);}

}
