//developer Volosikova M.A.
#include "saod_unit.h"
#include <iostream>
#include <array>
#include <iostream>
#include <chrono>
using namespace chrono;
using namespace std;
using namespace m136;

int main()
{
	// module test
	IsSortedTest();


	setlocale(LC_ALL, "Rus");
	// array size
	size_t n = 0;
	int key = 0;
	cout << "Введите количество элементов массива: " << endl;
	cin >> n;
	// dynamically creating an array of size n
	double* test_mas = new double [n];
	cout << "Fill time:\t Sort:\t IsSorted:  \t\n";

	// count for  Fill function
	// start time point
	auto t0 = steady_clock::now();
	for (int i = 0; i < 101; i++)
	{
		Fill<double>(test_mas, n, -1000, 1000);
	}
	// finish time point
	auto t1 = steady_clock::now();
	// console output
	cout << duration_cast<milliseconds>(t1 - t0).count()/100 << "\t\t ";



	// ПОИСК

	//cout << "Введите искомое число: " << endl;
	//cin >> key;
	//// count for SimplpeSearch function
	//// start time point
	//t0 = steady_clock::now();
	//for (int i = 0; i < 101; i++)
	//{
	//	SimpleSearch<double>(test_mas, n, key);
	//}
	//// finish time point
	//t1 = steady_clock::now();
	//// console output
	//cout << (t1 - t0).count() / 100 << "\t\t ";

	//МАКС. ЭЛЕМЕНТ
	
	//double max1, max2;
	//cout << "\nMaxEl:\n";
	//// count for IsSorted function
	//// start time point
	//t0 = steady_clock::now();
	//size_t k = 0;
	//for (int i = 0; i < 101; i++)
	//{
	//	k = MaxEl(test_mas, n, max1, max2);
	//}
	//// finish time point
	//t1 = steady_clock::now();
	//// console output
	//cout << (t1 - t0).count()/100 << endl;

	//FiWriteeMaxEl("Anal", test_mas, n);




	delete[] test_mas;
}