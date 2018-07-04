#pragma once
#include "LinkedStructure.h"

using namespace std;

class SingleLinkedList:public LinkedStructure<SingleLinkedList>
{
public:
	//initialize the node containing only one postnodular address
	SingleLinkedList();

	//Call the LinkedStructure for destruction
	~SingleLinkedList();

	//the id of a node
	int id;

	//Reference to https://stackoverflow.com/a/32899001/9240791 
	//store the address of post node
	void at(SingleLinkedList* nextnode);

	//retreat the address of post node
	SingleLinkedList* at();
};

SingleLinkedList::SingleLinkedList():LinkedStructure(1)
{
}

SingleLinkedList::~SingleLinkedList()
{
}

inline void SingleLinkedList::at(SingleLinkedList* nextnode)
{
	next[0] = nextnode;
}

inline SingleLinkedList * SingleLinkedList::at()
{
	return next[0];
}


