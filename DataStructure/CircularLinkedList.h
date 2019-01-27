#pragma once
#include "LinkedStructure.h"

using namespace std;

template<typename T>
class CircularLinkedList:virtual public LinkedStructure<CircularLinkedList<T>,T>
{
private:
	//store the first node of the list
	CircularLinkedList<T>* first;

	//store the current node
	CircularLinkedList<T>* current;

	//contruction for append method. It will assign the address of the first node in every child node
	CircularLinkedList(T inputvalue, CircularLinkedList<T>* node);

public:
	//initialize the node containing one of postnodular and prenodular address
	CircularLinkedList(T inputevalue);

	//Call the LinkedStructure for destruction
	~CircularLinkedList();

	//add a new value
	virtual void append(T input_value);

	//retrive the first node
	CircularLinkedList* begin();
};

template<typename T> 
inline CircularLinkedList<T>::CircularLinkedList(T inputevalue):LinkedStructure<CircularLinkedList<T>,T>(inputevalue,2)
{
	first = this;
	//first->SetNode(nullptr, 0);
}

template<typename T>
inline CircularLinkedList<T>::CircularLinkedList(T inputvalue, CircularLinkedList<T>* node):LinkedStructure<CircularLinkedList<T>,T>(inputvalue,2)
{
	first = node;
}


template<typename T> 
inline CircularLinkedList<T>::~CircularLinkedList()
{
}

template<typename T>
inline void CircularLinkedList<T>::append(T input_value)
{
	CircularLinkedList<T>* newnode = new CircularLinkedList<T>(input_value, this);

	current = first;

	while ((current->GetNode(0) != nullptr))
	{
		//!important! it seems the object comparison is not allowed the "!="
		//if post node is the first node, the current node is the last and the loop is end. If not, current node will be replaced by GetNode method.
		if (current->GetNode(0) == first)
		{
			break;
		}
		else
		{
			current = current->GetNode(0);
		}
	}

	//append the last node into the Lists
	current->SetNode(newnode, 0);

	//connect the last to the first
	newnode->SetNode(first, 0);
	
	//connect the newnode to its parent, current node
	newnode->SetNode(current, 1);
}

template<typename T>
inline CircularLinkedList<T>* CircularLinkedList<T>::begin()
{
	return first;
}

