package Controle;

import Entite.LireResultat;
import Entite.ListCheminFichier;
import Entite.ReadWriteFichier;

public class ControleMenuImage {
    ControlLancerExecutable controlLancerExecutable;

    public ControleMenuImage(ControlLancerExecutable controlLancerExecutable) {
        this.controlLancerExecutable = controlLancerExecutable ;
    }

    public void comparaisonImage(String cheminAudioTXT, String cheminFichierRecherche) {
        ReadWriteFichier.writeOn(ListCheminFichier.cheminPontJC,
                "comparaisonImage(" + cheminAudioTXT + ")");
        controlLancerExecutable.lancerOut();
        LireResultat.setRequete(cheminFichierRecherche);
    }
}
