package lancement;

import Boundary.*;
import Controle.ControlConnexion;
import Controle.ControlLancerExecutable;
import Controle.ControlMenuAudio;
import Controle.ControlVisualiserHistorique;
import Entite.*;

public class MAE {
	private Etat etat_courant = Etat.Menu_general;

	// variables a utiliser au cours du programme
	private Config config;
	LireResultat lireResultat;
	private int erreur = 0;
	private String stringLue;
	static String string;
	String BmpJpg;

	private ControlConnexion controlConnexion;
	private ControlLancerExecutable controlLancerExecutable;
	private ControlVisualiserHistorique controlVisualiserHistorique;
	private ControlMenuAudio controlMenuAudio;

	private BoundaryMenuGeneral boundaryMenuGeneral;
	private BoundaryMenuAdministrateur boundaryMenuAdministrateur;
	private BoundaryMenuVisualisation boundaryMenuVisualisation;
	private BoundaryMenuUtilisateur boundaryMenuUtilisateur;
	private BoundaryMenuTexte boundaryMenuTexte;
	private BoundaryMenuImage boundaryMenuImage;
	private BoundaryMenuAudio boundaryMenuAudio;
	private BoundaryMenuConfig boundaryMenuConfig;
	private BoundaryVisualiserHistorique boundaryVisualiserHistorique;
	private ThreadViderHistorique threadViderHistorique;

	public MAE() {
		this.config = new Config();
		this.config.lire_config();

		this.lireResultat = new LireResultat();
		// control
		this.controlLancerExecutable = new ControlLancerExecutable();
		this.controlConnexion = new ControlConnexion();
		this.controlVisualiserHistorique = new ControlVisualiserHistorique();
		this.controlMenuAudio = new ControlMenuAudio(controlLancerExecutable);

		// boundary
		this.boundaryMenuGeneral = new BoundaryMenuGeneral(new BoundaryConnexion(this.controlConnexion));
		this.boundaryMenuAdministrateur = new BoundaryMenuAdministrateur();
		this.boundaryMenuVisualisation = new BoundaryMenuVisualisation(this.controlLancerExecutable);
		this.boundaryMenuUtilisateur = new BoundaryMenuUtilisateur();
		this.boundaryMenuTexte = new BoundaryMenuTexte(this.controlLancerExecutable);
		this.boundaryMenuImage = new BoundaryMenuImage(this.controlLancerExecutable);
		this.boundaryMenuAudio = new BoundaryMenuAudio(this.controlMenuAudio);
		this.boundaryMenuConfig = new BoundaryMenuConfig(new BoundaryConfig());
		this.boundaryVisualiserHistorique = new BoundaryVisualiserHistorique (this.controlVisualiserHistorique);

		this.threadViderHistorique = new ThreadViderHistorique();
		this.threadViderHistorique.start();
		
	}
	public static void main(String[] args) {

		MAE mae = new MAE();
		ReadWriteFichier.writeOn(ListCheminFichier.cheminPontJC, "indexationGeneraleFerme()");
		mae.controlLancerExecutable.lancerOut();
		mae.stringLue = ReadWriteFichier.read(ListCheminFichier.cheminPontCJ);
		System.out.println(mae.stringLue);
		mae.lancerMAE();	
	}

	public void lancerMAE() {
		while (true) {
			ReadWriteFichier.writeOn(ListCheminFichier.cheminPontJC, "indexation()");
			controlLancerExecutable.lancerOut();
			this.stringLue = ReadWriteFichier.read(ListCheminFichier.cheminPontCJ);
			System.out.println(this.stringLue);
			switch (this.etat_courant) {
			case Menu_general: {
				this.etat_courant = boundaryMenuGeneral.menuGeneral();
				break;
			}

			case Menu_Admin: {
				this.etat_courant = boundaryMenuAdministrateur.menuAdministrateur();
			}
				break;

			case Menu_Configuration: {
				this.etat_courant = this.boundaryMenuConfig.menuConfig();
			}
				break;
			case Menu_Visualisation: {
				this.etat_courant = boundaryMenuVisualisation.menuVisualisation();
				break;
			}
			case Menu_Utilisateur: {
				this.etat_courant = boundaryMenuUtilisateur.menuUtilisateur();
			}
				break;
			case Menu_texte: {
				this.etat_courant = boundaryMenuTexte.menuTexte();
			}
				break;
			case Menu_image: {

				this.etat_courant = boundaryMenuImage.menuImage();
			}
				break;

			case Menu_audio: {
				this.etat_courant = boundaryMenuAudio.menuAudio();
			}
				break;
			default: {
				System.out.println("Il y a une erreur, vous allez etre redirigez vers le \"Menu General\"\n");
				this.erreur = 14;
				if (this.erreur != 0) {
					BoundaryErreur.afficherErreur(this.erreur);
				}
				this.etat_courant = Etat.Menu_general;
			}
			}
		}
	}
}
