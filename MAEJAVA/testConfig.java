public class testConfig {

    public static void main(String[] args) {
       Config config = new Config();
       config.Lire_config();
       System.out.println(config.afficher_config());
       config.setNb_Bit_Fort("6");
       config.ecrire_config();
    }
}