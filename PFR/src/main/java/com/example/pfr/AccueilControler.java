package com.example.pfr;

import java.io.IOException;
import java.net.URL;
import java.util.ResourceBundle;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class AccueilControler {

    private Stage stage;
    boolean Admin;
    @FXML
    private ResourceBundle resources;

    @FXML
    private URL location;

    @FXML
    void Connexion(ActionEvent event) throws IOException {

        FXMLLoader fxmlLoader = new FXMLLoader(PFRApplication.class.getResource("ConnexionUtilisateur.fxml"));
       // ConnexionController connexionController = fxmlLoader.getController();
        //connexionController.testAdmin(Admin);
        stage = (Stage) ((Node)event.getSource()).getScene().getWindow();
        Scene scene = new Scene(fxmlLoader.load(), 600, 400);
        stage.setTitle("ConnexionUtilisateur");
        stage.setScene(scene);
        stage.show();
    }
    @FXML
    void Admin(ActionEvent event)  throws IOException {
        Admin=true;
        FXMLLoader fxmlLoader = new FXMLLoader(PFRApplication.class.getResource("ConnexionAdministrateur.fxml"));
        //ConnexionController connexionController = fxmlLoader.getController();
        //connexionController.testAdmin(Admin);
        stage = (Stage) ((Node)event.getSource()).getScene().getWindow();
        Scene scene = new Scene(fxmlLoader.load(), 600, 400);
        stage.setTitle("ConnexionAdministrateur");
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
