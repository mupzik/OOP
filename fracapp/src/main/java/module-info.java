module com.example.fracapp {
    requires javafx.controls;
    requires javafx.fxml;


    opens com.example.fracapp to javafx.fxml;
    exports com.example.fracapp;
}