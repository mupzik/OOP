//developer Volosikova M.A.
#pragma once
#include <vector>
#include <fstream>
#include <string>
#include <exception>
using namespace std;
/// пространство имен для функций для задания 136(м)
namespace m136 {
	/// заполнение вектора числами в диапазоне [a,b], n - размер последовательности
	template <typename T>
	void Fill(vector<T>& posl, size_t n, T a = -100, T b = 100)

	{
		// задание нового размера вектору
		posl.resize(n);
		for (size_t i = 0; i < n; i++)
		{
			//заполнение вектора числами
			posl[i] = (T)rand() / RAND_MAX * a + b;
		}
	}


	/// заполнение вектора числами в диапазоне [a,b], n - размер последовательности, T - шаблонный тип данных
	template <typename T>
	void Fill(T* arr, size_t size, T a = -100, T b = 100)
	{
		T diap = b - a;				// Диапазон рандома
		for (unsigned i = 0; i < size; i++) // Цикл для ввода заполнения
		{
			arr[i] = (float)rand() / RAND_MAX * diap + a; // заполнение массива
			// RAND_MAX - константа записанная в бибилиотеке cstdlib.  Гарантируется, что это значение не менее 32767
		}
	}

	/// заполнение вектора числами в диапазоне, n - размер последовательности, T - шаблонный тип данных
	template <typename T>
	void SFill(T* arr, size_t size)
	{				
		for (size_t i = 0; i<size; i++) // Цикл для ввода заполнения
		{
			arr[i] = i;
			// RAND_MAX - константа записанная в бибилиотеке cstdlib.  Гарантируется, что это значение не менее 32767
		}
	}

	/// записать в файл вектор, Fnamee - , posl - ссылка на вектор с последовательностью
	template <typename T>
	void FiWritee(const string& Fnamee, const vector<T>& posl)
	{
		// открытие файла
		ofstream filef;
		filef.open(Fnamee);
		// проверка открытия файла
		if (!filef.is_open())
			throw std::invalid_argument("Файл не может быть открыт");
		// проверка существования последовательности
		else if (posl.size() == 0)
		{
			// закрытие файла
			filef.close();
			throw std::invalid_argument("Последовательность не может быть записана в файл");
		}
		// запись в файл
		else for (size_t i = 0; i < posl.size(); i++) {
			filef << posl[i] << "\n";
		}
		// закрытие файла
		filef.close();
	}

	///записать в файл массив
	/// записать в файл, Fnamee - имя файла, posl - указатель на массив с последовательностью, n - размер последовательности
	template <typename T>
	void FiWritee(const string& Fnamee, const T* posl, size_t n)
	{
		// открытие файла
		ofstream filef;
		filef.open(Fnamee);
		// проверка открытия файла
		if (!filef.is_open())
			throw std::invalid_argument("Файл не может быть открыт");
		// проверка существования последовательности
		else if ((n < 1) or (posl == nullptr))
		{
			// закрытие файла
			filef.close();
			throw std::invalid_argument("Последовательность не может быть записана в файл");
		}
		// запись в файл
		else for (size_t i = 0; i < n; i++) {
			filef << posl[i] << "\n";
		}
		// закрытие файла
		filef.close();
	}


	///Загрузка вектора posl из файла file_name
	template <typename T>
	void FiRead(const string& file_name, vector<T>& posl)
	{
		// открытие файла на чтение
		ifstream file;
		file.open(file_name);
		// проверка открытия файла
		if (!file.is_open())
			throw std::invalid_argument("Файл не может быть открыт");
		//чтение последовательности с файла
		else
		{
			//ch для чтения строки, numb для перевода проччтенной строк в число
			string ch;
			int numb;
			int i = 0;
			// чтение последовательности, добавлением в конец вектора каждого нового значения
			while (!file.eof())
			{
				i++;
				file >> ch;
				numb = stof(ch);
				posl.push_back(numb);

			}
		}
		// закрытие файла
		file.close();
	}

