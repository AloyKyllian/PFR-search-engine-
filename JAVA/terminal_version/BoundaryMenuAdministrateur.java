public class BoundaryMenuAdministrateur{

    ControlLancerExecutable controlLancerExecutable = new ControlLancerExecutable();


    public Etat menuAdministrateur()
    {
    	Etat etat_courant = Etat.Menu_Admin;
        System.out.println("\n__________________________Menu Administrateur__________________________\n");
        System.out.println("\nVeuillez faire votre choix  : \n");
        System.out.println("\n[1] Indexation\n[2] Configuration\n[3] Visualisation des recueils des descripteurs\n[R] Retour \"Mode Utilisateur\"\n");

        char choix = Clavier.entrerClavierChar();

        switch (choix) 
        {
            case '1': 
            {
                ReadWriteFichier.writeOn(ListCheminFichier.cheminPontJC, "indexationGeneraleFerme()");
                controlLancerExecutable.lancerOut();
                String stringLue = ReadWriteFichier.read(ListCheminFichier.cheminPontCJ);
                System.out.println(stringLue);
            }break;
            case '2': 
            {
            	etat_courant = Etat.Menu_Configuration;
            }break;
            case '3': 
            {
            	etat_courant = Etat.Menu_Visualisation;
            }break;
            case 'R': 
            {
            	etat_courant = Etat.Menu_Utilisateur;
            }break;
            default: 
            {
                BoundaryErreur.afficherErreur(11);
                etat_courant = Etat.Menu_Admin;
            }break;
        }
        return etat_courant;
    }
}
