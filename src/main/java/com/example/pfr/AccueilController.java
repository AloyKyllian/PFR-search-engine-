package com.example.pfr;

import java.io.IOException;
import java.net.URL;
import java.util.ResourceBundle;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Scene;
import javafx.scene.control.TextArea;
import javafx.scene.image.ImageView;
import javafx.stage.Stage;

public class AccueilController {

    private Stage stage;
    @FXML
    private TextArea AideTexte;
    private boolean aide = false;
    boolean Admin;
    @FXML
    private ResourceBundle resources;
    @FXML
    private ImageView image;

    @FXML
    private URL location;

    @FXML
    void Texte(ActionEvent event) throws IOException {
        FXMLLoader fxmlLoader = new FXMLLoader(PFRApplication.class.getResource("MenuTexte.fxml"));
        stage = (Stage) ((Node)event.getSource()).getScene().getWindow();
        Scene scene = new Scene(fxmlLoader.load(), 1000, 750);
        stage.setTitle("MenuTexte");
        stage.setScene(scene);
        stage.show();
    }
    @FXML
    void Image(ActionEvent event) throws IOException {
        FXMLLoader fxmlLoader = new FXMLLoader(PFRApplication.class.getResource("MenuImage.fxml"));
        stage = (Stage) ((Node)event.getSource()).getScene().getWindow();
        Scene scene = new Scene(fxmlLoader.load(), 984, 750);
        stage.setTitle("MenuImage");
        stage.setScene(scene);
        stage.show();
    }
    @FXML
    void Audio(ActionEvent event) throws IOException {
        FXMLLoader fxmlLoader = new FXMLLoader(PFRApplication.class.getResource("MenuAudio.fxml"));
        stage = (Stage) ((Node)event.getSource()).getScene().getWindow();
        Scene scene = new Scene(fxmlLoader.load(), 1000, 750);
        stage.setTitle("MenuAudio");
        stage.setScene(scene);
        stage.show();
    }
    @FXML
    void Admin(ActionEvent event)  throws IOException {
        Admin=true;
        FXMLLoader fxmlLoader = new FXMLLoader(PFRApplication.class.getResource("ConnexionAdministrateur.fxml"));
        stage = (Stage) ((Node)event.getSource()).getScene().getWindow();
        Scene scene = new Scene(fxmlLoader.load(), 1000, 750);
        stage.setTitle("ConnexionAdministrateur");
        stage.setScene(scene);
        stage.show();
    }
    @FXML
    void historique(ActionEvent event) throws IOException {
        FXMLLoader fxmlLoader = new FXMLLoader(PFRApplication.class.getResource("Historique.fxml"));
        stage = (Stage) ((Node)event.getSource()).getScene().getWindow();
        Scene scene = new Scene(fxmlLoader.load(), 1000, 750);
        stage.setTitle("Historique");
        stage.setScene(scene);
        stage.show();
    }

    @FXML
    void Quitter(ActionEvent event) {
        System.exit(1);
    }

    @FXML
    void initialize() {
    }
}