	///Проверка, отсортирован ли массив по возрастанию
	///posl - указатель на массив с последовательностью, n - размер последовательности
	template <typename T>
	bool IsSortedAscending(const T* posl, const size_t n)
	{
		for (size_t i = 0; i < n-1; i++)
		{
			if (posl[i] <= posl[i + 1]) {}
			else
			{
				return false;
			}
		}
		return true;
	}

	///Проверка, отсортирован ли вектор по возрастанию
    ///posl - ссылка на вектор с последовательностью, n - размер последовательности
	template <typename T>
	bool IsSortedAscending(vector<T>& posl, const size_t n)
	{
		for (size_t i = 0; i < n - 1; i++)
		{
			if (posl[i] <= posl[i + 1]) {}
			else
			{
				return false;
			}
		}
		return true;
	}


	///Проверка, отсортирован ли массив по убыванию
	///posl - указатель на массив с последовательностью, n - размер последовательности
	template <typename T>
	bool IsSortedDescending(const T* posl, const size_t n)
	{
		for (size_t i = 0; i < n - 1; i++)
		{
			if (posl[i] >= posl[i + 1]) {}
			else
			{
				return false;
			}
		}
		return true;
	}

	///Проверка, отсортирован ли вектор по убыванию
	///posl - ссылка на вектор с последовательностью, n - размер последовательности
	template <typename T>
	bool IsSortedDescending(vector<T>& posl, const size_t n)
	{
		for (size_t i = 0; i < n - 1; i++)
		{
			if (posl[i] >= posl[i + 1]) {}
			else
			{
				return false;
			}
		}
		return true;
	}


	///Проверка, отсортирован ли массив
	///posl - указатель на массив с последовательностью, n - размер последовательности
	template <typename T>
	bool IsSorted(const T* posl, const size_t n)
	{
		return IsSortedAscending(posl, n) + IsSortedDescending(posl, n);
	}

	///Проверка, отсортирован ли вектор по убыванию
	///posl - ссылка на вектор с последовательностью, n - размер последовательности
	template <typename T>
	bool IsSorted(vector<T>& posl, const size_t n)
	{
		return IsSortedAscending(posl, n) + IsSortedDescending(posl, n);
	}

	///Сортировка массива по возрастанию
	///posl - указатель на массив с последовательностью, n - размер последовательности
	template <typename T>
	void BubbleSortAscending(T* posl, const size_t n)
	{
		T cur;
		while (IsSortedAscending(posl, n) != 1)
			for (size_t i = 0; i < n - 1; i++)
			{
				cur = posl[i];
				if (posl[i] > posl[i + 1])
				{
					cur = posl[i];
					posl[i] = posl[i + 1];
					posl[i + 1] = cur;
				}
			}
	}

	///Сортировка массива по убыванию
	///posl - указатель на массив с последовательностью, n - размер последовательности
	template <typename T>
	void BubbleSortDescending(T* posl, const size_t n)
	{
		T cur;
		while (IsSortedDescending(posl, n) != 1)
			for (size_t i = 0; i < n - 1; i++)
			{
				cur = posl[i];
				if (posl[i] < posl[i + 1])
				{
					cur = posl[i];
					posl[i] = posl[i + 1];
					posl[i + 1] = cur;
				}
			}
	}

	/// Best - O(1), Worst - O(n), - Mid O(n)
	/// Линейный поиск элемента в массиве, возвращает индекс элемента, -1, если элемент не найден
	/// Линейный поиск элемента в массиве 
	/// posl - указатель на массив с последовательностью, n - размер последовательности, elem - искомый елемент
	template <typename T>
	long long SimpleSearch(T* posl, const size_t n, T elem)
	{
		// перебор элементов массива
		for (size_t i = 0; i < n; i++)
			if (posl[i] == elem)
				return i;
		
		return -1;

	}

