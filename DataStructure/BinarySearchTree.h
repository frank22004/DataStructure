#pragma once
#include "LinkedStructure.h"
#include "stdafx.h"
#include "stack"

//define node[0]:left, node[1]:right, node[2]:parent

using namespace std;

template<typename T>
class BinarySearchTree:virtual public LinkedStructure<BinarySearchTree<T>,T>
{
public:
	//initialize the node containing only one postnodular address
	BinarySearchTree();

	//initialize the node
	BinarySearchTree(T value);

	//Call the LinkedStructure for destruction
	~BinarySearchTree();

	//the id of a node
	//int id;

	//a root of a tree
	BinarySearchTree* root;

	//setting and calling method of parental nodular address
	void parent(BinarySearchTree* head);
	//return the parental nodular address
	BinarySearchTree* parent();

	//setting and calling method of left postnodular address
	void left(BinarySearchTree* leftchild);
	//return the lef nodular address
	BinarySearchTree* left();

	//setting and calling method of right postnodular address
	void right(BinarySearchTree* rightchild);
	//return the right nodular address
	BinarySearchTree* right();

	//output all elements order by left, parent, and right
	void inorderWalk();

	//search a subtree for a certain value
	BinarySearchTree* search(T querryValue);

	//find the smallest value in a sbutree
	BinarySearchTree* min();

	//find the largest value in a subtree
	BinarySearchTree* max();

	//add new value
	void append(T input_value);

	//replace A with B in liked structure to assists the deletion of A
	void transplant(BinarySearchTree* deletednode, BinarySearchTree* nextOfdeletednode);

	//delete a node
	void erase(BinarySearchTree* deletednode);

private:
	//insert a node by ascending order
	void insert(BinarySearchTree* insertValue);

	//for the appendix of a new value
	BinarySearchTree(T value, BinarySearchTree<T>* node);

	//a temp variable for search, min/max
	BinarySearchTree* x;
	
	//a temp variable for insetion
	BinarySearchTree* ytemp;

	//a temp variable for root
	BinarySearchTree* xtemp;

	//using a stacks as a buffer of encountered nodes for inorder tree walk
	stack<BinarySearchTree*>leftstack;
};


template<typename T>
inline BinarySearchTree<T>::BinarySearchTree():LinkedStructure<BinarySearchTree<T>, T>(3)
{	
}

template<typename T>
inline BinarySearchTree<T>::BinarySearchTree(T value):LinkedStructure<BinarySearchTree<T>,T>(value,3)
{
	//id = value;
	root = this;
}

template<typename T>
inline BinarySearchTree<T>::~BinarySearchTree()
{
}

template<typename T>
inline void BinarySearchTree<T>::parent(BinarySearchTree* head)
{
	//next[0]=head;
	this->SetNode(head, 2);
}

template<typename T>
inline BinarySearchTree<T>* BinarySearchTree<T>::parent()
{
	return this->GetNode(2);
}

template<typename T>
inline void BinarySearchTree<T>::left(BinarySearchTree* leftchild)
{
	//next[1] = leftchild;
	this->SetNode(leftchild, 0);
}

template<typename T>
inline BinarySearchTree<T>* BinarySearchTree<T>::left()
{
	return this->GetNode(0);
}

template<typename T>
inline void BinarySearchTree<T>::right(BinarySearchTree* rightchild)
{
	//next[2] = rightchild;
	this->SetNode(rightchild, 1);
}

template<typename T>
inline BinarySearchTree<T>* BinarySearchTree<T>::right()
{
	return this->GetNode(1);
}

template<typename T>
inline void BinarySearchTree<T>::inorderWalk()
{
	//begin from root
	x = this->root;
	printf("Output all of the nodes by inorder: \n");

	//search the left node from the root at first, then cast every node by descending order. 
	//Each node will be evaluated the existance of the right child.
	//If existed, the directory will be change to the right child and search the left side as below.
	do
	{
		//output every node in stacks
		while (!leftstack.empty())
		{
			ytemp = leftstack.top();
			printf("The value of %p is %d , parent = %p, left child = %p, right child = %p \n", ytemp, ytemp->GetValues(), ytemp->parent(), ytemp->left(), ytemp->right());
			leftstack.pop();

			//change the directroy to right child if exists
			if (ytemp->right() != nullptr)
			{
				x = ytemp->right();
				break;
			}
		}
		
		//stack every left children
		while (x != nullptr)
		{
			leftstack.push(x);
			x = x->left();
		}
	} while (!leftstack.empty());
}

