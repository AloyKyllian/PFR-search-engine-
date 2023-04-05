package Controle;

import Entite.Affichage;

import java.util.ArrayList;
import java.util.List;

public class ControlLireResultat {
    
    public ArrayList<String> affichage(String type, List<String> requeteComplexe, String typeImage){
        return Affichage.affichageFinale(type, requeteComplexe, typeImage);
    }
}