	/// Best - O(1), Worst - O(lod(n)), - Mid O(lod(n))
	/// Линейный поиск элемента в отсортированном по возрастанию массиве, возвращает индекс элемента, -1, если элемент не найден O(log(n))
	/// posl - указатель на массив с последовательностью, n - размер последовательности, elem - искомый елемент
	template <typename T>
	long long BinarySearchA(T* posl, const size_t n, T key)
	{
			size_t l = 0; // левая граница 
			size_t r = n; // правая граница
			size_t mid;   // середина

			while (l < r) {
				mid = (l + r) / 2; // считываем срединный индекс отрезка [l,r]

				if (posl[mid] > key) r = mid; // проверяем, какую часть нужно отбросить с поиска
				else l = mid + 1;
			}

			r--; // уменьшаем на один 

			if (posl[r] == key)
				return r;
			else return -1;
	}

	/// Best - O(1), Worst - O(lod(n)), - Mid O(lod(n))
	/// Линейный поиск элемента в отсортированном по убыванию массиве, возвращает индекс элемента, -1, если элемент не найден
	/// posl - указатель на массив с последовательностью, n - размер последовательности, elem - искомый елемент
	template <typename T>
	long long BinarySearchD(T* posl, const size_t n, T key)
	{
		size_t l = 0; // левая граница 
		size_t r = n; // правая граница
		size_t mid;   // середина

		while (l < r) {
			mid = (l + r) / 2; // считываем срединный индекс отрезка [l,r]

			if (posl[mid] < key) r = mid; // проверяем, какую часть нужно отбросить с поиска
			else l = mid + 1;
		}

		r--; // уменьшаем на один 

		if (posl[r] == key)
			return r;
		else return -1;
	}

	/// Лучший случай - O(n), средний - O(n), худший - O(n), количество сравнений <= 2n
	/// находит два максимальных числа, возвращает количество сравнений
	template <typename T>
	size_t MaxEl(T* posl, const size_t n, T& max1, T& max2)
	{
		// счетчик сравнений, инициализация для сравнениия
		size_t k = 0;
		max1 = posl[1];
		max2 = posl[2];
		// сравнения до конца массива
		for (size_t i = 0; i < n; i++)
		{
			// сравнение для максимального
			k++;
			if (posl[i] > max1)
			{
				max2 = max1;
				max1 = posl[i];
			}
			// сравнение для второго числа
			else 
			{
				k++;
				if (posl[i] > max2)
					max2 = posl[i];
			}
		}
		return k;
	}


	/// Вывод результатов MaxEl
/// записать в файл, Fnamee - имя файла, posl - указатель на массив с последовательностью, n - размер последовательности
	template <typename T>
	void FiWriteeMaxEl(const string& Fnamee, T* posl, size_t n)
	{
		// открытие файла
		ofstream filef;
		filef.open(Fnamee);
		// проверка открытия файла
		if (!filef.is_open())
			throw std::invalid_argument("Файл не может быть открыт");
		// проверка существования последовательности
		else if ((n < 1) or (posl == nullptr))
		{
			// закрытие файла
			filef.close();
			throw std::invalid_argument("Последовательность не может быть записана в файл");
		}
		// запись в файл
		else
		{
			T max1 = 0, max2 = 0;
			int k = MaxEl<T>(posl, n, max1, max2);
			filef << "max1 = " << max1 << "\tmax2 = " << max2 << "\tпроизведение: " << max1 * max2 << "\tКоличество операций: " << k << "\nМассив:\n";
			for (size_t i = 0; i < n; i++) {
				filef << posl[i] << "\n";
			}
		}
		// закрытие файла
		filef.close();
	}


	/// Сумма элементов одномерного массива рекурсией
	/// posl - указатель на масиив, n - размер массива
	template <typename T>
	T SumElemR(T* posl, size_t n)
	{
		if (n == 1)
			return posl[0];
		else if (n == 0)
			return 0;
		else
			return posl[n-1] + SumElemR(posl, n-1);
	}
	
	/// Сумма элементов одномерного массива итерациями
	/// posl - указатель на масиив, n - размер массива
	template <typename T>
	T SumElemI(T* posl, size_t n)
	{
		T sum = 0;
		for (size_t i = 0; i < n; i++)
			sum += posl[i];
		return sum;
	}

