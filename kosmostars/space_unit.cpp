// ����������� ���������� �.�.
#include "space_unit.h"	
#include <iostream>
#include <string>
#include <math.h>
#include <exception>
#include <cassert>
using namespace std;

/// ��������� ���� ����� ������ �� �����
double star_life(float mass)
{
	return pow(299792458, 2) / pow(mass, 2.5);
}

/// ������������ � �������� ���������� ���������� ���������� ����
space_unit::space_unit() {};



/// ������ ����� ���
void space_unit::set_name(string new_name)
{
	name = new_name;
}

/// ������ ����� ���
void space_unit::set_mass(float new_mass)
{
}

/// ������ ����� ������
void space_unit::set_radius(float new_radius)
{
	if (new_radius <= 0)
		throw new exception("Invalid Argument");
	else
		radius = new_radius;
}

/// ������ ����� �����������
void space_unit::set_temperature(float new_temperature)
{
	temperature = new_temperature;
}

/// ������ ����� ��������
void space_unit::set_velocity(float new_velocity)
{
	if (new_velocity <= 0)
		throw new exception("Invalid Argument");
	else
		velocity = new_velocity;
}

/// ������ ����� �������
void space_unit::set_age(float new_age)
{
	if (new_age <= 0)
		throw invalid_argument("������� ������ ���� ������ 0");
	else
		age = new_age;
}

/// ������� ��� �������
string space_unit::get_name() const
{
	return name;
}

/// ������� ��� �������
double space_unit::get_mass() const
{
	return mass;
}

/// ������� ������ �������
float space_unit::get_radius() const
{
	return radius;
}

///  ������� ����������� �������
double space_unit::get_temperature() const
{
	return temperature;
}

///  ������� �������� �������
double space_unit::get_velocity() const
{
	return velocity;
}

///  ������� ������� �������
double space_unit::get_age() const
{
	return age;
}

/// ���������
void space_unit::impact(space_unit* unit)
{
}

/// ������� ��� ����������
string space_unit::info() const
{
}


/// ����������� � �������� ���������� ������ c ���������� ����������� ������
star::star(std::string UnitName, float mmass, unsigned int pplanets, float vvelocity, float aage)
{
		if ((mmass <= 0) or (vvelocity <= 0) or (aage <= 0))
			cout << "Invalid Argument";
		else
		{
			mass = mmass;
			radius = pow(mass, 0.75);
			temperature = pow((pow(radius, 5.2)/(4*3.14*pow(radius, 2)*5.67*pow(10, -8))), 0.25);
			velocity = vvelocity;
			planets = pplanets;
			age = aage;
			name = UnitName;
			if (temperature > 250)
				star_color = color::�������;
			else if (temperature > 200)
				star_color = color::�����;
			else if (temperature > 30)
				star_color = color::������;
			else
				star_color = color::�������;

			if (age < star_life(get_mass()))
				status = slife::������;
			else
				status = slife::�������;
		}
}

/// ������ ���������� ������
void star::set_planets(unsigned int new_quantity)
{
	if (new_quantity >= 0)
		planets = new_quantity;
}

void star::set_mass(float new_mass)
{
	if (new_mass <= 0)
		throw invalid_argument("����� ���������� ������ 0");
	else
	{
		mass = new_mass;
		radius = pow(mass, 0.75);
		temperature = pow((pow(radius, 5.2) / (4 * 3.14 * pow(radius, 2) * 5.67 * pow(10, -8))), 0.25);

		if (temperature > 250)
			star_color = color::�������;
		else if (temperature > 200)
			star_color = color::�����;
		else if (temperature > 30)
			star_color = color::������;
		else
			star_color = color::�������;
	}
}

/// ������� ���������� ������
unsigned int star::get_planets() const
{
	return planets;
}

/// ������� ����
string star::get_color() const
{
	switch (star_color)
	{
	case color::�������:
		return "�������";
		break;
	case color::�����:
		return "�����";
		break;
	case color::������:
		return "������";
		break;
	case color::���������:
		return "���������";
		break;
	case color::�������:
		return "�������";
		break;
	default:
		return "������";
		break;
	}
}

/// ������� ������
string star::get_status() const
{
	switch (status)
	{
	case slife::������:
		return "������";
		break;
	case slife::�������:
		return "�������";
		break;
	default:
		return "��� �������";
		break;
	}
}

/// ��������� �� ��������� ���. ���
void star::growing_up(unsigned int plus_age)
{
	age += plus_age;
	if (age < star_life(get_mass()))
		status = slife::������;
	else
		status = slife::�������;
}

/// ���������
void star::impact(space_unit* unit)
{
	mass += unit->get_mass();
}

/// ������� ��� ����������
string star::info() const
{
	return "���: " + name + ". ������: " + get_status() + ", �������: " + to_string(age) + ", ����: "+ get_color()+ ", �������: " + to_string(planets) +", �����:" + to_string(mass) + ", ������: " + to_string(get_radius()) + ", �����������: " + to_string(temperature);
}


/// ����������� ������ � �������� ���������� ������� ��� ������ � ���������
planet::planet(string UnitName, float mmass, unsigned int ssatelites, float ddistance, float rradius, float ttemperature, float vvelocity, float aage, star* bbelonging)
{
	if ((mmass <= 0) or (vvelocity <= 0) or (aage <= 0)or (distance <0))
		 throw new exception ("Invalid Argument");
	else
	{
		name = UnitName;
		mass = mmass;
		radius = rradius;
		temperature = ttemperature;
		velocity = vvelocity;
		age = aage;
		name = UnitName;
		belonging = bbelonging;
		distance = ddistance;
		satellites = ssatelites;

		if (mass >=40000)
			type = ptype::������;
		else if (mass >= 130)
			type = ptype::�������_�������_����;
		else type = ptype::����������_�������;

	}

}
/// ������ ���������� ���������
void planet::set_satellites(unsigned int new_quantity)
{
	if (new_quantity < 0)
		throw new exception("Invalid Argument");
	else
		satellites = new_quantity;
}

