package com.example.pfr;

import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.input.MouseEvent;
import javafx.scene.text.Text;
import javafx.stage.Stage;
import javafx.util.Duration;

import java.io.IOException;
import java.net.URL;
import java.util.ResourceBundle;

public class ErreurConnexionAdminController {

    public Stage stage;
    @FXML
    public Button Boutton;
    @FXML
    public ResourceBundle resources;

    @FXML
    public URL location;

    @FXML
    public Text decompte;

    @FXML
    private Label countdownLabel;
        private Timeline timeline;
        private int timeSeconds = 10; // temps initial en secondes

        public void initialize() {
            assert decompte != null : "fx:id=\"decompte\" was not injected: check your FXML file 'Erreur_Connexion.fxml'.";
            // Créer une ligne de temps pour mettre à jour le compte à rebours
            timeline = new Timeline();
            timeline.setCycleCount(Timeline.INDEFINITE);
            timeline.getKeyFrames().add(new KeyFrame(Duration.seconds(1), event -> {
                timeSeconds--;
                // Mettre à jour l'étiquette de décompte à rebours
                countdownLabel.setText("Temps restant : " + timeSeconds + " secondes");
                // Arrêter la ligne de temps une fois que le temps est écoulé
                if (timeSeconds <= 0) {
                    timeline.stop();
                    countdownLabel.setText("Temps écoulé !");
                }
            }));
        }

        @FXML
        private void handleMouseMoved(MouseEvent event) {
            if (timeline == null) {
                // Démarrer le compte à rebours uniquement lorsque la souris se déplace pour la première fois
                timeline = new Timeline();
                timeline.setCycleCount(Timeline.INDEFINITE);
                timeline.getKeyFrames().add(new KeyFrame(Duration.seconds(1), e -> {
                    timeSeconds--;
                    countdownLabel.setText("Temps restant : " + timeSeconds + " secondes");
                    if (timeSeconds <= 0) {
                        timeline.stop();
                        countdownLabel.setText("Temps écoulé !");
                    }
                }));
                timeline.play();
            } else {
                // Continuer le compte à rebours s'il est déjà démarré
                timeline.play();
            }
        }

    void Changement(MouseEvent event) throws InterruptedException, IOException {
        Thread.sleep(10000);

        FXMLLoader fxmlLoader = new FXMLLoader(PFRApplication.class.getResource("ConnexionAdministrateur.fxml"));
        stage = (Stage) ((Node)event.getSource()).getScene().getWindow();
        Scene scene = new Scene(fxmlLoader.load(), 1000, 750);
        stage.setTitle("ConnexionUtilisateur");
        stage.setScene(scene);
        stage.show();
    }

}
