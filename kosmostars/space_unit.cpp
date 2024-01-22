// разработчик Волосикова М.А.
#include "space_unit.h"	
#include <iostream>
#include <string>
#include <math.h>
#include <exception>
#include <cassert>
using namespace std;

/// вычислить срок жизни звезды по массе
double star_life(float mass)
{
	return pow(299792458, 2) / pow(mass, 2.5);
}

/// консчтруктор с базовыми значениями небольшого немебсного тела
space_unit::space_unit() {};



/// задать новое имя
void space_unit::set_name(string new_name)
{
	name = new_name;
}

/// задать новый вес
void space_unit::set_mass(float new_mass)
{
}

/// задать новый радиус
void space_unit::set_radius(float new_radius)
{
	if (new_radius <= 0)
		throw new exception("Invalid Argument");
	else
		radius = new_radius;
}

/// задать новую температуру
void space_unit::set_temperature(float new_temperature)
{
	temperature = new_temperature;
}

/// задать новую скорость
void space_unit::set_velocity(float new_velocity)
{
	if (new_velocity <= 0)
		throw new exception("Invalid Argument");
	else
		velocity = new_velocity;
}

/// задать новый возраст
void space_unit::set_age(float new_age)
{
	if (new_age <= 0)
		throw invalid_argument("Возраст должен быть больше 0");
	else
		age = new_age;
}

/// вернуть имя объекта
string space_unit::get_name() const
{
	return name;
}

/// вернуть вес объекта
double space_unit::get_mass() const
{
	return mass;
}

/// вернуть радиус объекта
float space_unit::get_radius() const
{
	return radius;
}

///  вернуть температуру объекта
double space_unit::get_temperature() const
{
	return temperature;
}

///  вернуть скорость объекта
double space_unit::get_velocity() const
{
	return velocity;
}

///  вернуть возраст объекта
double space_unit::get_age() const
{
	return age;
}

/// столкнуть
void space_unit::impact(space_unit* unit)
{
}

/// вывести всю информацию
string space_unit::info() const
{
}


/// конструктор с базовыми значениями звезды c примерными параметрами Солнца
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
				star_color = color::Голубой;
			else if (temperature > 200)
				star_color = color::Белый;
			else if (temperature > 30)
				star_color = color::Желтый;
			else
				star_color = color::Красный;

			if (age < star_life(get_mass()))
				status = slife::Светит;
			else
				status = slife::Погасла;
		}
}

/// задать количество планет
void star::set_planets(unsigned int new_quantity)
{
	if (new_quantity >= 0)
		planets = new_quantity;
}

void star::set_mass(float new_mass)
{
	if (new_mass <= 0)
		throw invalid_argument("Масса должнабыть больше 0");
	else
	{
		mass = new_mass;
		radius = pow(mass, 0.75);
		temperature = pow((pow(radius, 5.2) / (4 * 3.14 * pow(radius, 2) * 5.67 * pow(10, -8))), 0.25);

		if (temperature > 250)
			star_color = color::Голубой;
		else if (temperature > 200)
			star_color = color::Белый;
		else if (temperature > 30)
			star_color = color::Желтый;
		else
			star_color = color::Красный;
	}
}

/// вывести количество планет
unsigned int star::get_planets() const
{
	return planets;
}

/// вывести цвет
string star::get_color() const
{
	switch (star_color)
	{
	case color::Голубой:
		return "Голубой";
		break;
	case color::Белый:
		return "Белый";
		break;
	case color::Желтый:
		return "Желтый";
		break;
	case color::Оранжевый:
		return "Оранжевый";
		break;
	case color::Красный:
		return "Красный";
		break;
	default:
		return "Желтый";
		break;
	}
}

/// вывести статус
string star::get_status() const
{
	switch (status)
	{
	case slife::Светит:
		return "Светит";
		break;
	case slife::Погасла:
		return "Погасла";
		break;
	default:
		return "Нет даннных";
		break;
	}
}

/// состарить на нескольно млн. лет
void star::growing_up(unsigned int plus_age)
{
	age += plus_age;
	if (age < star_life(get_mass()))
		status = slife::Светит;
	else
		status = slife::Погасла;
}

/// столкнуть
void star::impact(space_unit* unit)
{
	mass += unit->get_mass();
}

/// вывести всю информацию
string star::info() const
{
	return "Имя: " + name + ". Статус: " + get_status() + ", возраст: " + to_string(age) + ", цвет: "+ get_color()+ ", планеты: " + to_string(planets) +", масса:" + to_string(mass) + ", радиус: " + to_string(get_radius()) + ", температура: " + to_string(temperature);
}


/// конструктор класса с базовыми значениями планеты без звезды и спутников
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
			type = ptype::Гигант;
		else if (mass >= 130)
			type = ptype::Планета_земного_типа;
		else type = ptype::Карликовая_планета;

	}

}
/// задать количество спутников
void planet::set_satellites(unsigned int new_quantity)
{
	if (new_quantity < 0)
		throw new exception("Invalid Argument");
	else
		satellites = new_quantity;
}

/// задать расстояние до звезды
void planet::set_distance(float new_distance)
{
	if (new_distance < 0)
		throw new exception("Invalid Argument");
	else
		distance = new_distance;
}