	/// функция объединяет два массива для сортировки слиянием
	/// первый подмассив arr[begin..mid]
	/// второй подмассив arr[mid+1..end]
	template <typename T>
	void merge(T* arr, size_t left, size_t mid, size_t right)
	{


		size_t subArrayOne = mid - left + 1,
			subArrayTwo = right - mid;
		// Create temp arrays
		T* leftArray = new T[subArrayOne],
			* rightArray = new T[subArrayTwo];

		// Copy data to temp arrays leftArray[] and rightArray[]
		for (size_t i = 0; i < subArrayOne; i++)
			leftArray[i] = arr[left + i];
		for (size_t i = 0; i < subArrayTwo; i++)
			rightArray[i] = arr[mid + 1 + i];

		size_t indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
		size_t indexOfMergedArray = left;

		// Merge the temp arrays back into array[left..right]
		while (indexOfSubArrayOne < subArrayOne
			&& indexOfSubArrayTwo < subArrayTwo) {
			if (leftArray[indexOfSubArrayOne]
				<= rightArray[indexOfSubArrayTwo]) {
				arr[indexOfMergedArray]
					= leftArray[indexOfSubArrayOne];
				indexOfSubArrayOne++;
			}
			else {
				arr[indexOfMergedArray]
					= rightArray[indexOfSubArrayTwo];
				indexOfSubArrayTwo++;
			}
			indexOfMergedArray++;
		}

		// Copy the remaining elements of
		// left[], if there are any
		while (indexOfSubArrayOne < subArrayOne) {
			arr[indexOfMergedArray]
				= leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
			indexOfMergedArray++;
		}

		// Copy the remaining elements of
		// right[], if there are any
		while (indexOfSubArrayTwo < subArrayTwo) {
			arr[indexOfMergedArray]
				= rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
			indexOfMergedArray++;
		}
		delete[] leftArray;
		delete[] rightArray;
	}



	/// posl - указатель на масиив, n - размер массива
	/// a - сортируемый массив, его левая граница lb, правая граница ub (n - 1)
	/// сортировка слиянием
	template <class T>
	void mergeSort(T* posl, size_t lb, size_t ub) {
		size_t split;                   // индекс, по которому делим массив
		if (lb < ub) {                // если есть более 1 элемента
			split = (lb + ub) / 2;

			mergeSort(posl, lb, split);       // сортировать левую половину 
			mergeSort(posl, split + 1, ub);   // сортировать правую половину 
			merge(posl, lb, split, ub);       // слить результаты в общий массив
		}
	}

	/// функция разделения для быстрой сортировки
	/// posl - массив, start - начало массива, end - конец массива
	template <typename T>
	size_t partition(T* arr, size_t start, size_t end)
	{

		T pivot = arr[start];

		size_t count = 0;
		for (size_t i = start + 1; i <= end; i++) {
			if (arr[i] < pivot)
				count++;
		}

		// Giving pivot element its correct position
		size_t pivotIndex = start + count;
		swap(arr[pivotIndex], arr[start]);

		// Sorting left and right parts of the pivot element
		size_t i = start, j = end;

		while (i < pivotIndex && j > pivotIndex) {

			while (arr[i] <= pivot) {
				i++;
			}

			while (arr[j] > pivot) {
				j--;
			}

			if (i < pivotIndex && j > pivotIndex) {
				swap(arr[i++], arr[j--]);
			}
		}

		return pivotIndex;
	}

	/// быстрая сортировка
	template <typename T>
	void quickSort(T* arr, size_t start, size_t end)
	{

		// base case
		if (start >= end)
			return;

		// partitioning the array
		size_t p = partition(arr, start, end);

		// Sorting the left part
		quickSort(arr, start, p - 1);

		// Sorting the right part
		quickSort(arr, p + 1, end);
	}




	/// Тест функций сортировки IsSorted, IsSortedDescending, IsSortedAscending
	void IsSortedTest();
}