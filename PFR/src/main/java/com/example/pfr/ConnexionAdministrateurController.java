package com.example.pfr;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.stage.Stage;

import java.io.IOException;
import java.net.URL;
import java.util.ResourceBundle;

public class ConnexionAdministrateurController {

    private Stage stage;
    @FXML
    private Label myLabel;
    @FXML
    private TextField mylogin;
    @FXML
    private TextField mymdp;

    @FXML
    private Button myButton;

    private String login;
    private String mdp;

    private boolean testadmin;
    @FXML
    private ResourceBundle resources;

    @FXML
    private URL location;


    @FXML
    void validerAdmin(ActionEvent event) throws IOException {

        login = (mylogin.getText());
        mdp = (mymdp.getText());
        System.out.println(login);
        System.out.println(mdp);
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

    }
}
