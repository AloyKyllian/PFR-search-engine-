package com.example.pfr;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.net.URL;
import java.nio.file.Files;
import java.util.ResourceBundle;
import java.util.Scanner;

import Controle.*;
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


public class ResultatImageController {

    ControlIndexation controleIndexation = new ControlIndexation();

    private ControlLireResultat controlLireResultat = new ControlLireResultat();
    private ControlLancerExecutable controlLancerExecutable = new ControlLancerExecutable();

    private ControlMenuImage controlMenuImage = new ControlMenuImage(controlLancerExecutable,controlLireResultat);
    private Stage stage;

    @FXML
    private ImageView Image;
    private Image image = new Image("file:HYLYK.png");
    @FXML
    private VBox vbox;
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
    public void afficherContenuFichier(ActionEvent event,String xmlFilePath) throws IOException {
       /*String currentWorkingDir = System.getProperty("user.dir");
        System.out.println("Répertoire de travail actuel : " + currentWorkingDir);*/

        // chemin du fichier texte
        String TXTfilePath = "Bonjour.txt";
        // String xmlFilePath = "./src/main/java/com/example/pfr/29-Ligue_des_champions___Lyon.xml";
        // création d'un objet File
        File xmlFile = new File(xmlFilePath);
        String xmlContent = new String(Files.readAllBytes(xmlFile.toPath()));
        File file = new File(TXTfilePath);
        FileWriter writer = new FileWriter(file);
        writer.write(xmlContent);
        writer.close();
        // création d'un objet Scanner pour lire le contenu du fichier
        Scanner scanner;
        try {
            scanner = new Scanner(file);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
            return;
        }

        // création d'une chaîne de caractères pour stocker le contenu du fichier
        String text = "";

        // boucle pour lire chaque ligne du fichier et les ajouter à la chaîne de caractères
        while (scanner.hasNextLine()) {
            text += scanner.nextLine() + "\n";
        }

        // fermeture du scanner
        scanner.close();
        // création d'une zone de texte pour afficher le contenu du fichier
        Texte.setText(text);
        // affichage de la zone de texte dans l'interface utilisateur
        // par exemple, vous pouvez ajouter la zone de texte à un VBox
        // ou à une autre disposition de votre choix
    }
    @FXML
    void initialize() {
        //assert texte1 != null : "fx:id=\"texte1\" was not injected: check your FXML file 'ResultatTexte.fxml'.";
        assert Texte != null : "fx:id=\"Texte\" was not injected: check your FXML file 'ResultatTexte.fxml'.";
        //Récupération du nombre de résultats
        //passer la map en parametres pour setBouttons
        setBouttons(10);    // Remplacer 21 par le nombre de résultats
        controleIndexation.indexation();
    }
}

