package Controle;

import Entite.Affichage;
import Entite.BDHistorique;
import Entite.TypeFichier;

import java.util.ArrayList;

public class ControlMenuAudio {
	ControlLancerExecutable controlLancerExecutable;
	ControlLireResultat controlLireResultat;
	BDHistorique bdHistorique = BDHistorique.getInstance();

	public ControlMenuAudio(ControlLancerExecutable controlLancerExecutable,ControlLireResultat controlLireResultat) {
		this.controlLancerExecutable = controlLancerExecutable ;
		this.controlLireResultat=controlLireResultat;
	}

	public ArrayList<String>  comparaisonAudio(String cheminAudioTXT, String cheminFichierRecherche) {
		ArrayList<String> resultatFinale= new ArrayList<>();
		Affichage.setRequete(cheminFichierRecherche);
		bdHistorique.enregistrerHistorique(  TypeFichier.AUDIO, "Comparaison", "", cheminFichierRecherche);
		return resultatFinale=controlLireResultat.affichage("audio",null,null);
	}
}
