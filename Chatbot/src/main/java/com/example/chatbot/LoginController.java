package com.example.chatbot;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.image.Image;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
import javafx.scene.layout.AnchorPane;
import javafx.scene.text.Text;
import javafx.stage.Stage;

import java.io.IOException;



public class LoginController {

    /** error color */
    final String errc = "#ffc3bf";

    /** continue button */
    @FXML
    private Button ContinueButton;

    /** hello text */
    @FXML
    public Text HelloText;

    /** login window pane */
    @FXML
    private AnchorPane LoginWindowPane;

    /** username taxt field */
    @FXML
    public TextField UsernameTextField;

    /** create and open new chat window */
    @FXML
    public void chatStart(String username) throws IOException {
        FXMLLoader fxmlLoader1 = new FXMLLoader(MainChatController.class.getResource("MainChatWindow.fxml"));
        Scene scene = new Scene(fxmlLoader1.load());
        Stage stage = new Stage();
        stage.setTitle("Марвин");
        stage.setScene(scene);
        // app icon
        Image ico = new Image("https://cdn-icons-png.flaticon.com/512/5039/5039010.png");
        stage.getIcons().add(ico);
        stage.show();

        // calling a controller with handlers
        MainChatController main_window = fxmlLoader1.getController();
        main_window.setLogin( UsernameTextField.getText() );
        main_window.initialize();

        UsernameTextField.getScene().getWindow().hide();

    }

    /** open chat window button */
    @FXML
    public void OnClick_ContinueButton(ActionEvent event) throws IOException {
        chatStart(UsernameTextField.getText());
    }


    /** hotkey Enter for new_window */
    public void onTextField_login_key_pressed(KeyEvent keyEvent) throws IOException {
        if (keyEvent.getCode().equals(KeyCode.ENTER)){
            chatStart(UsernameTextField.getText());
        }
    }
}
