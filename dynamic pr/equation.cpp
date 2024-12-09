/// разработчик Волосикова М.А.
#include <string>
#include <cassert>

using namespace std;

/// Функция для проверки уравнения вида A+B=C,
/// используется в рекурсивной функции solveEquation
/// equation - строка c с уравнением
bool isCorrectEquation(const string &equation)
{
    // находим расположение плюса в строке
    size_t plus = equation.find('+');
    size_t equal = equation.find('=');

    // преобразуем string to integer::
    // выделяем подстроку .substr(откуда, сколько символов шагать):
    // от начала строки до плюса (первое число)
    size_t A = stoi(equation.substr(0, plus));

    // от плюса до равно
    size_t B = stoi(equation.substr(plus + 1, equal - plus - 1));

    // от равно и дальше
    size_t C = stoi(equation.substr(equal + 1));

    // вернет true, если алгоритм нашел решение и вернет false если нет
    return A + B == C;
}

/// Функция для решения задачи "Уравнения с пропущенными цифрами" вида A+B=C, 
/// Пример входного файла ??2?4+9?=355 Пример выходного файла 00264+91=355
/// equation - строка ввода, index - начальный индекс строки, необходим для рекурсивности
void solveEquation(string &equation, int index, string &result)
{
    // если индекс уже совпадает с кол-вом символов в уравнении
    if (index == equation.size())
    {
        // и уравнение получилось решить
        if (isCorrectEquation(equation))
        {
            // возращаем его
            result = equation;
        }
        // если нет, то возращаем строку о невозможности решения
        if (result == "")
        {
            result = "Can't solve the equation.";
        }

        return;
    }

    // если в строке уравнения по индексу нашли вопрос
    if (equation[index] == '?')
    {
        // запускаем цикл поиска подходящей цифры от 0 до 10
        for (int digit = 0; digit <= 9; ++digit)
        {
            // подставляем цифру
            equation[index] = digit + '0'; // перевод int to char

            // после замены начинаем рекурсию, чтобы менять вопросики в уравнении дальше
            solveEquation(equation, index + 1, result);
        }
        equation[index] = '?'; // восстанавливаем исходное значение
    }
    else
    {
        // если не нашли, то двигаемся дальше
        solveEquation(equation, index + 1, result);
    }
}

/// Функция проверки solveEquation
void solveEquation_test()
{
    string *a = new string[5]{"96??+1??=97??", "1234??+234500=?2580?",
                              "76543210+1?=765432??", "1238+98??=11081", "6666+6666=13332"};
    string *a_ = new string[5]{"9699+100=9799",
                              "Can't solve the equation. I can solve only this type: 'A+B=C'",
                              "76543210+19=76543229","1238+9843=11081", "6666+6666=13332"};
    for (int i = 0; i < 4; i++) {
        string *a_to = new string[5];
        solveEquation(a[i], 0, a_to[i]);
        assert(a_[i]==a_to[i]);
    }
}