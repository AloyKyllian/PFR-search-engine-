package Controle;

import Entite.ListCheminFichier;
import Entite.ReadWriteFichier;

public class ControlIndexation {
    ControlLancerExecutable controlLancerExecutable = new ControlLancerExecutable();
    String stringLue;
    public String indexation_fermer() {
        ReadWriteFichier.writeOn(ListCheminFichier.cheminPontJC, "indexationGeneraleFerme()");
        controlLancerExecutable.lancerOut();
        stringLue = ReadWriteFichier.read(ListCheminFichier.cheminPontCJ);
        return stringLue;
    }

    public String indexation() {
        ReadWriteFichier.writeOn(ListCheminFichier.cheminPontJC, "indexation()");
        controlLancerExecutable.lancerOut();
        stringLue = ReadWriteFichier.read(ListCheminFichier.cheminPontCJ);
        return stringLue;
    }

}