template<typename T>
inline BinarySearchTree<T>* BinarySearchTree<T>::search(T querryValue)
{
	x = root;

	//search the left side if the querryValue is smaller than root, vice reversa.
	while ( (x != nullptr) && (querryValue != x->GetValues()) )
	{
		if (querryValue < (x->GetValues()) )
		{
			x = x->left();
		}
		else
		{
			x = x->right();
		}
	}
	return x;
}

template<typename T>
inline BinarySearchTree<T>* BinarySearchTree<T>::min()
{
	x = root;

	while (x->left() != nullptr)
	{
		x = x->left();
	}

	return x;
}

template<typename T>
inline BinarySearchTree<T>* BinarySearchTree<T>::max()
{
	x = root;

	while (x->right() != nullptr)
	{
		x = x->right();
	}
	return x;
}

template<typename T>
inline void BinarySearchTree<T>::append(T input_value)
{
	BinarySearchTree<T>* newnode = new BinarySearchTree<T>(input_value, this);

	this->insert(newnode);
}

template<typename T>
inline void BinarySearchTree<T>::insert(BinarySearchTree* insertValue)
{
	ytemp = nullptr;
	xtemp = root;

	//find the nearest value in the tree
	while (xtemp != nullptr)
	{
		ytemp = xtemp;

		if ((insertValue->GetValues()) < (xtemp->GetValues()))
		{
			xtemp = xtemp->left();
		}
		else
		{
			xtemp = xtemp->right();
		}
	}

	//configure the nearest value as inserValue's parent
	insertValue->parent(ytemp);

	if (ytemp == nullptr)
	{
		//configure the inserValue as root if the nearest value doesn't exist
		this->root = insertValue;
		insertValue->root = insertValue;
	}
	else if ((insertValue->GetValues()) < (ytemp->GetValues()))
	{
		//Conversely, configure insertValue as the left child if its value is lower than parent.
		ytemp->left(insertValue);
		insertValue->root = this->root;
	}
	else
	{
		//Vice Reversa. configure it as the right child
		ytemp->right(insertValue);
		insertValue->root = this->root;
	}
}

template<typename T>
inline void BinarySearchTree<T>::transplant(BinarySearchTree* deletednode, BinarySearchTree* nextOfdeletednode)
{
	if (deletednode->parent() == nullptr)
	{
		this->root = nextOfdeletednode;
	}
	else if (deletednode == deletednode->parent()->left())
	{
		//check whether the deletion is the left child of parent, then replace it with nextofdeletednode
		deletednode->parent()->left(nextOfdeletednode);
	}
	else
	{
		//Vice Reversa. check the right child of parent
		deletednode->parent()->right(nextOfdeletednode);
	}

	if (nextOfdeletednode != nullptr)
	{
		//link the parental node and nextOfdeletednode
		nextOfdeletednode->parent(deletednode->parent());
	}
}

template<typename T>
inline void BinarySearchTree<T>::erase(BinarySearchTree* deletednode)
{
	if (deletednode->left() == nullptr)
	{
		//concatenate the right subtree and parental node of deletion
		transplant(deletednode, deletednode->right());
	}
	else if (deletednode->right() == nullptr)
	{
		//concatenate the left subtree and parental node of deletion
		transplant(deletednode, deletednode->left());
	}
	else
	{
		//find the smallest of the right subtree
		x = deletednode->right()->min();

		//if the smallest is not the next, it moves to the next
		if (x->parent() != deletednode)
		{
			//C'ause the smallest haven't the left subtree
			transplant(x,x->right());
			x->right(deletednode->right());
			x->right()->parent(x);
		}

		//concatenate the left subtree of deletion and smallest
		transplant(deletednode,x);
		x->left(deletednode->left());
		x->left()->parent(x);
	}
}

template<typename T>
inline BinarySearchTree<T>::BinarySearchTree(T value, BinarySearchTree<T>* node):LinkedStructure<BinarySearchTree<T>, T>(value, 3)
{
	root = node;
}

