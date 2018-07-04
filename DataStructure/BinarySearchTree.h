#pragma once
#include "LinkedStructure.h"
#include "stdafx.h"
#include "stack"

using namespace std;

class BinarySearchTree:public LinkedStructure<BinarySearchTree>
{
public:
	//initialize the node containing only one postnodular address
	BinarySearchTree();

	BinarySearchTree(int value);

	//Call the LinkedStructure for destruction
	~BinarySearchTree();

	//the id of a node
	int id;

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
	BinarySearchTree* search(int k);

	//find the smallest value in a sbutree
	BinarySearchTree* min();

	//find the largest value in a subtree
	BinarySearchTree* max();

	//insert a node by ascending order
	void insert(BinarySearchTree* insertValue);

	//replace A with B in liked structure to assists the deletion of A
	void transplant(BinarySearchTree* deletednode, BinarySearchTree* nextOfdeletednode);

	//delete a node
	void erase(BinarySearchTree* deletednode);

private:
	//a temp variable for search, min/max
	BinarySearchTree* x;
	
	//a temp variable for insetion
	BinarySearchTree* ytemp;

	//a temp variable for root
	BinarySearchTree* xtemp;
};



BinarySearchTree::BinarySearchTree():LinkedStructure(3)
{	
}

inline BinarySearchTree::BinarySearchTree(int value):LinkedStructure(3)
{
	id = value;
	root = this;
}

BinarySearchTree::~BinarySearchTree()
{
}

inline void BinarySearchTree::parent(BinarySearchTree* head)
{
	next[0]=head;
}

inline BinarySearchTree *BinarySearchTree::parent()
{
	return next[0];
}

inline void BinarySearchTree::left(BinarySearchTree* leftchild)
{
	next[1] = leftchild;
}

inline BinarySearchTree *BinarySearchTree::left()
{
	return next[1];
}

inline void BinarySearchTree::right(BinarySearchTree* rightchild)
{
	next[2] = rightchild;
}

inline BinarySearchTree *BinarySearchTree::right()
{
	return next[2];
}

inline void BinarySearchTree::inorderWalk()
{
	//begin from root
	x = this->root;
	printf("inorder輸出所有的node: ");

	//using a stacks as a buffer of encountered nodes
	stack<BinarySearchTree*>leftstack;
	do
	{
		//output every node in stacks
		while (!leftstack.empty())
		{
			ytemp = leftstack.top();
			printf(" %d ", ytemp->id);
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
	} while ((!leftstack.empty()));
}

inline BinarySearchTree *BinarySearchTree::search(int k)
{
	x = this;

	while ( (x !=NULL) && (k != x->id) )
	{
		if (k < x->id)
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

inline BinarySearchTree *BinarySearchTree::min()
{
	x = this;

	while (x->left() != nullptr)
	{
		x = x->left();
	}

	return x;
}

inline BinarySearchTree * BinarySearchTree::max()
{
	x = this;

	while (x->right() != nullptr)
	{
		x = x->right();
	}
	return x;
}

inline void BinarySearchTree::insert(BinarySearchTree* insertValue)
{
	ytemp = nullptr;
	xtemp = this->root;

	//find the nearest value in the tree
	while (xtemp != nullptr)
	{
		ytemp = xtemp;

		if ((insertValue->id) < (xtemp->id))
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
	else if ((insertValue->id) < (ytemp->id))
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

inline void BinarySearchTree::transplant(BinarySearchTree* deletednode, BinarySearchTree* nextOfdeletednode)
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

inline void BinarySearchTree::erase(BinarySearchTree * deletednode)
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

