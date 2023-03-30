package com.example.pfr;

import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.application.Application;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;
import javafx.util.Duration;

import java.io.IOException;

public class ErreurConnexionAdminController{
private Stage stage;

    @FXML
    private Label countdownLabel;
    private Timeline timeline;
    private int timeSeconds = 10; // temps initial en secondes

    public void initialize() {

    }

    @FXML
    private void handleMouseMoved(MouseEvent event) throws IOException {
        if (timeline == null) {
            // Démarrer le compte à rebours uniquement lorsque la souris se déplace pour la première fois
            timeline = new Timeline();
            timeline.setCycleCount(Timeline.INDEFINITE);
            timeline.getKeyFrames().add(new KeyFrame(Duration.seconds(1), e -> {
                timeSeconds--;
                countdownLabel.setText("Temps restant : " + timeSeconds + " secondes");
                if (timeSeconds <= 0) {
                    timeline.stop();
                    stage = (Stage) ((Node)event.getSource()).getScene().getWindow();
                    FXMLLoader fxmlLoader = new FXMLLoader(PFRApplication.class.getResource("ConnexionAdministrateur.fxml"));
                    Scene scene = null;
                    try {
                        scene = new Scene(fxmlLoader.load(), 600, 400);
                    } catch (IOException ex) {
                        throw new RuntimeException(ex);
                    }
                    stage.setTitle("ConnexionAdministrateur");
                    stage.setScene(scene);
                    stage.show();
                }
            }));
            timeline.play();
        } else {
            // Continuer le compte à rebours s'il est déjà démarré
            timeline.play();
        }

    }

}