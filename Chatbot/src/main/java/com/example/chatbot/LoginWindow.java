/** login window
 * developer Volosikova M.A.*/
package com.example.chatbot;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.image.Image;
import javafx.stage.Stage;
import java.io.IOException;

/** main app class for run program */
public class LoginWindow extends Application {
    @Override
    public void start(Stage stage) throws IOException {

        // login window
        FXMLLoader fxmlLoader = new FXMLLoader(LoginController.class.getResource("login-view.fxml"));
        // set window size
        Scene scene = new Scene(fxmlLoader.load(), 352, 236);
        // set window title
        stage.setTitle("Логин");
        stage.setScene(scene);
        // app icon
        Image ico = new Image("https://cdn-icons-png.flaticon.com/512/5039/5039010.png");
        stage.getIcons().add(ico);
        stage.show();

    }

    public static void main(String[] args) {
        launch();
    }
}