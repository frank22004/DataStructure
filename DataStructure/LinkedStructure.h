#pragma once
#include "stdafx.h"
#include "vector"

using namespace std;

template<typename T>
class LinkedStructure
{
private:
	//determine the number of postnodular address within a node
	int howmanynodes;
	
public:
	//a vector containing the address of post nodes
	vector<T *>next;

	//Set the number of connected nodes
	LinkedStructure(int how_many_nodes)
	{
		for (int i = 0; i < how_many_nodes; i++)
		{
			next.push_back(nullptr);
		}
	};
	
	//free all elements and resize it to 
	~LinkedStructure() 
	{ 
		next.clear();
	};
};

