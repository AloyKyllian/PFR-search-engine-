package com.example.pfr;

import java.io.IOException;
import java.net.URL;
import java.util.ResourceBundle;

import Controle.ControlLancerExecutable;
import Controle.ControlLireResultat;
import Controle.ControlMenuAudio;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.TextArea;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;


public class ResultatAudioController {

    private Stage stage;
    private ControlLireResultat controlLireResultat = new ControlLireResultat();
    private ControlLancerExecutable controlLancerExecutable = new ControlLancerExecutable();

    private ControlMenuAudio controlMenuAudio = new ControlMenuAudio(controlLancerExecutable,controlLireResultat);
    @FXML
    private ImageView Image;
    private Image image = new Image("file:50.jpg");
    @FXML
    private VBox vbox;
    private int tailleVbox=0;

    @FXML
    private ResourceBundle resources;

    @FXML
    private URL location;

    @FXML
    private TextArea Texte;
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
        FXMLLoader fxmlLoader = new FXMLLoader(PFRApplication.class.getResource("Recherche.fxml"));
        stage = (Stage) ((Node)event.getSource()).getScene().getWindow();
        Scene scene = new Scene(fxmlLoader.load(), 1000, 750);
        stage.setTitle("Recherhce");
        stage.setScene(scene);
        stage.show();
    }

    public void setBouttons(int nbResultat){
        int i=1;
        while(i!=nbResultat+1){
            tailleVbox = tailleVbox +60;
            vbox.setPrefSize(224,tailleVbox);
            Button Bouttons = new Button("Image "+i);
            Bouttons.setPrefSize(224,60);
            i=i+1;
            Bouttons.setOnAction(e -> {
                Image.setImage(image);
            });
            vbox.getChildren().add(Bouttons);
        }
    }

    @FXML
    void initialize() {
        //assert texte1 != null : "fx:id=\"texte1\" was not injected: check your FXML file 'ResultatTexte.fxml'.";
        assert Texte != null : "fx:id=\"Texte\" was not injected: check your FXML file 'ResultatTexte.fxml'.";
        //Récupération du nombre de résultats
        //controlMenuAudio.comparaisonAudio();
        setBouttons(10);    // Remplacer 21 par le nombre de résultats

    }
}