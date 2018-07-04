#pragma once
/*
	Name¡G	heapMap
	author: Sizeblesnail
*/

//exchange value of A and B, which is called by reference
extern void exchange(int &A, int &B);

class heapMap
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
	heapMap(int arr[], int size);
	~heapMap();

	//order the heapMap-form array by ascending power
	void headSort(int arr[], int size);

	//check the rank for the parent-child node, and rearrange the largest number as a parent
	void maxHeapify(int arr[], int size, int parent_ID);
};

