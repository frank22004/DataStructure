#pragma once
/*
	Name¡G	Insertion Sort
	Author: Sizeblesnail
	Created Date: Aug 2018
*/

using namespace std;

template<typename T>
class insertionSort
{
private:
	//every value in the array
	T key;
public:
	//sorting array by insertion method
	insertionSort(T* arr, int leng);

	//determinate the object
	~insertionSort();
};


template<typename T> 
inline insertionSort<T>::insertionSort(T* arr, int leng)
{
	for (int i = 0; i < leng; i++)
	{
		key = arr[i];

		int j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}


template<typename T> 
inline insertionSort<T>::~insertionSort()
{
}
