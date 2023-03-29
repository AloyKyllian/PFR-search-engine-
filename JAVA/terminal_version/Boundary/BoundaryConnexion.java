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
		

		
		boolean  result = controlConnexion.seConnecter( login, mdp);
        return result;
	}

}
