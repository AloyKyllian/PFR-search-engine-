package Controle;

import Entite.*;

import java.io.File;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class ControlMenuImage {
    ControlLancerExecutable controlLancerExecutable;
    ControlLireResultat controlLireResultat;
    private List<String> listImgRouge;
    private List<String> listImgVert;
    private List<String> listImgBleu;
    BDHistorique bdHistorique = BDHistorique.getInstance();

    public ControlMenuImage(ControlLancerExecutable controlLancerExecutable, ControlLireResultat controlLireResultat) {
        this.controlLancerExecutable = controlLancerExecutable ;
        this.controlLireResultat=controlLireResultat;
        listImgRouge = new ArrayList<>();
        listImgRouge.add("16.jpg");
        listImgRouge.add("17.jpg");
        listImgRouge.add("43.jpg");
        listImgRouge.add("36.jpg");
        listImgRouge.add("38.jpg");
        listImgRouge.add("42.jpg");
        listImgVert = new ArrayList<>();
        listImgVert.add("32.jpg");
        listImgVert.add("35.jpg");
        listImgVert.add("34.jpg");
        listImgVert.add("39.jpg");
        listImgVert.add("41.jpg");
        listImgVert.add("37.jpg");
        listImgBleu = new ArrayList<>();
        listImgBleu.add("07.jpg");
        listImgBleu.add("20.jpg");
        listImgBleu.add("13.jpg");
        listImgBleu.add("44.jpg");
        listImgBleu.add("45.jpg");
        listImgBleu.add("22.jpg");
    }

    public ArrayList<String> comparaisonImage(String cheminFichierRecherche) {
        ArrayList<String> resultatFinale= new ArrayList<>();
        String typeImage = null;
        if(cheminFichierRecherche.contains("bmp")){
            typeImage="bmp";
            cheminFichierRecherche.replace("bmp","txt");
        }
        else if(cheminFichierRecherche.contains("jpg")){
            typeImage="jpg";
            cheminFichierRecherche.replace("jpg","txt");
        }
        ReadWriteFichier.writeOn(ListCheminFichier.cheminPontJC, "comparaisonImage(" + cheminFichierRecherche + ")");
        controlLancerExecutable.lancerOut();
        Affichage.setRequete(cheminFichierRecherche);
        bdHistorique.enregistrerHistorique(  TypeFichier.AUDIO, "Comparaison", "", cheminFichierRecherche);
        resultatFinale=controlLireResultat.affichage("image",null,typeImage);
        //System.out.println("dans control Image : "+resultatFinale.get(0));
        return resultatFinale;
    }

    public  List<String> rechercheCouleur(String couleur) {
        bdHistorique.enregistrerHistorique(  TypeFichier.IMAGE, "Recherche", "Couleur", couleur);
        if(couleur.equals("rouge")){
            return listImgRouge;
        }
        else if(couleur.equals("vert")){
            return listImgVert;
        }
        else if(couleur.equals("bleu")){
            return listImgBleu;
        }
        return null;
    }
}
