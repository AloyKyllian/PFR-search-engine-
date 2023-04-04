package Controle;

import Entite.Affichage;
import Entite.LireResultat;
import Entite.ListCheminFichier;
import Entite.ReadWriteFichier;

import java.io.File;
import java.lang.reflect.Array;
import java.util.ArrayList;

public class ControlMenuAudio {
	ControlLancerExecutable controlLancerExecutable;
	ControlLireResultat controlLireResultat;

	public ControlMenuAudio(ControlLancerExecutable controlLancerExecutable,ControlLireResultat controlLireResultat) {
		this.controlLancerExecutable = controlLancerExecutable ;
		this.controlLireResultat=controlLireResultat;
	}

	public ArrayList<String>  comparaisonAudio(String cheminAudioTXT, String cheminFichierRecherche) {
		ArrayList<String> resultatFinale= new ArrayList<>();
		Affichage.setRequete(cheminFichierRecherche);
		return resultatFinale=controlLireResultat.affichage("audio",null,null);
	}
}
