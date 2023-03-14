package test.java;

import java.io.IOException;

public class exect {
    private String pathOut;

    public void startOut() {

        ProcessBuilder processBuilder = new ProcessBuilder(this.pathOut);
        try {
            Process process = processBuilder.start();
            // Attendez que le processus se termine
            try {

                int exitCode = process.waitFor();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            // Affichez le code de sortie du processus
            System.out.println("Code de sortie : " + exitCode);
        } catch (IOException e) {
            e.printStackTrace();
        }

    }
    // Démarrez le processus

}
