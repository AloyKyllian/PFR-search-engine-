package com.example.pfr;

import java.io.IOException;
import java.io.ObjectInputFilter;
import java.net.URL;
import java.util.ResourceBundle;

import Controle.ControlConfig;
import Controle.ControlIndexation;
import Entite.Config;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Scene;
import javafx.scene.control.ChoiceBox;
import javafx.scene.control.Slider;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.stage.Stage;

public class ConfigurationController {

    ControlConfig controlconfig = new ControlConfig();
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
    private ChoiceBox<Integer> fenetre;
    private Integer[] nombrefenetredispo = {512,1024,2048,4096,8192};

    @FXML
    private TextField nbmot;

    @FXML
    private Slider similarite;

    @FXML
    private Slider temps;

    @FXML
    private Slider bitfort;

    static String nombremot;
    static int seuil;
    static int nombrebits;
    static int nombrefenetre;
    static int intervalletps;


    @FXML
    void Appliquer(ActionEvent event) throws IOException {

        nombremot = nbmot.getText();
        seuil = (int) similarite.getValue();
        nombrebits = (int) bitfort.getValue();
        intervalletps = (int) temps.getValue();
        nombrefenetre = fenetre.getValue();
        FXMLLoader fxmlLoader = new FXMLLoader(PFRApplication.class.getResource("MenuAdministrateur.fxml"));
        stage = (Stage) ((Node)event.getSource()).getScene().getWindow();
        Scene scene = new Scene(fxmlLoader.load(), 1000, 750);
        stage.setTitle("MenuAdministrateur");
        stage.setScene(scene);
        stage.show();
        controlconfig.ModifierConfig(nombremot,nombrebits,intervalletps,seuil,nombrefenetre);
        controleIndexation.indexation_fermer();
        //System.out.println(nombremot);
        //System.out.println(seuil);
        //System.out.println(nombrebits);
        //System.out.println(nombrefenetre);
        //System.out.println(intervalletps);
    }

    @FXML
    void Retour(ActionEvent event) throws IOException{
        FXMLLoader fxmlLoader = new FXMLLoader(PFRApplication.class.getResource("MenuAdministrateur.fxml"));
        stage = (Stage) ((Node)event.getSource()).getScene().getWindow();
        Scene scene = new Scene(fxmlLoader.load(), 1000, 750);
        stage.setTitle("MenuAdministrateur");
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
        assert fenetre != null : "fx:id=\"fenetre\" was not injected: check your FXML file 'Configuration.fxml'.";
        assert nbmot != null : "fx:id=\"nbmot\" was not injected: check your FXML file 'Configuration.fxml'.";
        assert similarite != null : "fx:id=\"similarite\" was not injected: check your FXML file 'Configuration.fxml'.";
        assert temps != null : "fx:id=\"temps\" was not injected: check your FXML file 'Configuration.fxml'.";
        assert bitfort != null : "fx:id=\"bitfort\" was not injected: check your FXML file 'Configuration.fxml'.";
        AideTexte.setVisible(false);
        controlconfig.lire_config();
        //controlconfig.setconfig(seuil,intervalletps,nombrebits,nombrefenetre,nombremot);
        seuil = controlconfig.getSimilariter();
        intervalletps = controlconfig.getIntervale();
        nombrebits = controlconfig.getNb_Bit_Fort();
        nombrefenetre = controlconfig.getNb_Fenetre();
        nombremot = controlconfig.getNb_Mots_Cle();
        fenetre.getItems().addAll(nombrefenetredispo);
        nbmot.setText(nombremot);
        similarite.setValue(seuil);
        temps.setValue(intervalletps);
        bitfort.setValue(nombrebits);
        fenetre.setValue(nombrefenetre);
        controleIndexation.indexation();

    }
}
