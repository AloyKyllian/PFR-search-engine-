package com.example.pfr;

import java.io.IOException;
import java.net.URL;
import java.util.ResourceBundle;

import Controle.ControlIndexation;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.control.TextArea;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class MenuAdministrateurController {

    ControlIndexation controleIndexation = new ControlIndexation();

    private Stage stage;

    @FXML
    private TextArea AideTexte;
    private boolean aide = false;
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
        Scene scene = new Scene(fxmlLoader.load(), 1000, 750);
        stage.setTitle("Configuration");
        stage.setScene(scene);
        stage.show();
    }

    @FXML
    void Descripteurs(ActionEvent event) throws IOException {
        FXMLLoader fxmlLoader = new FXMLLoader(PFRApplication.class.getResource("Descripteurs.fxml"));
        // ConnexionController connexionController = fxmlLoader.getController();
        //connexionController.testAdmin(Admin);
        stage = (Stage) ((Node)event.getSource()).getScene().getWindow();
        Scene scene = new Scene(fxmlLoader.load(), 1000, 750);
        stage.setTitle("descripteur");
        stage.setScene(scene);
        stage.show();
    }

    @FXML
    void Indexation(ActionEvent event) {
        controleIndexation.indexation_fermer();
    }

    @FXML
    void Mode_Utilisateur(ActionEvent event) throws IOException {
        FXMLLoader fxmlLoader = new FXMLLoader(PFRApplication.class.getResource("Accueil.fxml"));
        // ConnexionController connexionController = fxmlLoader.getController();
        //connexionController.testAdmin(Admin);
        stage = (Stage) ((Node)event.getSource()).getScene().getWindow();
        Scene scene = new Scene(fxmlLoader.load(), 1000, 750);
        stage.setTitle("Accueil");
        stage.setScene(scene);
        stage.show();
    }

    @FXML
    void Quitter(ActionEvent event) throws IOException {
        System.exit(1);
    }

    @FXML
    void aide(ActionEvent event){
        if(aide==false){
            AideTexte.setVisible(true);
            aide = true;
        }
        else if(aide==true){
            AideTexte.setVisible(false);
            aide = false;
        }

    }

    @FXML
    void initialize() {
        controleIndexation.indexation();
        AideTexte.setVisible(false);
    }
}
