#pragma once
#include "LinkedStructure.h"

template<typename T>
class DoubleLinkedList:virtual public LinkedStructure<DoubleLinkedList<T>, T>
{
private:
	//store the first node of the list
	DoubleLinkedList* first;

	//store the current node
	DoubleLinkedList* current;

public:
	//initialize the node containing one of postnodular and prenodular address
	DoubleLinkedList();

	//initialize a node with value
	DoubleLinkedList(T inputevalue);

	//Call the LinkedStructure for destruction
	~DoubleLinkedList();

	//add a new value
	virtual void append(T input_value);
};



template<typename T> 
inline DoubleLinkedList<T>::DoubleLinkedList():LinkedStructure<DoubleLinkedList<T>,T>(2)
{
	first = nullptr;
}

template<typename T>
inline DoubleLinkedList<T>::DoubleLinkedList(T inputevalue):LinkedStructure<DoubleLinkedList<T>,T>(inputevalue,2)
{
	first = this;
}

template<typename T> 
inline DoubleLinkedList<T>::~DoubleLinkedList()
{
}

template<typename T>
inline void DoubleLinkedList<T>::append(T inpute_value)
{
	DoubleLinkedList* newnode = new DoubleLinkedList(inpute_value);

	current = first;

	while ((current->GetNode(0) != nullptr) /*|| (current->GetNode(0) != first)*/)
	{
		current = current->GetNode(0);
	}

	current->SetNode(newnode, 0);

	//connect the newnode to its parent, current node
	newnode->SetNode(current, 1);

	//newnode->SetNode(current, 1);
}
