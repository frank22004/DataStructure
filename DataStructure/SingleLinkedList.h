#pragma once
#include "LinkedStructure.h"

using namespace std;

template<typename T>
class SingleLinkedList:public LinkedStructure<SingleLinkedList<T>>
{
public:
	//initialize a node containing only one postnodular address
	SingleLinkedList();

	//initialize a node with value
	SingleLinkedList(T inputvalue);

	//Call the LinkedStructure for destruction
	~SingleLinkedList();

	//the id of a node
	T value;

	//Reference to https://stackoverflow.com/a/32899001/9240791 
	//store the address of post node
	void at(SingleLinkedList* nextnode);

	//retreat the address of post node
	SingleLinkedList* at();

	//add a new node
	void append(T input_value);
};

template<typename T> SingleLinkedList<T>::SingleLinkedList():LinkedStructure(1)
{
}

template<typename T>
inline SingleLinkedList<T>::SingleLinkedList(T inputvalue):LinkedStructure(1)
{
	value = inputvalue;
}

template<typename T> 
SingleLinkedList<T>::~SingleLinkedList()
{
}

template<typename T> 
inline void SingleLinkedList<T>::at(SingleLinkedList* nextnode)
{
	next[0] = nextnode;
}

template<typename T> 
inline SingleLinkedList<T>* SingleLinkedList<T>::at()
{
	return next[0];
}

template<typename T>
inline void SingleLinkedList<T>::append(T input_value)
{
	SingleLinkedList(input_value);
}


