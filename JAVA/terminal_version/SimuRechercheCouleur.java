import java.util.List;
import java.util.ArrayList;


public class SimuRechercheCouleur
{
    //attributs
    private List<String> listImgRouge ;
    private List<String> listImgVert ;
    private List<String> listImgBleu ;
    private LancerExecutable lancerExe = new LancerExecutable();

    public SimuRechercheCouleur()
    {
        listImgRouge = new ArrayList<>();
        listImgRouge.add("16.jpg");
        listImgRouge.add("17.jpg");
        listImgRouge.add("43.jpg");
        listImgRouge.add("36.jpg");
        listImgRouge.add("38.jpg");
        listImgRouge.add("42.jpg");
        listImgVert = new ArrayList<>();
        listImgVert.add("32.jpg");
        listImgVert.add("35.jpg");
        listImgVert.add("34.jpg");
        listImgVert.add("39.jpg");
        listImgVert.add("41.jpg");
        listImgVert.add("37.jpg");
        listImgBleu = new ArrayList<>();
        listImgBleu.add("07.jpg");
        listImgBleu.add("20.jpg");
        listImgBleu.add("13.jpg");
        listImgBleu.add("44.jpg");
        listImgBleu.add("45.jpg");
        listImgBleu.add("22.jpg");
    }

    //methode
    public void recherche(String couleur,int Pourcentage )
    {
        if(couleur.equals("rouge"))
        {
            System.out.println("Liste des fichiers contenant du rouge à plus de "+ Pourcentage+" %");
            int cpt =0;
            for(String chaine : this.listImgRouge ){
                cpt++;
                System.out.println("["+cpt+"] " + chaine );
            }
            READ_WRITE_FICHIER.ouvertureFichier("../../DATA_FIL_ROUGE_DEV/IMG_et_AUDIO/TEST_RGB/16.jpg");
            System.out.println("\nPenser a fermé la fenetre apres l'avoir consulter pour poursuivre votre activité\n");
            
        }
        else if(couleur.equals("vert"))
        {
             System.out.println("Liste des fichiers contenant du vert à plus de "+ Pourcentage+" %");
            int cpt =0;
            for(String chaine : this.listImgVert ){
                cpt++;
                System.out.println("["+cpt+"] " + chaine );
            }
            READ_WRITE_FICHIER.ouvertureFichier("../../DATA_FIL_ROUGE_DEV/IMG_et_AUDIO/TEST_RGB/32.jpg");
            System.out.println("\nPenser a fermé la fenetre apres l'avoir consulter pour poursuivre votre activité\n");
        }
        else if(couleur.equals("bleu"))
        {
             System.out.println("Liste des fichier contenant du bleu à plus de "+ Pourcentage+" %");
            int cpt =0;
            for(String chaine : this.listImgBleu ){
                cpt++;
                System.out.println("["+cpt+"] " + chaine );
            }
            READ_WRITE_FICHIER.ouvertureFichier("../../DATA_FIL_ROUGE_DEV/IMG_et_AUDIO/TEST_RGB/07.jpg");
            System.out.println("\nPenser a fermé la fenetre apres l'avoir consulter pour poursuivre votre activité\n");
        }

    }
}
