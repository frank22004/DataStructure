#pragma once
#include "stdafx.h"
#include "vector"

using namespace std;

//template T represents the type of a node; template Dtype means the type of value.
template<typename T, typename Dtype>
class LinkedStructure
{
private:
	//determine the number of postnodular address within a node
	int howmanynodes;

	//determine the quantity of values in a node
	//int howmanyvalues;
	
	//a vector containing the address of post nodes
	vector<T *>next;

	//a data with template Dtype
	Dtype value;

public:
	//Set the number of connected nodes
	LinkedStructure(int how_many_nodes)
	{
		for (int i = 0; i < how_many_nodes; i++)
		{
			next.push_back(nullptr);
		}
	};

	//LinkedStructure(int how_many_nodes, int how_many_values)
	//{
	//	next.reserve(how_many_nodes);
	//	value.reserve(how_many_values);
	//}
	
	//Constructe a node, which contains a value with template Dtype, a number of nodes, and a number of values 
	LinkedStructure(Dtype input_values, int how_many_nodes)
	{
		for (int i = 0; i < how_many_nodes; i++)
		{
			next.push_back(nullptr);
		}

		value =input_values;

		/*value = vector<Dtype>(input_values);*/
	}

	//free all elements and resize it to 
	~LinkedStructure() 
	{ 
		next.clear();
	};

	//link the pre-node and post-node
	void SetNode(T* nextnode, int nodenum)
	{
		next[nodenum] = nextnode;
	}

	//Return the address of post-node
	T* GetNode(int nodenum)
	{
		return next[nodenum];
	}

	//Retrive a value
	Dtype GetValues()
	{
		return value;
	}
};

