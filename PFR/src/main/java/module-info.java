module com.example.pfr {
    requires javafx.controls;
    requires javafx.fxml;


    opens com.example.pfr to javafx.fxml;
    exports com.example.pfr;
}