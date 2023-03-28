package com.example.pfr;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.text.Text;
import javafx.stage.Stage;
import java.io.IOException;
import java.net.URL;
import java.util.ResourceBundle;

public class ConnexionUtilisateurController {

    private Stage stage;
    private int cpt=0;
    private Parent root;
    @FXML
    private Label myLabel;
    @FXML
    private Text Erreur;
    @FXML
    private TextField mylogin;
    @FXML
    private TextField mymdp;
    @FXML
    private Button valider;

    @FXML
    private Text decompte;

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
    void validerUtilisateur(ActionEvent event) throws IOException, InterruptedException {
        login = (mylogin.getText());
        mdp = (mymdp.getText());
        System.out.println(login);
        System.out.println(mdp);
        if((login.compareTo("h") == 0) && (mdp.compareTo("l")==0)){
            FXMLLoader fxmlLoader = new FXMLLoader(PFRApplication.class.getResource("MenuUtilisateur.fxml"));
            stage = (Stage) ((Node) event.getSource()).getScene().getWindow();
            Scene scene = new Scene(fxmlLoader.load(), 600, 400);
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
                FXMLLoader fxmlLoader = new FXMLLoader(PFRApplication.class.getResource("ErreurConnexionUtil.fxml"));
                stage = (Stage) ((Node) event.getSource()).getScene().getWindow();
                Scene scene = new Scene(fxmlLoader.load(), 1000, 600);
                stage.setTitle("MenuAdministrateur");
                stage.setScene(scene);
                stage.show();
            }
        }
    }

    @FXML
    void initialize() {
        assert mylogin != null : "fx:id=\"mylogin\" was not injected: check your FXML file 'ConnexionUtilisateur.fxml'.";
        assert mymdp != null : "fx:id=\"mymdp\" was not injected: check your FXML file 'ConnexionUtilisateur.fxml'.";
        assert valider != null : "fx:id=\"valider\" was not injected: check your FXML file 'ConnexionUtilisateur.fxml'.";
        assert Erreur != null : "fx:id=\"Erreur\" was not injected: check your FXML file 'ConnexionUtilisateur.fxml'.";
        Erreur.setVisible(false);
    }
}
