package com.example.pfr;

import java.net.URL;
import java.util.ResourceBundle;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.text.Text;

public class ConnexionController {

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

    public boolean testAdmin(boolean admin){
        return admin;
    }
    @FXML
    void valider(ActionEvent event) {

        login = (mylogin.getText());
        mdp = (mymdp.getText());
        System.out.println(login);
        Text text = new Text();
        text.setText("Bonjour");
        text.setX(50);
        text.setY(50);
    }

    @FXML
    void initialize() {

    }
}

