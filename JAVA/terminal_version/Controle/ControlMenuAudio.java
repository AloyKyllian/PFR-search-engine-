package Controle;

import Entite.Affichage;
import Entite.LireResultat;
import Entite.ListCheminFichier;
import Entite.ReadWriteFichier;

import java.util.HashMap;
import java.util.Map;

public class ControlMenuAudio {
	ControlLancerExecutable controlLancerExecutable;
	ControlLireResultat controlLireResultat;

	public ControlMenuAudio(ControlLancerExecutable controlLancerExecutable,ControlLireResultat controlLireResultat) {
		this.controlLancerExecutable = controlLancerExecutable ;
		this.controlLireResultat=controlLireResultat;
	}

	public Map<String, Integer> comparaisonAudio(String cheminAudioTXT, String cheminFichierRecherche) {
		Map<String, Integer> resultatFinale= new HashMap<>();
		Affichage.setRequete(cheminFichierRecherche);
		return resultatFinale=controlLireResultat.affichage("audio",null,null);
	}
}
