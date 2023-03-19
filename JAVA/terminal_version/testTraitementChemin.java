import java.io.File;
public class testTraitementChemin {

    public static void main(String[] args) {
        System.out.println("Bonjour, monde !");
        String nouveauchemin="";
        nouveauchemin=traitementChemin.extension(TypeFichier.TEXTE, "../hello/test.bmp");
        System.out.println("chemin donner a recup chemin : ../hello/test.bmp \n chemin qu'on doit avoir : ../hello/test.txt\n chemin qu'on a "+nouveauchemin);
        nouveauchemin=traitementChemin.extension(TypeFichier.IMAGE, "/test.txt");
        System.out.println("chemin donner a recup chemin : test.txt \n chemin qu'on doit avoir : test.bmp\n chemin qu'on a "+nouveauchemin);
        nouveauchemin=traitementChemin.extension(TypeFichier.IMAGE, "../test.txt");
        System.out.println("chemin donner a recup chemin : test.txt \n chemin qu'on doit avoir : test.jpg\n chemin qu'on a "+nouveauchemin);
        nouveauchemin=traitementChemin.extension(TypeFichier.TEXTE, "test.xml");
        System.out.println("chemin donner a recup chemin : test.xml \n chemin qu'on doit avoir : test.txt\n chemin qu'on a "+nouveauchemin);
        boolean test = traitementChemin.fichierExist("../DATA_FIL_ROUGE_DEV/IMG_et_AUDIO/TEST_SON/corpus_fi.wav");
        System.out.println("fichier exist\n on doit avoir un true : resultat :"+ test);
        test = traitementChemin.fichierExist("../MoteurC/DATA_FIL_ROUGE_DEV/IMG_et_AUDIO/TEST_SON/lol.wav");
        System.out.println("fichier exist\n on doit avoir un false : resultat :"+ test);
        
        test= traitementChemin.verifExtension("../MoteurC/DATA_FIL_ROUGE_DEV/IMG_et_AUDIO/TEST_SON/lol.wav", "wav");
        System.out.println("verif\n on doit avoir un true : resultat :"+ test);
        test = traitementChemin.verif("/MoteurC/DATA_FIL_ROUGE_DEV/IMG_et_AUDIO/TEST_SON/lol.wav", "txt");
        System.out.println("verif\n on doit avoir un false : resultat :"+ test);
    }
}
