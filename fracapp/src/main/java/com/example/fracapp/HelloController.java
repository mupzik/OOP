// developer Volosikova M.A.
package com.example.fracapp;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.text.Text;
/** controller class for main window*/
public class HelloController {

    /** first fraction for calc*/
    private Fraction MainFraction = new Fraction(1,1);

    /** second fraction for calc*/
    private Fraction CalcFrac = new Fraction(1,1);

    /** main button for calc*/
    @FXML
    private Button CalcButton;

    /** simple frac text*/
    @FXML
    private Text ComFracText;

    /** simple frac result text*/
    @FXML
    private Text ComFracTextRes;

    /** decimal frac text*/
    @FXML
    private Text DecFracText;

    /** decimal frac result text*/
    @FXML
    private Text DecFracTextRes;

    /** denominator text*/
    @FXML
    private Text DenText;

    /** enominator text 2*/
    @FXML
    private Text DenText1;

    /** textfield for first den*/
    @FXML
    private TextField FracDenominator;

    /** textfield for second den*/
    @FXML
    private TextField FracDenominator1;

    /** textfield for first num*/
    @FXML
    private TextField FracNumerator;


    /** textfield for second num*/
    @FXML
    private TextField FracNumerator1;

    /** frac info text*/
    @FXML
    private Text NumText;

    /** frac info text*/
    @FXML
    private Text NumText1;

    /** "Your frac:" text*/
    @FXML
    private Text YourFracText;

    /*SumButton method. to sum fractions*/
    public void SumOnClick() {
        //MainFraction.testfunc();

        // инициализация дробей для счета
        MainFraction.set_frac(Integer.parseInt(FracNumerator.getText()),Integer.parseInt(FracDenominator.getText()));
        CalcFrac.set_frac(Integer.parseInt(FracNumerator1.getText()),Integer.parseInt(FracDenominator1.getText()));

        MainFraction = MainFraction.sum(CalcFrac);

        // вывод результата
        ComFracTextRes.setText(MainFraction.toString());
        DecFracTextRes.setText(String.valueOf(MainFraction.get_frac_dec()));
    }

    /*SubButton method. to sub fractions*/
    public void SubOnClick() {

       // MainFraction.testfunc();
        // инициализация дробей для счета
        MainFraction.set_frac(Integer.parseInt(FracNumerator.getText()),Integer.parseInt(FracDenominator.getText()));
        CalcFrac.set_frac(Integer.parseInt(FracNumerator1.getText()),Integer.parseInt(FracDenominator1.getText()));

        MainFraction = MainFraction.sub(CalcFrac);

        // вывод результата
        ComFracTextRes.setText(MainFraction.toString());
        DecFracTextRes.setText(String.valueOf(MainFraction.get_frac_dec()));
    }

    /*MulButton method. to mul fractions*/
    public void MulOnClick() {

       // MainFraction.testfunc();
        // инициализация дробей для счета
        MainFraction.set_frac(Integer.parseInt(FracNumerator.getText()),Integer.parseInt(FracDenominator.getText()));
        CalcFrac.set_frac(Integer.parseInt(FracNumerator1.getText()),Integer.parseInt(FracDenominator1.getText()));

        MainFraction = MainFraction.mul(CalcFrac);

        // вывод результата
        ComFracTextRes.setText(MainFraction.toString());
        DecFracTextRes.setText(String.valueOf(MainFraction.get_frac_dec()));
    }

    /*DivButton method. to div fractions*/
    public void DivOnClick() {

       // MainFraction.testfunc();
        // инициализация дробей для счета
        MainFraction.set_frac(Integer.parseInt(FracNumerator.getText()),Integer.parseInt(FracDenominator.getText()));
        CalcFrac.set_frac(Integer.parseInt(FracNumerator1.getText()),Integer.parseInt(FracDenominator1.getText()));

        MainFraction = MainFraction.div(CalcFrac);

        // вывод результата
        ComFracTextRes.setText(MainFraction.toString());
        DecFracTextRes.setText(String.valueOf(MainFraction.get_frac_dec()));
    }
}


