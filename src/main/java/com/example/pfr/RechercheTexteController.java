package com.example.pfr;

import java.io.File;
import java.io.IOException;
import java.net.URL;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.ResourceBundle;
import Controle.ControlLancerExecutable;
import Controle.ControlIndexation;
import Controle.ControlLireResultat;
import Controle.ControlMenuTexte;
import Entite.Affichage;
import Entite.LireResultat;
import Entite.ListCheminFichier;
import Entite.ReadWriteFichier;
import javafx.event.ActionEvent;
import javafx.scene.Node;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.control.ChoiceBox;
import javafx.scene.control.MenuButton;
import javafx.scene.control.TextField;
import javafx.stage.Stage;
import javafx.scene.Scene;

public class RechercheTexteController {

    ControlIndexation controleIndexation = new ControlIndexation();
    ControlLancerExecutable controlLancerExecutable=new ControlLancerExecutable();
    ControlLireResultat controlLireResultat=new ControlLireResultat();
    ControlMenuTexte controlMenuTexte=new ControlMenuTexte(controlLancerExecutable,controlLireResultat);
    private Stage stage;
    @FXML
    private TextField AideTexte;
    private boolean aide = false;
    @FXML
    private ResourceBundle resources;

    @FXML
    private URL location;

    @FXML
    private ChoiceBox<String> choix ;
    private String[] requete = {"simple","complexe"};

    @FXML
    private TextField Barre;
    private String texte;

    @FXML
    void Valider(ActionEvent event)throws IOException {

        if(choix.getItems().contains("simple")) {
            ArrayList<String> resultatFinale = new ArrayList<>();
            System.out.println("simple");
            texte = Barre.getText();
            ArrayList<String> motsPlusAuMoins = new ArrayList<String>();
            motsPlusAuMoins.add(texte);
            //Appel de la fonction recherche
            resultatFinale = controlMenuTexte.rechercheMot(motsPlusAuMoins,"simple");
            System.out.println(texte);
        }
        else if(choix.getItems().contains("complexe")){
            //Appel de la fonction complexe
            System.out.println("complexe");
            texte = Barre.getText();
            //controlMenuTexte.setmotcle(texte);
            String[] words = texte.split("\\s+"); // Sépare la chaîne en un tableau de mots
            ArrayList<String> motsPlusAuMoins = new ArrayList<String>();

// Boucle sur le tableau de mots et ajoute chaque mot à la liste
            for (String word : words) {
                motsPlusAuMoins.add(word);
            }

// Affiche chaque mot et son signe associé
            for (String word : motsPlusAuMoins) {
                System.out.println(word.charAt(0) + " " + word.substring(1));
            }
            ArrayList<String> resultatFinale = new ArrayList<>();
            resultatFinale=controlMenuTexte.rechercheMot(motsPlusAuMoins,"complexe");
            System.out.println(texte);
        }
        FXMLLoader fxmlLoader = new FXMLLoader(PFRApplication.class.getResource("ResultatTexte.fxml"));
        stage = (Stage) ((Node)event.getSource()).getScene().getWindow();
        Scene scene = new Scene(fxmlLoader.load(), 1000, 750);
        stage.setTitle("ResultatTexte");
        stage.setScene(scene);
        stage.show();
    }

    @FXML
    void aide(ActionEvent event){
        if(aide==false){
            AideTexte.setVisible(true);
            aide = true;
        }
        else if(aide==true) {
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
        assert choix != null : "fx:id=\"Choix\" was not injected: check your FXML file 'Recherche.fxml'.";
        assert Barre != null : "fx:id=\"Barre\" was not injected: check your FXML file 'Recherche.fxml'.";
        controleIndexation.indexation();
        AideTexte.setVisible(false);
        choix.getItems().addAll(requete);

    }
}