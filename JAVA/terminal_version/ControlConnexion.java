public class ControlConnexion {
	public boolean seConnecter( String id, String mdp) {
		Login login = new Login(id,mdp);
        return login.verifierLogin();
	}
	

}