/// ������ ���������� �� ������
void planet::set_distance(float new_distance)
{
	if (new_distance < 0)
		throw new exception("Invalid Argument");
	else
		distance = new_distance;
}

/// ������ �������������� � ������
void planet::set_star(star* new_belonging)
{
	belonging = new_belonging;
}

/// ������� ���������� ���������
unsigned int planet::get_satellites() const
{
	return satellites;
}

/// ������� ����������� �� ������
double planet::get_distance()const
{
	return distance;
}

/// ������� ������ ������, � ������� ����������� �������
star planet::get_star()const
{
	return *belonging;
}

/// ������� ��� �������
string planet::get_type()const
{
	switch (type)
	{
	case ptype::������:
		return "������";
		break;
	case ptype::�������_�������_����:
		return "������� ������� ����";
		break;
	case ptype::����������_�������:
		return "���������� �������";
		break;
	default:
		return "�������";
		break;
	}
}

/// ������������� ����������
string planet::earthquake()
{
	return "��� ���� ��������";
}

/// ��������� �������
void planet::impact(space_unit* unit)
{
	if (unit->get_mass() > (0.3 * mass))
		mass += 0.2 * unit->get_mass();
	else
		mass += unit->get_mass();

	if (mass >= 40000)
		type = ptype::������;
	else if (mass >= 130)
		type = ptype::�������_�������_����;
	else type = ptype::����������_�������;
}

/// ������� ��� ����������
std::string planet::info() const
{
	string belongings;
	if (belonging == nullptr)
		belongings = "���";
	else
		belongings = belonging->get_name();
	return "���: " + name + ", ��������������: " + belongings + ", ��������: " + to_string(satellites) + ", ���: " + get_type()+ ", ���������� �� ������: "+ to_string(distance)+", �������: " + to_string(age) + ", �����: " + to_string(mass) + ", ������: " + to_string(radius) + ", �����������: " + to_string(temperature);

}

/// ���� ������ ������ star
void test_st()
{
	setlocale(LC_ALL, "Rus");
	// ������ ������
	star test("Star", 300000, 4, 30000, 400);
	planet* fall = new planet("kamikazze", 300);
	// ���� �������, ����������� ���� ����� ������
	assert(star_life(300000) >= 1823.2166);
	assert(star_life(15000) >=  3.26);
	assert(star_life(500000) >= 508.4127);
	// ���� �������
	assert(test.get_name() == "Star");
	assert(test.get_age() == 400);
	assert(test.get_mass() == 300000);
	assert(test.get_color() == "�������");
	assert(test.get_velocity() == 30000);
	assert(test.get_status() == "������");
	assert(test.get_temperature() >= 66547.17187);
	assert(test.get_planets() == 4);
	assert(test.get_radius() >= 12818.61035);
	assert(test.info() == "���: Star. ������: ������, �������: 400,000000, ����: �������, �������: 4, �����:300000,000000, ������: 12818,610352, �����������: 66547,171875");

	// ����� �������� ��� �����
	test.set_mass(50000);
	test.set_name("sstr");
	test.set_velocity(15000);
	test.set_planets(6);
	test.growing_up(1000000);

	// ������ ����
	assert(test.get_name() == "sstr");
	assert(test.get_age() == 1000400);
	assert(test.get_mass() == 50000);
	assert(test.get_color() == "�������");
	assert(test.get_velocity() == 15000);
	assert(test.get_status() == "�������");
	assert(test.get_planets() == 6);
	assert(test.get_radius() >= 3343.701416);

	// ������ ���� ��� ������� ������������
	test.set_mass(500000);
	assert(test.get_mass() == 500000);
	assert(test.get_color() == "�������");
	assert(test.get_radius() >= 18803.01562);

	test.impact(fall);
	assert(test.get_mass() == 500300);
	test.impact(fall);
	assert(test.get_mass() == 500600);
	test.impact(fall);
	assert(test.get_mass() == 500900);
	

}

/// ���� ������ ������ planet
void test_pl()
{
	setlocale(LC_ALL, "Rus");
	// ������ �������
	star* ftest = new star;
	planet test("plan", 3000, 4, 20000, 2000, 0, 1500, 400);
	planet* fall = new planet("kamikazze", 300);
	test.impact(fall);
	// ���� �������
	assert(test.get_name() == "plan");
	assert(test.get_age() == 400);
	assert(test.get_mass() == 3300);
	assert(test.get_velocity() == 1500);
	assert(test.get_type() == "������� ������� ����");
	assert(test.get_temperature() >= 0);
	assert(test.get_satellites() == 4);
	assert(test.get_distance() == 20000);
	assert(test.get_radius() >= 2000);
	assert(test.info() == "���: plan, ��������������: ���, ��������: 4, ���: ������� ������� ����, ���������� �� ������: 20000,000000, �������: 400,000000, �����: 3300,000000, ������: 2000,000000, �����������: 0,000000");

	// ����� �������� ��� �����
	test.set_mass(50000);
	test.set_satellites(34);
	test.impact(fall);
	cout << test.get_mass();
	assert(test.get_mass() == 50300);
	assert(test.get_type() == "������");
	assert(test.get_satellites() == 34);
	// ��������� ���� ������� � ������������
	test.set_mass(500000);
	fall->set_mass(300000);
	test.impact(fall);
	assert(test.get_mass() == 560000);
	assert(test.get_type() == "������");
}