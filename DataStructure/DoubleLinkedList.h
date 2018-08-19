#pragma once
#include "LinkedStructure.h"

template<typename T>
class DoubleLinkedList:LinkedStructure<DoubleLinkedList>
{
public:
	//initialize the node containing one of postnodular and prenodular address
	DoubleLinkedList();

	//Call the LinkedStructure for destruction
	~DoubleLinkedList();

	//the value of a node
	T value;

	//store the address of post node
	void at(DoubleLinkedList* nextnode);

	//store the address of previous node
	void back(DoubleLinkedList* prenode);

	//retreat the address of post node
	DoubleLinkedList at();

	//retreat the address of previous node
	DoubleLinkedList back();
};



template<typename T> DoubleLinkedList::DoubleLinkedList():LinkedStructure(2)
{
}


template<typename T> DoubleLinkedList::~DoubleLinkedList()
{
}

template<typename T>
inline void DoubleLinkedList<T>::at(DoubleLinkedList * nextnode)
{
	next[0] = nextnode;
}

template<typename T>
inline void DoubleLinkedList<T>::back(DoubleLinkedList * prenode)
{
	next[1] = prenode;
}

template<typename T>
inline DoubleLinkedList DoubleLinkedList<T>::at()
{
	return next[0];
}

template<typename T>
inline DoubleLinkedList DoubleLinkedList<T>::back()
{
	return next[1];
}
