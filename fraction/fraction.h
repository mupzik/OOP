#pragma once
#include <string>

// наибольший общий делитель
int NOD(int a, int b);

// класс "дробь
class fraction
{
private:
	// числитель и знаменатель
	int num, den;
public:
	// конструктор, начальные значения 1/1
	fraction(int nnum = 1, int dden = 1);

	// задать числитель
	void set_num(int new_num);

	// задать знаменатель
	void set_den(int new_den);

	// задать дробь
	void set_frac(int new_num, int new_den);

	// вывести числитель
	int get_num() const;

	// вывести знаменатель
	int get_den() const;

	// вывести дробь
	float get_frac() const;

	// операция сложение дробей
	fraction operator + (const fraction& sum_frac) const;

	// операция сложение дробей
	fraction operator - (const fraction& sum_frac) const;

	// операция перемножение
	fraction operator * (const fraction& mul_frac) const;

	// операция деление
	fraction operator / (const fraction& div_frac) const;

	// операция присваивание
	fraction operator = (const fraction& div_frac) const;

	// операция сравнение
	bool operator == (const fraction& div_frac) const;

	// операция сократить дробь
	void reduce();

	//операция перевести в строку
	std::string to_string();
};


