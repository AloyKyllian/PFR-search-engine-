module com.example.pfr {
    requires javafx.controls;
    requires javafx.fxml;
    requires java.desktop;


    opens com.example.pfr to javafx.fxml;
    exports com.example.pfr;
    exports Boundary;
    opens Boundary to javafx.fxml;
    exports lancement;
    opens lancement to javafx.fxml;
}