package com.example.pfr;

import Controle.ControlConnexion;
import Controle.ControlIndexation;
import com.example.pfr.PFRApplication;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.text.Text;
import javafx.stage.Stage;
import java.io.IOException;
import java.net.URL;
import java.util.ResourceBundle;


public class ConnexionAdministrateurController {


    ControlIndexation controleIndexation = new ControlIndexation();
    ControlConnexion controlConnexion = new ControlConnexion();
    public int cpt=0;
    private Stage stage;
    @FXML
    private Label myLabel;
    @FXML
    private TextField mylogin;
    @FXML
    private TextField mymdp;
    @FXML
    private Text Erreur;
    @FXML
    private Button valider;


    @FXML
    private Button myButton;

    private String login;
    private String mdp;

    private boolean testadmin;
    @FXML
    private ResourceBundle resources;

    @FXML
    private URL location;


    @FXML
    void validerAdmin(ActionEvent event) throws IOException {
        login = (mylogin.getText());
        mdp = (mymdp.getText());

        boolean  result = controlConnexion.seConnecter( login, mdp);
        // Mettre la Fonction Connexion
        /*System.out.println(login);
        System.out.println(mdp);*/
        if(result==true){
            FXMLLoader fxmlLoader = new FXMLLoader(PFRApplication.class.getResource("MenuAdministrateur.fxml"));
            stage = (Stage) ((Node) event.getSource()).getScene().getWindow();
            Scene scene = new Scene(fxmlLoader.load(), 1000, 750);
            stage.setTitle("MenuAdministrateur");
            stage.setScene(scene);
            stage.show();
        }
        else {
            Erreur.setVisible(true);
            cpt = cpt + 1;
            if(cpt==4){
                cpt=1;
            }
            if(cpt==3){
                FXMLLoader fxmlLoader = new FXMLLoader(PFRApplication.class.getResource("ErreurConnexionAdmin.fxml"));
                stage = (Stage) ((Node) event.getSource()).getScene().getWindow();
                Scene scene = new Scene(fxmlLoader.load(), 1000, 750);
                stage.setTitle("MenuAdministrateur");
                stage.setScene(scene);
                stage.show();
            }
        }
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
    void Quitter(ActionEvent event) throws IOException {
        System.exit(1);
    }

    @FXML
    void initialize() {
        assert mylogin != null : "fx:id=\"mylogin\" was not injected: check your FXML file 'ConnexionUtilisateur.fxml'.";
        assert mymdp != null : "fx:id=\"mymdp\" was not injected: check your FXML file 'ConnexionUtilisateur.fxml'.";
        assert valider != null : "fx:id=\"valider\" was not injected: check your FXML file 'ConnexionUtilisateur.fxml'.";
        assert Erreur != null : "fx:id=\"Erreur\" was not injected: check your FXML file 'ConnexionUtilisateur.fxml'.";
        Erreur.setVisible(false);
        controleIndexation.indexation();

    }
}
