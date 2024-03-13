// developer Volosikova M.A.
package com.example.fracapp;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.text.Text;

public class HelloController {

    private Fraction MainFraction = new Fraction(1,1);

    private Fraction CalcFrac = new Fraction(1,1);

    @FXML
    private Button CalcButton;

    @FXML
    private Text ComFracText;

    @FXML
    private Text ComFracTextRes;

    @FXML
    private Text DecFracText;

    @FXML
    private Text DecFracTextRes;

    @FXML
    private Text DenText;

    @FXML
    private Text DenText1;

    @FXML
    private TextField FracDenominator;

    @FXML
    private TextField FracDenominator1;

    @FXML
    private TextField FracNumerator;

    @FXML
    private TextField FracNumerator1;

    @FXML
    private Text NumText;

    @FXML
    private Text NumText1;

    @FXML
    private Text YourFracText;

    /*SumButton method. to sum fractions*/
    public void SumOnClick() {
        // инициализация дробей для счета
        MainFraction.set_frac(Integer.parseInt(FracNumerator.getText()),Integer.parseInt(FracDenominator.getText()));
        CalcFrac.set_frac(Integer.parseInt(FracNumerator1.getText()),Integer.parseInt(FracDenominator1.getText()));

        MainFraction = MainFraction.sum(CalcFrac);

        // вывод результата
        ComFracTextRes.setText(MainFraction.get_frac());
        DecFracTextRes.setText(String.valueOf(MainFraction.get_frac_dec()));
    }

    /*SubButton method. to sub fractions*/
    public void SubOnClick() {
        // инициализация дробей для счета
        MainFraction.set_frac(Integer.parseInt(FracNumerator.getText()),Integer.parseInt(FracDenominator.getText()));
        CalcFrac.set_frac(Integer.parseInt(FracNumerator1.getText()),Integer.parseInt(FracDenominator1.getText()));

        MainFraction = MainFraction.sub(CalcFrac);

        // вывод результата
        ComFracTextRes.setText(MainFraction.get_frac());
        DecFracTextRes.setText(String.valueOf(MainFraction.get_frac_dec()));
    }

    /*MulButton method. to mul fractions*/
    public void MulOnClick() {
        // инициализация дробей для счета
        MainFraction.set_frac(Integer.parseInt(FracNumerator.getText()),Integer.parseInt(FracDenominator.getText()));
        CalcFrac.set_frac(Integer.parseInt(FracNumerator1.getText()),Integer.parseInt(FracDenominator1.getText()));

        MainFraction = MainFraction.mul(CalcFrac);

        // вывод результата
        ComFracTextRes.setText(MainFraction.get_frac());
        DecFracTextRes.setText(String.valueOf(MainFraction.get_frac_dec()));
    }

    /*DivButton method. to div fractions*/
    public void DivOnClick() {
        // инициализация дробей для счета
        MainFraction.set_frac(Integer.parseInt(FracNumerator.getText()),Integer.parseInt(FracDenominator.getText()));
        CalcFrac.set_frac(Integer.parseInt(FracNumerator1.getText()),Integer.parseInt(FracDenominator1.getText()));

        MainFraction = MainFraction.div(CalcFrac);

        // вывод результата
        ComFracTextRes.setText(MainFraction.get_frac());
        DecFracTextRes.setText(String.valueOf(MainFraction.get_frac_dec()));
    }
}


