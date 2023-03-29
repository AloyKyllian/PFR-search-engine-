package Entite;

import java.util.Scanner;

public class Clavier {
    private static Scanner scanner = new Scanner(System.in);

    public static int entrerClavierInt() {
        return scanner.nextInt();
    }

    public static String entrerClavierString() {
        return scanner.next();
    }

    public static String entrerClavierLine() {
        return scanner.nextLine();
    }

    public static char entrerClavierChar() {
        return scanner.next().charAt(0);
    }

}
