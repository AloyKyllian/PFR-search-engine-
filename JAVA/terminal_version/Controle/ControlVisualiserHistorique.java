package Controle;

import Entite.BDHistorique;

import java.beans.PropertyChangeListener;

public class ControlVisualiserHistorique {
    
    BDHistorique bdHistorique = BDHistorique.getInstance();

    public void setListener(String propertyName, PropertyChangeListener listener)
    {
        bdHistorique.addPropertyChangeListener(propertyName,listener);
    }
}
