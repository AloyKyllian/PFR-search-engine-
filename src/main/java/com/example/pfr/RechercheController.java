package com.example.pfr;

import java.io.IOException;
import java.net.URL;
import java.util.ResourceBundle;

import Controle.ControlIndexation;
import javafx.event.ActionEvent;
import javafx.scene.Node;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.control.MenuButton;
import javafx.scene.control.TextField;
import javafx.stage.Stage;
import javafx.scene.Scene;

public class RechercheController {

    ControlIndexation controleIndexation = new ControlIndexation();
    private Stage stage;
    @FXML
    private TextField AideTexte;
    private boolean aide = false;
    @FXML
    private ResourceBundle resources;

    @FXML
    private URL location;

    @FXML
    private MenuButton Choix;

    @FXML
    private TextField Barre;
    private String texte;

    @FXML
    void Valider(ActionEvent event) {
        if(Choix.getText().compareTo("simple")==0){
            //Appel de la fonction recherche
            System.out.println("simple");
            texte = Barre.getText();
            System.out.println(texte);
        }
        else if(Choix.getText().compareTo("complexe")==0){
            //Appel de la fonction Comparaison
            System.out.println("complexe");
            texte = Barre.getText();
            System.out.println(texte);
        }
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
    void Retour(ActionEvent event) throws IOException {
        FXMLLoader fxmlLoader = new FXMLLoader(PFRApplication.class.getResource("MenuTexte.fxml"));
        stage = (Stage) ((Node)event.getSource()).getScene().getWindow();
        Scene scene = new Scene(fxmlLoader.load(), 1000, 750);
        stage.setTitle("MenuTexte");
        stage.setScene(scene);
        stage.show();
    }
    @FXML
    void Quitter(ActionEvent event) throws IOException {
        FXMLLoader fxmlLoader = new FXMLLoader(PFRApplication.class.getResource("Accueil.fxml"));
        stage = (Stage) ((Node)event.getSource()).getScene().getWindow();
        Scene scene = new Scene(fxmlLoader.load(), 1000, 750);
        stage.setTitle("Bienvenue chez ID-HYLYK !");
        stage.setScene(scene);
        stage.show();
    }

    @FXML
    void initialize() {
        assert Choix != null : "fx:id=\"Choix\" was not injected: check your FXML file 'Recherche.fxml'.";
        assert Barre != null : "fx:id=\"Barre\" was not injected: check your FXML file 'Recherche.fxml'.";
        controleIndexation.indexation();
        AideTexte.setVisible(false);

    }
}