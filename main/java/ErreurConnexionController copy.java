package com.example.pfr;

import java.io.IOException;
import java.net.URL;
import java.util.ResourceBundle;

import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.input.MouseEvent;
import javafx.scene.text.Text;
import javafx.stage.Stage;

public class ErreurConnexionController {

    public Stage stage;
    @FXML
    public Button Boutton;
    @FXML
    public ResourceBundle resources;

    @FXML
    public URL location;

    @FXML
    public Text decompte;


    public ErreurConnexionController() {
    }

    @FXML
    public void initialize() throws InterruptedException {
        assert decompte != null : "fx:id=\"decompte\" was not injected: check your FXML file 'Erreur_Connexion.fxml'.";
    }
    @FXML

    void Changement(MouseEvent event) throws InterruptedException, IOException {
        Thread.sleep(10000);
        stage = (Stage) ((Node)event.getSource()).getScene().getWindow();
        FXMLLoader fxmlLoader = new FXMLLoader(PFRApplication.class.getResource("ConnexionUtilisateur.fxml"));
        Scene scene = new Scene(fxmlLoader.load(), 600, 400);
        stage.setTitle("ConnexionUtilisateur");
        stage.setScene(scene);
        stage.show();
    }

}
