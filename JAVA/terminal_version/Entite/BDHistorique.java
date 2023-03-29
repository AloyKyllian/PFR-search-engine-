package Entite;

import java.beans.PropertyChangeListener;
import java.beans.PropertyChangeSupport;
import java.util.HashMap;
import java.util.Map;
import java.util.Calendar;

public class BDHistorique {
    
    private Map<Integer, TypeFichier> mapHistorique;
    private PropertyChangeSupport support = new PropertyChangeSupport(this);
    private static int numHistorique=0;

    private BDHistorique()
    {
        mapHistorique = new HashMap<>();
    }
    private static class BDHistoriqueHolder{
        private final static BDHistorique instance = new BDHistorique();
    }
    public static BDHistorique getInstance()
    {
        return BDHistoriqueHolder.instance;
    }
    public void addPropertyChangeListener(String propertyName, PropertyChangeListener listener)
    {
        support.addPropertyChangeListener(propertyName,listener);
    }
    public void enregistrerHistorique(  TypeFichier typeFichier, String recherche, String requete, String nomFichier)
    {
        
        numHistorique++;
        Calendar calendar = Calendar.getInstance();
        int heure = calendar.get(Calendar.HOUR_OF_DAY);
        int minute = calendar.get(Calendar.MINUTE);
        mapHistorique.put(numHistorique,typeFichier);
        String [] labels = new String[6];
        labels[0]=typeFichier.toString();
        labels[1]=recherche;
        labels[2]=requete;
        labels[3]=nomFichier;
        labels[4]=String.valueOf(heure);
        labels[5]=String.valueOf(minute);
        support.firePropertyChange(PropertyName.ENREGISTRER_HISTORIQUE.toString(), null, labels);
    }

    public void viderHistorique()
    {
        this.support.firePropertyChange(PropertyName.VIDER_HISTORIQUE.toString(), null, null);
        this.mapHistorique.clear();
    }
}
