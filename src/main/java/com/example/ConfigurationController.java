package com.example;

import java.io.IOException;
import java.net.URL;
import java.util.ResourceBundle;

import Controle.ControlConfig;
import com.example.pfr.PFRApplication;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Scene;
import javafx.scene.control.ChoiceBox;
import javafx.scene.control.MenuButton;
import javafx.scene.control.Slider;
import javafx.scene.control.TextField;
import javafx.stage.Stage;

public class ConfigurationController {

    private Stage stage;

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

    int nombremot;
    int seuil;
    int nombrebits;
    int nombrefenetre;
    int intervalletps;

    ControlConfig controlConfig=new ControlConfig();

    @FXML
    void Appliquer(ActionEvent event) throws IOException {
        nombremot = Integer.parseInt(nbmot.getText());
        seuil = (int) similarite.getValue();
        nombrebits = (int) bitfort.getValue();
        intervalletps = (int) temps.getValue();
        nombrefenetre = fenetre.getValue();
        FXMLLoader fxmlLoader = new FXMLLoader(PFRApplication.class.getResource("MenuAdministrateur.fxml"));
        // ConnexionController connexionController = fxmlLoader.getController();
        //connexionController.testAdmin(Admin);
        stage = (Stage) ((Node)event.getSource()).getScene().getWindow();
        Scene scene = new Scene(fxmlLoader.load(), 600, 400);
        stage.setTitle("MenuAdministrateur");
        stage.setScene(scene);
        stage.show();
        controlConfig.ModifierConfig(nombremot,seuil,nombrebits,nombrefenetre,intervalletps);
        System.out.println(nombremot);
        System.out.println(seuil);
        System.out.println(nombrebits);
        System.out.println(nombrefenetre);
        System.out.println(intervalletps);


    }

    @FXML
    void Retour(ActionEvent event) throws IOException{
        FXMLLoader fxmlLoader = new FXMLLoader(PFRApplication.class.getResource("MenuAdministrateur.fxml"));
        // ConnexionController connexionController = fxmlLoader.getController();
        //connexionController.testAdmin(Admin);
        stage = (Stage) ((Node)event.getSource()).getScene().getWindow();
        Scene scene = new Scene(fxmlLoader.load(), 600, 400);
        stage.setTitle("MenuAdministrateur");
        stage.setScene(scene);
        stage.show();
    }
    @FXML
    void initialize() {
        controlConfig.lire_config();
        nombremot = Integer.parseInt(controlConfig.getNb_Mots_Cle());
        seuil = controlConfig.getSimilariter();
        nombrebits = controlConfig.getNb_Bit_Fort();
        intervalletps = controlConfig.getNb_Fenetre();
        nombrefenetre = controlConfig.getIntervale();
        assert fenetre != null : "fx:id=\"fenetre\" was not injected: check your FXML file 'Configuration.fxml'.";
        assert nbmot != null : "fx:id=\"nbmot\" was not injected: check your FXML file 'Configuration.fxml'.";
        assert similarite != null : "fx:id=\"similarite\" was not injected: check your FXML file 'Configuration.fxml'.";
        assert temps != null : "fx:id=\"temps\" was not injected: check your FXML file 'Configuration.fxml'.";
        assert bitfort != null : "fx:id=\"bitfort\" was not injected: check your FXML file 'Configuration.fxml'.";
        fenetre.getItems().addAll(nombrefenetredispo);

    }
}
