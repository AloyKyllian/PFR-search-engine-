import java.lang.*;
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
        super();
    }
    public Config( String Nb_Mots_Cle,String Similariter,String Nb_Bit_Fort,String Nb_Fenetre,String Intervale)
    {
        this.Nb_Mots_Cle= Nb_Mots_Cle;
        this.Similariter =Similariter ;
        this.Nb_Bit_Fort= Nb_Bit_Fort;
        this.Nb_Fenetre= Nb_Fenetre;
        this.Intervale= Intervale;
    }

    //methodes
    public String afficher_config()
    {
        String texte="";
        texte= "[1] Nombre de mots-clé : "+Nb_Mots_Cle+"\n[2] Similarité : "+Similariter+"\n[3] Nombre de bits de poids fort : "+Nb_Bit_Fort+"\n[4] Nombre de fenetres : "+Nb_Fenetre+"\n[5] Intervale de temps : "+Intervale;
        return texte;
    }
    public void Ecrire_CONFIG() 
    {
        String chaine=this.afficher_config();
        READ_WRITE_FICHIER.writeOn("../MoteurC/Gestion-Config/Config.txt",chaine); 
    }

    public void Lire_config()
    {
        String chaine="";
        chaine=READ_WRITE_FICHIER.read("../MoteurC/Gestion-Config/Config.txt");
        String[] premier = chaine.split("\n");
        String cle = premier[0].substring(25,premier[0].length());
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
    public void Lire_motCle()
    {
        String chaine="";
        System.out.println("../MoteurC/Gestion-Config/Config.txt");
        String[] premier = chaine.split("\n");
        String cle = premier[0].substring(25,premier[0].length());
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
    
    public String get_Nb_Mots_Cle()
    {
        return this.Nb_Mots_Cle;
    }

    public String getSimilariter()
    {
        return this.Similariter;

    }
    public String getNb_Bit_Fort()
    {
        return this.Nb_Bit_Fort;

    }
    public String getNb_Fenetre()
    {
        return    this.Nb_Fenetre;
    }
    public String getIntervale()
    {
        return  this.Intervale;
    }
    public void setNb_Mots_Cle()
    {
       this.Nb_Mots_Cle= Clavier.entrerClavierString();
    }
    public void setSimilariter()
    {
            this.Similariter= Clavier.entrerClavierString();
    }
    public void setNb_Bit_Fort()
    {
            this.Nb_Bit_Fort= Clavier.entrerClavierString();
    }
    public void setNb_Fenetre()
    {
            this.Nb_Fenetre= Clavier.entrerClavierString();
    }
    public void setIntervale()
    {
            this.Intervale= Clavier.entrerClavierString();
    }
}