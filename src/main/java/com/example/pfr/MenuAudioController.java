package com.example.pfr;

import Controle.*;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Scene;
import javafx.stage.Stage;
import javafx.scene.control.TextArea;
import java.io.IOException;
import java.net.URL;
import java.util.ResourceBundle;

public class MenuAudioController {

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
    void Comparaison(ActionEvent event) throws IOException {
        FXMLLoader fxmlLoader = new FXMLLoader(PFRApplication.class.getResource("ResultatAudioComparaison.fxml"));
        stage = (Stage) ((Node)event.getSource()).getScene().getWindow();
        Scene scene = new Scene(fxmlLoader.load(), 1000, 750);
        stage.setTitle("Comparaison Audio");
        stage.setScene(scene);
        stage.show();
    }

    @FXML
    void Quitter(ActionEvent event) throws IOException {
        System.exit(1);
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
