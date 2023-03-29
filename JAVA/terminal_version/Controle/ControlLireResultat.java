package Controle;

import Entite.Affichage;

import java.util.List;
import java.util.Map;

public class ControlLireResultat {
    
    public Map<String,Integer> affichage(String type, List<String> requeteComplexe, String typeImage){
        return Affichage.affichageFinale(type, requeteComplexe, typeImage);
    }
}

