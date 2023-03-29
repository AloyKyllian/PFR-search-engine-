package Controle;

import Entite.LireResultat;
import Entite.ListCheminFichier;
import Entite.ReadWriteFichier;

public class ControlMenuAudio {
	ControlLancerExecutable controlLancerExecutable;

	public ControlMenuAudio(ControlLancerExecutable controlLancerExecutable) {
		this.controlLancerExecutable = controlLancerExecutable ;
	}

	public void comparaisonAudio(String cheminAudioTXT, String cheminFichierRecherche) {
		ReadWriteFichier.writeOn(ListCheminFichier.cheminPontJC,
				"comparaisonAudio(" + cheminAudioTXT + ")");
		controlLancerExecutable.lancerOut();
		LireResultat.setRequete(cheminFichierRecherche);
	}
}
