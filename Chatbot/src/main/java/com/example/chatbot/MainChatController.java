/** main window
 developer Volosikova M.A. * */
package com.example.chatbot;

import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;

/** controller class for main chat window */
public class MainChatController {

    /** send button */
    @FXML
    private Button SendButton;

    /** chat field */
    @FXML
    private TextArea chatTextArea;

    /** message field */
    @FXML
    private TextField messageTextField;

    /** username */
    private String Username;

    /** send button */
    public void sendMessage(){

    }
    /** set username */
    public void setLogin(String name){
        this.Username = name;
    }

    /** get username (returns username) */
    public String getLogin() {
        return Username;
    }

    /** for history */
    ArrayList<String> history = new ArrayList<String>();

    /** object chatbot
     * load username for history and history if it exists*/
    BotMarvin newBot = new BotMarvin(this.getLogin(), history);


    /** "send" button event handler */
    public void onButtonClick() throws IOException {
        // get string from message field
        String msg = (String) messageTextField.getText();
        // displays answer
        chatTextArea.setText(newBot.Answer(msg));
        messageTextField.setText("");
    }

    /** initialize history if it exists
     *  called when chat window opens */
    public void initialize(){
        newBot.set_username(Username);
        // file name
        String FileName = this.getLogin()+".txt";
        File f = new File(FileName);
        // if exists, display history
        if (f.exists()){
            newBot.FillingFromFileHistory();
            chatTextArea.setText(newBot.toString());
        }
    }


    /** hotkey Enter for onButtonClick() */
    public void onTextField_sendPressed(KeyEvent keyEvent) throws IOException {
        if (keyEvent.getCode().equals(KeyCode.ENTER)){
            onButtonClick();
        }
    }

}
