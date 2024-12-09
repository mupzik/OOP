#include <exception>
#include <iostream>
#include "fraction.h"
#include <string>

// наибольший общий делитель
int NOD(int a, int b)
{
	while (a != 0 and b != 0)
	{
		if (a < b)
			b %= a;
		else a %= b;
	}
	return a + b;
}

// конструктор, начальные значения 1/1
fraction::fraction(int nnum, int dden)
{
	num = nnum;
	den = dden;
}

// задать числитель
void fraction::set_num(int new_num)
{
	num = new_num;
}

// задать знаменатель
void fraction::set_den(int new_den)
{
	if (new_den == 0)
		std::cout << "Попробуйте снова";
	else
		den = new_den;
}

// задать дробь
void fraction::set_frac(int new_num, int new_den)
{
	if (new_den == 0)
		std::cout << "Попробуйте снова";
	else
		num = new_num;
	den = new_den;
}

// вывести числитель
int fraction::get_num() const
{
	return num;
}

// вывести знаменатель
int fraction::get_den() const
{
	return den;
}

// вывести дробь
float fraction::get_frac() const
{
	return float(num) / float(den);
}

// операция сложение дробей
fraction fraction::operator + (const fraction& sum_frac) const
{
	fraction Result;
	Result.num = num * sum_frac.den + den * sum_frac.num;
	Result.den = den * sum_frac.den;
	return Result;
}

// операция  вычитание дробей
fraction fraction::operator - (const fraction& sum_frac) const
{
	fraction Result;
	Result.num = num * sum_frac.den - den * sum_frac.num;
	Result.den = den * sum_frac.den;
	return Result;
}

// операция перемножение
fraction fraction::operator * (const fraction& mul_frac) const
{
	fraction Result;
	Result.num = num * mul_frac.num;
	Result.den = den * mul_frac.den;
	return Result;
}

// операция деление
fraction fraction::operator / (const fraction& div_frac) const
{
	fraction Result;
	Result.num = num * div_frac.den;
	Result.den = den * div_frac.num;
	return Result;
}

// операция присваивание
fraction fraction::operator = (const fraction& copy_frac) const
{
	fraction Result;
	Result.set_num(copy_frac.num);
	Result.set_den(copy_frac.den);
	return Result;
}

// операция сравнениие
bool fraction::operator == (const fraction& eq_frac) const
{
	if (float(num) / float(den) == float(eq_frac.num) / float(eq_frac.den))
		return 1;
	else return 0;
}

// операция сократить дробь
void fraction::reduce()
{
	int c = NOD(num, den);
	num = num / c;
	den = den / c;
}

//операция перевести в строку
std::string fraction::to_string()
{
	return std::to_string(float(num) / float(den));
}

