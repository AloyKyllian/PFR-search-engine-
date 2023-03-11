
public class Main {
    public static void main(String[] args) {
        READ_WRITE_FICHIER.write("test.txt", "hello WORLD \nBonsoir");
        System.out.println(READ_WRITE_FICHIER.read("test.txt"));

    }
}
