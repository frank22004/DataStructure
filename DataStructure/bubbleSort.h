#pragma once
#include "interchangeAandB.h"
/*
	Name¡G	Bubble Sort
	Author: Sizeblesnail
	Created Date: Aug 2018
*/

template<typename T>
class bubbleSort:virtual public interchangeAandB<T>
{
public:
	//sorting the array by bubble sorting
	bubbleSort(T* arr, int size);

	//deconstruction of object
	~bubbleSort();
};

template<typename T>
inline bubbleSort<T>::bubbleSort(T* arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				interchangeAandB<T>::exchangevalue((arr + j), (arr + j + 1));
			}
		}
	}
}

template<typename T>
inline bubbleSort<T>::~bubbleSort()
{
}

