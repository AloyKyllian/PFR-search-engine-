package com.example.pfr;

import java.io.IOException;
import java.net.URL;
import java.util.ResourceBundle;

import Controle.ControleVisualiserDescripteur;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class DescripteursController {

    private final ControleVisualiserDescripteur controleVisualiserDescripteur=new ControleVisualiserDescripteur();
    private Stage stage;
    @FXML
    private ResourceBundle resources;

    @FXML
    private URL location;

    @FXML
    void Audio(ActionEvent event) {
        controleVisualiserDescripteur.controleSystemAudio();
    }

    @FXML
    void Image(ActionEvent event) {
        controleVisualiserDescripteur.controleSystemImage();
    }

    @FXML
    void Quitter(ActionEvent event) throws IOException {
        FXMLLoader fxmlLoader = new FXMLLoader(PFRApplication.class.getResource("Accueil.fxml"));
        stage = (Stage) ((Node)event.getSource()).getScene().getWindow();
        Scene scene = new Scene(fxmlLoader.load(), 1000, 750);
        stage.setTitle("Accueil");
        stage.setScene(scene);
        stage.show();
    }

    @FXML
    void Retour(ActionEvent event) throws IOException {
        FXMLLoader fxmlLoader = new FXMLLoader(PFRApplication.class.getResource("MenuAdministrateur.fxml"));
        stage = (Stage) ((Node)event.getSource()).getScene().getWindow();
        Scene scene = new Scene(fxmlLoader.load(), 1000, 750);
        stage.setTitle("MenuAdministrateur");
        stage.setScene(scene);
        stage.show();
    }

    @FXML
    void Texte(ActionEvent event) {
        controleVisualiserDescripteur.controleSystemTexte();
    }

    @FXML
    void initialize() {

    }
}
