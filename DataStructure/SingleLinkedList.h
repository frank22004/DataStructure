#pragma once
#include "LinkedStructure.h"
#include "vector"

using namespace std;

template<typename T>
class SingleLinkedList:virtual public LinkedStructure<SingleLinkedList<T>, T >
{
private:
	//store the first node of the list
	SingleLinkedList* first;

	//store the current node
	SingleLinkedList* current;

public:
	//initialize a node containing only one postnodular address
	SingleLinkedList();

	//initialize a node with value
	SingleLinkedList(T inputvalue);

	//Call the LinkedStructure for destruction
	~SingleLinkedList();

	//add a new value
	virtual void append(T input_value);

	//SingleLinkedList(vector<T> inputvalues);
	//Reference to https://stackoverflow.com/a/32899001/9240791 
	//store the address of post node
	//void at(SingleLinkedList* nextnode);

	//retreat the address of post node
	//SingleLinkedList<T>* at() 
	//{
	//	return next[0];
	//};
};

template<typename T> 
inline SingleLinkedList<T>::SingleLinkedList():LinkedStructure<SingleLinkedList<T>, T >(1)
{
	first = nullptr;
	//at(nullptr);
	//LinkedStructure<SingleLinkedList<T>>::SetNode(nullptr, 0);
}

template<typename T>
inline SingleLinkedList<T>::SingleLinkedList(T inputvalue):LinkedStructure<SingleLinkedList<T>, T >(inputvalue,1)
{
	/*at(new SingleLinkedList<T>());
	at().value = inputvalue;*/
	//LinkedStructure<SingleLinkedList<T>, T>::SetValues(inputvalue);
	first = this;
	//at(nullptr);
	//LinkedStructure<SingleLinkedList<T>>::SetNode(nullptr, 0);
}
//
//template<typename T>
//inline SingleLinkedList<T>::SingleLinkedList(vector<T> inputvalues):LinkedStructure<SingleLinkedList<T>, T >(inputvalues,1,1)
//{
//}

template<typename T> 
SingleLinkedList<T>::~SingleLinkedList()
{
}

//template<typename T> 
//inline void SingleLinkedList<T>::at(SingleLinkedList* nextnode)
//{
//	next[0] = nextnode;
//}

//template<typename T> 
//SingleLinkedList<T>* SingleLinkedList<T>::at()
//{
//	return next[0];
//}

template<typename T>
inline void SingleLinkedList<T>::append(T input_value)
{
	SingleLinkedList* newnode = new SingleLinkedList(input_value);	

	//check which is the first node
	if (first == nullptr)
	{
		first = newnode;
		return;
	}

	//travese the link structure
	current = first;

	while (current->GetNode(0) != nullptr)
	{
		current = current->GetNode(0);
	}

	//append the node to the end of link structure
	current->SetNode(newnode, 0);
}


