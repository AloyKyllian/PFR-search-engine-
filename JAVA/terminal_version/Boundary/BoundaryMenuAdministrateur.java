package Boundary;

import Controle.ControlLancerExecutable;
import Entite.Clavier;
import Entite.Etat;
import Entite.ListCheminFichier;
import Entite.ReadWriteFichier;

public class BoundaryMenuAdministrateur{

    ControlLancerExecutable controlLancerExecutable = new ControlLancerExecutable();


    public Etat menuAdministrateur()
    {
    	Etat etat_courant = Etat.Menu_Admin;
        System.out.println("\n__________________________Menu Administrateur__________________________\n");
        System.out.println("\nVeuillez faire votre choix  : \n");
        System.out.println("\n[1] Indexation\n[2] Configuration\n[3] Visualisation des recueils des descripteurs\n[R] Retour \"Mode Utilisateur\"\n");

        char choix = Clavier.entrerClavierChar();

        switch (choix) {
            case '1' -> {
                ReadWriteFichier.writeOn(ListCheminFichier.cheminPontJC, "indexationGeneraleFerme()");
                controlLancerExecutable.lancerOut();
                String stringLue = ReadWriteFichier.read(ListCheminFichier.cheminPontCJ);
                System.out.println(stringLue);
            }
            case '2' -> {
                etat_courant = Etat.Menu_Configuration;
            }
            case '3' -> {
                etat_courant = Etat.Menu_Visualisation;
            }
            case 'R' -> {
                etat_courant = Etat.Menu_Utilisateur;
            }
            default -> {
                BoundaryErreur.afficherErreur(11);
            }
        }
        return etat_courant;
    }
}
