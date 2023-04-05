package com.example.pfr;

import java.io.IOException;
import java.net.URL;
import java.util.ResourceBundle;

import Controle.ControlIndexation;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Scene;
import javafx.scene.control.TextArea;
import javafx.stage.Stage;

public class MenuImageController {

    ControlIndexation controleIndexation = new ControlIndexation();
    public Stage stage;

    @FXML
    private TextArea AideTexte;
    private boolean aide = false;

    @FXML
    private ResourceBundle resources;

    @FXML
    private URL location;

    @FXML
    void Comparaison(ActionEvent event) throws IOException{
        FXMLLoader fxmlLoader = new FXMLLoader(PFRApplication.class.getResource("ResultatsImageComparaison.fxml"));
        stage = (Stage) ((Node)event.getSource()).getScene().getWindow();
        Scene scene = new Scene(fxmlLoader.load(), 1000, 750);
        stage.setTitle("RechercheImage");
        stage.setScene(scene);
        stage.show();
    }

    @FXML
    void Quitter(ActionEvent event) throws IOException {
        System.exit(1);
    }

    @FXML
    void Recherche(ActionEvent event) throws IOException {
        FXMLLoader fxmlLoader = new FXMLLoader(PFRApplication.class.getResource("ResultatImage.fxml"));
        stage = (Stage) ((Node)event.getSource()).getScene().getWindow();
        Scene scene = new Scene(fxmlLoader.load(), 1000, 750);
        stage.setTitle("RechercheImage");
        stage.setScene(scene);
        stage.show();
    }

    @FXML
    void Retour(ActionEvent event) throws IOException {
        FXMLLoader fxmlLoader = new FXMLLoader(PFRApplication.class.getResource("Accueil.fxml"));
        stage = (Stage) ((Node)event.getSource()).getScene().getWindow();
        Scene scene = new Scene(fxmlLoader.load(), 1000, 750);
        stage.setTitle("Accueil");
        stage.setScene(scene);
        stage.show();
    }

    @FXML
    void aide(ActionEvent event){
        if(!aide){
            AideTexte.setVisible(true);
            aide = true;
        }
        else if(aide){
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
