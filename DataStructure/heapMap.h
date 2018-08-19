#pragma once
#include "interchangeAandB.h"
/*
	Name¡G	heap Mapping and Sorting
	Author: Sizeblesnail
	Created Date: Aug 2018
*/

template<typename T>
class heapMap:virtual public interchangeAandB<T>
{
private:
	//define left child of nodes in heapMap trees
	int left;

	//define right child of nodes in heaMap trees
	int right;

	//define the largest number in every node
	int largest;

public:
	//transform array into heapMap
	heapMap(T* arr, int size);

	//determinate the object
	~heapMap();

	//order the heapMap-form array by ascending power
	void headSort(T* arr, int size);

protected:
	//check the rank for the parent-child node, and rearrange the largest number as a parent
	void maxHeapify(T* arr, int size, int parent_ID);
};

template<typename T>
heapMap<T>::heapMap(T* arr, int size)
{
	for (int i = size - 1; i >= 0; i--)
	{
		maxHeapify(arr, size, i);
	}
}

template<typename T>
heapMap<T>::~heapMap()
{
}

template<typename T>
void heapMap<T>::headSort(T* arr, int size)
{
	heapMap(arr, size);

	for (int i = size - 1; i >= 0; i--)
	{
		interchangeAandB<T>::exchangevalue(arr, (arr + i));
		maxHeapify(arr, --size, 0);
	}
}

template<typename T>
void heapMap<T>::maxHeapify(T* arr, int size, int parent_ID)
{
	left = 2 * parent_ID + 1;
	right = 2 * parent_ID + 2;

	if (left < size && arr[parent_ID] < arr[left])
	{
		largest = left;
	}
	else
	{
		largest = parent_ID;
	}

	if (right < size && arr[largest] < arr[right])
	{
		largest = right;
	}

	if (largest != parent_ID)
	{
		interchangeAandB<T>::exchangevalue((arr + parent_ID), (arr + largest));
		maxHeapify(arr, size, largest);
	}
}

