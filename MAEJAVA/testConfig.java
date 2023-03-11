public class testConfig {
    public static void main(String[] args) {
       Config config = new Config();
       config.Lire_config();
       System.out.println(config.afficher_config());
    }
}