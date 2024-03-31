//developer Volosikova M.A.
#pragma once
#include <vector>
#include <fstream>
#include <string>
#include <exception>
using namespace std;
/// ������������ ���� ��� ������� ��� ������� 136(�)
namespace m136 {
	/// ���������� ������� ������� � ��������� [a,b], n - ������ ������������������
	template <typename T>
	void Fill(vector<T>& posl, size_t n, T a = -100, T b = 100)

	{
		// ������� ������ ������� �������
		posl.resize(n);
		for (size_t i = 0; i < n; i++)
		{
			//���������� ������� �������
			posl[i] = (T)rand() / RAND_MAX * a + b;
		}
	}


	/// ���������� ������� ������� � ��������� [a,b], n - ������ ������������������, T - ��������� ��� ������
	template <typename T>
	void Fill(T* arr, size_t size, T a = -100, T b = 100)
	{
		T diap = b - a;				// �������� �������
		for (unsigned i = 0; i < size; i++) // ���� ��� ����� ����������
		{
			arr[i] = (float)rand() / RAND_MAX * diap + a; // ���������� �������
			// RAND_MAX - ��������� ���������� � ����������� cstdlib.  �������������, ��� ��� �������� �� ����� 32767
		}
	}

	/// ���������� ������� ������� � ���������, n - ������ ������������������, T - ��������� ��� ������
	template <typename T>
	void SFill(T* arr, size_t size)
	{				
		for (size_t i = 0; i<size; i++) // ���� ��� ����� ����������
		{
			arr[i] = i;
			// RAND_MAX - ��������� ���������� � ����������� cstdlib.  �������������, ��� ��� �������� �� ����� 32767
		}
	}

	/// �������� � ���� ������, Fnamee - , posl - ������ �� ������ � �������������������
	template <typename T>
	void FiWritee(const string& Fnamee, const vector<T>& posl)
	{
		// �������� �����
		ofstream filef;
		filef.open(Fnamee);
		// �������� �������� �����
		if (!filef.is_open())
			throw std::invalid_argument("���� �� ����� ���� ������");
		// �������� ������������� ������������������
		else if (posl.size() == 0)
		{
			// �������� �����
			filef.close();
			throw std::invalid_argument("������������������ �� ����� ���� �������� � ����");
		}
		// ������ � ����
		else for (size_t i = 0; i < posl.size(); i++) {
			filef << posl[i] << "\n";
		}
		// �������� �����
		filef.close();
	}

	///�������� � ���� ������
	/// �������� � ����, Fnamee - ��� �����, posl - ��������� �� ������ � �������������������, n - ������ ������������������
	template <typename T>
	void FiWritee(const string& Fnamee, const T* posl, size_t n)
	{
		// �������� �����
		ofstream filef;
		filef.open(Fnamee);
		// �������� �������� �����
		if (!filef.is_open())
			throw std::invalid_argument("���� �� ����� ���� ������");
		// �������� ������������� ������������������
		else if ((n < 1) or (posl == nullptr))
		{
			// �������� �����
			filef.close();
			throw std::invalid_argument("������������������ �� ����� ���� �������� � ����");
		}
		// ������ � ����
		else for (size_t i = 0; i < n; i++) {
			filef << posl[i] << "\n";
		}
		// �������� �����
		filef.close();
	}


	///�������� ������� posl �� ����� file_name
	template <typename T>
	void FiRead(const string& file_name, vector<T>& posl)
	{
		// �������� ����� �� ������
		ifstream file;
		file.open(file_name);
		// �������� �������� �����
		if (!file.is_open())
			throw std::invalid_argument("���� �� ����� ���� ������");
		//������ ������������������ � �����
		else
		{
			//ch ��� ������ ������, numb ��� �������� ����������� ����� � �����
			string ch;
			int numb;
			int i = 0;
			// ������ ������������������, ����������� � ����� ������� ������� ������ ��������
			while (!file.eof())
			{
				i++;
				file >> ch;
				numb = stof(ch);
				posl.push_back(numb);

			}
		}
		// �������� �����
		file.close();
	}

	///��������, ������������ �� ������ �� �����������
	///posl - ��������� �� ������ � �������������������, n - ������ ������������������
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

	///��������, ������������ �� ������ �� �����������
    ///posl - ������ �� ������ � �������������������, n - ������ ������������������
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


	///��������, ������������ �� ������ �� ��������
	///posl - ��������� �� ������ � �������������������, n - ������ ������������������
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

	///��������, ������������ �� ������ �� ��������
	///posl - ������ �� ������ � �������������������, n - ������ ������������������
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


	///��������, ������������ �� ������
	///posl - ��������� �� ������ � �������������������, n - ������ ������������������
	template <typename T>
	bool IsSorted(const T* posl, const size_t n)
	{
		return IsSortedAscending(posl, n) + IsSortedDescending(posl, n);
	}

	///��������, ������������ �� ������ �� ��������
	///posl - ������ �� ������ � �������������������, n - ������ ������������������
	template <typename T>
	bool IsSorted(vector<T>& posl, const size_t n)
	{
		return IsSortedAscending(posl, n) + IsSortedDescending(posl, n);
	}

	///���������� ������� �� �����������
	///posl - ��������� �� ������ � �������������������, n - ������ ������������������
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

	///���������� ������� �� ��������
	///posl - ��������� �� ������ � �������������������, n - ������ ������������������
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
	/// �������� ����� �������� � �������, ���������� ������ ��������, -1, ���� ������� �� ������
	/// �������� ����� �������� � ������� 
	/// posl - ��������� �� ������ � �������������������, n - ������ ������������������, elem - ������� �������
	template <typename T>
	long long SimpleSearch(T* posl, const size_t n, T elem)
	{
		// ������� ��������� �������
		for (size_t i = 0; i < n; i++)
			if (posl[i] == elem)
				return i;
		
		return -1;

	}

