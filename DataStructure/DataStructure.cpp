// DataStructure.cpp: 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include "iostream"
#include "stdio.h"
#include "heapMap.h"
#include "CircularLinkedList.h"
#include "SingleLinkedList.h"
#include "DoubleLinkedList.h"
//#include "BinarySearchTree.h"
#include "mergeSort.h"
#include "insertionSort.h"
#include "bubbleSort.h"
//#include "interchangeAandB.h"
#include <vector>

using namespace std;


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


int main ()
{
	int arr[] = {0,8,3,2,4};
	int bubble[] = {5,8,6,9,13,1,2,7};
	int merge[] = {2,4,5,7,1,2,3,6};
	int sort[8] = {50,100,20,1,3,56,42,78};
	long sortln[6] = {1456748,2233,89842,401232,846548,567808};
	vector<long> mergarr;

	/*insertion sort Demo*/
	insertionSort<int>insert(arr, 5);
	cout << "insertion sorting: ";
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	/*Bubble Sort Demo*/
	bubbleSort<int>bubb(bubble, 8);
	cout << "bubble sorting: ";
	for (int i = 0; i < 8; i++)
	{
		cout << bubble[i] << " ";
	}
	cout << endl;

	/*Heap Sort Demo*/
	heapMap<int>hea(merge,8);
	cout << "Tranform array into heap map: ";
	for (int i = 0; i < 8; i++)
	{
		cout << merge[i] << " ";
	}
	hea.headSort(merge, 8);
	cout << endl <<"heap sorting: ";
	for (int i = 0; i < 8; i++)
	{
		cout << merge[i] << " ";
	}
	cout << endl;

	/*Merge Sorting Demo*/
	mergarr.assign(sortln, sortln+6);
	
	/*mergeSort<int>mer(newmerge, sort, 8);*/
	cout << "Merge Sorting: ";
	mergeSort<long>(mergarr, 6);
	for (int i = 0; i < 6; i++)
	{
		cout << mergarr[i] << " ";
	}
	cout << endl;

	/*Linked List Demo*/
	int i;
	cout << "The Demo of a single-linked structure. " << endl;
	SingleLinkedList<int>* tail = new SingleLinkedList<int>(1);
	//tail->head = NULL;
	for (int i = 1; i < 5; i++)
	{
		tail->append(i);
		//tail->next->head = tail;
		/*tail = tail->at() ;
		tail->at(nullptr);*/
	}

	while (tail != nullptr)
	{
		printf("%d和記憶體位置：%p、子位置：%p \n", tail->GetValues(), tail, tail->GetNode(0));
		tail = tail->GetNode(0);
	}

	/*Double Linked Demo*/
	cout << endl << "The Demo of a double-linked structure." << endl;
	DoubleLinkedList<int>* duo = new DoubleLinkedList<int>(0);

	for (int i = 0; i < 5; i++)
	{
		duo->append(i);
	}

	while (duo != nullptr)
	{
		printf("%d和記憶體位置：%p、孩子:%p、父親:%p \n", duo->GetValues(), duo, duo->GetNode(0), duo->GetNode(1));
		duo = duo->GetNode(0);
	}
	/*Circle Linked Demo*/
	cout << endl << "The Demo of a circular link structure." << endl;
	CircularLinkedList<int>* cir = new CircularLinkedList<int>(10);
	/*CircularLinkedList<int>* compare = cir;*/

	for (int i = 11; i < 15; i++)
	{
		cir->append(i);
	}

	/*for (cir->GetNode(0) != cir->begin())
	{
		printf("%d locate at %p, its child is %p, and its parent is %p. \n", cir->GetValues(), cir, cir->GetNode(0), cir->GetNode(1));
		cir = cir->GetNode(0);
	}*/

	do
	{
		printf("%d locate at %p, its child is %p, and its parent is %p. \n", cir->GetValues(), cir, cir->GetNode(0), cir->GetNode(1));
		cir = cir->GetNode(0);
	} while (cir != cir->begin());
	///*Binary Search Tree Demo*/
	//BinarySearchTree* node5 = new BinarySearchTree(20);
	//BinarySearchTree* node4 = new BinarySearchTree(10);
	//BinarySearchTree* node3 = new BinarySearchTree(15);
	//BinarySearchTree* node6 = new BinarySearchTree(30);
	//BinarySearchTree* node7 = new BinarySearchTree(40);

	//node5->root = node5;
	//node5->insert(node3);
	//node5->insert(node4);
	//node5->insert(node6);
	//node5->insert(node7);


	//printf("node3是%p、node4是%p、node6是%p、node7是%p\n", node3, node4,node6,node7);
	//printf("node5(%p)的左兒子:%p、右兒子：%p、老爸是%p \n", node5, node5->left(), node5->right(),node5->parent());
	//printf("/n 尋找id為30的節點：%p \n", node5->search(30));
	//printf("找最小值%d的node: %p \n", node5->min()->id, node5->min());
	//printf("找最大值%d的node: %p \n", node5->max()->id, node5->max());
	//printf("node7(%p)的父節點 %p \n",node7,node7->parent());
	//printf("根為%p,其值為%d", node7->root,node7->root->id);
	//printf("node6的右兒子為%p、左兒子是%p \n",node6->right(),node6->left());

	//node5->inorderWalk();

	//printf("\n 刪除一個node4 \n");
	//node5->erase(node4);
	//node5->inorderWalk();

	system("PAUSE");
    return 0;
}


