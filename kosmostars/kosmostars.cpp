// разработчик Волосикова М.А.
#include <iostream>
#include "space_unit.h"

int main()
{
    setlocale(LC_ALL, "Rus");

    // проверка работоспособности классов 
    test_st();
    test_pl();

    // объект абстрактного класса space_unit не может быть создан
    // space_unit object;
    // указатель на косм. объект
    space_unit * object;
    // указатель на звезду
    star* sun = new star;
    star sstar("SUUN", 40000, 4, 300, 1500);
    // объект планета
    planet mars("Mars", 3000, 4, 20000, 2000, 0, 1500, 400, sun);


    object = &sstar;  

    // методы sun, object(sstar) и mars определены по-разному
    std::cout << sun->info() << "\n\n";
    std::cout << object->info() << "\n\n";
    std::cout << sstar.info() << "\n\n"; // метод info от space_unit переопределяется для star (благодаря указателю)
    std::cout << mars.info() << "\n\n";
    
    // у класса space_unit нет метода get_color(). метод не определен, программа не скомпилируется
    //std::cout << object->get_color();

    // преодразование указателя space_unit к star
    star* testStar = dynamic_cast<star*>(object);
    if (testStar) std::cout<<testStar->get_color();
}

