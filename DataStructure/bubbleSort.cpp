#include "stdafx.h"
#include "bubbleSort.h"
using namespace std;

extern void exchange(int &A, int &B);

bubbleSort::bubbleSort(int arr[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				exchange(arr[j], arr[j + 1]);
			}
		}
	}
}


bubbleSort::~bubbleSort()
{
}