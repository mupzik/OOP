#pragma once
#include <string>

// ���������� ����� ��������
int NOD(int a, int b);

// ����� "�����
class fraction
{
private:
	// ��������� � �����������
	int num, den;
public:
	// �����������, ��������� �������� 1/1
	fraction(int nnum = 1, int dden = 1);

	// ������ ���������
	void set_num(int new_num);

	// ������ �����������
	void set_den(int new_den);

	// ������ �����
	void set_frac(int new_num, int new_den);

	// ������� ���������
	int get_num() const;

	// ������� �����������
	int get_den() const;

	// ������� �����
	float get_frac() const;

	// �������� �������� ������
	fraction operator + (const fraction& sum_frac) const;

	// �������� �������� ������
	fraction operator - (const fraction& sum_frac) const;

	// �������� ������������
	fraction operator * (const fraction& mul_frac) const;

	// �������� �������
	fraction operator / (const fraction& div_frac) const;

	// �������� ������������
	fraction operator = (const fraction& div_frac) const;

	// �������� ���������
	bool operator == (const fraction& div_frac) const;

	// �������� ��������� �����
	void reduce();

	//�������� ��������� � ������
	std::string to_string();
};