	/// Best - O(1), Worst - O(lod(n)), - Mid O(lod(n))
	/// �������� ����� �������� � ��������������� �� ����������� �������, ���������� ������ ��������, -1, ���� ������� �� ������ O(log(n))
	/// posl - ��������� �� ������ � �������������������, n - ������ ������������������, elem - ������� �������
	template <typename T>
	long long BinarySearchA(T* posl, const size_t n, T key)
	{
			size_t l = 0; // ����� ������� 
			size_t r = n; // ������ �������
			size_t mid;   // ��������

			while (l < r) {
				mid = (l + r) / 2; // ��������� ��������� ������ ������� [l,r]

				if (posl[mid] > key) r = mid; // ���������, ����� ����� ����� ��������� � ������
				else l = mid + 1;
			}

			r--; // ��������� �� ���� 

			if (posl[r] == key)
				return r;
			else return -1;
	}

	/// Best - O(1), Worst - O(lod(n)), - Mid O(lod(n))
	/// �������� ����� �������� � ��������������� �� �������� �������, ���������� ������ ��������, -1, ���� ������� �� ������
	/// posl - ��������� �� ������ � �������������������, n - ������ ������������������, elem - ������� �������
	template <typename T>
	long long BinarySearchD(T* posl, const size_t n, T key)
	{
		size_t l = 0; // ����� ������� 
		size_t r = n; // ������ �������
		size_t mid;   // ��������

		while (l < r) {
			mid = (l + r) / 2; // ��������� ��������� ������ ������� [l,r]

			if (posl[mid] < key) r = mid; // ���������, ����� ����� ����� ��������� � ������
			else l = mid + 1;
		}

		r--; // ��������� �� ���� 

		if (posl[r] == key)
			return r;
		else return -1;
	}

	/// ������ ������ - O(n), ������� - O(n), ������ - O(n), ���������� ��������� <= 2n
	/// ������� ��� ������������ �����, ���������� ���������� ���������
	template <typename T>
	size_t MaxEl(T* posl, const size_t n, T& max1, T& max2)
	{
		// ������� ���������, ������������� ��� ����������
		size_t k = 0;
		max1 = posl[1];
		max2 = posl[2];
		// ��������� �� ����� �������
		for (size_t i = 0; i < n; i++)
		{
			// ��������� ��� �������������
			k++;
			if (posl[i] > max1)
			{
				max2 = max1;
				max1 = posl[i];
			}
			// ��������� ��� ������� �����
			else 
			{
				k++;
				if (posl[i] > max2)
					max2 = posl[i];
			}
		}
		return k;
	}


	/// ����� ����������� MaxEl
/// �������� � ����, Fnamee - ��� �����, posl - ��������� �� ������ � �������������������, n - ������ ������������������
	template <typename T>
	void FiWriteeMaxEl(const string& Fnamee, T* posl, size_t n)
	{
		// �������� �����
		ofstream filef;
		filef.open(Fnamee);
		// �������� �������� �����
		if (!filef.is_open())
			throw std::invalid_argument("���� �� ����� ���� ������");
		// �������� ������������� ������������������
		else if ((n < 1) or (posl == nullptr))
		{
			// �������� �����
			filef.close();
			throw std::invalid_argument("������������������ �� ����� ���� �������� � ����");
		}
		// ������ � ����
		else
		{
			T max1 = 0, max2 = 0;
			int k = MaxEl<T>(posl, n, max1, max2);
			filef << "max1 = " << max1 << "\tmax2 = " << max2 << "\t������������: " << max1 * max2 << "\t���������� ��������: " << k << "\n������:\n";
			for (size_t i = 0; i < n; i++) {
				filef << posl[i] << "\n";
			}
		}
		// �������� �����
		filef.close();
	}


	/// ����� ��������� ����������� ������� ���������
	/// posl - ��������� �� ������, n - ������ �������
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
	
	/// ����� ��������� ����������� ������� ����������
	/// posl - ��������� �� ������, n - ������ �������
	template <typename T>
	T SumElemI(T* posl, size_t n)
	{
		T sum = 0;
		for (size_t i = 0; i < n; i++)
			sum += posl[i];
		return sum;
	}

	/// ������� ���������� ��� ������� ��� ���������� ��������
	/// ������ ��������� arr[begin..mid]
	/// ������ ��������� arr[mid+1..end]
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



	/// posl - ��������� �� ������, n - ������ �������
	/// a - ����������� ������, ��� ����� ������� lb, ������ ������� ub (n - 1)
	/// ���������� ��������
	template <class T>
	void mergeSort(T* posl, size_t lb, size_t ub) {
		size_t split;                   // ������, �� �������� ����� ������
		if (lb < ub) {                // ���� ���� ����� 1 ��������
			split = (lb + ub) / 2;

			mergeSort(posl, lb, split);       // ����������� ����� �������� 
			mergeSort(posl, split + 1, ub);   // ����������� ������ �������� 
			merge(posl, lb, split, ub);       // ����� ���������� � ����� ������
		}
	}

	/// ������� ���������� ��� ������� ����������
	/// posl - ������, start - ������ �������, end - ����� �������
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

	/// ������� ����������
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




	/// ���� ������� ���������� IsSorted, IsSortedDescending, IsSortedAscending
	void IsSortedTest();
}