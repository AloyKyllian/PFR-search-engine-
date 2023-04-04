package Controle;

import Entite.Affichage;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;

public class ControlLireResultat {
    
    public ArrayList<String> affichage(String type, List<String> requeteComplexe, String typeImage){
        return Affichage.affichageFinale(type, requeteComplexe, typeImage);
    }
}

