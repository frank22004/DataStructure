// DataStructure.cpp: 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include "iostream"
#include "stdio.h"
#include "heapMap.h"
#include "LinkedStructure.h"
#include "SingleLinkedList.h"
#include "BinarySearchTree.h"
//#include "stack"

using namespace std;

void insertionSort(int arr[], int leng) {

	int key = 0;

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

	return;
}

void bubbleSort(int arr[], int leng) {
	int temp = 0;

	for (int i = 0; i < leng-1; i++)
	{
		for (int j = 0; j < leng-i-1; j++)
		{
			if (arr[j] > arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	return;
}

class MergeSort
{
public:
	MergeSort(int sort_arr[], int arr[], int leng);
	~MergeSort();
	void Sorting(int sort_arr[], int arr[], int start, int end);
	void Merge(int sort_arr[], int arr[], int start, int end, int middle);
private:

};

MergeSort::MergeSort(int sort_arr[], int arr[], int leng)
{
	for (int i = 0; i < leng; i++)
	{
		sort_arr[i] = arr[i];
	}

	Sorting(sort_arr,arr,0,leng-1);
}

MergeSort::~MergeSort()
{
}

void MergeSort::Sorting(int sort_arr[], int arr[], int start, int end)
{
	int middle = (start + end) / 2;

	while ((end - start) >= 2)
	{
		Sorting(sort_arr, arr, start, middle);
		Sorting(sort_arr, arr, middle + 1, end);
	}

	Merge(sort_arr, arr, start, end, middle);
}

void MergeSort::Merge(int sort_arr[], int arr[], int start, int end, int middle)
{
	for (int i = start; i <= middle; i++)
	{
		if (sort_arr[i] < sort_arr[middle + 1 + i])
		{
			arr[i] = sort_arr[i];
		}
		else {
			arr[i] = sort_arr[middle + i];
		}
	}

	MergeSort(sort_arr, arr, end - start + 1);
}

//void mergeSort(int sort_arr[],int arr[], int start, int end, int leng) {
//	int middle = (start + end) / 2;
//	
//	for (int i = 0; i < leng; i++)
//	{
//		sort_arr[i] = arr[i];
//	}s
//
//	while ((end-start) >= 1)
//	{
//		mergeSort(sort_arr, arr, start, middle, middle - start);
//		mergeSort(sort_arr, arr, middle + 1, end, end - middle);
//	}
//
//
//}
void Merge(int sort_arr[], int arr[], int start, int end, int middle)
{
	for (int i = start; i <= middle; i++)
	{
		if (sort_arr[i] < sort_arr[middle + 1 + i])
		{
			arr[i] = sort_arr[i];
		}
		else {
			arr[i] = sort_arr[middle + i];
		}
	}

	MergeSort(sort_arr, arr, end - start + 1);
}

void Sorting(int sort_arr[], int arr[], int start, int end)
{
	int middle = (start + end) / 2;

	while ((end - start) >= 2)
	{
		Sorting(sort_arr, arr, start, middle);
		Sorting(sort_arr, arr, middle + 1, end);
	}

	Merge(sort_arr, arr, start, end, middle);
}

void MergeSort(int sort_arr[], int arr[], int leng)
{
	for (int i = 0; i < leng; i++)
	{
		sort_arr[i] = arr[i];
	}

	Sorting(sort_arr, arr, 0, leng - 1);
}

//void inorder_tree_walk(BinarySearchTree* x) {
//	//recursive method
//	if (x != nullptr)
//	{
//		inorder_tree_walk(x->left());
//		printf(" %d ",x->id);
//		inorder_tree_walk(x->right());
//	}
//
//	//2 stacks method
//	stack<BinarySearchTree*>leftstack, rightstack;
//	do
//	{
//		//stacks every left children including itself
//		while (x != nullptr)
//		{
//			leftstack.push(x);
//
//			//meanwhile,it stacks the right child of a node if right child exists
//			if (x->right != nullptr)
//			{
//				rightstack.push(x->right);
//			}
//			x = x->left;
//		}
//
//		//successively pop out the left stack until it's empty or one of nodes exists right child
//		do
//		{
//			x = leftstack.top();
//			printf(" %d ", x->id);
//			leftstack.pop();
//		} while ((!leftstack.empty()) && (x->right == nullptr));
//
//		//pop out 1 right stack and relocate on its left child
//		if (!rightstack.empty())
//		{
//			x = rightstack.top();
//			printf(" %d ", x->id);
//			rightstack.pop();
//			x = x->left;
//		}
//	} while ((!leftstack.empty()) && (!rightstack.empty()));
//};


int main()
{
	int arr[] = {0,8,3,2,4};
	int bubble[] = {5,8,6,9,13,1,2,7};
	int merge[] = {2,4,5,7,1,2,3,6};
	int newmerge[8];

	/*insertionSort(arr, 5);

	for (int i = 0; i < 5; i++)
	{
		printf("%d ", arr[i]);
	}

	bubbleSort(bubble, 8);

	for (int i = 0; i < 8; i++)
	{
		printf("%d ", bubble[i]);
	}*/

	//MergeSort(newmerge, merge, 8);

	//printf("Merge Sort: ");
	//for (int i = 0; i < 8; i++)
	//{
	//	printf("%d", newmerge[i]);
	//}

	/*HeapMap Demo*/
	//heapMap heapmap(merge, 8);
	//heapmap.headSort(merge, 8);
	//for (int i = 0; i < 8; i++)
	//{
	//	printf("%d ", merge[i]);
	//}

	/*Linked List Demo*/
	int i;
	SingleLinkedList* tail = new SingleLinkedList;
	//tail->head = NULL;
	for (int i = 0; i < 5; i++)
	{
		tail->id = i;
		tail->at(new SingleLinkedList);
		printf("%d和記憶體位置：%p、子位置：%p \n", tail->id, tail, tail->at());

		//tail->next->head = tail;
		tail = tail->at() ;
		tail->at(nullptr);
	}
	
	/*Binary Search Tree Demo*/
	BinarySearchTree* node5 = new BinarySearchTree(20);
	BinarySearchTree* node4 = new BinarySearchTree(10);
	BinarySearchTree* node3 = new BinarySearchTree(15);
	BinarySearchTree* node6 = new BinarySearchTree(30);
	BinarySearchTree* node7 = new BinarySearchTree(40);

	node5->root = node5;
	node5->insert(node3);
	node5->insert(node4);
	node5->insert(node6);
	node5->insert(node7);


	printf("node3是%p、node4是%p、node6是%p、node7是%p\n", node3, node4,node6,node7);
	printf("node5(%p)的左兒子:%p、右兒子：%p、老爸是%p \n", node5, node5->left(), node5->right(),node5->parent());
	printf("/n 尋找id為30的節點：%p \n", node5->search(30));
	printf("找最小值%d的node: %p \n", node5->min()->id, node5->min());
	printf("找最大值%d的node: %p \n", node5->max()->id, node5->max());
	printf("node7(%p)的父節點 %p \n",node7,node7->parent());
	printf("根為%p,其值為%d", node7->root,node7->root->id);
	printf("node6的右兒子為%p、左兒子是%p \n",node6->right(),node6->left());

	node5->inorderWalk();

	printf("\n 刪除一個node4 \n");
	node5->erase(node4);
	node5->inorderWalk();

	system("PAUSE");
    return 0;
}


