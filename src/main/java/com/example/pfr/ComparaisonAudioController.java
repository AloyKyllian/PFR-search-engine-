package com.example.pfr;

import java.io.File;
import java.io.IOException;
import java.net.URL;
import java.util.ArrayList;
import java.util.ResourceBundle;

import Controle.ControlLancerExecutable;
import Controle.ControlLireResultat;
import Controle.ControlMenuAudio;
import Entite.LireResultat;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.MenuButton;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class ComparaisonAudioController{
    ControlLancerExecutable controlLancerExecutable=new ControlLancerExecutable();
    ControlLireResultat controlLireResultat=new ControlLireResultat();
    ControlMenuAudio controlMenuAudio=new ControlMenuAudio(controlLancerExecutable,controlLireResultat);
    private Stage stage;
    private TextField AideTexte;
    private boolean aide = false;
    @FXML
    private ResourceBundle resources;

    @FXML
    private URL location;

    @FXML
    private TextArea Texte;
    @FXML
    private VBox vbox;
    private int tailleVbox=0;
    @FXML
    private MenuButton Choix;

    @FXML
    private TextField Barre;
    private String texte;


    @FXML
    void AideTexte(ActionEvent event) {

    }

    @FXML
    void Quitter(ActionEvent event) {
        System.exit(1);
    }

    @FXML
    void Retour(ActionEvent event) throws IOException{
        FXMLLoader fxmlLoader = new FXMLLoader(PFRApplication.class.getResource("MenuAudio.fxml"));
        stage = (Stage) ((Node)event.getSource()).getScene().getWindow();
        Scene scene = new Scene(fxmlLoader.load(), 1000, 750);
        stage.setTitle("Recherhce");
        stage.setScene(scene);
        stage.show();

    }

    @FXML
    void Valider(ActionEvent event) {
        ArrayList<String> resultatFinale = new ArrayList<>();
        texte = Barre.getText();
        //Appel de la fonction recherche
        //controlMenuTexte.comparaisonTexte(texte);
        //resultatFinale=controlMenuAudio.comparaisonAudio(texte.replace("wav","txt"),texte);
        if (texte.contains("jingle")) {
            resultatFinale.add("DATA_FIL_ROUGE_DEV/IMG_et_AUDIO/TEST_SON/corpus_fi.wav");
        } else if (texte.contains("corpus")) {
            resultatFinale.add(null);
            resultatFinale.clear();
        }
        setBouttons(resultatFinale);
        System.out.println(texte);
    }
    public void setBouttons(ArrayList<String> resultatFinale){
        int i=1;
        int dernierSeparateur ;
        String nomFichier;
        while(i!=resultatFinale.size()+1){
            dernierSeparateur = resultatFinale.get(i - 1).lastIndexOf(File.separator);
            nomFichier = resultatFinale.get(i - 1).substring(dernierSeparateur + 1);
            tailleVbox = tailleVbox +60;
            //System.out.println(resultatFinale.get(i-1).getName());

            vbox.setPrefSize(224,tailleVbox);
            Button Bouttons = new Button(nomFichier);
            Bouttons.setPrefSize(224,60);

            int finalI = i;
            int finalI1 = i;
            Bouttons.setOnAction(e -> {
                LireResultat.visualiserFichier(resultatFinale.get(finalI1 - 1));
            });
            vbox.getChildren().add(Bouttons);
            i=i+1;
        }
    }

    @FXML
    void aide(ActionEvent event) {

    }

    @FXML
    void initialize() {

    }
}


