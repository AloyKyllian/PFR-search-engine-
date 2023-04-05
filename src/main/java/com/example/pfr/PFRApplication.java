package com.example.pfr;

import Boundary.BoundaryVisualiserHistorique;
import Controle.ControlIndexation;
import Controle.ControlVisualiserHistorique;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.io.IOException;

public class PFRApplication extends Application {

    ControlIndexation controleIndexation = new ControlIndexation();
    private ControlVisualiserHistorique controlVisualiserHistorique;
    private BoundaryVisualiserHistorique boundaryVisualiserHistorique;

    @Override
    public void start(Stage stage) throws IOException {
        this.controlVisualiserHistorique = new ControlVisualiserHistorique();
        this.boundaryVisualiserHistorique = new BoundaryVisualiserHistorique (this.controlVisualiserHistorique);
        controleIndexation.indexation_fermer();
        FXMLLoader fxmlLoader = new FXMLLoader(PFRApplication.class.getResource("Accueil.fxml"));
        Scene scene = new Scene(fxmlLoader.load(), 1000, 750);
        stage.setTitle("Bienvenue chez ID-HYLYK !");
        stage.setScene(scene);
        stage.show();
    }

    public static void main(String[] args) {
        launch();
    }
}

