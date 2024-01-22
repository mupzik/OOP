// разработчик Волосикова М.А.
#pragma once
#include <string>
using namespace std;

// перечислимые типы для полей классов planet, star
enum class ptype { Гигант, Планета_земного_типа, Карликовая_планета};
enum class color { Голубой, Белый, Желтый, Оранжевый, Красный};
enum class slife { Светит, Погасла};

double star_life(float mass);

class space_unit
{
protected:
	// название тела
	std::string name;

	// масса ((x)кг*10^20)
	// радиус (тыс. км)
	// температура (К)
	// скорость (тыс. км/ч)
	// период вращения (км/ч)
	// возраст (млн. лет)
	float mass, radius, temperature, velocity, age;

public:
	/// консчтруктор с базовыми значениями небольшого немебсного тела
	space_unit();
	
	/// задать новое имя
	void set_name(std::string new_name);

	/// задать новый вес
	virtual void set_mass(float new_mass);

	/// задать новый радиус
	void set_radius(float new_radius);

	/// задать новую температуру
	void set_temperature(float new_temperature);

	/// задать новую скорость
	void set_velocity(float new_velocity);

	/// задать новый возраст
	void set_age(float new_age);

	/// вернуть имя объекта
	std::string get_name() const;

	/// вернуть вес объекта
	double get_mass() const;

	/// вернуть радиус объекта
	float get_radius() const;

	///  вернуть температуру объекта
	double get_temperature() const;

	///  вернуть скорость объекта
	double get_velocity() const;
	
	///  вернуть возраст объекта
	double get_age() const;

	/// столкнуть объекты
	virtual void impact(space_unit* unit) = 0;

	/// вывести всю информацию
	virtual std::string info() const = 0;
};


class star: public space_unit
{
protected:
	// количество планет (шт)
	// цвет звезды
	// статус (светится, погасла)
	unsigned int planets;
	color star_color;
	slife status;

public:
	/// конструктор с базовыми значениями звезды c примерными параметрами Солнца
	star(std::string UnitName = "Звезда", float mmass = 20000, unsigned int pplanets = 0, float vvelocity = 30, float aage = 100);
	
	/// задать количество планет
	void set_planets(unsigned int new_quantity);

	/// задать новую температуру
	void set_mass(float new_mass) override;
	
	/// вывести количество планет
	unsigned int get_planets() const;
	
	/// вывести цвет
	string get_color() const;
	
	/// вывести статус
	string get_status() const;
	
	/// состарить на нескольно млн. лет
	void growing_up(unsigned int plus_age);
	
	/// столкнуть
	void impact(space_unit* unit) override;
	
	/// вывести всю информацию
	string info() const override;
};



class planet : public space_unit
{
protected:
	/// количество спутников (шт)
	/// расстояние до звезды (тыс. км)
	/// тип планеты (Газ. гигант, П. земного типа, Карликовая п.)
	int satellites;
	float distance;
	star* belonging;
	ptype type;
public:
	/// конструктор класса с базовыми значениями планеты без звезды и спутников
	planet(string UnitName = "Планета", float mmass = 3000, unsigned int ssatelites = 0, float ddistance = 1000, float rradius = 5000, float ttemperature = 0, float vvelocity = 30, float aage = 100, star* bbelonging = nullptr);
	
	/// задать количество спутников
	void set_satellites(unsigned int new_quantity);

	/// задать расстояние до звезды
	void set_distance(float new_distance);

	/// задать принадлежность к звезде
	void set_star(star* new_belonging);

	/// вывести количество спутников
	unsigned int get_satellites() const;

	/// вывести трасстояние до звезды
	double get_distance()const;

	/// вывести объект звезда, к которой принадлежит планета
	star get_star()const;

	/// вывести тип планеты
	string get_type()const;

	/// землетрясение землетрясёт
	string earthquake();

	/// столкнуть объекты
	void impact(space_unit* unit) override;

	/// вывести всю информацию
	std::string info() const override;

};

/// тест работы класса star
void test_st();

/// тест работы класса planet
void test_pl();