/// задать принадлежность к звезде
void planet::set_star(star* new_belonging)
{
	belonging = new_belonging;
}

/// вывести количество спутников
unsigned int planet::get_satellites() const
{
	return satellites;
}

/// вывести трасстояние до звезды
double planet::get_distance()const
{
	return distance;
}

/// вывести объект звезда, к которой принадлежит планета
star planet::get_star()const
{
	return *belonging;
}

/// вывести тип планеты
string planet::get_type()const
{
	switch (type)
	{
	case ptype::Гигант:
		return "Гигант";
		break;
	case ptype::Планета_земного_типа:
		return "Планета земного типа";
		break;
	case ptype::Карликовая_планета:
		return "Карликовая планета";
		break;
	default:
		return "Планета";
		break;
	}
}

/// землетрясение землетрясёт
string planet::earthquake()
{
	return "Это было потрясно";
}

/// столкнуть объекты
void planet::impact(space_unit* unit)
{
	if (unit->get_mass() > (0.3 * mass))
		mass += 0.2 * unit->get_mass();
	else
		mass += unit->get_mass();

	if (mass >= 40000)
		type = ptype::Гигант;
	else if (mass >= 130)
		type = ptype::Планета_земного_типа;
	else type = ptype::Карликовая_планета;
}

/// вывести всю информацию
std::string planet::info() const
{
	string belongings;
	if (belonging == nullptr)
		belongings = "нет";
	else
		belongings = belonging->get_name();
	return "Имя: " + name + ", Принадлежность: " + belongings + ", спутники: " + to_string(satellites) + ", тип: " + get_type()+ ", расстояние до звезды: "+ to_string(distance)+", возраст: " + to_string(age) + ", масса: " + to_string(mass) + ", радиус: " + to_string(radius) + ", температура: " + to_string(temperature);

}

/// тест работы класса star
void test_st()
{
	setlocale(LC_ALL, "Rus");
	// объект звезда
	star test("Star", 300000, 4, 30000, 400);
	planet* fall = new planet("kamikazze", 300);
	// тест функции, вычисляющей срок жизни звезды
	assert(star_life(300000) >= 1823.2166);
	assert(star_life(15000) >=  3.26);
	assert(star_life(500000) >= 508.4127);
	// тест методов
	assert(test.get_name() == "Star");
	assert(test.get_age() == 400);
	assert(test.get_mass() == 300000);
	assert(test.get_color() == "Голубой");
	assert(test.get_velocity() == 30000);
	assert(test.get_status() == "Светит");
	assert(test.get_temperature() >= 66547.17187);
	assert(test.get_planets() == 4);
	assert(test.get_radius() >= 12818.61035);
	assert(test.info() == "Имя: Star. Статус: Светит, возраст: 400,000000, цвет: Голубой, планеты: 4, масса:300000,000000, радиус: 12818,610352, температура: 66547,171875");

	// новые значения для теста
	test.set_mass(50000);
	test.set_name("sstr");
	test.set_velocity(15000);
	test.set_planets(6);
	test.growing_up(1000000);

	// второй тест
	assert(test.get_name() == "sstr");
	assert(test.get_age() == 1000400);
	assert(test.get_mass() == 50000);
	assert(test.get_color() == "Голубой");
	assert(test.get_velocity() == 15000);
	assert(test.get_status() == "Погасла");
	assert(test.get_planets() == 6);
	assert(test.get_radius() >= 3343.701416);

	// третий тест для методов вычислениями
	test.set_mass(500000);
	assert(test.get_mass() == 500000);
	assert(test.get_color() == "Голубой");
	assert(test.get_radius() >= 18803.01562);

	test.impact(fall);
	assert(test.get_mass() == 500300);
	test.impact(fall);
	assert(test.get_mass() == 500600);
	test.impact(fall);
	assert(test.get_mass() == 500900);
	

}

/// тест работы класса planet
void test_pl()
{
	setlocale(LC_ALL, "Rus");
	// объект планета
	star* ftest = new star;
	planet test("plan", 3000, 4, 20000, 2000, 0, 1500, 400);
	planet* fall = new planet("kamikazze", 300);
	test.impact(fall);
	// тест методов
	assert(test.get_name() == "plan");
	assert(test.get_age() == 400);
	assert(test.get_mass() == 3300);
	assert(test.get_velocity() == 1500);
	assert(test.get_type() == "Планета земного типа");
	assert(test.get_temperature() >= 0);
	assert(test.get_satellites() == 4);
	assert(test.get_distance() == 20000);
	assert(test.get_radius() >= 2000);
	assert(test.info() == "Имя: plan, Принадлежность: нет, спутники: 4, тип: Планета земного типа, расстояние до звезды: 20000,000000, возраст: 400,000000, масса: 3300,000000, радиус: 2000,000000, температура: 0,000000");

	// новые значения для теста
	test.set_mass(50000);
	test.set_satellites(34);
	test.impact(fall);
	cout << test.get_mass();
	assert(test.get_mass() == 50300);
	assert(test.get_type() == "Гигант");
	assert(test.get_satellites() == 34);
	// последний тест методов с вычислениями
	test.set_mass(500000);
	fall->set_mass(300000);
	test.impact(fall);
	assert(test.get_mass() == 560000);
	assert(test.get_type() == "Гигант");
}