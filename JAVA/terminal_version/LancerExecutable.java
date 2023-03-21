import java.io.IOException;
import java.io.File;
import java.lang.Process;
import java.lang.ProcessBuilder;

public class LancerExecutable {

  private String pathOut = ListCheminFichier.cheminExeC;

  public void lancerOut() {
    try {
        File executable = new File(this.pathOut);
        if (!executable.canExecute()) {
            executable.setExecutable(true);
        }
        ProcessBuilder pb = new ProcessBuilder(this.pathOut);
        Process p = pb.start();

        int exitCode = p.waitFor();
        System.out.println("Le processus s'est terminé avec le code de sortie " + exitCode);
    } catch (IOException | InterruptedException e) {
      e.printStackTrace();
    }
  }
}