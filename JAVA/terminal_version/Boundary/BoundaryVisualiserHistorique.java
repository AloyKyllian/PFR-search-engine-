package Boundary;

import Controle.ControlVisualiserHistorique;
import Entite.ListCheminFichier;
import Entite.PropertyName;
import Entite.ReadWriteFichier;

import java.beans.PropertyChangeEvent;
import java.beans.PropertyChangeListener;

public class BoundaryVisualiserHistorique implements PropertyChangeListener{
    
    ControlVisualiserHistorique control;

    public BoundaryVisualiserHistorique(ControlVisualiserHistorique control)
    {
        this.control=control;
        this.control.setListener(PropertyName.ENREGISTRER_HISTORIQUE.toString(), this);
        this.control.setListener(PropertyName.VIDER_HISTORIQUE.toString(), this);
    }

    public void propertyChange(PropertyChangeEvent evt)
    { 
        String propertyName = evt.getPropertyName();
        PropertyName choix= PropertyName.valueOf(propertyName);
       
        switch(choix)
        {
            case ENREGISTRER_HISTORIQUE :
            {
                Object objet = evt.getNewValue();
                String [] labels = (String []) objet;
                String typeFichier = labels[0];
                String recherche= labels[1];
                String requete= labels[2];
                String nomFichier= labels[3];
                String heure = labels[4];
                String minute= labels[5];
                //System.out.println(heure+":"+minute+" "+typeFichier+" "+recherche+" "+requete+" "+nomFichier);
                ReadWriteFichier.write(ListCheminFichier.cheminHistorique,
                heure+":"+minute+" "+typeFichier+" "+recherche+" "+requete+" "+nomFichier+"\n");
            }break;
            case VIDER_HISTORIQUE:
			{
				ReadWriteFichier.effacer(ListCheminFichier.cheminHistorique);				
			}break;
        }
    }
}
