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

public class MenuAdministrateurController {

    private Stage stage;
    @FXML
    private ResourceBundle resources;

    @FXML
    private URL location;

    @FXML
    void Configuration(ActionEvent event) throws IOException{
        FXMLLoader fxmlLoader = new FXMLLoader(PFRApplication.class.getResource("Configuration.fxml"));
        // ConnexionController connexionController = fxmlLoader.getController();
        //connexionController.testAdmin(Admin);
        stage = (Stage) ((Node)event.getSource()).getScene().getWindow();
        Scene scene = new Scene(fxmlLoader.load(), 750, 460);
        stage.setTitle("Configuration");
        stage.setScene(scene);
        stage.show();
    }

    @FXML
    void Descripteurs(ActionEvent event) {

    }

    @FXML
    void Indexation(ActionEvent event) {

    }

    @FXML
    void Mode_Utilisateur(ActionEvent event) throws IOException {
        FXMLLoader fxmlLoader = new FXMLLoader(PFRApplication.class.getResource("MenuUtilisateur.fxml"));
        // ConnexionController connexionController = fxmlLoader.getController();
        //connexionController.testAdmin(Admin);
        stage = (Stage) ((Node)event.getSource()).getScene().getWindow();
        Scene scene = new Scene(fxmlLoader.load(), 600, 400);
        stage.setTitle("MenuUtilisateur");
        stage.setScene(scene);
        stage.show();
    }

    @FXML
    void initialize() {

    }
}
