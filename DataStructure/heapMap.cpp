#include "stdafx.h"
#include "heapMap.h"
#include "iostream"
extern void exchange(int &A, int &B);

using namespace std;

heapMap::heapMap(int arr[], int size)
{
	for (int i = size - 1 ; i >= 0 ; i--)
	{
		maxHeapify(arr, size, i);
	}
}


heapMap::~heapMap()
{
}

void heapMap::headSort(int arr[], int size)
{
	heapMap(arr, size);

	for (int i = size - 1; i >= 0; i--)
	{
		exchange(arr[0], arr[i]);
		maxHeapify(arr, --size, 0);
	}
}

void heapMap::maxHeapify(int arr[], int size, int parent_ID)
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
		exchange(arr[parent_ID], arr[largest]);
		maxHeapify(arr, size, largest);
	}
}

//void heapMap::exchange(int &A, int &B)
//{
//	temp = A;
//	A = B;
//	B = temp;
//}
