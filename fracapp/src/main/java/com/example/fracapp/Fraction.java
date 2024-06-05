package com.example.fracapp;
// developer Volosikova M.A.

/** MY FRACTION CLASS*/
public class Fraction {

    /** числитель и знаменатель*/
    private int num, den;

    /** конструктор, начальные значения 1/1
     * бросает исключение, если знаменатель = 0*/
    public Fraction(int nnum, int dden) {

        if (dden == 0)
            throw new IllegalArgumentException("denominator can not be '0' ");
        else {
            set_frac(nnum, dden);
        }
    }

    /** конструктор, начальные значения 1/1 */
    public Fraction() {
        set_frac(1, 1);
    }

    /** задать числитель*/
    public void set_num(int new_num) {
        num = new_num;
    }

    /** задать знаменатель
     * бросает исключение, если знаменатель = 0 */
    public void set_den(int new_den) {
        // проверка знаменателя на 0
        if (new_den == 0)
            throw new IllegalArgumentException("denominator can not be '0'");
        else
            den = new_den;
    }

    /** задать дробь
     * бросает исключение, если знаменатель = 0 */
    public void set_frac(int new_num, int new_den) {
        set_den(new_den);
        set_num(new_num);
    }

    /** вывести числитель*/
    public int get_num() {
        return num;
    }

    /** вывести знаменатель*/
    public int get_den() {
        return den;
    }

    /** вывести десятичную дробь*/
    public float get_frac_dec() {
        return (float) num / (float) den;
    }

    @Override
    /** вывести обыкновенную дробь*/
    public String toString() {
        return Integer.toString(this.get_num()) + "/" + Integer.toString(this.get_den());
    }

    /** операция сложение дробей*/
    public Fraction sum(Fraction sum_frac) {
        Fraction Result = new Fraction();
        Result.num = num * sum_frac.den + den * sum_frac.num;
        Result.den = den * sum_frac.den;
        return Result;
    }

    /** операция  вычитание дробей*/
    public Fraction sub(Fraction sum_frac) {
        Fraction Result = new Fraction();
        Result.num = num * sum_frac.den - den * sum_frac.num;
        Result.den = den * sum_frac.den;
        return Result;
    }

    /** операция перемножение*/
    public Fraction mul(Fraction mul_frac) {
        Fraction Result = new Fraction();
        Result.num = num * mul_frac.num;
        Result.den = den * mul_frac.den;
        return Result;
    }

    /**операция деление*/
    public Fraction div(Fraction div_frac) {
        Fraction Result = new Fraction();
        Result.num = num * div_frac.den;
        Result.den = den * div_frac.num;
        return Result;
    }

    /** операция сравнениие*/
    public boolean eq(Fraction eq_frac) {
        if ((float) num / (float) den == (float) eq_frac.num / (float) eq_frac.den)
            return true;
        else return false;
    }

    /** операция сократить дробь*/
    public void reduce() {
        int c = NOD(num, den);
        num = num / c;
        den = den / c;
    }

    /** возвращает наибольший общий делитель a и b*/
    public static int NOD(int a, int b) {
        // итерация цикла присваивает большему числу остаток от деления большего на меньшее
        while (a != 0 && b != 0) {
            if (a < b)
                b %= a;
            else a %= b;
        }
        return a + b;
    }
}
