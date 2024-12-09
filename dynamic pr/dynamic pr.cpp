/// разработчик Волосикова М.А.

#include <iostream>
#include <fstream>
#include "equation.h"
using namespace std;

// https://github.com/ivtipm/Data-structures-and-algorithms/blob/main/tasks/task_s1_dynamic_programming.md
// Задача Уравнение с пропущенными цифрами
// Задано уравнение вида A + B = C, где A, 
// B и C – неотрицательные целые числа, 
// в десятичной записи которых некоторые цифры заменены знаками вопроса (?).
// Примером такого уравнения является ?2+34=4?. 
// Требуется так подставить вместо знаков вопроса цифры, 
// чтобы это равенство стало верным, либо определить, что это невозможно.
// Входные данные Заданное уравнение содержится в первой строке входного файла. 
// Длина уравнения не превышает 80 символов. Входной файл не содержит пробелов. 
// Выходные данные В выходной файл требуется вывести верное равенство, 
// полученное из исходного уравнения заменой знаков вопроса цифрами, 
// либо сообщение «решения не существует».
// Пример входного файла ??2?4+9?=355 Пример выходного файла 00264+91=355
int main()
{
   // solveEquation_test();
    // файлы для ввода уравнения и вывода результата
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    // проверка на запуск файлов
    if (!inputFile.is_open() || !outputFile.is_open())
    {
        throw runtime_error("Error opening files.");
        return 1;
    }

    // вводим строку из input
    string equation;
    string result;
    inputFile >> equation;

    // если строка < 80 символов (по условию), решается уравнение
    if (-1 < equation.length() < 81)
    {
        solveEquation(equation, 0, result);
        // вывод в файл
        outputFile << result;
    }

    // закрыть файли
    inputFile.close();
    outputFile.close();

    cout << "Finished";
    return 0;
}
