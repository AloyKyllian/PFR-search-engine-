package com.example.pfr;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.net.URL;
import java.util.ResourceBundle;
import java.util.Scanner;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.control.TextArea;
import javafx.scene.input.MouseEvent;
import javafx.stage.Stage;

public class HistoriqueController {

    @FXML
    private ResourceBundle resources;

    private Stage stage;

    @FXML
    private URL location;

    @FXML
    private TextArea histo;

    @FXML
    void Retour(ActionEvent event) throws IOException {
        FXMLLoader fxmlLoader = new FXMLLoader(PFRApplication.class.getResource("Accueil.fxml"));
        Scene scene = new Scene(fxmlLoader.load(), 1000, 750);
        stage.setTitle("Bienvenue chez ID-HYLYK !");
        stage.setScene(scene);
        stage.show();
    }
    public void afficherContenuFichier(String chemin) {
        // chemin du fichier texte
        //String filePath = "chemin/vers/mon/fichier.txt";

        // création d'un objet File
        File file = new File(chemin);

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
        histo.setText(text);

        // affichage de la zone de texte dans l'interface utilisateur
        // par exemple, vous pouvez ajouter la zone de texte à un VBox
        // ou à une autre disposition de votre choix
    }

    @FXML
    void initialize() {
        assert histo != null : "fx:id=\"histo\" was not injected: check your FXML file 'Historique.fxml'.";
        afficherContenuFichier("Historique.txt");
    }

}
