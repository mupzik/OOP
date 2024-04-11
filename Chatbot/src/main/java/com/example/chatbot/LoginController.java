package com.example.chatbot;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.stage.Modality;
import javafx.scene.Scene;
import javafx.scene.Parent;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.layout.AnchorPane;
import javafx.scene.text.Text;
import javafx.stage.Stage;

import java.io.IOException;



public class LoginController {

    @FXML
    private Button ContinueButton;

    @FXML
    public Text HelloText;

    @FXML
    private AnchorPane LoginWindowPane;

    @FXML
    private TextField UsernameTextField;

    @FXML
    public static void chatStart() throws IOException {
         /*FXMLLoader fxmlLoader = new FXMLLoader(LoginController.class.getResource("MainChatWindow.fxml"));
        Scene scene = new Scene(fxmlLoader.load(), 352, 236);
        Stage stage1 = new Stage();
        stage1.setTitle("ChatBot");
        stage1.setScene(scene);
        stage1.show();*/
        //(LoginController.class.getResource("login-view.fxml"));


        FXMLLoader fxmlLoader1 = new FXMLLoader(MainChatController.class.getResource("MainChatWindow.fxml"));
        Scene scene = new Scene(fxmlLoader1.load());
        Stage stage = new Stage();
        stage.setTitle("");
        stage.setScene(scene);
        stage.show();

       // HelloText.getScene().getWindow().hide();

    }
    @FXML
    public void OnClick_ContinueButton(ActionEvent event) throws IOException {
        //String username = UsernameTextField.getText();
        chatStart();;


    }

}
