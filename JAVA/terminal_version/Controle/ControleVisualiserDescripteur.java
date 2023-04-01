package Controle;

import Entite.ListCheminFichier;
import Entite.ReadWriteFichier;

public class ControleVisualiserDescripteur {

    private ControlLancerExecutable controlLancerExecutable = new ControlLancerExecutable();

    public String controleSystemTexte()
    {
        String stringLue;
        ReadWriteFichier.writeOn(ListCheminFichier.cheminPontJC, "systemTexte()");
        this.controlLancerExecutable.lancerOut();
        stringLue = ReadWriteFichier.read(ListCheminFichier.cheminPontCJ);
        return stringLue;
    }

    public String controleSystemImage()
    {
        String stringLue;
        ReadWriteFichier.writeOn(ListCheminFichier.cheminPontJC, "systemImage()");
        this.controlLancerExecutable.lancerOut();
        stringLue = ReadWriteFichier.read(ListCheminFichier.cheminPontCJ);
        return stringLue;
    }

    public String controleSystemAudio()
    {
        String stringLue;
        ReadWriteFichier.writeOn(ListCheminFichier.cheminPontJC, "systemAudio()");
        this.controlLancerExecutable.lancerOut();
        stringLue = ReadWriteFichier.read(ListCheminFichier.cheminPontCJ);
        return stringLue;
    }


}
