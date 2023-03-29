package Boundary;

import Entite.Clavier;
import Entite.Config;
import Entite.TypeConfig;

public class BoundaryConfig {

	 private Config config = Config.getInstance();

	public BoundaryConfig() {
	}
	public void ModifierConfig(TypeConfig Type){
	        boolean modif = false;
	        Integer nb;
	        switch(Type){
	            case NB_MOTS_CLE:
	            { 
	                System.out.println("\nEntrez le nombre de mot-clé voulu [supérieur a 0] :\n");
	                nb = Clavier.entrerClavierInt();
	                if(nb <= 0)
	                {
	                    System.out.println("\nLa valeur doit etre supérieur à 0");
	                }
	                else
	                {
	                    modif = true;
	                    this.config.setNb_Mots_Cle(nb.toString());
	                }

	            }break;
	            case NB_BITS_FORT:
	            { 
	                System.out.println("\nEntrez le nombre de bits voulu [entre 0 et 8] :\n");
	                nb = Clavier.entrerClavierInt();
	                if(nb <= 0)
	                {
	                    System.out.println("\nLa valeur doit etre supérieur à 0");
	                }
	                else if (nb > 8)
	                {
	                    System.out.println("\nLa valeur doit etre inféreiur à 8");
	                }
	                else
	                {
	                    modif = true;
	                    config.setNb_Bit_Fort(nb.toString());
	                }

	            }break;
	            case INTERVALLE:
	            { 
	                System.out.println("\nEntrez l'intervalle de temps voulu [supérieur a 0] :\n");
	                nb = Clavier.entrerClavierInt();
	                if(nb <= 0)
	                {
	                    System.out.println("\nLa valeur doit etre supérieur à 0");
	                }
	                else
	                {
	                    modif = true;
	                    config.setIntervale(nb.toString());   
	                }

	            }break;
	            case SIMILARITER:
	            { 
	                System.out.println("\nEntrez le pourcentage de similariter voulu [entre 0 et 100]:\n");
	                nb = Clavier.entrerClavierInt();
	                if(nb <= 0)
	                {
	                    System.out.println("\nLa valeur doit etre supérieur à 0");
	                }
	                else if (nb > 100)
	                {
	                    System.out.println("\nLa valeur doit etre inférieur à 100");
	                }
	                else
	                {
	                    modif = true;
	                    config.setSimilariter(nb.toString());
	                }

	            }break;
	            case NB_FENETRE:
	            {
	                System.out.println("\nEntrez le nombre de fenetre voulu [supérieur a 256 et puissance de 2]:\n");
	                nb = Clavier.entrerClavierInt();
	                if(nb < 256)
	                {
	                    System.out.println("\nLa valeur doit etre supérieur à 256");
	                }
	                else if ( (nb & (nb -1)) == 0)
	                {
	                    System.out.println("\nLa valeur doit etre une puissance de 2");
	                }
	                else
	                {
	                    modif = true;
	                    config.setNb_Fenetre(nb.toString());
	                }
	            }break;
	        }
	        if(modif)
	        {
	            config.ecrire_config();
	        }
	       
	    }

}
