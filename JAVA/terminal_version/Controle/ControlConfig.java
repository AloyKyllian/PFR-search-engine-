package Controle;

import Entite.*;

public class ControlConfig {

    private Config config = Config.getInstance();

    public String getNb_Mots_Cle()
    {
        return config.getNb_Mots_Cle();
    }
    public int getSimilariter()
    {
        return config.getSimilariter();
    }
    public int getNb_Bit_Fort()
    {
        return config.getNb_Bit_Fort();
    }
    public int getNb_Fenetre()
    {
        return config.getNb_Fenetre();
    }
    public int getIntervale()
    {
        return config.getIntervale();
    }


    public void ModifierConfig( String motcle, int bits, int intervalle, int similarite, int nbFenetre){
        this.config.setNb_Mots_Cle(motcle);
        this.config.setIntervale(String.valueOf(intervalle));
        this.config.setNb_Bit_Fort(String.valueOf(bits));
        this.config.setSimilariter(String.valueOf(similarite));
        this.config.setNb_Fenetre(String.valueOf(nbFenetre));
        this.config.ecrire_config();
        }
    public void lire_config()
    {
        config.lire_config();
    }

}
