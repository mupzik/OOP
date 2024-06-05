/** class chat bot
 * dev Volosikova M.A.*/
package com.example.chatbot;
import java.io.*;
import java.net.URL;
import java.util.ArrayList;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.URLConnection;


/** chatbot class */
public class BotMarvin implements AbsBot{

    // function pointer type
    public interface FunctionPointer {
        void methodSignature() throws IOException;
    }

    /** string for answer*/
    private String ans;

    /** string for question*/
    private String inp;

    /** reqex array */
    public String[] Reg = new String[]{"(.* )?[П,п]ривет(.*)?",
            "(?i)(.* )?который (сейчас )?час(.*)?", "(?i)(.* )?сколько (сейчас )?времени(.*)?",
            "(.* )?\\d+( )?\\+( )?\\d+(.*)?", "(.* )?[К, к]урс доллара(.*)?"};

    /** Массив ссылок на методы, соотретсвующие регулярным выражениям из массива Reg */
    public FunctionPointer[] functionPointersArray =
            new FunctionPointer[]{this::Hello, this::CurrentTime, this::CurrentTime, this::sum, this::dollar};

    /** username */
    private String username;


    /** history */
    private ArrayList<String> history;

    /** constructor with no parameters */
    public BotMarvin(){
        username = "";
        history = new ArrayList<String>();}

    /** constructor with parameters */
    public BotMarvin(String name, ArrayList<String> H){
        username = name;
        history = H;
    }

    /** get username */
    public String get_username(){
        return this.username;
    }

    /** set username */
    public void set_username(String name){
        this.username = name;
    }

    /** get history */
    public ArrayList<String> get_history(){
        return this.history;
    }

    /** set history */
    public void set_history(ArrayList<String> H){
        history =H;
    }

    /** hello answer */
    public void Hello(){
        ans = "Привет, " + this.get_username() + "! Я Марвин.";
    }

    /** get current time */
    public void CurrentTime(){
        java.time.LocalTime currentTime = java.time.LocalTime.now();
        ans = currentTime.toString().substring(0,5);
    }

    /** add stroke to history*/
    public void AddMessage(String str){
        history.add(str);
    }


    /** format stroke to add in history, type true - msg from bot, false - from user */
    public String FormatMessage(String msg, boolean type){
        java.time.LocalTime currentTime = java.time.LocalTime.now();
        String time = currentTime.toString().substring(0,5);
        if (!type){
            return time + " " + this.get_username() + ": " + msg + "\n";
        }
        else
            return time + " " + "Bot: " + msg + "\n\n";
    }

    /** save history in file */
    public void WriteToFileHistory(){
        String filename = username + ".txt"; // имя файла
        try {
            FileWriter FHistory = new FileWriter(filename); // выводимая строка
            for (String string : history) {
                FHistory.write(string);
            }
            FHistory.close();
        }
        catch (IOException err) {
            err.printStackTrace();
        }

    }

    /** display history from file */
    public void FillingFromFileHistory() {
        String fname = username + ".txt"; //имя файла
        try {
            BufferedReader reader = new BufferedReader(new FileReader(fname));
            String line = reader.readLine(); //строка, в которую считывается  текст
            while (line != null) {
                history.add(line);
                line = reader.readLine();
            }
            reader.close();
        } catch (IOException err) {
            err.printStackTrace();
        }

    }

    /** sum integer a + b */
    public void sum() {
        String text2 = inp;
        Pattern number = Pattern.compile("\\d+");
        Matcher number_matcher = number.matcher( text2 );
        if ( number_matcher.find() ){
            int a = Integer.parseInt(number_matcher.group());
            if ( number_matcher.find() ){
                int b = Integer.parseInt(number_matcher.group());
                int c = a + b;
                ans = String.valueOf(c);
            }
        }
    }


    /** dollar course information*/
    private static String downloadWebPage(String url) throws IOException {

        //StringBuilder result = new StringBuilder();
        String result = "";
        String result1 = "";
        String line;

        Pattern number = Pattern.compile("(/*)?<div class=\"fintool_button\" id=\"ft_52148\"><div class=\"content\"><div class=\"info\"><div class=\"title\"><img src=\"/img/fin_up.gif\" width=\"10\" height=\"10\" align=\"absmiddle\" />USD</div><div class=\"value\">\\d{2},\\d{4}</div>(/*)?");
        Pattern number1 = Pattern.compile("(/*)?\\d{2},\\d{4}(/*)?");
        URLConnection urlConnection = new URL(url).openConnection();

        try (InputStream is = urlConnection.getInputStream();
             BufferedReader br = new BufferedReader(new InputStreamReader(is))) {

            while ((line = br.readLine()) != null) {
                Matcher number_matcher = number.matcher(line);
                if (number_matcher.find()) {
                    result = number_matcher.group();
                    Matcher number_matcher1 = number1.matcher(result);
                    if (number_matcher1.find()) {
                        result1 = "1$ = "+ number_matcher1.group()+"Р";
                        return result1;
                    }
                }
            }
        }
        catch (IOException e) {
            e.printStackTrace();
        }

        return result1;

    }

    /** dollar course */
    public void dollar() throws IOException {
        ans = downloadWebPage("https://www.finmarket.ru/currency/rates/");
    }

    /** answer method */
    @Override public String Answer(String input) throws IOException {
        ans = "";
        inp = input;
        for (int i = 0; i < Reg.length; i++) {
            if ( input.matches(Reg[i]) ){
                functionPointersArray[i].methodSignature(); //вызов соответствующего метода
                AddMessage(FormatMessage(input, false));
                AddMessage(FormatMessage(ans, true));
                WriteToFileHistory();
                return toString();
            }
        }
        ans = "Я таких слов не знаю, попробуй еще раз";
        AddMessage(FormatMessage(input, false));
        AddMessage(FormatMessage(ans, true));
        WriteToFileHistory();
        return toString();
    }

    /** returned history in string format */
    public String toString() {
        String line = "";
        for (int i = 0; i < history.size(); i++){
            line = line + history.get(i) + "\n";
        }
        return line;
    }

}
