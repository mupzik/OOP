#ifndef EQUATION_H
#define EQUATION_H

#include <string>
#include <cassert>

using namespace std;

/// Функция для проверки уравнения вида A+B=C, 
/// используется в рекурсивной функции solveEquation
/// Вернет true, если алгоритм нашел решение и вернет false если нет
/// equation - строка, где хранится уравнение
bool isCorrectEquation(const string &equation);

/// Функция для решения задачи "Уравнения с пропущенными цифрами"
/// equation - строка ввода, index - начальный индекс строки, необходим для рекрсивности
void solveEquation(string &equation, int index, string &result);

/// Функция проверки solveEquation
void solveEquation_test();


#endif