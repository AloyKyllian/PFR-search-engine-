package Boundary;

import Controle.ControlConnexion;
import Entite.Clavier;

public class BoundaryConnexion {
	ControlConnexion controlConnexion;

	public BoundaryConnexion(ControlConnexion controlConnexion) {
		this.controlConnexion=controlConnexion;
	}

	public boolean seConnecter() {
		String login,mdp;
		
		 System.out.println("\nVeuillez entrer votre login");
		login= Clavier.entrerClavierString();

		System.out.println("\nVeuillez entrer votre mot de passe");
		mdp= Clavier.entrerClavierString();
		
		boolean  result = controlConnexion.seConnecter( login, mdp);
        return result;
	}

}
