#pragma once
#include "vector"
#include "limits"
#include "typeinfo"
/*
	Name¡G	Merge Sort
	Author: Sizeblesnail
	Created Date: Aug 2018
*/

template<typename T>
class mergeSort
{
private:
	//The maximum value as an endpoint indicator
	int max;

	//iterate the left side of sub array
	int left_indicator;

	//iterate the right side of sub array
	int right_indicator;

public:
	//Input a vector with certain type and the length of a array, then start sorting by comparision of binary division of a vector
	mergeSort(std::vector<T>& arr, int leng);

	//destruction of mergeSort object
	~mergeSort();

protected:
	//successively splite a vector into 2 sub vector
	void splitarr(std::vector<T>& arr, int start, int end);

	//rearrange two arraies into one array by ascending order
	void Sorting(std::vector<T>& arr, int start, int middle, int end);
};

template<typename T>
inline mergeSort<T>::mergeSort(std::vector<T>& arr, int leng)
{
	//configue the maximum value based on its type
	max = std::numeric_limits<T>::max();

	//start to binarily split the vector
	splitarr(arr, 0, leng-1);
}

template<typename T>
mergeSort<T>::~mergeSort()
{
}

template<typename T>
inline void mergeSort<T>::splitarr(std::vector<T>& arr, int start, int end)
{
	if ( (end - start) >=1 )
	{
		//find the middle position
		int middle = (start + end) / 2;

		//recursively calling itself, and split a vector into two subunits
		splitarr(arr, start, middle);
		splitarr(arr, middle + 1, end);

		//aneal two subunits into a vector, and sort it by ascending degree
		Sorting(arr, start, middle, end);
	}
}

template<typename T>
inline void mergeSort<T>::Sorting(std::vector<T>& arr, int start, int middle, int end)
{
	//split a vector into left and right parts, copy them into two new vectors
	std::vector<T>leftarr(arr.begin()+start, arr.begin()+middle+1);
	std::vector<T>rightarr(arr.begin()+middle+1, arr.begin()+end+1);

	//append a maximum value as an endpoint indicator
	leftarr.insert(leftarr.end(), max);
	rightarr.insert(rightarr.end(), max);

	//default the pointer of the left and right part
	left_indicator = 0;
	right_indicator = 0;

	for (int i = start; i <= end; i++)
	{
		//compare the left and right side, and copy the smaller value into a vector
		if (leftarr[left_indicator] <= rightarr[right_indicator])
		{
			arr[i] = leftarr[left_indicator];
			left_indicator++;
		}
		else
		{
			arr[i] = rightarr[right_indicator];
			right_indicator++;
		}
	}
}
