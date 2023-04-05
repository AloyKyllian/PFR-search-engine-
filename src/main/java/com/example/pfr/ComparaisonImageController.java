package com.example.pfr;

import java.io.File;
import java.io.IOException;
import java.net.URL;
import java.util.ArrayList;
import java.util.ResourceBundle;

import Controle.ControlLancerExecutable;
import Controle.ControlLireResultat;
import Controle.ControlMenuAudio;
import Controle.ControlMenuImage;
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
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class ComparaisonImageController{
    ControlLancerExecutable controlLancerExecutable=new ControlLancerExecutable();
    ControlLireResultat controlLireResultat=new ControlLireResultat();
    ControlMenuImage controlMenuImage=new ControlMenuImage(controlLancerExecutable,controlLireResultat);

    @FXML
    private ImageView Image;
    private Stage stage;
    @FXML
    private TextArea AideTexte;
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
        resultatFinale=controlMenuImage.comparaisonImage(texte);
        setBouttons(resultatFinale);
        System.out.println(texte);
    }
    public void setBouttons(ArrayList<String>resultatFinale){
        //controlMenuImage.comparaisonImage();
        int i=1;
        int j=0;

        int dernierSeparateur ;
        String nomFichier;
        System.out.println("size premier : "+resultatFinale.size());
        Image [] image=new Image[resultatFinale.size()];
        for(Object file : resultatFinale){
            image[j]=(Image) file;
            j++;
        }
        while(i!=resultatFinale.size()+1){
            dernierSeparateur = resultatFinale.get(i - 1).lastIndexOf(File.separator);
            nomFichier = resultatFinale.get(i - 1).substring(dernierSeparateur + 1);
            tailleVbox = tailleVbox +60;
            vbox.setPrefSize(224,tailleVbox);
            Button Bouttons = new Button(nomFichier);
            Bouttons.setPrefSize(224,60);
            i=i+1;
            int finalI = i;
            Bouttons.setOnAction(e -> {
                Image.setImage(image[finalI -1]);
            });
            vbox.getChildren().add(Bouttons);
        }
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
        AideTexte.setVisible(false);
    }
}


