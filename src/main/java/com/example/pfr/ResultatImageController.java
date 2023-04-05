package com.example.pfr;

import java.awt.*;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.net.URL;
import java.nio.file.Files;
import java.util.List;
import java.util.ResourceBundle;
import java.util.Scanner;
import java.util.Arrays;
import java.util.stream.Collectors;

import Controle.*;
import javafx.event.ActionEvent;
import javafx.scene.input.MouseEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.ColorPicker;
import javafx.scene.control.Slider;
import javafx.scene.control.TextArea;
import javafx.scene.paint.Color;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;


public class ResultatImageController {

    ControlIndexation controleIndexation = new ControlIndexation();

    private ControlLireResultat controlLireResultat = new ControlLireResultat();
    private ControlLancerExecutable controlLancerExecutable = new ControlLancerExecutable();

    private ControlMenuImage controlMenuImage = new ControlMenuImage(controlLancerExecutable,controlLireResultat);
    private Stage stage;
    private List<Color> allowedColors= Arrays.asList(Color.RED,Color.GREEN,Color.BLUE);
    @FXML
    private ImageView Image;
    private Image image = new Image("file:HYLYK.png");
    @FXML
    private ColorPicker colorpicker;

    @FXML
    private Rectangle blueBox;

    @FXML
    private Rectangle rougeBox;

    @FXML
    private Rectangle vertBox;
    @FXML
    private Slider seuil;
    @FXML
    private VBox vbox;

    private String couleur = "rouge";
    static private int pourcentage=1;
    private int tailleVbox=0;
    //@FXML
    //private Text texte1;
   /* @FXML
    private Button panel1;
    @FXML
    private ScrollPane scrollPane;*/
    @FXML
    private ResourceBundle resources;

    @FXML
    private URL location;

    @FXML
    private TextArea Texte;
    @FXML
    void Quitter(ActionEvent event) throws IOException {
        System.exit(1);
    }

    @FXML
    void Retour(ActionEvent event) throws IOException {
        FXMLLoader fxmlLoader = new FXMLLoader(PFRApplication.class.getResource("MenuImage.fxml"));
        stage = (Stage) ((Node)event.getSource()).getScene().getWindow();
        Scene scene = new Scene(fxmlLoader.load(), 1000, 750);
        stage.setTitle("Recherhce");
        stage.setScene(scene);
        stage.show();
    }

    public void setBouttons(int nbResultat){
        //controlMenuImage.comparaisonImage();
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
    void Rouge(MouseEvent event) {
        couleur = "rouge";
    }


    @FXML
    void Vert(MouseEvent event) {
        couleur = "vert";
    }

    @FXML
    void Bleu(MouseEvent event) {
        couleur = "bleu";
    }

    @FXML
    void Valider(ActionEvent event) {
        pourcentage = (int)seuil.getValue();
        System.out.println(couleur);
        System.out.println(pourcentage);
    }

    @FXML
    void initialize() {
        //assert texte1 != null : "fx:id=\"texte1\" was not injected: check your FXML file 'ResultatTexte.fxml'.";
        assert Texte != null : "fx:id=\"Texte\" was not injected: check your FXML file 'ResultatTexte.fxml'.";
        //Récupération du nombre de résultats
        //passer la map en parametres pour setBouttons
        setBouttons(10);    // Remplacer 21 par le nombre de résultats
        controleIndexation.indexation();
        //colorpicker.setCustomColors(allowedColors.stream().collect(Collectors.toSet()));
    }
}

