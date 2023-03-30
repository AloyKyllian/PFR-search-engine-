package Controle;

import Entite.LireResultat;
import Entite.ListCheminFichier;
import Entite.ReadWriteFichier;

public class ControleMenuImage {
    ControlLancerExecutable controlLancerExecutable;



    public ControleMenuImage(ControlLancerExecutable controlLancerExecutable) {
        this.controlLancerExecutable = controlLancerExecutable ;
    }

    public  Map<String, Integer> comparaisonImage(String cheminImageTXT, String cheminFichierRecherche) {
        Map<String, Integer> resultatFinale= new HashMap<>();
        String typeImage;
        if(cheminFichierRecherche.contains("bmp")){
            typeImage="bmp"

        }
        else if(cheminFichierRecherche.contains("jpg")){
            typeImage="jpg"
        }
        ReadWriteFichier.writeOn(ListCheminFichier.cheminPontJC,
                "comparaisonImage(" + cheminImageTXT + ")");
        controlLancerExecutable.lancerOut();
        Affichage.setRequete(cheminFichierRecherche);
        return resultatFinale=Affichage.affichageFinale("image",null,typeImage);
    }

    public  Map<String, Integer> rechercheCouleur(String couleur) {
        Map<String, Integer> resultatFinale= new HashMap<>();

        return resultatFinale=Affichage.affichageFinale("image",null,typeImage);
    }
}
