package com.example.pfr;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.net.URL;
import java.nio.file.Files;
import java.util.*;

import Controle.ControlIndexation;
import Controle.ControlLancerExecutable;
import Controle.ControlLireResultat;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.ChoiceBox;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;
import Controle.ControlMenuTexte;

public class ResultatTexteController {

    ControlIndexation controleIndexation = new ControlIndexation();

    private final ControlLireResultat controlLireResultat = new ControlLireResultat();
    private final ControlLancerExecutable controlLancerExecutable = new ControlLancerExecutable();

    private final ControlMenuTexte controlMenuTexte = new ControlMenuTexte(controlLancerExecutable,controlLireResultat);
    @FXML
    private TextArea AideTexte;
    private boolean aide = false;
    private Stage stage;
    @FXML
    private VBox vbox;
    private int tailleVbox=0;
    @FXML
    private ChoiceBox<String> Choix;
    private final String[] requete = {"Simple","Complexe"};
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
    private TextField Barre;
    private String texte;
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
    void Valider(ActionEvent event) throws IOException {
        vbox.getChildren().removeAll(vbox.getChildren());
        if(Choix.getValue().compareTo("Simple")==0) {
            ArrayList<String> resultatFinale = new ArrayList<>();
            resultatFinale.clear();
            System.out.println("simple");
            texte = Barre.getText();
            ArrayList<String> motsPlusAuMoins = new ArrayList<>();
            motsPlusAuMoins.clear();
            motsPlusAuMoins.add(texte);
            //Appel de la fonction recherche
            System.out.println("mot :");
            System.out.print(motsPlusAuMoins);
            resultatFinale = controlMenuTexte.rechercheMot(motsPlusAuMoins,"simple");
            System.out.println("taille :");
            System.out.print(resultatFinale.size());
            setBouttons(resultatFinale);
            System.out.println(texte);
        }
        if(Choix.getValue().compareTo("Complexe")==0) {
            ArrayList<String> resultatFinale = new ArrayList<>();
            System.out.println("Complexe");
            texte = Barre.getText();
            ArrayList<String> motsPlusAuMoins = new ArrayList<>();
            motsPlusAuMoins.add(texte);
            //Appel de la fonction recherche
            resultatFinale = controlMenuTexte.rechercheMot(motsPlusAuMoins,"complexe");
            setBouttons(resultatFinale);
            System.out.println(texte);
        }
    }
    public void setBouttons(ArrayList<String>resultatFinale){
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
            Bouttons.setOnAction(e -> {
                try {
                    afficherContenuFichier(e,resultatFinale.get(finalI -1));
                } catch (IOException ex) {
                    throw new RuntimeException(ex);
                }
            });
            vbox.getChildren().add(Bouttons);
            i=i+1;
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
    void aide(ActionEvent event){
        if(!aide){
            AideTexte.setVisible(true);
            aide = true;
        }
        else if(aide){
            AideTexte.setVisible(false);
            aide = false;
        }

    }
    @FXML
    void initialize() {
        //assert texte1 != null : "fx:id=\"texte1\" was not injected: check your FXML file 'ResultatTexte.fxml'.";
        assert Texte != null : "fx:id=\"Texte\" was not injected: check your FXML file 'ResultatTexte.fxml'.";
        //Récupération du nombre de résultats
        //A REVOIR controlLireResultat.affichage(,null,null);
          // Remplacer 21 par le nombre de résultats
        controleIndexation.indexation();
        Choix.getItems().addAll(requete);
        Choix.setValue("Simple");
        AideTexte.setVisible(false);
    }
}

