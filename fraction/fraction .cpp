#include <exception>
#include <iostream>
#include "fraction.h"
#include <string>

// ���������� ����� ��������
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

// �����������, ��������� �������� 1/1
fraction::fraction(int nnum, int dden)
{
	num = nnum;
	den = dden;
}

// ������ ���������
void fraction::set_num(int new_num)
{
	num = new_num;
}

// ������ �����������
void fraction::set_den(int new_den)
{
	if (new_den == 0)
		std::cout << "���������� �����";
	else
		den = new_den;
}

// ������ �����
void fraction::set_frac(int new_num, int new_den)
{
	if (new_den == 0)
		std::cout << "���������� �����";
	else
		num = new_num;
	den = new_den;
}

// ������� ���������
int fraction::get_num() const
{
	return num;
}

// ������� �����������
int fraction::get_den() const
{
	return den;
}

// ������� �����
float fraction::get_frac() const
{
	return float(num) / float(den);
}

// �������� �������� ������
fraction fraction::operator + (const fraction& sum_frac) const
{
	fraction Result;
	Result.num = num * sum_frac.den + den * sum_frac.num;
	Result.den = den * sum_frac.den;
	return Result;
}

// ��������  ��������� ������
fraction fraction::operator - (const fraction& sum_frac) const
{
	fraction Result;
	Result.num = num * sum_frac.den - den * sum_frac.num;
	Result.den = den * sum_frac.den;
	return Result;
}

// �������� ������������
fraction fraction::operator * (const fraction& mul_frac) const
{
	fraction Result;
	Result.num = num * mul_frac.num;
	Result.den = den * mul_frac.den;
	return Result;
}

// �������� �������
fraction fraction::operator / (const fraction& div_frac) const
{
	fraction Result;
	Result.num = num * div_frac.den;
	Result.den = den * div_frac.num;
	return Result;
}

// �������� ������������
fraction fraction::operator = (const fraction& copy_frac) const
{
	fraction Result;
	Result.set_num(copy_frac.num);
	Result.set_den(copy_frac.den);
	return Result;
}

// �������� ����������
bool fraction::operator == (const fraction& eq_frac) const
{
	if (float(num) / float(den) == float(eq_frac.num) / float(eq_frac.den))
		return 1;
	else return 0;
}

// �������� ��������� �����
void fraction::reduce()
{
	int c = NOD(num, den);
	num = num / c;
	den = den / c;
}

//�������� ��������� � ������
std::string fraction::to_string()
{
	return std::to_string(float(num) / float(den));
}

