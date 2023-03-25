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

public class MenuUtilisateurController {

    private Stage stage;
    @FXML
    private ResourceBundle resources;

    @FXML
    private URL location;

    @FXML
    void Texte(ActionEvent event) {

    }
    @FXML
    void Image(ActionEvent event) {

    }
    @FXML
    void Audio(ActionEvent event) {

    }
    @FXML
    void Quitter(ActionEvent event) throws IOException {
        FXMLLoader fxmlLoader = new FXMLLoader(PFRApplication.class.getResource("Accueil.fxml"));
        // ConnexionController connexionController = fxmlLoader.getController();
        //connexionController.testAdmin(Admin);
        stage = (Stage) ((Node)event.getSource()).getScene().getWindow();
        Scene scene = new Scene(fxmlLoader.load(), 600, 400);
        stage.setTitle("Accueil");
        stage.setScene(scene);
        stage.show();
    }



    @FXML
    void initialize() {

    }
}
