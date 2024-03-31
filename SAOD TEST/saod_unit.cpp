//developer Volosikova M.A.
#include <cassert>
#include "saod_unit.h"

/// Тест функций сортировки IsSortedAscending, IsSortedDescending, IsSorted
void m136::IsSortedTest()
{
	// not sorted array
	vector<float> test1		{1, 2.3, 4, 6, 3.24};

	// sorted ascending
	vector<int>	  test2		{1, 2, 3, 4, 5};

	// sorted ascending
	int			  test3[]	{1, 2, 3, 4, 5};

	// sorted descending
	float		  test4[]	{5, 4, 3, 2, 1, -4.5};

	// not sorted 
	float		  test5[]	{4, 5, 3, 2, 1, -4.5};

	// not sorted 
	int			  test6[]	{2, 1, 3, 4, 5};

	// result for MaxEl function
	int max11, max12;
	float max21, max22;

	// IsSortedAscending test
	assert(IsSortedAscending(test1, 5) == 0);
	assert(IsSortedAscending(test2, 5) == 1);
	assert(IsSortedAscending(test3, 5) == 1);
	assert(IsSortedAscending(test4, 6) == 0);
	assert(IsSortedAscending(test5, 6) == 0);
	assert(IsSortedAscending(test6, 5) == 0);

	// IsSortedDescending test
	assert(IsSortedDescending(test1, 5) == 0);
	assert(IsSortedDescending(test2, 5) == 0);
	assert(IsSortedDescending(test3, 5) == 0);
	assert(IsSortedDescending(test4, 6) == 1);
	assert(IsSortedDescending(test5, 6) == 0);
	assert(IsSortedDescending(test6, 5) == 0);

	//IsSorted test
	assert(IsSorted(test1, 5) == 0);
	assert(IsSorted(test2, 5) == 1);
	assert(IsSorted(test3, 5) == 1);
	assert(IsSorted(test4, 6) == 1);
	assert(IsSorted(test5, 6) == 0);
	assert(IsSorted(test6, 5) == 0);

	// SimpleSearch test
	assert(SimpleSearch(test3, 5, 3) == 2); // в середине
	assert(SimpleSearch<float>(test4, 6, -4.5) == 5); // в конце
	assert(SimpleSearch<float>(test5, 5, 0) == -1); // не найден
	assert(SimpleSearch<float>(test5, 5, 4) == 0); // в начале


	// BubbleSortAscending test
	BubbleSortAscending(test4, 6);
	assert(IsSortedAscending(test4, 6) == 1);
	BubbleSortAscending(test6, 5);
	assert(IsSortedAscending(test6, 5) == 1);
	BubbleSortAscending(test5, 6);
	assert(IsSortedAscending(test5, 6) == 1);
	
	// середина, начало, нет, в конце
	// BinarySearchA test
	assert(BinarySearchA(test3, 5, 3) == 2); // в середине
	assert(BinarySearchA<float>(test4, 6, 5) == 5); // в конце
	assert(BinarySearchA<float>(test5, 5, 0) == -1); // не найден
	assert(BinarySearchA<float>(test5, 5, -4.5) == 0); // в начале


	// BubbleSortDescending test
	BubbleSortDescending(test4, 6);
	assert(IsSortedDescending(test4, 6) == 1);
	BubbleSortDescending(test6, 5);
	assert(IsSortedDescending(test6, 5) == 1);
	BubbleSortDescending(test5, 6);
	assert(IsSortedDescending(test5, 6) == 1);
	BubbleSortDescending(test3, 5);
	assert(IsSortedDescending(test3, 5) == 1);

	// середина, начало, нет, в конце
	// BinarySearchA test
	assert(BinarySearchD(test3, 5, 3) == 2); // в середине
	assert(BinarySearchD<float>(test4, 6, -4.5) == 5); // в конце
	assert(BinarySearchD<float>(test5, 5, 0) == -1); // не найден
	assert(BinarySearchD<float>(test5, 5, 5) == 0); // в начале
	
	// Max Element test
	MaxEl(test3, 5, max11, max12);
	assert(max11 == 5);
	assert(max12 == 4);
	MaxEl(test4, 6, max21, max22);
	assert(max21 == 5);
	assert(max22 == 4);
	MaxEl(test5, 5, max21, max22);
	assert(max21 == 5);
	assert(max22 == 4);

	// SumElemR test
	assert(SumElemR(test3, 5) == 15);
	assert(SumElemR(test4, 6) == 10.5);
	assert(SumElemR(test5, 6) == 10.5);
	assert(SumElemR(test5, 1) == 5);
	assert(SumElemR(test5, 0) == 0);
	
	// SumElemI test
	assert(SumElemI(test3, 5) == 15);
	assert(SumElemI(test4, 6) == 10.5);
	assert(SumElemI(test5, 6) == 10.5);
	assert(SumElemI(test5, 1) == 5);
	assert(SumElemI(test5, 0) == 0);
}