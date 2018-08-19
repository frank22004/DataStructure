#pragma once
#include "LinkedStructure.h"

using namespace std;

template<typename T>
class CircularLinkedList:public LinkedStructure<CircularLinkedList>
{
public:
	CircularLinkedList();
	~CircularLinkedList();

	//the value of a node
	T value;

	//store the address of post node
	void at(CircularLinkedList* nextnode);

	//retreat the address of post node
	CircularLinkedList at();
};

template<typename T> CircularLinkedList::CircularLinkedList():LinkedStructure(1)
{
}


template<typename T> CircularLinkedList::~CircularLinkedList()
{
}

template<typename T>
inline void CircularLinkedList<T>::at(CircularLinkedList * nextnode)
{
	next[0] = nextnode;
}

template<typename T>
inline CircularLinkedList CircularLinkedList<T>::at()
{
	return next[0];
}
